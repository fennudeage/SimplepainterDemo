#ifndef PAINTERMAIN_H
#define PAINTERMAIN_H

#include <QMainWindow>
#include<QToolButton>
#include<QLabel>
#include<QComboBox>
#include<QSpinBox>
#include"drawarea.h"
class painterMain : public QMainWindow
{
    Q_OBJECT

public:
    painterMain(QWidget *parent = 0);
    ~painterMain();
   public  slots:
    void showstyle();
    void showcolor();
private:
   void  creatTsoolBar();
    drawArea * DrawArea;
   QLabel * styleLable;
   QComboBox *stylecomboBox;
   QLabel *LinewidthLable;
   QSpinBox *LinewidthspinBox;
   QToolButton *colorBtn,*clearnBtn;
   
    
};

#endif // PAINTERMAIN_H
