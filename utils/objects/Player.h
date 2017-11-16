#ifndef BITWOLF_ENGINE_PLAYER_H
#define BITWOLF_ENGINE_PLAYER_H


#include <QGraphicsRectItem>

class Player : public QGraphicsRectItem {
public:
    Player();
    void setX(int x);
    void setY(int y);
    void keyPressEvent(QKeyEvent *event) override;
};


#endif //BITWOLF_ENGINE_PLAYER_H
