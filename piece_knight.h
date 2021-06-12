#ifndef PIECE_KNIGHT_H
#define PIECE_KNIGHT_H

#include "fd_chessPiece.h"
class Knight:public ChessPiece
{
public:
    Knight(QString place,QGraphicsItem *parent = 0);
    void setImage();
    void moves();
};

#endif
