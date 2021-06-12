#include "fd_chessBox.h"
#include "game.h"
#include "piece_king.h"
#include <QDebug>
extern Game *game;
ChessBox::ChessBox(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    // Создаём поле 100*100
    setRect(0,0,100,100);
    setHasChessPiece(false);
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        // Отмена выбора фигуры
        if(currentPiece == game->pieceToMove && currentPiece){
            currentPiece->mousePressEvent(event);
            return;
        }

        // Если выбрано
        if(game->pieceToMove){

            //removing the eaten piece
            QList <ChessBox *> movLoc = game->pieceToMove->moveLocation();
            // Убеждаемся, что варианты хода назодятся в допустимом пределе
            int check = 0;
            for(int i = 0, n = movLoc.size(); i < n;i++) {
                if(movLoc[i] == this)
                    check = 1;
            }
            // Если нажали на место, в которое нельзя ходить
            if(check == 0)
                return;

            // Сбрасываем окраску на нормальный
            game->pieceToMove->decolor();

            // У пешки первый ход на 2
            game->pieceToMove->firstMove = false;

            // Съедаем фигуруы
            if(this->getHasChessPiece()){
                this->currentPiece->setCurrentBox(NULL);
                game->eatPiece(this->currentPiece);
            }
            // Обновляем положения фигуры
            game->pieceToMove->getCurrentBox()->setHasChessPiece(false);
            game->pieceToMove->getCurrentBox()->currentPiece = NULL;
            game->pieceToMove->getCurrentBox()->resetOriginalColor();
            placePiece(game->pieceToMove);

            game->pieceToMove = NULL;// Фигура может ходить >1 раза
            // Переход хода
            game->changeTurn();
        }
        // Выбираем фигуру
        else if(this->getHasChessPiece())
        {
            this->currentPiece->mousePressEvent(event);
        }
}
///Вспомогательные функции

// Выбираем вет
void ChessBox::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

// ДЛя относительного позиционирования
void ChessBox::placePiece(ChessPiece *piece)
{

    piece->setPos(x() + 50 - piece->pixmap().width()/2, y() + 50 - piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasChessPiece(true,piece);
    currentPiece = piece;
}

// Возвращаем оригинальный цвет
void ChessBox::resetOriginalColor()
{
    setColor(originalColor);
}

void ChessBox::setOriginalColor(QColor value)
{
    originalColor = value; // сохраняем предыдущий цвет
    setColor(originalColor);
}

bool ChessBox::getHasChessPiece()
{
    return hasChessPiece;
}

void ChessBox::setHasChessPiece(bool value, ChessPiece *piece)
{
    hasChessPiece = value;
    if(value)
        setChessPieceColor(piece->getSide());
    else
        setChessPieceColor("NONE");
}


QString ChessBox::getChessPieceColor()
{
    return chessPieceColor;
}

void ChessBox::setChessPieceColor(QString value)
{
    chessPieceColor = value;
}
