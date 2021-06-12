#include "piece_rook.h"
#include "game.h"

extern Game *game;
Rook::Rook(QString place,QGraphicsItem *parent):ChessPiece(place,parent)
{
    setImage();
}

void Rook::setImage()
{
    if(side == "1")
        setPixmap(QPixmap(":Pices/rook1.png"));
    else
        setPixmap(QPixmap(":Pices/rook.png"));
}

void Rook::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString place = this->getSide();

    // Верх
    for(int i = row - 1, j = col; i >= 0 ; i--) {
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }

    // Низ
    for(int i = row + 1, j = col; i <= 7 ; i++) {
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }

    // Лево
    for(int i = row, j = col - 1; j >= 0 ; j--) {
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }

    //Право
    for(int i = row, j = col + 1; j <= 7 ; j++){
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }
}
