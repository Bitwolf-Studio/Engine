#include "utils/Game.h"
#include "utils/base/XMLParser.h"

int main(int argc, char *argv[])
{
    Game game(argc, argv);
    return game.start();
}
