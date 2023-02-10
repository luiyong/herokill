#include "Room.h"

#include "Player.h"
#include <algorithm>

#include <iostream>

using namespace herokill;

void Room::addPlayer(const PlayerPtr& player)
{
    players_.push_back(player);
}

void Room::removePlayer(const PlayerPtr& player)
{
    std::vector<PlayerPtr>::iterator it = std::find(players_.begin(), players_.end(), player);
    if (it != players_.end())
    {
        players_.erase(it);
    }
}

void Room::dumpPlayer()
{
    for(auto it = players_.begin(); it != players_.end(); it++)
    {
        std::cout << "id: " << (*it)->id() << " hp: " << (*it)->hp() << std::endl;
    }
}

void Room::run()
{

}