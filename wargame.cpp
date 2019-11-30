#include "wargame.h"
#include "ui_wargame.h"

WarGame::WarGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WarGame)
{
    ui->setupUi(this);

    setFixedSize(1365, 980);
    setWindowTitle("WarGame");
    setWindowIcon(QIcon(":/ico/icon.ico"));

    QDesktopWidget *deskdop=QApplication::desktop();
        move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);

    QPixmap pixmap = QPixmap(":/image/startPage/res/image/startPage/backGround.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);

    ui->startButton->setStyleSheet("QPushButton{border-image: url(:/image/startPage/res/image/startPage/startButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/startPage/res/image/startPage/startButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/startPage/res/image/startPage/startButton3.png);}");
    ui->levelsButton->setStyleSheet("QPushButton{border-image: url(:/image/startPage/res/image/startPage/levelsButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/startPage/res/image/startPage/levelsButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/startPage/res/image/startPage/levelsButton3.png);}");
    ui->settingsButton->setStyleSheet("QPushButton{border-image: url(:/image/startPage/res/image/startPage/settingsButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/startPage/res/image/startPage/settingsButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/startPage/res/image/startPage/settingsButton3.png);}");
    ui->helpButton->setStyleSheet("QPushButton{border-image: url(:/image/startPage/res/image/startPage/helpButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/startPage/res/image/startPage/helpButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/startPage/res/image/startPage/helpButton3.png);}");
    ui->exitButton->setStyleSheet("QPushButton{border-image: url(:/image/startPage/res/image/startPage/exitButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/startPage/res/image/startPage/exitButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/startPage/res/image/startPage/exitButton3.png);}");

    stage = nullptr;
}

WarGame::~WarGame()
{
    delete ui;
    if (stage)
        delete stage;
}
void WarGame::closeEvent(QCloseEvent *event)
{
//    int choose;
//    choose = QMessageBox::question(this, tr("退出游戏"),
//                                   QString(tr("确认退出游戏?")),
//                                   QMessageBox::Yes | QMessageBox::No);

//    if (choose== QMessageBox::No)
//    {
//          event->ignore();
//    }
//    else if (choose== QMessageBox::Yes)
//    {
          event->accept();
//    }
}


void WarGame::on_startButton_clicked()
{
    ui->startButton->setVisible(false);
    ui->levelsButton->setVisible(false);
    ui->settingsButton->setVisible(false);
    ui->helpButton->setVisible(false);
    ui->exitButton->setVisible(false);

    initCityStage();
}
void WarGame::win_stage()
{
    NextLevel* next = new NextLevel(this);
    connect(next, SIGNAL(quit()), this, SLOT(quit_to_main()));
    next->show();
}
void WarGame::quit_to_main()
{
    if (stage)
        delete stage;
    ui->startButton->setVisible(true);
    ui->levelsButton->setVisible(true);
    ui->settingsButton->setVisible(true);
    ui->helpButton->setVisible(true);
    ui->exitButton->setVisible(true);

    QPixmap pixmap = QPixmap(":/image/startPage/res/image/startPage/backGround.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
}
void WarGame::initCityStage()
{
    QPixmap cityBG = QPixmap(":/image/levelBackground/res/image/level_city.jpg").scaled(this->size());
    stage = new GameModel(this, cityBG, 4000);
    connect(stage, SIGNAL(win()), this, SLOT(win_stage()));
    stage->prepareGame();

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            stage->addPikachu(stage->Blue, 100 + 100 * i, 400 + 100 * j);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            stage->addSquirtle(stage->Red, 900 + 100 * i, 400 + 100 * j);
    stage->prepareGame();
    stage->startGame();
}
