#include "Game.h"
#include "base/XMLParser.h"

int Game::start() {
    auto * scene = new Scene();
    XMLParser parser;
    parser.loadXml(QString("Tutorial"), scene);
    scene->prepareScene();
    this->setScene(scene);
    this->setFixedSize(1280, 720);
    this->show();
    return QApplication::exec();
}