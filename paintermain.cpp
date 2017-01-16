#include "paintermain.h"
#include<QToolBar>
#include<QColorDialog>
#define tr QStringLiteral
painterMain::painterMain(QWidget *parent)
    : QMainWindow(parent)
{
    DrawArea=new drawArea;
    setCentralWidget(DrawArea);
    creatTsoolBar();
   setMinimumSize(600,400);
   showstyle();
   DrawArea->setwidth(LinewidthspinBox->value());
   DrawArea->setcolor(Qt::black);

    
    
    
    
}

painterMain::~painterMain()
{

}
void painterMain::creatTsoolBar(){
    QToolBar* toolBar=addToolBar("tool");
    styleLable=new QLabel(QStringLiteral("先行风格"));
   stylecomboBox=new QComboBox;
   stylecomboBox->addItem("solidline",static_cast<int>(Qt::SolidLine));
    stylecomboBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
   stylecomboBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    stylecomboBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
  stylecomboBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
    connect(stylecomboBox,SIGNAL(activated(int)),this,SLOT(showstyle()));
    LinewidthLable =new QLabel(tr("线宽"));
    LinewidthspinBox=new QSpinBox;
    connect(LinewidthspinBox,SIGNAL(valueChanged(int)),DrawArea,SLOT(setwidth(int)));
    colorBtn= new QToolButton;
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn,SIGNAL(clicked(bool)),SLOT(showcolor()));
    clearnBtn=new QToolButton(this);
    clearnBtn->setText(tr("清除"));
    connect(clearnBtn,SIGNAL(clicked(bool)),DrawArea,SLOT(clear()));
    toolBar->addWidget(styleLable);
    toolBar->addWidget(stylecomboBox);
    toolBar->addWidget(LinewidthLable);
    toolBar->addWidget(LinewidthspinBox);
    toolBar->addWidget(colorBtn);
}
void painterMain::showstyle(){

    DrawArea->setStyle(stylecomboBox->itemData(stylecomboBox->currentIndex(),Qt::UserRole).toInt());





}
void painterMain::showcolor(){

    QColor color= QColorDialog::getColor(Qt::black,this);

    if(color.isValid()){
         DrawArea->setcolor(color);
        QPixmap p(20,20);
        p.fill(color);
        colorBtn->setIcon(QIcon(p));
    }




    }





