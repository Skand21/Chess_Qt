#ifndef FD_BOARDCHESS_H
#define FD_BOARDCHESS_H
#include <QGraphicsRectItem>
#include "fd_chessPiece.h"
class ChessBoard
{
public:
    ChessBoard();

    void drawBoxes();

    void setUpWhite();
    void setUpBlack();

    void addChessPiece();
private:
    QList <ChessPiece *> white;
    QList <ChessPiece *> black;
};

#endif
