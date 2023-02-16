
#include "CardPool.h"
#include "Player.h"
#include "Room.h"

#include <iostream>

using namespace herokill;

int main(void)
{
    std::cout << "hello herokill" << std::endl;
    
    Room room(1, k1v1);
    for(int i = 0; i < 2; i++)
    {
        PlayerPtr player(new Player(i));
        room.addPlayer(player);
    }
    room.dumpPlayer();
    room.run();
    std::cout << "game over!!!" << std::endl;
    return 0;
}
