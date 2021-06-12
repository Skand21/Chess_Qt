#ifndef PIECE_BISHOP_H
#define PIECE_BISHOP_H

#include "fd_chessPiece.h"
class Bishop:public ChessPiece
{
public:
    Bishop(QString place,QGraphicsItem *parent = 0);
    void setImage();
    void moves();
};

#endif
