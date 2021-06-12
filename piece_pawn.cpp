#include "piece_pawn.h"
#include "game.h"
#include <typeinfo>
#include "piece_king.h"
extern Game * game;
Pawn::Pawn(QString place,QGraphicsItem *parent):ChessPiece(place,parent)
{
    setImage();
    firstMove = true; // У пешки 1 ход на 1 клетку больше
}

void Pawn::setImage()
{
    if(side == "1")
        setPixmap(QPixmap(":Pices/pawn1.png"));
    else
        setPixmap(QPixmap(":Pices/pawn.png"));
}

void Pawn::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;

    if(this->getSide() == "1"){
        if(col > 0 && row > 0 && game->collection[row-1][col-1]->getChessPieceColor() == "0") {
            location.append(game->collection[row-1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row > 0 && game->collection[row-1][col+1]->getChessPieceColor() == "0") {
            location.append(game->collection[row-1][col+1]);
            boxSetting(location.last());
        }
        if(row>0 && (!game->collection[row-1][col]->getHasChessPiece())) {
            location.append(game->collection[row-1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row-2][col]->getHasChessPiece()){
                location.append(game->collection[row-2][col]);
                boxSetting(location.last());
            }
        }
    }
    else{
        if(col > 0 && row < 7 && game->collection[row+1][col-1]->getChessPieceColor() == "1") {
            location.append(game->collection[row+1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row <  7 && game->collection[row+1][col+1]->getChessPieceColor() == "1") {
            location.append(game->collection[row+1][col+1]);
            boxSetting(location.last());
        }
        if(row<7 && (!game->collection[row+1][col]->getHasChessPiece())) {
            location.append(game->collection[row+1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row+2][col]->getHasChessPiece()){
                location.append(game->collection[row+2][col]);
                boxSetting(location.last());
            }
        }
    }
}


