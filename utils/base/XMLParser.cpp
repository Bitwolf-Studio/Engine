//
// Created by Nicolas on 12.11.17.
//

#include <QDir>
#include <QDebug>
#include <QXmlStreamReader>
#include <QGraphicsScene>
#include "XMLParser.h"
#include "../objects/Player.h"

XMLParser::XMLParser() = default;

/**
 * This function loads an XML file and stores it in the local variable currentFile.
 * @param xmlFile
 */
void XMLParser::loadXml(QString xmlFile) {
    qDebug() << QString(QDir::currentPath() + "/../game/scene_config/" + xmlFile + ".xml");
    auto *file = new QFile(QString(QDir::currentPath() + "/../game/scene_config/" + xmlFile + ".xml"));
    if (!file->open(QFile::ReadOnly | QFile::Text)) {
        // Error:
    }
    currentFile = file;
};

/**
 * This function reads the XML file stored in private variable currentFile
 * and sets the scene.
 */
QGraphicsScene* XMLParser::setScene() {
    auto * scene = new QGraphicsScene;
    auto * player = new Player;

    QXmlStreamReader reader;
    reader.setDevice(currentFile);
    reader.readNext();

    while (!reader.atEnd() && !reader.hasError()) {
        reader.readNext();
        if (reader.isStartElement()) {
            if (reader.name().toString() == "map") {
                int width = reader.attributes().value(QString("width")).toInt();
                int height = reader.attributes().value(QString("height")).toInt();
                scene->setSceneRect(0, 0, width, height);
                reader.readNext();
            }
            else if (reader.name().toString() == "player") {
                scene->addItem(player);
                int x = reader.attributes().value(QString("x")).toInt();
                int y = reader.attributes().value(QString("y")).toInt();
                player->setPos(x, player->y());
                player->setPos(player->x(), y);
            }
        }
    }
    currentFile->close();
    return scene;
};

