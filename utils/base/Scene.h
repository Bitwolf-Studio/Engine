#ifndef BITWOLF_ENGINE_SCENE_H
#define BITWOLF_ENGINE_SCENE_H


#include <QGraphicsScene>

class Scene : public QGraphicsScene {
public:
    Scene();
    virtual QString getName() = 0;
};


#endif //BITWOLF_ENGINE_SCENE_H
