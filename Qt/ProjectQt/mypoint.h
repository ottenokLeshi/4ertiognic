#ifndef MYPOINT_H
#define MYPOINT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

/* Чтобы работали СЛОТЫ и СИГНАЛЫ, наследуемся от QOBJECT,
 * */
class MyPoint : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
   explicit MyPoint(QObject *parent = 0,double x, double y);
    ~MyPoint();

signals:
    /* Сигнал, который будет послыаться в том случае,
     * если произошел клик мышью по объекту
     * */
    void signal1();

protected:
    /* Перегружаем метод нажатия мышью, для его перехвата
     * */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    /* Данные методы виртуальные, поэтому их необходимо реализовать
     * в случае наследования от QGraphicsItem
     * */
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double _x;
    double _y;
};

#endif // MYPOINT_H
