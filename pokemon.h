#ifndef POKEMON_H
#define POKEMON_H

#include <QString>
#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsItemAnimation>
#include <math.h>
#include <QDebug>
#include <QPainter>

enum UnitState { STOP, MOVE, ATTACK };
enum SideType { RedSide, BlueSide };
enum Direction { LEFT, RIGHT };
class Pokemon : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit Pokemon(QWidget *parent = nullptr);
    Pokemon(SideType newSide, QString newName, QPainter* newPainter,  QMovie* newModel,
            qreal newSpeed, int wid, int hgt, int maxHP, int newAbilityPoint, int newAttackAbility,
            qreal newAttackSpeed, int newAttackDistance);
    ~Pokemon();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    void moveTo(qreal x, qreal y);
    void moveTo(QPointF point);
    void stop();
    void setState(UnitState newState);

    int getHp();
    int getAttackAbility();
    UnitState getState();
    void cutHp(int cut);

protected:
    int pWidth, pHeight;
    QString name;
    QPainter* painter;
    QMovie* model;
    SideType side;

    int HP;
    qreal speed;
    int abilityPoint;
    int attackAbility;
    qreal attackSpeed;
    int attackDistance;

    Direction direct;
    UnitState state;
};
/*
class Pikachu : public Pokemon
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit Pikachu(QWidget *parent = nullptr);
    Pikachu(SideType newSide, QGraphicsView* view);
//    ~Pikachu();
};
*/
#endif // POKEMON_H
