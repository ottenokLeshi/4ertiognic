#include "mypoint.h"

MyPoint::MyPoint(QObject *parent,double x, double y)
    : QObject(parent), QGraphicsItem(), _x(x), _y(y)
{

}

MyPoint::~MyPoint()
{

}

QRectF MyPoint::boundingRect() const
{
    /* возвращаем координаты расположения точки
     * по ним будет определятсья нажатие точки
     * */
    return QRectF(_x,_y,10,10);
}

void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Устанавливаем кисть в QPainter и отрисовываем круг, то есть ТОЧКУ
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(_x, _y, 10, 10));
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

/* Переопределив метод перехвата события нажатия кнопки мыши,
 * добавляем посылку СИГНАЛА от объекта
 * */
void MyPoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signal1();
    // Вызываем родительскую функцию события нажатия кнопки мыши
    QGraphicsItem::mousePressEvent(event);
}
