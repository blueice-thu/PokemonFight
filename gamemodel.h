#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "pokemon.h"
#include "pokemonability.h"
#include <vector>
#include <QString>
#include <QDebug>
#include <QMainWindow>
#include <QGraphicsView>
#include <QPixmap>
#include <QWheelEvent>
#include <QScrollBar>
#include <QPaintEvent>
#include <QTransform>
#include <QTimer>

namespace Ui {
class GameModel;
}
enum GameStatus { PREPARE, PLAYING, PAUSE, WIN, DEFEAT };
typedef struct Side
{
    SideType type;
    size_t live_pokemon;
    std::vector<Pokemon*> units;
}Side;
class GameModel : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameModel(QWidget *parent = nullptr);
    GameModel(QMainWindow* window, QPixmap& background, int maxPoint);
    ~GameModel();
    void initUi();
    void wheelEvent(QWheelEvent *event);

    Pokemon* getEnemy(Pokemon* me, Side &yourSide);
    void moveToEnemy();
    void attackEnemy(Pokemon* attacker, Pokemon* attacked);

    void pauseGame();
    void continueGame();
    void checkWinDefeat();
    void killPokemon();
    GameStatus checkStatus();

    void addPokemon();
    void addBulbasaur(Side &side, int x, int y);
    void addCharmander(Side &side, int x, int y);
    void addHeracross(Side &side, int x, int y);
    void addJigglypuff(Side &side, int x, int y);
    void addJirachi(Side &side, int x, int y);
    void addLugia(Side &side, int x, int y);
    void addLuxio(Side &side, int x, int y);
    void addMachop(Side &side, int x, int y);
    void addMeowth(Side &side, int x, int y);
    void addOnix(Side &side, int x, int y);
    void addPangoro(Side &side, int x, int y);
    void addPikachu(Side &side, int x, int y);
    void addPolitoed(Side &side, int x, int y);
    void addPsyduck(Side &side, int x, int y);
    void addRaikou(Side &side, int x, int y);
    void addSquirtle(Side &side, int x, int y);
    void addZweilous(Side &side, int x, int y);

    void keyPressEvent(QKeyEvent *event);

    Side Red, Blue;
signals:
    void win();
    void defeat();
    void pause();
public slots:
    void onCheckGameStatus();
    void startGame();
    void prepareGame();

private slots:
    void on_addButton_0_clicked();
    void on_addButton_1_clicked();
    void on_addButton_2_clicked();
    void on_addButton_3_clicked();
    void on_addButton_4_clicked();
    void on_addButton_5_clicked();
    void on_addButton_6_clicked();
    void on_addButton_7_clicked();
    void on_addButton_8_clicked();
    void on_addButton_9_clicked();
    void on_addButton_10_clicked();
    void on_addButton_11_clicked();
    void on_addButton_12_clicked();
    void on_addButton_13_clicked();
    void on_addButton_14_clicked();
    void on_addButton_15_clicked();
    void on_addButton_16_clicked();
    void on_minusButton_0_clicked();
    void on_minusButton_1_clicked();
    void on_minusButton_2_clicked();
    void on_minusButton_3_clicked();
    void on_minusButton_4_clicked();
    void on_minusButton_5_clicked();
    void on_minusButton_6_clicked();
    void on_minusButton_7_clicked();
    void on_minusButton_8_clicked();
    void on_minusButton_9_clicked();
    void on_minusButton_10_clicked();
    void on_minusButton_11_clicked();
    void on_minusButton_12_clicked();
    void on_minusButton_13_clicked();
    void on_minusButton_14_clicked();
    void on_minusButton_15_clicked();
    void on_minusButton_16_clicked();



private:
    GameStatus status;
    QGraphicsScene* scene;
    int totalAblityPoint;
    QTimer* gameTimer;
    Ui::GameModel *ui;
    int numPokemon[MAX_POKEMON] = {0};
};

#endif // GAMEMODEL_H
