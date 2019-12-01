#include "pokemon.h"

Pokemon::Pokemon(SideType newSide, QString newName, QPainter* newPainter,  QMovie* newModel,
                 qreal newSpeed, int wid, int hgt,
                 int maxHP, int newAbilityPoint, int newAttackAbility,
                 qreal newAttackSpeed, int newAttackDistance)
{
    setFlags(QGraphicsItem::ItemSendsGeometryChanges);

    side = newSide;
    if (side == BlueSide)
    {
        direct = RIGHT;
    }
    else
    {
        direct = LEFT;
        setFlags(QGraphicsItem::ItemIsMovable);
    }

    painter = newPainter;
    model = newModel;
    pWidth = wid;
    pHeight = hgt;

    name = newName;

    HP = maxHP;
    speed = newSpeed / 10.0;
    abilityPoint = newAbilityPoint;
    attackAbility = newAttackAbility;
    attackSpeed = newAttackSpeed;
    attackDistance = newAttackDistance;

    state = STOP;
    model->start();

}
Pokemon::~Pokemon()
{
    if (model)
        delete model;
    if (painter)
        delete painter;
}
UnitState Pokemon::getState()
{
    return state;
}
void Pokemon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (direct == RIGHT)
        painter->drawImage(boundingRect(), model->currentImage().mirrored(true, false));
    else
        painter->drawImage(boundingRect(), model->currentImage());
    this->update();
}
QRectF Pokemon::boundingRect() const
{
    return QRectF(-pWidth / 2, -pHeight / 2, pWidth, pHeight);
}
QPainterPath Pokemon::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(-pWidth / 2, -pHeight / 2, pWidth, pHeight));
    return path;
}
void Pokemon::moveTo(qreal x, qreal y)
{
    qreal deltaX = x - this->x();
    qreal deltaY = y - this->y();
    qreal dis2 = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (dis2 < attackDistance)
    {
        state = ATTACK;
        return;
    }
    else
    {
        state = MOVE;
    }
    if (state != MOVE)
        return;
    if (deltaX > 0)
        direct = RIGHT;
    else
        direct = LEFT;
    qreal dx = this->x() + speed * deltaX / dis2 * 25;
    qreal dy = this->y() + speed * deltaY / dis2 * 25;
    this->setPos(QPointF(dx, dy));
}
void Pokemon::moveTo(QPointF point)
{
    moveTo(point.x(), point.y());
}
void Pokemon::stop()
{
    state = STOP;
}
//QVariant Pokemon::itemChange(GraphicsItemChange change, const QVariant &value)
//{
//    if (change == ItemPositionChange && scene()) {
//        // value is the new position.
//        QPointF newPos = value.toPointF();
//        QRectF rect = scene()->sceneRect();
//        if (!rect.contains(newPos)) {
//            // Keep the item inside the scene rect.
//            newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
//            newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
//            return newPos;
//        }
//    }
//    return QGraphicsItem::itemChange(change, value);
//}
void Pokemon::setState(UnitState newState)
{
    state = newState;
}
int Pokemon::getHp()
{
    return HP;
}
void Pokemon::cutHp(int cut)
{
    HP = HP - cut;
}
int Pokemon::getAttackAbility()
{
    return attackAbility;
}
