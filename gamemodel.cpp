#include "gamemodel.h"

GameModel::GameModel(QMainWindow* window, QPixmap& background, int maxPoint) :
    status(PREPARE)
{
    Red.live_pokemon = 0;
    Red.type = RedSide;
    Blue.live_pokemon = 0;
    Blue.type = BlueSide;
    totalAblityPoint = maxPoint;

    gameTimer = new QTimer(this);
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(onCheckGameStatus()));

    this->setParent(window);
    this->setFixedSize(window->size());

    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, this->x(), this->y());
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setScene(scene);
    scene->addPixmap(background);
    this->show();
}
GameModel::~GameModel()
{
    delete scene;
    delete gameTimer;
}
void GameModel::prepareGame()
{

}
void GameModel::startGame()
{
    status = PLAYING;
    gameTimer->start(30);
    for (int i = 0; i < Blue.live_pokemon; i++)
        Blue.units[i]->setState(MOVE);
    for (int i = 0; i < Red.live_pokemon; i++)
        Red.units[i]->setState(MOVE);
}
void GameModel::checkWinDeafet()
{
    if (Blue.live_pokemon == 0)
        winGame();
    else if (Red.live_pokemon == 0)
        defeatGame();
}
GameStatus GameModel::checkStatus()
{
    return status;
}
void GameModel::wheelEvent(QWheelEvent *event)
{
//    status = PLAYING;
    if (status != PLAYING)
        return;
    // 获取当前鼠标相对于view的位置;
    QPointF cursorPoint = event->pos();
    // 获取当前鼠标相对于scene的位置;
    QPointF scenePos = this->mapToScene(QPoint(cursorPoint.x(), cursorPoint.y()));

    // 获取view的宽高;
    qreal viewWidth = this->viewport()->width();
    qreal viewHeight = this->viewport()->height();

    // 获取当前鼠标位置相当于view大小的横纵比例;
    qreal hScale = cursorPoint.x() / viewWidth;
    qreal vScale = cursorPoint.y() / viewHeight;

    // 当前放缩倍数;
    qreal scaleFactor = this->matrix().m11();
    int wheelDeltaValue = event->delta();

    qreal wheelSpeed = 1.1;
    if (wheelDeltaValue > 0)
    {
        if (scaleFactor > 2)
            return;
        this->scale(wheelSpeed, wheelSpeed);
    }
    else
    {
        if (scaleFactor <= 1)
            return;
        this->scale(1.0 / wheelSpeed, 1.0 / wheelSpeed);
        if (this->matrix().m11() <= 1.0)
            this->scale(wheelSpeed, wheelSpeed);
    }
    // 将scene坐标转换为放大缩小后的坐标;
    QPointF viewPoint = this->matrix().map(scenePos);
    // 通过滚动条控制view放大缩小后的展示scene的位置;
    this->horizontalScrollBar()->setValue(int(viewPoint.x() - viewWidth * hScale));
    this->verticalScrollBar()->setValue(int(viewPoint.y() - viewHeight * vScale));
}

QPointF GameModel::getEnemyPos(Pokemon* me, Side &yourSide)
{
    qreal minDistance2 = 10000000;
    qreal thisDistance2 = 0.0;
    int k = 0;
    int yourNumber = yourSide.units.size();
    for (int i = 0; i < yourNumber; i++)
    {
        thisDistance2 = pow(me->pos().x() - yourSide.units[i]->pos().x(), 2)
                + pow(me->pos().y() - yourSide.units[i]->pos().y(), 2);
        if (minDistance2 > thisDistance2)
        {
            minDistance2 = thisDistance2;
            k = i;
        }
    }
    return (yourSide.units[k]->pos());
}
void GameModel::moveToEnemy()
{
    for (int i = 0; i < Blue.live_pokemon; i++)
    {
        QPointF enemyPos = getEnemyPos(Blue.units[i], Red);
        Blue.units[i]->moveTo(enemyPos);
    }
    for (int i = 0; i < Red.live_pokemon; i++)
    {
        QPointF enemyPos = getEnemyPos(Red.units[i], Blue);
        Red.units[i]->moveTo(enemyPos);
    }
}
void GameModel::onCheckGameStatus()
{
    if (status == PLAYING)
    {
        checkWinDeafet();
        moveToEnemy();
    }
}
void GameModel::addPikachu(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/pikachu.gif");
    Pokemon* pikachu = new Pokemon(side.type, "Pikachu", p, pMovie, 0.5, 60, 60, 120, 250, 25);
    side.units.push_back(pikachu);
    side.live_pokemon++;

    this->scene->addItem(pikachu);
    pikachu->setPos(x, y);
}
void GameModel::addSquirtle(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/squirtle.gif");
    Pokemon* squirtle = new Pokemon(side.type, "Squirtle", p, pMovie, 0.5, 53, 54, 100, 200, 20);
    side.units.push_back(squirtle);
    side.live_pokemon++;

    this->scene->addItem(squirtle);
    squirtle->setPos(x, y);
}
void GameModel::addCharmander(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/charmander.gif");
    Pokemon* charmander = new Pokemon(side.type, "Squirtle", p, pMovie, 0.5, 48, 57, 80, 200, 30);
    side.units.push_back(charmander);
    side.live_pokemon++;

    this->scene->addItem(charmander);
    charmander->setPos(x, y);
}
