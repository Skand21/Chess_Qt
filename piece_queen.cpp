#include "piece_queen.h"
#include "game.h"

extern Game *game;
Queen::Queen(QString place,QGraphicsItem *parent):ChessPiece(place,parent)
{
    setImage();
}

void Queen::setImage()
{
    if(side == "1")
        setPixmap(QPixmap(":Pices/queen1.png"));
    else
        setPixmap(QPixmap(":Pices/queen.png"));
}


void Queen::moves()
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

    ///ДИАГОНАЛИ

    //Верх Лево
    for(int i = row - 1, j = col - 1; i >= 0 && j >=0; i--,j--) {
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }

    //Верх Право
    for(int i = row - 1, j = col + 1; i >= 0 && j <= 7; i--,j++) {
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }

    //Низ Право
    for(int i = row + 1,j = col + 1; i <= 7 && j <= 7; i++,j++) {
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }

    //Низ Лево
    for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }
}
