#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "pokemon.h"
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

enum GameStatus { PREPARE, PLAYING, PAUSE, WIN, DEFEAT };
typedef struct Side
{
    SideType type;
    int live_pokemon;
    std::vector<Pokemon*> units;
}Side;
class GameModel : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameModel(QWidget *parent = nullptr);
    GameModel(QMainWindow* window, QPixmap& background, int maxPoint);
    ~GameModel();
    void wheelEvent(QWheelEvent *event);

    Pokemon* getEnemy(Pokemon* me, Side &yourSide);
    void moveToEnemy();
    void attackEnemy(Pokemon* attacker, Pokemon* attacked);

    void prepareGame();
    void startGame();
    void checkWinDefeat();
    void killPokemon();
    GameStatus checkStatus();

    void addPikachu(Side &side, int x, int y);
    void addSquirtle(Side &side, int x, int y);
    void addCharmander(Side &side, int x, int y);

    Side Red, Blue;
signals:
    void win();
    void defeat();
public slots:
    void onCheckGameStatus();
private:
    GameStatus status;
    QGraphicsScene* scene;
    int totalAblityPoint;
    QTimer* gameTimer;
};

#endif // GAMEMODEL_H
