//
// Created by Nicolas on 12.11.17.
//

#ifndef BITWOLF_ENGINE_XMLPARSER_H
#define BITWOLF_ENGINE_XMLPARSER_H


#include <QString>
#include <QFile>

class XMLParser {
private:
    QFile * currentFile;

public:
    XMLParser();
    void loadXml(QString);
    QGraphicsScene* setScene();
};


#endif //BITWOLF_ENGINE_XMLPARSER_H
