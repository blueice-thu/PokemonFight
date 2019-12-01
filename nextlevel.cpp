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
    ui->resumeButton->setStyleSheet("QPushButton{border-image: url(:/image/mainGame/res/image/mainGame/resumeButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/mainGame/res/image/mainGame/resumeButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/mainGame/res/image/mainGame/resumeButton3.png);}");
    ui->nextButton->setStyleSheet("QPushButton{border-image: url(:/image/otherButton/res/image/otherButton/nextButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/otherButton/res/image/otherButton/nextButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/otherButton/res/image/otherButton/nextButton3.png);}");
    ui->quitButton->setStyleSheet("QPushButton{border-image: url(:/image/otherButton/res/image/otherButton/quitButton.png);}"
                                  "QPushButton:hover{border-image: url(:/image/otherButton/res/image/otherButton/quitButton2.png);}"
                                  "QPushButton:pressed{border-image: url(:/image/otherButton/res/image/otherButton/quitButton3.png);}");
    move(parent->width() / 2 - this->width() / 4, parent->height() / 2 - this->height() / 4);
    setAttribute(Qt::WA_DeleteOnClose);
}

NextLevel::~NextLevel()
{
    delete ui;
}

void NextLevel::on_quitButton_pressed()
{
    this->quit();
    emit quit();
}
void NextLevel::on_nextButton_pressed()
{
    this->close();
    emit next();
}
void NextLevel::on_restartButton_pressed()
{
    this->close();
    emit restart();
}
void NextLevel::on_resumeButton_pressed()
{
    this->close();
    emit resume();
}
void NextLevel::setLablePic(QString picPath)
{
    ui->label->setPixmap(QPixmap(picPath));
}
void NextLevel::setNextVisble(bool vis)
{
    ui->nextButton->setVisible(vis);
}
void NextLevel::setResumeVisble(bool vis)
{
    ui->resumeButton->setVisible(vis);
}
