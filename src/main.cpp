
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
        room.addPlayer(std::make_shared<Player>(i));
    }
    room.dumpPlayer();

    CardPool pools;
    std::cout << "card pool init:" << std::endl;
    pools.dumpCards();
    std::cout << "card pool shuffle:" << std::endl;
    pools.shuffle();
    pools.dumpCards();

    return 0;
}
