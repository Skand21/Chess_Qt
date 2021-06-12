#ifndef FD_CHESSBOX_H
#define FD_CHESSBOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include "fd_chessPiece.h"
#include <QGraphicsSceneMouseEvent>

class ChessPiece;
class ChessBox:public QGraphicsRectItem
{
public:

    ChessBox(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor(QColor color);
    void placePiece(ChessPiece *piece);

    void resetOriginalColor();
    void setOriginalColor(QColor value);

    bool getHasChessPiece();
    void setHasChessPiece(bool value,ChessPiece *piece = 0);

    QString getChessPieceColor() ;
    void setChessPieceColor(QString value);

    int rowLoc;
    int colLoc;

    ChessPiece * currentPiece;

private:
    QBrush brush;
    QColor originalColor;
    bool hasChessPiece;
    QString chessPieceColor;
};
#endif
