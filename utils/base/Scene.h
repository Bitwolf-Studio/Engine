#ifndef BITWOLF_ENGINE_SCENE_H
#define BITWOLF_ENGINE_SCENE_H

#include <QGraphicsScene>
#include "../objects/Player.h"

class Scene : public QGraphicsScene {
private:
    int           width   = 1280;
    int           height  = 720;
    int           time    = 2000;
    QString       target  = QString("");
    QColor        bgcolor = QColor("white");
    Player        *player;
    QGraphicsItem bgimage;
public:
    Scene();

    int getWidth();

    int getHeight();

    void setWidth(int x);

    void setHeight(int y);

    void setTime(int time);

    void setTarget(QString target);

    void setBgColor(QColor color);

    void prepareScene();

    Player *getPlayer();

    void createPlayer();

    // TODO: Create an createSprite() function
};


#endif //BITWOLF_ENGINE_SCENE_H