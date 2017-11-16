#ifndef BITWOLF_ENGINE_SCENE_H
#define BITWOLF_ENGINE_SCENE_H


#include <QGraphicsScene>
#include "../objects/Player.h"

class Scene : public QGraphicsScene {
private:
    int width = 1280;
    int height = 720;
    Player * player;
public:
    Scene();
    int getWidth();
    int getHeight();
    void setWidth(int x);
    void setHeight(int y);
    void setRect();
    void prepareScene();
    Player * getPlayer();
};


#endif //BITWOLF_ENGINE_SCENE_H