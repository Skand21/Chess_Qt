#ifndef PIECE_PAWN_H
#define PIECE_PAWN_H

#include "fd_chessPiece.h"
class Pawn:public ChessPiece
{
public:
    Pawn(QString place,QGraphicsItem *parent = 0);
    void setImage();
    void moves();
};

#endif // PIECE_PAWN_H
