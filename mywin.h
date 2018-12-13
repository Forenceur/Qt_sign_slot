#ifndef MYWIN_H
#define MYWIN_H

#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QLCDNumber>
#include <QPushButton>
#include <QProgressBar>

class MyWin : public QWidget
{
private:
    Q_OBJECT
    QLCDNumber *m_lcd;
    QProgressBar *m_progress;
    QSlider *m_slider;
    QPushButton *m_button;

public:
    explicit MyWin(QWidget *parent = nullptr);
    ~MyWin();

signals:

public slots:
};

#endif // MYWIN_H
