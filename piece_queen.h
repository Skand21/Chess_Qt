#ifndef PIECE_QUEEN_H
#define PIECE_QUEEN_H

#include "fd_chessPiece.h"
class Queen:public ChessPiece
{
public:
    Queen(QString place,QGraphicsItem *parent = 0);
    void setImage();
    void moves();
};

#endif
