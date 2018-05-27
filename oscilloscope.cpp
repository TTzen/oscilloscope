#include "oscilloscope.h"
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QVector>
#include <QLine>
#include <qmath.h>

oscilloscope::oscilloscope(QWidget *parent)
    : QWidget(parent)
{
    m_XPoints = 100;
    m_YPoints = 80;
}


void oscilloscope::paintEvent(QPaintEvent *event)
{
    event = event;
    createBackground();
}


void oscilloscope::createBackground()
{
    QPainter painter(this);

    painter.setPen(QPen(Qt::white));
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(0, 0, 500, 400);

    QVector<QPointF> PointS;
    for (int Ycount = 0; Ycount < m_YPoints / 10; ++Ycount){
        for (int Xcount = 0; Xcount < m_XPoints; ++Xcount){
            PointS.append(QPointF(Xcount * 5, Ycount * 50));
        }
    }

    for (int Xcount = 0; Xcount < m_XPoints / 10; ++Xcount){
        for (int Ycount = 0; Ycount < m_YPoints; ++Ycount){
            PointS.append(QPointF(Xcount * 50, Ycount * 5));
        }
    }

    painter.drawPoints(PointS.data(), PointS.size());

    painter.setPen(QPen(Qt::red));
    QVector<QPointF> ACPoint = ACWave();

    painter.drawPoints(ACPoint.data(), ACPoint.size());
}


/*
* 将逻辑坐标点转换成真实的物理坐标并在屏幕上显示出来
*/
QPointF oscilloscope::physicsCoords(qreal X, qreal Y)
{
    QPointF result;
    result.setX(500 - X * 50 / 0.1);
    result.setY(200 - Y * 50 / 100);
    return result;
}


QVector<QPointF> oscilloscope::ACWave()
{
    QVector<QPointF> reslut;
    for (int count = 0; count < 500; ++count){
        qreal time = count * 0.002;                //一个像素代表0.2ms
        qreal voltage = 200 * qSqrt(2) * qSin( 2 * M_PI * time);
        reslut.append(physicsCoords(time, voltage));    //生成物理坐标
    }
    return reslut;
}
