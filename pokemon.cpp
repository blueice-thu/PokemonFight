#include "pokemon.h"

Pokemon::Pokemon(SideType newSide, QString newName, QPainter* newPainter,  QMovie* newModel,
                 qreal newSpeed, int maxHP, int wid, int hgt, int newAbilityPoint)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);

    side = newSide;
    if (side == BlueSide)
        direct = RIGHT;
    else
        direct = LEFT;
    pWidth = wid;
    pHeight = hgt;
    name = newName;
    painter = newPainter;
    model = newModel;
    speed = newSpeed / 10.0;
    HP = maxHP;
    abilityPoint = newAbilityPoint;
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
void Pokemon::moveTo(int x, int y)
{
    stop();
    state = MOVE;
    qreal distance = sqrt(pow(x - this->x(), 2) + pow(x - this->y(), 2));
    if (x - this->x() > 0)
        direct = RIGHT;
    else
        direct = LEFT;
    int timeLength = static_cast<int>(distance / speed);
    if (timeLine)
        delete timeLine;
    timeLine = new QTimeLine(timeLength);
    timeLine->setCurveShape(QTimeLine::EaseInOutCurve);
    animation->setTimeLine(timeLine);
    animation->setTranslationAt(1, x - this->x(), y - this->y());
    timeLine->start();
}
void Pokemon::moveTo(QPointF point)
{
    moveTo(point.x(), point.y());
}
void Pokemon::stop()
{
    setPos(this->pos());
//    if (timeLine)
//        timeLine->stop();
//    if (animation)
//    {
//        animation->clear();
//    }
}
