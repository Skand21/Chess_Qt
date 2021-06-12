#include "piece_knight.h"
#include "game.h"
extern Game *game;

Knight::Knight(QString place,QGraphicsItem *parent):ChessPiece(place,parent)
{
    setImage();
}

void Knight::setImage()
{
    if(side == "1")
        setPixmap(QPixmap(":Pices/knight1.png"));
    else
        setPixmap(QPixmap(":Pices/knight.png"));
}

void Knight::moves()
{
    int i ,j;
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString place  = this->getSide();

    // Верх левый врех
    i = row - 2;
    j = col - 1;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != place) ) {
        location.append(game->collection[i][j]);
        boxSetting(location.last());
    }

    // Верх правый верх
    i = row - 2;
    j = col + 1;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != place) ) {
        location.append(game->collection[i][j]);
        boxSetting(location.last());
    }

    // Низ левый низ
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != place) ) {
        location.append(game->collection[i][j]);
        boxSetting(location.last());
    }

    // Низ право низ
    i = row + 2;
    j = col + 1;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != place) ) {
        location.append(game->collection[i][j]);
        boxSetting(location.last());
    }

    // Верх лево лево
    i = row - 1;
    j = col - 2;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != place) ) {
        location.append(game->collection[i][j]);
        boxSetting(location.last());
    }

    // Низ лево лево
    i = row + 1;
    j = col - 2;
    if(i <=7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != place) ) {
        location.append(game->collection[i][j]);
        boxSetting(location.last());
    }

    // Верх право право
    i = row - 1;
    j = col + 2;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != place) ) {
        location.append(game->collection[i][j]);
        boxSetting(location.last());
    }

    // Низ право право
    i = row + 1;
    j = col +  2;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != place) ) {
        location.append(game->collection[i][j]);
        boxSetting(location.last());
    }
}

