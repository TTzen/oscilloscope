#ifndef OSCILLOSCOPE_H
#define OSCILLOSCOPE_H

#include <QWidget>

class oscilloscope : public QWidget
{
    Q_OBJECT

public:
    explicit oscilloscope(QWidget *parent = nullptr);


signals:

public slots:

private:
    void createBackground();

    QPointF physicsCoords(qreal X, qreal Y);    //物理左边转换，把数字坐标转换成真实的物理坐标

    QVector<QPointF> ACWave();                  //模拟一个交流电波形
protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    int m_XPoints;
    int m_YPoints;
};

#endif // OSCILLOSCOPE_H
