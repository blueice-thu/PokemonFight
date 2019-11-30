#ifndef NEXTLEVEL_H
#define NEXTLEVEL_H

#include <QDialog>
#include <QDesktopWidget>
#include <QApplication>

namespace Ui {
class NextLevel;
}

class NextLevel : public QDialog
{
    Q_OBJECT

public:
    explicit NextLevel(QWidget *parent = nullptr);
    ~NextLevel();
signals:
    void quit();
    void next();
    void restart();
private slots:
    void on_quitButton_pressed();

    void on_nextButton_pressed();

    void on_restartButton_pressed();

private:
    Ui::NextLevel *ui;
};

#endif // NEXTLEVEL_H
