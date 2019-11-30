#include "nextlevel.h"
#include "ui_nextlevel.h"

NextLevel::NextLevel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextLevel)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
//    setWindowFlags(Qt::CustomizeWindowHint);
//    setWindowFlags(Qt::FramelessWindowHint);
}

NextLevel::~NextLevel()
{
    delete ui;
}

void NextLevel::on_quitButton_pressed()
{
    emit quit();
    this->close();
}

void NextLevel::on_nextButton_pressed()
{
    emit next();
}

void NextLevel::on_restartButton_pressed()
{
    emit restart();
}
