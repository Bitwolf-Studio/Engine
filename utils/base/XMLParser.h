#ifndef BITWOLF_ENGINE_XMLPARSER_H
#define BITWOLF_ENGINE_XMLPARSER_H


#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include "Scene.h"

class XMLParser {
private:
    QFile *currentFile;

public:
    XMLParser();
    bool isValid(QFile * file);
    void loadXml(QString file, Scene * scene);
    void readMapAttributes(QXmlStreamReader * reader, Scene * scene);
    void readPlayerAttributes(QXmlStreamReader * reader, Scene *scene);
    QString readStrAttr(QXmlStreamReader * reader, QString attribute);
    int readIntAttr(QXmlStreamReader *reader, QString attribute);
};


#endif //BITWOLF_ENGINE_XMLPARSER_H
