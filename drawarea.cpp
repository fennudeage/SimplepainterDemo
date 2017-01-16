#include "drawarea.h"
#include<QPalette>
#include<QPen>
#include<QtCore>
#include<QtGui>
drawArea::drawArea(QWidget *parent) : QWidget(parent)
{
   setAutoFillBackground(true);
   setPalette(QPalette(Qt::white));
   pix =new QPixmap(size());
   pix->fill(Qt::white);
   setMinimumSize(600,400);





}
void drawArea::setStyle(int s){
    style=s;




}
void drawArea::setwidth(int W){
    width=W;


}
void drawArea::setcolor(QColor c){
    color=c;
}
void drawArea::mousePressEvent(QMouseEvent *e ){

    start= e->pos();



}
void drawArea::mouseMoveEvent(QMouseEvent * e){
  QPainter *painter=new QPainter();
  QPen pen;
  pen.setStyle((Qt::PenStyle)style);
  pen.setWidth(width);
  pen.setColor(color);

  painter->begin(pix);
  painter->setPen(pen);
  painter->drawLine(start,e->pos());
  painter->end();
  start=e->pos();


}
void drawArea::paintEvent(QPaintEvent * e){
   QPainter painter(this);
   painter.drawPixmap(QPoint(0,0),*pix);


}
void drawArea::clear(){
    QPixmap *clearpix =new QPixmap(size());
    clearpix->fill(Qt::white);
    pix =clearpix;
    update();


}
void drawArea::resizeEvent(QResizeEvent * e){
}
