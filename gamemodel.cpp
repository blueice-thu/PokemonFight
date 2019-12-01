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
//    size_t i = 0;
//    while (i < Red.units.size())
//    {
//        delete (Red.units[i]);
//        i++;
//    }
//    i = 0;
//    while (i < Blue.units.size())
//    {
//        delete (Blue.units[i]);
//        i++;
//    }
//    while (!Red.units.empty())
//    {
//        delete Red.units.back();
//        Red.units.pop_back();
//    }
//    while (!Blue.units.empty())
//    {
//        delete Blue.units.back();
//        Blue.units.pop_back();
//    }
}
void GameModel::prepareGame()
{

}
void GameModel::startGame()
{
    if (Red.live_pokemon == 0)
        return;
    status = PLAYING;
    gameTimer->start(30);
    for (size_t i = 0; i < Blue.live_pokemon; i++)
        Blue.units[i]->setState(MOVE);
    for (size_t i = 0; i < Red.live_pokemon; i++)
    {
        Red.units[i]->setState(MOVE);
        Red.units[i]->setFlags(QGraphicsItem::ItemIsMovable);
    }
}
void GameModel::checkWinDefeat()
{
    if (Blue.live_pokemon <= 0)
//    if (true)
    {
        gameTimer->stop();
        emit win();
    }
    else if (Red.live_pokemon <= 0)
    {
        gameTimer->stop();
        emit defeat();
    }
}
GameStatus GameModel::checkStatus()
{
    return status;
}
void GameModel::wheelEvent(QWheelEvent *event)
{
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

Pokemon* GameModel::getEnemy(Pokemon* me, Side &yourSide)
{
    qreal minDistance2 = 10000000;
    qreal thisDistance2 = 0.0;
    int k = 0;
    int yourNumber = yourSide.units.size();
    int i = 0;
    while (i < yourNumber)
    {
        thisDistance2 = pow(me->pos().x() - yourSide.units[i]->pos().x(), 2)
                + pow(me->pos().y() - yourSide.units[i]->pos().y(), 2);
        if (minDistance2 > thisDistance2)
        {
            minDistance2 = thisDistance2;
            k = i;
        }
        i++;
    }
    return (yourSide.units[k]);
}
void GameModel::moveToEnemy()
{
    for (size_t i = 0; i < Blue.live_pokemon; i++)
    {
        Pokemon* enemy = getEnemy(Blue.units[i], Red);
        qDebug() << enemy->getHp();
        QPointF enemyPos = enemy->pos();
        Blue.units[i]->moveTo(enemyPos);
        if (Blue.units[i]->getState() == ATTACK)
        {
            attackEnemy(Blue.units[i], enemy);
        }
    }
    for (size_t i = 0; i < Red.live_pokemon; i++)
    {
        Pokemon* enemy = getEnemy(Red.units[i], Blue);
        QPointF enemyPos = enemy->pos();
        Red.units[i]->moveTo(enemyPos);
        if (Red.units[i]->getState() == ATTACK)
        {
            attackEnemy(Red.units[i], enemy);
        }
    }
}
void GameModel::killPokemon()
{
    for (size_t i = 0; i < Blue.live_pokemon; i++)
    {
        if (Blue.units[i]->getHp() <= 0)
        {
            scene->removeItem(Blue.units[i]);
            Pokemon* temp = Blue.units[i];
            Blue.units.erase(std::begin(Blue.units) + i);
            delete temp;
            Blue.live_pokemon--;
        }
    }
    for (size_t i = 0; i < Red.live_pokemon; i++)
    {
        if (Red.units[i]->getHp() <= 0)
        {
            scene->removeItem(Red.units[i]);
            Pokemon* temp = Red.units[i];
            Red.units.erase(std::begin(Red.units) + i);
            delete temp;
            Red.live_pokemon--;
        }
    }
}
void GameModel::attackEnemy(Pokemon* attacker, Pokemon* attacked)
{
    attacked->cutHp(attacker->getAttackAbility());
}
void GameModel::onCheckGameStatus()
{
    if (status == PLAYING)
    {
        checkWinDefeat();
        killPokemon();
        moveToEnemy();
    }
}
void GameModel::addPikachu(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/pikachu.gif");
    Pokemon* pikachu = new Pokemon(side.type, "Pikachu", p, pMovie, 0.5, 60, 60, 120, 250, 25, 5, 30);
    side.units.push_back(pikachu);
    side.live_pokemon++;

    this->scene->addItem(pikachu);
    pikachu->setPos(x, y);
}
void GameModel::addSquirtle(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/squirtle.gif");
    Pokemon* squirtle = new Pokemon(side.type, "Squirtle", p, pMovie, 0.5, 53, 54, 100, 200, 20, 5, 30);
    side.units.push_back(squirtle);
    side.live_pokemon++;

    this->scene->addItem(squirtle);
    squirtle->setPos(x, y);
}
void GameModel::addCharmander(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/charmander.gif");
    Pokemon* charmander = new Pokemon(side.type, "Squirtle", p, pMovie, 0.5, 48, 57, 50, 200, 30, 4, 60);
    side.units.push_back(charmander);
    side.live_pokemon++;

    this->scene->addItem(charmander);
    charmander->setPos(x, y);
}
