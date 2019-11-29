#include "pokemon.h"

Pokemon::Pokemon(SideType newSide, QString newName, QPainter* newPainter,  QMovie* newModel,
                 qreal newSpeed, int wid, int hgt,
                 int maxHP, int newAbilityPoint, int newAttackAbility)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);

    side = newSide;
    if (side == BlueSide)
        direct = RIGHT;
    else
        direct = LEFT;

    painter = newPainter;
    model = newModel;
    pWidth = wid;
    pHeight = hgt;

    name = newName;

    HP = maxHP;
    speed = newSpeed / 10.0;
    abilityPoint = newAbilityPoint;
    attackAbility = newAttackAbility;

    state = STOP;
    model->start();

    animation = new QGraphicsItemAnimation;
    animation->setItem(this);
    timeLine = nullptr;
}
Pokemon::~Pokemon()
{
    if (model)
        delete model;
    if (animation)
        delete animation;
    if (timeLine)
        delete timeLine;
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
    if (state != MOVE)
        return;
    qreal deltaX = x - this->x();
    qreal deltaY = y - this->y();
    qreal dis2 = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (dis2 < 40)
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
void Pokemon::setState(UnitState newState)
{
    state = newState;
}
