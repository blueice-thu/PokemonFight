#include "nextlevel.h"
#include "ui_nextlevel.h"

NextLevel::NextLevel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextLevel)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlags(Qt::FramelessWindowHint);

    ui->restartButton->setStyleSheet("QPushButton{border-image: url(:/image/otherButton/res/image/otherButton/restartButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/otherButton/res/image/otherButton/restartButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/otherButton/res/image/otherButton/restartButton3.png);}");
    ui->nextButton->setStyleSheet("QPushButton{border-image: url(:/image/otherButton/res/image/otherButton/nextButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/otherButton/res/image/otherButton/nextButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/otherButton/res/image/otherButton/nextButton3.png);}");
    ui->quitButton->setStyleSheet("QPushButton{border-image: url(:/image/otherButton/res/image/otherButton/quitButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/otherButton/res/image/otherButton/quitButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/otherButton/res/image/otherButton/quitButton3.png);}");
    move(400, 400);
}

NextLevel::~NextLevel()
{
    delete ui;
}

void NextLevel::on_quitButton_pressed()
{
    emit quit();
}

void NextLevel::on_nextButton_pressed()
{
    emit next();
}

void NextLevel::on_restartButton_pressed()
{
    emit restart();
}
