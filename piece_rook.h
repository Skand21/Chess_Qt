#ifndef PIECE_ROOK_H
#define PIECE_ROOK_H

#include "fd_chessPiece.h"
class Rook:public ChessPiece
{
public:
    Rook(QString place, QGraphicsItem *parent = 0);
    void setImage();
    void moves();
};

#endif
