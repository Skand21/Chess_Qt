#include "piece_king.h"
#include "game.h"
#include "piece_pawn.h"
extern Game *game;
King::King(QString place,QGraphicsItem *parent):ChessPiece(place,parent)
{
    setImage();
}

void King::setImage()
{
    if(side == "1")
        setPixmap(QPixmap(":Pices/king1.png"));
    else
        setPixmap(QPixmap(":Pices/king.png"));
}

void King::moves()
    {
        location.clear();
        int row = this->getCurrentBox()->rowLoc;
        int col = this->getCurrentBox()->colLoc;
        QString place = this->getSide();

        // Лево Верх
        if(col > 0 && row > 0 && !(game->collection[row-1][col-1]->getChessPieceColor() == place)) {
            location.append(game->collection[row-1][col-1]);
            boxSetting(location.last());
        }
        // Право Верх
        if(col < 7 && row > 0 && !(game->collection[row-1][col+1]->getChessPieceColor() == place)) {
            location.append(game->collection[row-1][col+1]);
            boxSetting(location.last());
        }
        // Верх
        if(row>0 && !(game->collection[row-1][col]->getChessPieceColor() == place)) {
            location.append(game->collection[row-1][col]);
            boxSetting(location.last());
        }
        // Низ
        if(row<7 && !(game->collection[row+1][col]->getChessPieceColor() == place)) {
            location.append(game->collection[row+1][col]);
            boxSetting(location.last());
        }
        // Лево
        if(col>0 && !(game->collection[row][col-1]->getChessPieceColor() == place)) {
            location.append(game->collection[row][col-1]);
            boxSetting(location.last());
        }
        // Право
        if(col<7 && !(game->collection[row][col+1]->getChessPieceColor() == place)) {
            location.append(game->collection[row][col+1]);
            boxSetting(location.last());
        }
        // Лево Низ
        if(col > 0 && row < 7  && !(game->collection[row+1][col-1]->getChessPieceColor() == place)) {
            location.append(game->collection[row+1][col-1]);
            boxSetting(location.last());
        }
        // ПРаво Низ
        if(col < 7 && row < 7 && !(game->collection[row+1][col+1]->getChessPieceColor() == place)) {
            location.append(game->collection[row+1][col+1]);
            boxSetting(location.last());
        }
}
