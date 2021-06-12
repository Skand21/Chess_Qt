#include "piece_bishop.h"
#include "game.h"
extern Game *game;

Bishop::Bishop(QString place,QGraphicsItem *parent):ChessPiece(place,parent)
{
    setImage();
}

void Bishop::setImage()
{
    if(side == "1")
        setPixmap(QPixmap(":Pices/bishop1.png"));
    else
        setPixmap(QPixmap(":Pices/bishop.png"));
}

void Bishop::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString place = this->getSide();

    /// Для каждого свободной клетки по диагонали

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
    for(int i = row + 1, j = col + 1; i <= 7 && j <= 7; i++,j++) {
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }

    //Низ Лево
    for(int i = row + 1, j = col - 1; i <= 7 && j >= 0; i++,j--) {
        if(game->collection[i][j]->getChessPieceColor() == place)
            break;
        else{
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }
}
