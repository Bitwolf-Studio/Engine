#ifndef BITWOLF_ENGINE_PLAYER_H
#define BITWOLF_ENGINE_PLAYER_H


#include <QGraphicsRectItem>

class Player : public QGraphicsRectItem {
public:
    void keyPressEvent(QKeyEvent *event) override;

    Player();
};


#endif //BITWOLF_ENGINE_PLAYER_H
