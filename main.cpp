#include "utils/Game.h"
#include "game/scenes/Tutorial.h"

int main(int argc, char *argv[])
{
    Game game(argc, argv);
    game.setScene(new Tutorial());
    game.setFixedSize(500, 500);
    game.show();

    return game.exec(); // TODO: CLion: This is no error, need to check this.
}
