#include "game.h"
#include "fd_buttons.h"
#include <QPixmap>
#include "piece_king.h"
#include <QDebug>

Game::Game(QWidget *parent ):QGraphicsView(parent)
{
    // Окрашивыем бг в серый
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBackgroundBrush(brush);

    // Сцена
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,800,800);
    setFixedSize(810,810);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    pieceToMove = NULL; // Ничего не захватили
    setTurn("1"); // Первыми ходят белые=)
}

void Game::eatPiece(ChessPiece *piece)
{
    scene()->removeItem(piece); // Съедаем фигуру
    alivePiece.removeAll(piece); // Удаляем фигуру из массива Живых фигур
    // Делаем проверку, не выйграли ли мы случаем
    if(piece->getSide() == "1") {
        King *g = dynamic_cast <King *>(piece);
        if(piece == g){
            displayGameEnd("Black");
        }
    }
    else{
        King *g = dynamic_cast <King *>(piece);
        if(piece == g){
            displayGameEnd("White");
        }
    }
}

// Добавляем объект
void Game::addToScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}

// Удаляем объект
void Game::removeFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);
}

// Возвращает true
QString Game::getTurn()
{
    return turn;
}
// Ход = значению
void Game::setTurn(QString value)
{
    turn = value;
}

void Game::changeTurn()
{
    if(getTurn() == "1")
        setTurn("0");
    else
        setTurn("1");
}

void Game::start()
{
    // Убираем ненужные элементы
    for(int i = 0, n = objs.size(); i < n; i++)
        removeFromScene(objs[i]);

    // Рисуем доску
    chess = new ChessBoard();
    chess->drawBoxes();

    // Выполняем расстановку шахмат
    chess->addChessPiece();
}

void Game::displayMainMenu()
{
    // Название игры
    QGraphicsTextItem *titleText = new QGraphicsTextItem("CHESS");
    QFont titleFont("Times" , 70);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::darkBlue);

    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    objs.append(titleText);

    // Кнопка Играть
    Button * playButton = new Button("PLAY");
    playButton->setPos(width()/2 - playButton->boundingRect().width()/2,
                       height()/2 - playButton->boundingRect().height()/2);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(start())); // по нажатии на кнопку вызывает start()
    addToScene(playButton); // Добавляем на сцену
    objs.append(playButton);// Добавляем объекты, чтобы их удалить
}

void Game::getWallpaper()
{
    //setPixmap(QPixmap(":Wallpaper.png"));

}

void Game::displayGameEnd(QString winner)
{
    // Выводим победителя
    QGraphicsTextItem *titleText = new QGraphicsTextItem(winner + " won!!!");
    QFont titleFont("Times" , 80);
    titleText->setFont(titleFont);
    if (winner == "White")
        titleText->setDefaultTextColor(Qt::red);
    else
        titleText->setDefaultTextColor(Qt::green);

    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    objs.append(titleText);

    // Кнопка Выхода
    Button * playButton = new Button("EXIT");
    playButton->setPos(width()/2 - playButton->boundingRect().width()/2,
                       height()/2 - playButton->boundingRect().height()/2);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(gameEnd())); // по нажатии на кнопку вызывает gameEnd()
    addToScene(playButton); // Добавляем на сцену
}

void Game::gameEnd()
{
    exit(EXIT_FAILURE);
}
