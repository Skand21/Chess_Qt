#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <fd_boardChess.h>
#include "fd_chessPiece.h"

class Game:public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);

    // Для работы с фигурами со сцены
    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    // Для захвата
    ChessPiece *pieceToMove;

    void eatPiece(ChessPiece *piece);

    QString getTurn() ;
    void setTurn( QString value);
    void changeTurn();

    ChessBox *collection[8][8];
    QGraphicsTextItem *check;
    QList <ChessPiece *> alivePiece;

    // Для вывода на экран
    // Сделатьотдельным классом
    void displayMainMenu();
    void displayGameEnd(QString winner);

    void getWallpaper();

public slots:
    void start();
    void gameEnd();

private:
    QGraphicsScene *gameScene;
    QString turn;
    ChessBoard *chess;
    QList <QGraphicsItem *> objs;
};

#endif // GAME_H
