#ifndef BITWOLF_ENGINE_GAME_H
#define BITWOLF_ENGINE_GAME_H


#include <QApplication>
#include <QGraphicsView>

class Game final : public QApplication, public QGraphicsView {
public:
    Game(int &argc, char **argv) : QApplication(argc, argv) {};
};


#endif //BITWOLF_ENGINE_GAME_H
