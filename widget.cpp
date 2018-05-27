#include <QWidget>
#include "widget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QLabel>
#include "oscilloscope.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* vBoxlayout = new QVBoxLayout(this);
    /* 标题栏 */
    m_TiTleLab = new QLabel("GreenThink Power",this);
    m_TiTleLab->setStyleSheet("color:rgb(0, 102, 0)");
    m_TiTleLab->setFont(QFont("Consolas", 20));

    vBoxlayout->addWidget(m_TiTleLab, 1);


    /* 示波器栏 */
    QHBoxLayout* hBoxlayout = new QHBoxLayout(this);
    m_oscilloscope = new oscilloscope(this);
//    m_oscilloscope->setStyleSheet("background-color:rgb(00,255,255)");
    hBoxlayout->addWidget(m_oscilloscope);
    vBoxlayout->addLayout(hBoxlayout, 8);

    /* 管理栏 */
    m_Manage = new QWidget(this);
    m_Manage->setStyleSheet("background-color:rgb(128,128,128)");
    vBoxlayout->addWidget(m_Manage, 1);
    setFixedSize(800, 550);

    setStyleSheet("background-color:rgb(135,206,250)");
}

Widget::~Widget()
{

}



void Widget::paintEvent(QPaintEvent *event)
{
    event = event;
}
