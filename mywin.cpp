#include "mywin.h"

MyWin::MyWin(QWidget *parent) : QWidget(parent)
{
    QSize sizeWin(LARGEUR,HAUTEUR);
    setFixedSize(sizeWin);

    m_lcd=new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(65,20);

    m_progress=new QProgressBar(this);
    m_progress->setGeometry(20,55,150,20);

    m_slider_w=new QSlider(Qt::Horizontal, this);
    m_slider_w->setRange(0,100);
    m_slider_w->setGeometry(20,85,150,20);

    m_slider_h=new QSlider(Qt::Vertical,this);
    m_slider_h->setGeometry(5,5,20,150);
    m_slider_h->setRange(0,100);
    m_slider_h->setValue(100);

    m_button=new QPushButton("reset",this);
    m_button->setGeometry(70, 105, 50, 30);

    QObject::connect(m_slider_w,SIGNAL(valueChanged(int)),m_lcd,SLOT(display(int)));
    QObject::connect(m_slider_w,SIGNAL(valueChanged(int)),m_progress,SLOT(setValue(int)));

    QObject::connect(m_button,SIGNAL(clicked()),this,SLOT(resetProgress()));

    QObject::connect(m_slider_w,SIGNAL(valueChanged(int)),this,SLOT(changerLargeur(int)));
    QObject::connect(m_slider_h,SIGNAL(valueChanged(int)),this,SLOT(changerHauteur(int)));

    QObject::connect(this,SIGNAL(agrandissementMax(int)),m_slider_h,SLOT(setValue(int)));
}


MyWin::~MyWin()
{
    /*optionnel car Qt supprime les elements contenus
     * delete m_lcd;
     * delete m_slider_w;
     * delete m_progress;
     * */
}

void MyWin::changerLargeur(int largeur)
{
    setFixedSize(LARGEUR+largeur, height());
    if(width()==LARGEUR+100)
    {
        emit agrandissementMax(0);
    }
}

void MyWin::changerHauteur(int hauteur)
{
    setFixedSize(width(), HAUTEUR+(100-hauteur));
}

void MyWin::resetProgress(void)
{
    m_slider_w->setValue(0);
    m_slider_h->setValue(100);
    m_lcd->display(0);
    m_progress->reset();
}
