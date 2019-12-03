#include "gamemodel.h"
#include "ui_gamemodel.h"

GameModel::GameModel(QMainWindow* window, QPixmap& background, int maxPoint) :
    status(SELECT), ui(new Ui::GameModel)
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
//    scene->addPixmap(QPixmap(":/image/preparePage/res/image/preparePage/prepareBG.png").scaled(window->size()));
    this->show();
    setFocus();

    ui->setupUi(window);
    connect(ui->quitButton, SIGNAL(clicked()), window, SLOT(quit_to_main()));
    connect(ui->reselectButton, SIGNAL(clicked()), window, SLOT(restart_stage()));
    connect(ui->playButton, SIGNAL(clicked()), this, SLOT(prepareGame()));
    initUi();
}
GameModel::~GameModel()
{
    delete scene;
    delete gameTimer;
    delete ui;
}
void GameModel::initUi()
{
    ui->point->setNum(this->totalAblityPoint);
    ui->playButton->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/playButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/playButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/playButton3.png);}");
    ui->reselectButton->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/reselectButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/reselectButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/reselectButton3.png);}");
    ui->quitButton->setStyleSheet("QPushButton{border-image: url(:/image/otherButton/res/image/otherButton/quitButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/otherButton/res/image/otherButton/quitButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/otherButton/res/image/otherButton/quitButton3.png);}");
    ui->addButton_0->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_1->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_2->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_3->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_4->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_5->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_6->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_7->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_8->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_9->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_10->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_11->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_12->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_13->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_14->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_15->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->addButton_16->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/plusButton.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/plusButton2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/plusButton3.png);}");
    ui->minusButton_0->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                                "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                                "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_1->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                                "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                                "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_2->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_3->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_4->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_5->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_6->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_7->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_8->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_9->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_10->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_11->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_12->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_13->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_14->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_15->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    ui->minusButton_16->setStyleSheet("QPushButton{border-image: url(:/image/preparePage/res/image/preparePage/minus.png);}"
                            "QPushButton:hover{border-image: url(:/image/preparePage/res/image/preparePage/minus2.png);}"
                            "QPushButton:pressed{border-image: url(:/image/preparePage/res/image/preparePage/minus3.png);}");
    connect(ui->addButton_0, SIGNAL(clicked()), this, SLOT(on_addButton_0_clicked()));
    connect(ui->addButton_1, SIGNAL(clicked()), this, SLOT(on_addButton_1_clicked()));
    connect(ui->addButton_2, SIGNAL(clicked()), this, SLOT(on_addButton_2_clicked()));
    connect(ui->addButton_3, SIGNAL(clicked()), this, SLOT(on_addButton_3_clicked()));
    connect(ui->addButton_4, SIGNAL(clicked()), this, SLOT(on_addButton_4_clicked()));
    connect(ui->addButton_5, SIGNAL(clicked()), this, SLOT(on_addButton_5_clicked()));
    connect(ui->addButton_6, SIGNAL(clicked()), this, SLOT(on_addButton_6_clicked()));
    connect(ui->addButton_7, SIGNAL(clicked()), this, SLOT(on_addButton_7_clicked()));
    connect(ui->addButton_8, SIGNAL(clicked()), this, SLOT(on_addButton_8_clicked()));
    connect(ui->addButton_9, SIGNAL(clicked()), this, SLOT(on_addButton_9_clicked()));
    connect(ui->addButton_10, SIGNAL(clicked()), this, SLOT(on_addButton_10_clicked()));
    connect(ui->addButton_11, SIGNAL(clicked()), this, SLOT(on_addButton_11_clicked()));
    connect(ui->addButton_12, SIGNAL(clicked()), this, SLOT(on_addButton_12_clicked()));
    connect(ui->addButton_13, SIGNAL(clicked()), this, SLOT(on_addButton_13_clicked()));
    connect(ui->addButton_14, SIGNAL(clicked()), this, SLOT(on_addButton_14_clicked()));
    connect(ui->addButton_15, SIGNAL(clicked()), this, SLOT(on_addButton_15_clicked()));
    connect(ui->addButton_16, SIGNAL(clicked()), this, SLOT(on_addButton_16_clicked()));
    connect(ui->minusButton_0, SIGNAL(clicked()), this, SLOT(on_minusButton_0_clicked()));
    connect(ui->minusButton_1, SIGNAL(clicked()), this, SLOT(on_minusButton_1_clicked()));
    connect(ui->minusButton_2, SIGNAL(clicked()), this, SLOT(on_minusButton_2_clicked()));
    connect(ui->minusButton_3, SIGNAL(clicked()), this, SLOT(on_minusButton_3_clicked()));
    connect(ui->minusButton_4, SIGNAL(clicked()), this, SLOT(on_minusButton_4_clicked()));
    connect(ui->minusButton_5, SIGNAL(clicked()), this, SLOT(on_minusButton_5_clicked()));
    connect(ui->minusButton_6, SIGNAL(clicked()), this, SLOT(on_minusButton_6_clicked()));
    connect(ui->minusButton_7, SIGNAL(clicked()), this, SLOT(on_minusButton_7_clicked()));
    connect(ui->minusButton_8, SIGNAL(clicked()), this, SLOT(on_minusButton_8_clicked()));
    connect(ui->minusButton_9, SIGNAL(clicked()), this, SLOT(on_minusButton_9_clicked()));
    connect(ui->minusButton_10, SIGNAL(clicked()), this, SLOT(on_minusButton_10_clicked()));
    connect(ui->minusButton_11, SIGNAL(clicked()), this, SLOT(on_minusButton_11_clicked()));
    connect(ui->minusButton_12, SIGNAL(clicked()), this, SLOT(on_minusButton_12_clicked()));
    connect(ui->minusButton_13, SIGNAL(clicked()), this, SLOT(on_minusButton_13_clicked()));
    connect(ui->minusButton_14, SIGNAL(clicked()), this, SLOT(on_minusButton_14_clicked()));
    connect(ui->minusButton_15, SIGNAL(clicked()), this, SLOT(on_minusButton_15_clicked()));
    connect(ui->minusButton_16, SIGNAL(clicked()), this, SLOT(on_minusButton_16_clicked()));
}
void GameModel::prepareGame()
{
    addPokemon();
    if (Red.live_pokemon == 0)
        return;
    ui->centralwidget->hide();
    status = PREPARE;
    for (size_t i = 0; i < Red.live_pokemon; i++)
    {
        Red.units[i]->setFlag(QGraphicsItem::ItemIsMovable, true);
    }
}
void GameModel::startGame()
{
    for (size_t i = 0; i < Red.live_pokemon; i++)
        Red.units[i]->setFlag(QGraphicsItem::ItemIsMovable, false);
    status = PLAYING;
    gameTimer->start(30);
    for (size_t i = 0; i < Blue.live_pokemon; i++)
        Blue.units[i]->setState(MOVE);
    for (size_t i = 0; i < Red.live_pokemon; i++)
    {
        Red.units[i]->setState(MOVE);
        Red.units[i]->setFlag(QGraphicsItem::ItemIsMovable, false);
    }
}
void GameModel::pauseGame()
{
    status = PAUSE;
    gameTimer->stop();
}
void GameModel::continueGame()
{
    status = PLAYING;
    gameTimer->start(30);
}
void GameModel::checkWinDefeat()
{
    if (Blue.live_pokemon <= 0)
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
void GameModel::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_X)
    {
        // Make HP MAX!
        if (status == PLAYING)
        {
            size_t i = 0;
            while (i < Red.live_pokemon)
            {
                if (Red.units[i]->getHp() < 1000000)
                    Red.units[i]->cutHp(-1000000);
                i++;
            }
        }
        else if (status == SELECT)
        {
            totalAblityPoint = 1000000;
            ui->point->setNum(totalAblityPoint);
        }
        QWidget::keyPressEvent(event);
        return;
    }
    switch(event->key())
    {
        case Qt::Key_Escape:
            if (status == PLAYING)
                emit pause();
            break;
        case Qt::Key_Enter:
            if (status == PREPARE)
                startGame();
            break;
        case Qt::Key_Return:
            if (status == PREPARE)
                startGame();
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}
Pokemon* GameModel::getEnemy(Pokemon* me, Side &yourSide)
{
    size_t yourNumber = yourSide.units.size();
    if (yourNumber == 0)
    {
        return nullptr;
    }
    qreal minDistance2 = 10000000;
    qreal thisDistance2 = 0.0;
    size_t k = 0;
    size_t i = 0;
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
        if (enemy == nullptr)
        {
            emit defeat();
            return;
        }
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
        if (enemy == nullptr)
        {
            emit win();
            return;
        }
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
void transPos(int& x, int& y)
{
    if (y < 800)
        y += 140;
    else
    {
        x -= 140;
        y = 300;
    }
}
void GameModel::addPokemon()
{
    int posX = 1200, posY = 300;
    for (unsigned int i = 0; i < MAX_POKEMON; i++)
    {
        if (numPokemon[i] == 0)
            continue;
        switch (i){
            case IDofBulbasaur:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addBulbasaur(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofCharmander:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addCharmander(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofHeracross:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addHeracross(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofJigglypuff:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addJigglypuff(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofJirachi:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addJirachi(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofLugia:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addLugia(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofLuxio:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addLuxio(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofMachop:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addMachop(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofMeowth:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addMeowth(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofOnix:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addOnix(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofPangoro:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addPangoro(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofPikachu:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addPikachu(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofPolitoed:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addPolitoed(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofPsyduck:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addPsyduck(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofRaikou:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addRaikou(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofSquirtle:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addSquirtle(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
            case IDofZweilous:
                for (int j = 0; j < numPokemon[i]; j++)
                {
                    addZweilous(Red, posX, posY);
                    transPos(posX, posY);
                }
                break;
        }
    }
}
void GameModel::addBulbasaur(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/bulbasaur.gif");
    Pokemon* bulbasaur = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofBulbasaur, 45, 49, MaxHPofBulbasaur,
                                     AbilityPointofBulbasaur, AttackAbilityofBulbasaur, AttackSpeedofBulbasaur,
                                     AttackDistanceofBulbasaur);
    side.units.push_back(bulbasaur);
    side.live_pokemon++;

    this->scene->addItem(bulbasaur);
    bulbasaur->setPos(x, y);
}
void GameModel::addCharmander(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/charmander.gif");
    Pokemon* charmander = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofCharmander, 48, 57, MaxHPofCharmander,
                                      AbilityPointofCharmander, AttackAbilityofCharmander, AttackSpeedofCharmander,
                                      AttackDistanceofCharmander);
    side.units.push_back(charmander);
    side.live_pokemon++;

    this->scene->addItem(charmander);
    charmander->setPos(x, y);
}
void GameModel::addHeracross(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/heracross.gif");
    Pokemon* heracross = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofHeracross, 90, 87, MaxHPofHeracross,
                                     AbilityPointofHeracross, AttackAbilityofHeracross, AttackSpeedofHeracross,
                                     AttackDistanceofHeracross);
    side.units.push_back(heracross);
    side.live_pokemon++;

    this->scene->addItem(heracross);
    heracross->setPos(x, y);
}
void GameModel::addJigglypuff(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/jigglypuff.gif");
    Pokemon* jigglypuff = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofJigglypuff, 46, 46, MaxHPofJigglypuff,
                                      AbilityPointofJigglypuff, AttackAbilityofJigglypuff, AttackSpeedofJigglypuff,
                                      AttackDistanceofJigglypuff);
    side.units.push_back(jigglypuff);
    side.live_pokemon++;

    this->scene->addItem(jigglypuff);
    jigglypuff->setPos(x, y);
}
void GameModel::addJirachi(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/jirachi.gif");
    Pokemon* jirachi = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofJirachi, 92, 68, MaxHPofJirachi,
                                   AbilityPointofJirachi, AttackAbilityofJirachi, AttackSpeedofJirachi,
                                   AttackDistanceofJirachi);
    side.units.push_back(jirachi);
    side.live_pokemon++;

    this->scene->addItem(jirachi);
    jirachi->setPos(x, y);
}
void GameModel::addLugia(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/lugia.gif");
    Pokemon* lugia = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofLugia, 156, 127, MaxHPofLugia,
                                 AbilityPointofLugia, AttackAbilityofLugia, AttackSpeedofLugia,
                                 AttackDistanceofLugia);
    side.units.push_back(lugia);
    side.live_pokemon++;

    this->scene->addItem(lugia);
    lugia->setPos(x, y);
}
void GameModel::addLuxio(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/luxio.gif");
    Pokemon* luxio = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofLuxio, 70, 77, MaxHPofLuxio, AbilityPointofLuxio,
                                 AttackAbilityofLuxio, AttackSpeedofLuxio, AttackDistanceofLuxio);
    side.units.push_back(luxio);
    side.live_pokemon++;

    this->scene->addItem(luxio);
    luxio->setPos(x, y);
}
void GameModel::addMachop(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/machop.gif");
    Pokemon* machop = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofMachop, 39, 63, MaxHPofMachop,
                                  AbilityPointofMachop, AttackAbilityofMachop, AttackSpeedofMachop, AttackDistanceofMachop);
    side.units.push_back(machop);
    side.live_pokemon++;

    this->scene->addItem(machop);
    machop->setPos(x, y);
}
void GameModel::addMeowth(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/meowth.gif");
    Pokemon* meowth = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofMeowth, 49, 61, MaxHPofMeowth, AbilityPointofMeowth,
                                  AttackAbilityofMeowth, AttackSpeedofMeowth, AttackDistanceofMeowth);
    side.units.push_back(meowth);
    side.live_pokemon++;

    this->scene->addItem(meowth);
    meowth->setPos(x, y);
}
void GameModel::addOnix(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/onix.gif");
    Pokemon* onix = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofOnix, 90, 115, MaxHPofOnix, AbilityPointofOnix,
                                AttackAbilityofOnix, AttackSpeedofOnix, AttackDistanceofOnix);
    side.units.push_back(onix);
    side.live_pokemon++;

    this->scene->addItem(onix);
    onix->setPos(x, y);
}
void GameModel::addPangoro(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/pangoro.gif");
    Pokemon* pangoro = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofPangoro, 97, 102, MaxHPofPangoro,
                                   AbilityPointofPangoro, AttackAbilityofPangoro, AttackSpeedofPangoro,
                                   AttackDistanceofPangoro);
    side.units.push_back(pangoro);
    side.live_pokemon++;

    this->scene->addItem(pangoro);
    pangoro->setPos(x, y);
}
void GameModel::addPikachu(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/pikachu.gif");
    Pokemon* pikachu = new Pokemon(side.type, "Pikachu", p, pMovie, SpeedofPikachu, 60, 60, MaxHPofPikachu,
                                   AbilityPointofPikachu, AttackAbilityofPikachu, AttackSpeedofPikachu,
                                   AttackDistanceofPikachu);
    side.units.push_back(pikachu);
    side.live_pokemon++;

    this->scene->addItem(pikachu);
    pikachu->setPos(x, y);
}
void GameModel::addPolitoed(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/politoed.gif");
    Pokemon* politoed = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofPolitoed, 63, 77, MaxHPofPolitoed,
                                    AbilityPointofPolitoed, AttackAbilityofPolitoed, AttackSpeedofPolitoed,
                                    AttackDistanceofPolitoed);
    side.units.push_back(politoed);
    side.live_pokemon++;

    this->scene->addItem(politoed);
    politoed->setPos(x, y);
}
void GameModel::addPsyduck(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/psyduck.gif");
    Pokemon* psyduck = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofPsyduck, 51, 53, MaxHPofPsyduck,
                                   AbilityPointofPsyduck, AttackAbilityofPsyduck, AttackSpeedofPsyduck,
                                   AttackDistanceofPsyduck);
    side.units.push_back(psyduck);
    side.live_pokemon++;

    this->scene->addItem(psyduck);
    psyduck->setPos(x, y);
}
void GameModel::addRaikou(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/raikou.gif");
    Pokemon* raikou = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofRaikou, 53, 54, MaxHPofRaikou,
                                  AbilityPointofRaikou, AttackAbilityofRaikou, AttackSpeedofRaikou,
                                  AttackDistanceofRaikou);
    side.units.push_back(raikou);
    side.live_pokemon++;

    this->scene->addItem(raikou);
    raikou->setPos(x, y);
}
void GameModel::addSquirtle(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/squirtle.gif");
    Pokemon* squirtle = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofSquirtle, 53, 54, MaxHPofSquirtle,
                                    AbilityPointofSquirtle, AttackAbilityofSquirtle, AttackSpeedofSquirtle,
                                    AttackDistanceofSquirtle);
    side.units.push_back(squirtle);
    side.live_pokemon++;

    this->scene->addItem(squirtle);
    squirtle->setPos(x, y);
}
void GameModel::addZweilous(Side &side, int x, int y)
{
    QPainter* p = new QPainter(this);
    QMovie* pMovie = new QMovie(":/pokemon/res/pokemon/zweilous.gif");
    Pokemon* zweilous = new Pokemon(side.type, "Squirtle", p, pMovie, SpeedofZweilous, 95, 79, MaxHPofZweilous,
                                    AbilityPointofZweilous, AttackAbilityofZweilous, AttackSpeedofZweilous,
                                    AttackDistanceofZweilous);
    side.units.push_back(zweilous);
    side.live_pokemon++;

    this->scene->addItem(zweilous);
    zweilous->setPos(x, y);
}
void GameModel::on_addButton_0_clicked()
{
    if (totalAblityPoint < AbilityPointofBulbasaur)
        return;
    totalAblityPoint -= AbilityPointofBulbasaur;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_0->setNum(++numPokemon[0]);
}
void GameModel::on_addButton_1_clicked()
{
    if (totalAblityPoint < AbilityPointofCharmander)
        return;
    totalAblityPoint -= AbilityPointofCharmander;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_1->setNum(++numPokemon[1]);
}
void GameModel::on_addButton_2_clicked()
{
    if (totalAblityPoint < AbilityPointofHeracross)
        return;
    totalAblityPoint -= AbilityPointofHeracross;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_2->setNum(++numPokemon[2]);
}
void GameModel::on_addButton_3_clicked()
{
    if (totalAblityPoint < AbilityPointofJigglypuff)
        return;
    totalAblityPoint -= AbilityPointofJigglypuff;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_3->setNum(++numPokemon[3]);
}
void GameModel::on_addButton_4_clicked()
{
    if (totalAblityPoint < AbilityPointofJirachi)
        return;
    totalAblityPoint -= AbilityPointofJirachi;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_4->setNum(++numPokemon[4]);
}
void GameModel::on_addButton_5_clicked()
{
    if (totalAblityPoint < AbilityPointofLugia)
        return;
    totalAblityPoint -= AbilityPointofLugia;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_5->setNum(++numPokemon[5]);
}
void GameModel::on_addButton_6_clicked()
{
    if (totalAblityPoint < AbilityPointofLuxio)
        return;
    totalAblityPoint -= AbilityPointofLuxio;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_6->setNum(++numPokemon[6]);
}
void GameModel::on_addButton_7_clicked()
{
    if (totalAblityPoint < AbilityPointofMachop)
        return;
    totalAblityPoint -= AbilityPointofMachop;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_7->setNum(++numPokemon[7]);
}
void GameModel::on_addButton_8_clicked()
{
    if (totalAblityPoint < AbilityPointofMeowth)
        return;
    totalAblityPoint -= AbilityPointofMeowth;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_8->setNum(++numPokemon[8]);
}
void GameModel::on_addButton_9_clicked()
{
    if (totalAblityPoint < AbilityPointofOnix)
        return;
    totalAblityPoint -= AbilityPointofOnix;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_9->setNum(++numPokemon[9]);
}
void GameModel::on_addButton_10_clicked()
{
    if (totalAblityPoint < AbilityPointofPangoro)
        return;
    totalAblityPoint -= AbilityPointofPangoro;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_10->setNum(++numPokemon[10]);
}
void GameModel::on_addButton_11_clicked()
{
    if (totalAblityPoint < AbilityPointofPikachu)
        return;
    totalAblityPoint -= AbilityPointofPikachu;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_11->setNum(++numPokemon[11]);
}
void GameModel::on_addButton_12_clicked()
{
    if (totalAblityPoint < AbilityPointofPolitoed)
        return;
    totalAblityPoint -= AbilityPointofPolitoed;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_12->setNum(++numPokemon[12]);
}
void GameModel::on_addButton_13_clicked()
{
    if (totalAblityPoint < AbilityPointofPsyduck)
        return;
    totalAblityPoint -= AbilityPointofPsyduck;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_13->setNum(++numPokemon[13]);
}
void GameModel::on_addButton_14_clicked()
{
    if (totalAblityPoint < AbilityPointofRaikou)
        return;
    totalAblityPoint -= AbilityPointofRaikou;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_14->setNum(++numPokemon[14]);
}
void GameModel::on_addButton_15_clicked()
{
    if (totalAblityPoint < AbilityPointofSquirtle)
        return;
    totalAblityPoint -= AbilityPointofSquirtle;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_15->setNum(++numPokemon[15]);
}
void GameModel::on_addButton_16_clicked()
{
    if (totalAblityPoint < AbilityPointofZweilous)
        return;
    totalAblityPoint -= AbilityPointofZweilous;
    ui->point->setNum(this->totalAblityPoint);
    ui->point_16->setNum(++numPokemon[16]);
}

void GameModel::on_minusButton_0_clicked()
{
    if (ui->point_0->text().toInt() > 0)
    {
        ui->point_0->setNum(--numPokemon[0]);
        totalAblityPoint += AbilityPointofBulbasaur;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_1_clicked()
{
    if (ui->point_1->text().toInt() > 0)
    {
        ui->point_1->setNum(--numPokemon[1]);
        totalAblityPoint += AbilityPointofCharmander;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_2_clicked()
{
    if (ui->point_2->text().toInt() > 0)
    {
        ui->point_2->setNum(--numPokemon[2]);
        totalAblityPoint += AbilityPointofHeracross;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_3_clicked()
{
    if (ui->point_3->text().toInt() > 0)
    {
        ui->point_3->setNum(--numPokemon[3]);
        totalAblityPoint += AbilityPointofJigglypuff;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_4_clicked()
{
    if (ui->point_4->text().toInt() > 0)
    {
        ui->point_4->setNum(--numPokemon[4]);
        totalAblityPoint += AbilityPointofJirachi;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_5_clicked()
{
    if (ui->point_5->text().toInt() > 0)
    {
        ui->point_5->setNum(--numPokemon[5]);
        totalAblityPoint += AbilityPointofLugia;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_6_clicked()
{
    if (ui->point_6->text().toInt() > 0)
    {
        ui->point_6->setNum(--numPokemon[6]);
        totalAblityPoint += AbilityPointofLuxio;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_7_clicked()
{
    if (ui->point_7->text().toInt() > 0)
    {
        ui->point_7->setNum(--numPokemon[7]);
        totalAblityPoint += AbilityPointofMachop;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_8_clicked()
{
    if (ui->point_8->text().toInt() > 0)
    {
        ui->point_8->setNum(--numPokemon[8]);
        totalAblityPoint += AbilityPointofMeowth;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_9_clicked()
{
    if (ui->point_9->text().toInt() > 0)
    {
        ui->point_9->setNum(--numPokemon[9]);
        totalAblityPoint += AbilityPointofOnix;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_10_clicked()
{
    if (ui->point_10->text().toInt() > 0)
    {
        ui->point_10->setNum(--numPokemon[10]);
        totalAblityPoint += AbilityPointofPangoro;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_11_clicked()
{
    if (ui->point_11->text().toInt() > 0)
    {
        ui->point_11->setNum(--numPokemon[11]);
        totalAblityPoint += AbilityPointofPikachu;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_12_clicked()
{
    if (ui->point_12->text().toInt() > 0)
    {
        ui->point_12->setNum(--numPokemon[12]);
        totalAblityPoint += AbilityPointofPolitoed;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_13_clicked()
{
    if (ui->point_13->text().toInt() > 0)
    {
        ui->point_13->setNum(--numPokemon[13]);
        totalAblityPoint += AbilityPointofPsyduck;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_14_clicked()
{
    if (ui->point_14->text().toInt() > 0)
    {
        ui->point_14->setNum(--numPokemon[14]);
        totalAblityPoint += AbilityPointofRaikou;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_15_clicked()
{
    if (ui->point_15->text().toInt() > 0)
    {
        ui->point_15->setNum(--numPokemon[15]);
        totalAblityPoint += AbilityPointofSquirtle;
        ui->point->setNum(this->totalAblityPoint);
    }
}
void GameModel::on_minusButton_16_clicked()
{
    if (ui->point_16->text().toInt() > 0)
    {
        ui->point_16->setNum(--numPokemon[16]);
        totalAblityPoint += AbilityPointofZweilous;
        ui->point->setNum(this->totalAblityPoint);
    }
}
