//Author : CONGILIO Luigi    CONSTANS Victor

#include "volumewidget.h"

VolumeWidget::VolumeWidget(QWidget *parent) :
    QWidget(parent)
{
    setMouseTracking(false);

    volume = 50;
    imgVolume = new QPixmap(":/images/images/gradient_tirangle.png");
    imgBordVolume = new QPixmap(":/images/images/bord_triangle.png");
    imgHP = new QPixmap(":/images/images/HP.png");
    imgHP_muet = new QPixmap(":/images/images/HP_muet.png");
    this->setMinimumHeight(40);
    this->setMinimumWidth(170);
}


void VolumeWidget::setVolume(int v)
{
    if(v < 0)
    {
        volume = 0;
    }
    else if(v > MAX_VOLUME)
    {
        volume = MAX_VOLUME;
    }
    else
    {
        volume = v;
    }

    this->repaint();


}

void VolumeWidget::wheelEvent(QWheelEvent *e)
{
    QPoint angle = e->angleDelta()/8;

    int volumeTmp;

    if(volume+angle.y() <= 0)
    {
        volumeTmp = 0;
    }
    else if(volume+angle.y() >= MAX_VOLUME)
    {
        volumeTmp = MAX_VOLUME;
    }
    else
    {
        volumeTmp=volume+angle.y();
    }

    emit(clientChangeVolume(volumeTmp));
}

void VolumeWidget::mousePressEvent(QMouseEvent *e)
{

    int volumeTmp;

    int position = e->x();


    if(position < 40)
    {
        if(volume == 0)
        {
            volumeTmp = saveVolume;
        }
        else
        {
            saveVolume = volume;
            volumeTmp = 0;
        }
    }
    else
    {
        if(position - 40 > MAX_VOLUME)
        {
            volumeTmp = MAX_VOLUME;
        }
        else
        {
            volumeTmp = position - 40;
        }
    }

    emit(clientChangeVolume(volumeTmp));
}

void VolumeWidget::mouseMoveEvent(QMouseEvent *e)
{
    int volumeTmp;

    int position = e->x();

    if(position <= 40)
    {
        volumeTmp = 0;
    }
    else if(position - 40 > MAX_VOLUME)
    {
        volumeTmp = MAX_VOLUME;
    }
    else
    {
        volumeTmp = position - 40;
    }

    emit(clientChangeVolume(volumeTmp));
}

void VolumeWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);

    if(volume == 0)
    {
        painter.drawPixmap(10,10,20,25,*imgHP_muet);
    }
    else
    {
        painter.drawPixmap(10,10,20,25,*imgHP);
    }

    QPointF* pt = new QPointF(40+volume/2,20);
    QRectF* rect = new QRectF(0,0,volume,40);
    QPainter::PixmapFragment fragment = QPainter::PixmapFragment::create(*pt,*rect,1,1,0,1);
    painter.drawPixmapFragments(&fragment,10,*imgVolume);

    painter.drawPixmap(40,0,130,40,*imgBordVolume);
}
