#include "utils/Game.h"
#include "utils/base/XMLParser.h"

int main(int argc, char *argv[])
{
    Game game(argc, argv);
    XMLParser parser;
    parser.loadXml(QString("Tutorial"));
    game.setScene(parser.setScene());
    game.setFixedSize(500, 500);
    game.show();

    return game.exec(); // TODO: CLion: This is no error, need to check this.
}
