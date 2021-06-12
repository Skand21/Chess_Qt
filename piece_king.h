#ifndef PIECE_KING_H
#define PIECE_KING_H

#include "fd_chessPiece.h"
class King:public ChessPiece
{
public:
    King(QString place,QGraphicsItem *parent = 0);
    void setImage();
    void moves();
};

#endif
