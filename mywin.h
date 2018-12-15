#ifndef MYWIN_H
#define MYWIN_H

#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QLCDNumber>
#include <QPushButton>
#include <QProgressBar>
#define HAUTEUR 200
#define LARGEUR 300

class MyWin : public QWidget
{
    Q_OBJECT

private:
    QLCDNumber *m_lcd;
    QProgressBar *m_progress;
    QSlider *m_slider_w;
    QSlider *m_slider_h;
    QPushButton *m_button;

public:
    explicit MyWin(QWidget *parent = nullptr);
    ~MyWin();

signals:
    void agrandissementMax(int taille);

public slots:
    void changerLargeur(int largeur);
    void changerHauteur(int hauteur);
    void resetProgress(void);
};

#endif // MYWIN_H
