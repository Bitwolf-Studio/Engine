#include <QFile>
#include <QXmlStreamReader>
#include <QDir>
#include "qdebug.h"
#include "Tutorial.h"
#include "../../utils/objects/Player.h"

QString Tutorial::getName()
{
    return QString("Tutorial");
}

Tutorial::Tutorial()
{
    auto *player = new Player();

    QString path = QDir::currentPath();
    QFile file(path + QString("/../game/scene_config/" + this->getName() + ".xml")); // TODO: We need find another place to store the files.
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        // Error:
    }
    QXmlStreamReader reader;
    reader.setDevice(&file);
    reader.readNext();
    while (!reader.atEnd()) { //&& !reader.hasError()
        reader.readNext();
        if (reader.isStartElement()) {
            if (reader.name().toString() == "player") {
                if (reader.attributes().first().name().toString() == "x") {
                    player->setPos(reader.attributes().first().value().toInt(), player->y());
                }
                if (reader.attributes().last().name().toString() == "y") {
                    player->setPos(player->x(), reader.attributes().last().value().toInt());
                }
            }
        }
    }
    file.close();

    this->addItem(player);
}
