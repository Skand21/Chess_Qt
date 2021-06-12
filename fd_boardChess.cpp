#include "fd_boardChess.h"
#include "fd_chessBox.h"
#include "game.h"
#include "piece_queen.h"
#include "piece_rook.h"
#include "piece_pawn.h"
#include "piece_king.h"
#include "piece_knight.h"
#include "piece_bishop.h"
extern Game *game;

ChessBoard::ChessBoard()
{
    // Даём каждой фигуре флаг
    // 1 - Черные; 0 - Белые
    setUpBlack();
    setUpWhite();
}

void ChessBoard::setUpBlack()
{
    ChessPiece *piece;
    piece = new Rook("0");
    black.append(piece);
    piece = new Knight("0");
    black.append(piece);
    piece = new Bishop("0");
    black.append(piece);
    piece = new Queen("0");
    black.append(piece);
    piece = new King("0");
    black.append(piece);
    piece = new Bishop("0");
    black.append(piece);
    piece = new Knight("0");
    black.append(piece);
    piece = new Rook("0");
    black.append(piece);

    // Пешки
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("0");
        black.append(piece);
    }
}

void ChessBoard::setUpWhite()
{
    ChessPiece *piece;
    // Пешки
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("1");
        white.append(piece);
    }
    piece = new Rook("1");
    white.append(piece);
    piece = new Knight("1");
    white.append(piece);
    piece = new Bishop("1");
    white.append(piece);
    piece = new Queen("1");
    white.append(piece);
    piece = new King("1");
    white.append(piece);
    piece = new Bishop("1");
    white.append(piece);
    piece = new Knight("1");
    white.append(piece);
    piece = new Rook("1");
    white.append(piece);
}


// Рисуем доску(окрашиваем в разные цвета клетки поочереди)
void ChessBoard::drawBoxes()
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            ChessBox *box = new ChessBox();
            game->collection[i][j] = box;
            box->rowLoc = i;
            box->colLoc = j;
            box->setPos(j*100, i*100);
            if((i + j) %2 == 0)
                box->setOriginalColor(Qt::darkGray);
            else
                box->setOriginalColor(Qt::darkRed);
            game->addToScene(box);
        }
    }
}

// Добавляем фигуры (до 2й строчки - белые; после 5й - чёрные)
void ChessBoard::addChessPiece() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            ChessBox *box = game->collection[i][j];
            if(i < 2) {
                static int k;
                box->placePiece(black[k]);
                game->addToScene(black[k++]);
            }
            else if (i > 5) {
                static int h;
                box->placePiece(white[h]);
                game->addToScene(white[h++]);
            }
        }
    }
}
