#ifndef NEXTLEVEL_H
#define NEXTLEVEL_H

#include <QDialog>
#include <QDesktopWidget>
#include <QApplication>
#include <QDebug>

namespace Ui {
class NextLevel;
}

class NextLevel : public QDialog
{
    Q_OBJECT

public:
    explicit NextLevel(QWidget *parent = nullptr);
    ~NextLevel();
    void setLablePic(QString picPath);
    void setNextVisble(bool vis);
    void setResumeVisble(bool vis);
signals:
    void quit();
    void next();
    void restart();
    void resume();
private slots:
    void on_quitButton_pressed();
    void on_nextButton_pressed();
    void on_restartButton_pressed();
    void on_resumeButton_pressed();

private:
    Ui::NextLevel *ui;
};

#endif // NEXTLEVEL_H
