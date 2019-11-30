#ifndef WARGAME_H
#define WARGAME_H

#include "gamemodel.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QStackedWidget>
#include <QGraphicsView>

namespace Ui {
class WarGame;
}

class WarGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit WarGame(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
    ~WarGame();
    void initCityStage();

private slots:
    void on_startButton_clicked();
    void win_stage();
    void quit_to_main();

private:
    Ui::WarGame *ui;
    GameModel* stage;
};

#endif // WARGAME_H
