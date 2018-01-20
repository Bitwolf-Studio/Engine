#include "Scene.h"

Scene::Scene()
{
    this->player = new Player();
}

int Scene::getWidth() {
    return this->width;
}

void Scene::setWidth(int x) {
    this->width = x;
}

int Scene::getHeight() {
    return this->height;
}

void Scene::setHeight(int y) {
    this->height = y;
}

Player * Scene::getPlayer() {
    return this->player;
}

void Scene::prepareScene() {
    this->addItem(this->player);
    this->setSceneRect(0, 0, this->width, this->height);
}

void Scene::setTime(int time) {
    this->time = time;
}

void Scene::setTarget(QString target) {
    this->target = target;
}

void Scene::setBgColor(QColor color) {
    this->bgcolor = color;
}
