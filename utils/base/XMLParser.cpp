#include <QDir>
#include <QDebug>
#include <QXmlStreamReader>
#include <QGraphicsScene>
#include "XMLParser.h"

XMLParser::XMLParser() = default;

/**
 * This function reads and parses an XML file and stores the data in the injected scene object.
 * @param xmlFile: Name of the Xml file located in game/scene_config, without the .xml extension.
 * @param * scene: A pointer to the scene object the data should be stored in.
 */
void XMLParser::loadXml(QString xmlFile, Scene * scene) {
    auto *file = new QFile(QString(QDir::currentPath() + "/../game/scene_config/" + xmlFile + ".xml"));
    if (!file->open(QFile::ReadOnly | QFile::Text)) {
        // Error:
        qDebug() << "Error opening file";
    }

    this->isValid(file);

    QXmlStreamReader reader;
    reader.setDevice(file);
    reader.readNext();

    while(!reader.atEnd() && !reader.hasError()) {
        reader.readNext();
        if (reader.isStartElement()) {
            if (reader.name().toString() == "map") {
                scene->setWidth(reader.attributes().value(QString("width")).toInt());
                scene->setHeight(reader.attributes().value(QString("height")).toInt());
                reader.readNext();
            }
            else if (reader.name().toString() == "player") {
                scene->getPlayer()->setX(reader.attributes().value(QString("x")).toInt());
                scene->getPlayer()->setY(reader.attributes().value(QString("y")).toInt());
                reader.readNext();
            }
        }
    }
    if (reader.hasError()) {
        qDebug() << reader.errorString();
    }

    file->close();
};

/**
 * This function checks if the currentFile is XML.
 * @return Returns true if the XML file is valid.
 */
bool XMLParser::isValid(QFile * file) {
    if (file == nullptr) {
        return false;
    }
    else if (true) {
        // TODO: Check if valid XML
        return true;
    }
    else {
        return false;
    }
};