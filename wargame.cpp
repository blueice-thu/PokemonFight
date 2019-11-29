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
}

WarGame::~WarGame()
{
    delete ui;
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
    ui->exitButton->setVisible(false);

    initCityStage();
}

void WarGame::initCityStage()
{
    QPixmap cityBG = QPixmap(":/image/levelBackground/res/image/level_city.jpg").scaled(this->size());
    GameModel* cityStage = new GameModel(this, cityBG, 4000);
    cityStage->prepareGame();

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cityStage->addPikachu(cityStage->Blue, 100 + 100 * i, 400 + 100 * j);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cityStage->addSquirtle(cityStage->Red, 900 + 100 * i, 400 + 100 * j);
    cityStage->startGame();
//    while (cityStage->checkStatus() == PREPARE)
//        cityStage->moveToEnemy();
}
