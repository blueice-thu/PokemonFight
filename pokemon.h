#ifndef POKEMON_H
#define POKEMON_H

#include <QString>
#include <QMovie>
#include <QLabel>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
//#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <math.h>

enum UnitState { STOP, MOVE, ATTACK, AFRAID, TORPID, DEAD };
enum SideType { RedSide, BlueSide };
enum Direction { LEFT, RIGHT };
class Pokemon : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Pokemon(QWidget *parent = nullptr);
    Pokemon(SideType newSide, QString newName, QPainter* newPainter,  QMovie* newModel,
                     qreal newSpeed, int maxHP, int wid, int hgt, int newAbilityPoint);
    ~Pokemon();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPainterPath shape() const;

    void moveTo(int x, int y);
    void moveTo(QPointF point);
    void stop();

private:
    int pWidth, pHeight;
    QString name;
    QPainter* painter;
    QMovie* model;
    qreal speed;
    int HP;
    Direction direct;
    UnitState state;
    SideType side;
    int abilityPoint;

    QGraphicsItemAnimation* animation;
    QTimeLine* timeLine;
};

#endif // POKEMON_H
