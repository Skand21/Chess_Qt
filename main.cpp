#include <QApplication>
#include "game.h"

Game *game;
int main(int argc, char *argv[])
{
    QApplication aplic(argc, argv);
    game = new Game();
    game->show(); // Показываем окно
    game->displayMainMenu(); // Выводим Главное меню
    return aplic.exec();
}
