#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class QPainter;
class QPushButton;
class QLabel;
class oscilloscope;


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    virtual void paintEvent(QPaintEvent *event);


private:
    QLabel*       m_TiTleLab;
    oscilloscope* m_oscilloscope;   //示波器面板
    QWidget*      m_Manage;         //管理面板
};

#endif // WIDGET_H
