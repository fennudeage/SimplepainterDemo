#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include<QPoint>
#include<QPainter>
#include<QPalette>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QResizeEvent>
class drawArea : public QWidget
{
    Q_OBJECT
public:
    explicit drawArea(QWidget *parent = 0);
          void mousePressEvent(QMouseEvent* );
          void mouseMoveEvent(QMouseEvent * );
          void paintEvent(QPaintEvent *);
          void resizeEvent(QResizeEvent *);
          
signals:

public slots:
  void setStyle(int);
  void setwidth(int);
  void setcolor(QColor);
  void clear();
private:
  QPixmap *pix;
  QPoint start,end;
  int width,hight,style;
  QColor color;
  
  
  
  
  
          
};

#endif // DRAWAREA_H
