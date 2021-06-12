#include "fd_buttons.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include "game.h"


Button::Button(QString btntext, QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    // Кнопка
    setRect(0,0,300,100);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);

    // Текст
    text = new QGraphicsTextItem(btntext, this);
    QFont titleFont("Times" , 30);
    text->setFont(titleFont);
    text->setDefaultTextColor(Qt::yellow);
    text->setPos(rect().width()/2 - text->boundingRect().width()/2,
                 rect().height()/2 - text->boundingRect().height()/2);

    // Графический элемент(интерактивный)
    setAcceptHoverEvents(true);
}

// Кнопка работает
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event)   emit clicked();
}

// Если мы наводим на кнопку, то меняется её цвет, иначе наоборот
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
    }
}
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);
    }
}
