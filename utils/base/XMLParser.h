#ifndef BITWOLF_ENGINE_XMLPARSER_H
#define BITWOLF_ENGINE_XMLPARSER_H


#include <QString>
#include <QFile>
#include "Scene.h"

class XMLParser {
private:
    QFile *currentFile;

public:
    XMLParser();
    bool isValid(QFile * file);
    void loadXml(QString file, Scene * scene);
};


#endif //BITWOLF_ENGINE_XMLPARSER_H
