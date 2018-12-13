#include "mywin.h"

MyWin::MyWin(QWidget *parent) : QWidget(parent)
{
    QSize sizeWin(300,150);
    setFixedSize(sizeWin);

    m_lcd=new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(115,20);

    m_progress=new QProgressBar(this);
    m_progress->setGeometry(75,55,150,20);

    m_slider=new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(75,85,150,20);

    m_button=new QPushButton("reset",this);
    m_button->setGeometry(125, 105, 50, 30);

    QObject::connect(m_slider,SIGNAL(valueChanged(int)),m_lcd,SLOT(display(int)));
    QObject::connect(m_slider,SIGNAL(valueChanged(int)),m_progress,SLOT(setValue(int)));

    QObject::connect(m_button,SIGNAL(clicked()),m_progress,SLOT(reset()));
}


MyWin::~MyWin()
{
    /*optionnel car Qt supprime les elements contenus
     * delete m_lcd;
     * delete m_slider;
     * delete m_progress;
     * */
}
