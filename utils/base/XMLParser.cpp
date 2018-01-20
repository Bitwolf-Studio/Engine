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

    auto reader = new QXmlStreamReader();
    reader->setDevice(file);
    reader->readNext();

    while(!reader->atEnd() && !reader->hasError()) {
        reader->readNext();
        if (reader->isStartElement()) {
            if (reader->name().toString() == "map") {
                this->readMapAttributes(reader, scene);
                qDebug() << "Map attribute read. Read next.";
                reader->readNext();
            }
            else if (reader->name().toString() == "player") {
                this->readPlayerAttributes(reader, scene);
                qDebug() << "Player attribute read. Read next.";
                reader->readNext();
            }
        }
    }
    if (reader->hasError()) {
        qDebug() << reader->errorString();
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
}
/**
 * This function reads the <map> subtree of the currentFile
 * @param reader The QXmlStreamReader object
 * @param scene The current Scene object
 */
void XMLParser::readMapAttributes(QXmlStreamReader * reader, Scene * scene) {
    // Set width and height of the Scene
    scene->setWidth(this->readIntAttr(reader, "width"));
    scene->setHeight(this->readIntAttr(reader, "height"));
    // Check if time attribute is available, if yes set time on scene
    if (this->readStrAttr(reader, "time") != "") {
        scene->setTime(this->readIntAttr(reader, "time"));
    }
    // Check if target attribute is available, if yes set target on scene
    if (this->readStrAttr(reader, "target") != "") {
        scene->setTarget(this->readStrAttr(reader, "target"));
    }
    // Check if bgcolor is available, if yes set bgcolor on scene
    if (this->readStrAttr(reader, "bgcolor") != "") {
        QString colorString = this->readStrAttr(reader, "bgcolor");
        QStringList colorList = colorString.split(",");
        int r = colorList[0].toInt();
        int g = colorList[1].toInt();
        int b = colorList[2].toInt();
        int a = colorList[3].toInt();
        scene->setBgColor(QColor(r,g,b,a));
    }
}

/**
 * This function read the <player> attributes of the currentFile
 * @param reader The QXmlStreamReader object
 * @param scene The current Scene object
 */
void XMLParser::readPlayerAttributes(QXmlStreamReader *reader, Scene *scene) {
    scene->getPlayer()->setX(reader->attributes().value(QString("x")).toInt());
    scene->getPlayer()->setY(reader->attributes().value(QString("y")).toInt());
}

/**
 * This reads an attribute of the current XML-Token (Element).
 * @param reader Pointer to QXmlStringReader object
 * @param attribute QString or String of the name of the attribute
 * @return The attribute converted to a string
 */
QString XMLParser::readStrAttr(QXmlStreamReader * reader, QString attribute) {
    return reader->attributes().value(attribute).toString();
}

/**
 * This reads an attribute of the current XML-Token (Element)
 * @param reader Pointer to QXmlStreamReader object
 * @param attribute QString or String of the name of the attribute
 * @return The attribute converted to an integer
 */
int XMLParser::readIntAttr(QXmlStreamReader *reader, QString attribute) {
    return reader->attributes().value(attribute).toInt();
};