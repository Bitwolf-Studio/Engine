#include "Scene.h"

Scene::Scene() {

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

Player *Scene::getPlayer() {
    return this->player;
}

void Scene::prepareScene() {
    this->setSceneRect(0, 0, this->width, this->height);
    this->setBackgroundBrush(QBrush(this->bgcolor));
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

void Scene::createPlayer() {
    this->player = new Player();
    this->addItem(this->player);
}
