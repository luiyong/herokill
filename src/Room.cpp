#include "Room.h"

#include "GameRule.h"
#include "Player.h"
#include "Singleton.h"

#include <algorithm>

#include <iostream>

using namespace herokill;

void Room::addPlayer(PlayerPtr& player)
{
    players_.push_back(player);
    player->setRoomPtr(this);
}

void Room::removePlayer(PlayerPtr& player)
{
    std::vector<PlayerPtr>::iterator it = std::find(players_.begin(), players_.end(), player);
    if (it != players_.end())
    {
        player->setRoomPtr(nullptr);
        players_.erase(it);
    }
}

void Room::removeAllPlayer(void)
{
    int size = players_.size();
    while(size-- > 0)
        players_.pop_back();
}

PlayerPtr Room::findNextPlayer(const PlayerPtr& player)
{
    std::vector<PlayerPtr>::iterator it = std::find(players_.begin(), players_.end(), player);
    if (it != players_.end())
    {
        it++;
        if (it != players_.end())
        {
                        if ((*it)->hp() > 0)
                                return *it;
                        else
                                return nullptr;
        }
        else
        {
            for(auto iter = players_.begin(); iter != players_.end(); iter++)
            {
                if((*iter) == player)
                    return nullptr;
                if ((*iter)->hp() > 0)
                {
                    return *iter;
                }
            }
        }
    }
    else
    {
        return nullptr;
    }
    return nullptr;
}

void Room::dumpPlayer()
{
    for(auto it = players_.begin(); it != players_.end(); it++)
    {
        std::cout << "id: " << (*it)->id() << " hp: " << (*it)->hp() << std::endl;
    }
}

bool Room::gameIsOver()
{
    if(alive_ == 1)
        return true;
    else
        return false;
}

void Room::run()
{
    // 初始化卡池
    Singleton<GameRule>::Instance().beforeRun();
    
    // 分发4张初始牌
    for(auto it = players_.begin(); it != players_.end(); it++)
    {
        auto cards = Singleton<GameRule>::Instance().drawCard(4);
        (*it)->drawCard(cards);
        (*it)->dumpHandCard();
    }

    while(!gameIsOver())
    {
        alive_ = players_.size();
        for(auto it = players_.begin(); it != players_.end(); it++)
        {
            if((*it)->hp() <= 0)
            {
                alive_--;
                continue;
            }
            //摸牌    
            auto cards = Singleton<GameRule>::Instance().drawCard(2);
            (*it)->drawCard(cards);
            std::cout << "before play:" << std::endl;
            (*it)->dumpHandCard();
            //出牌
            (*it)->playCard();

            std::cout << "after play:" << std::endl;
            (*it)->dumpHandCard();
            //弃牌
            (*it)->discard();
        }
    }

    for(auto it = players_.begin(); it != players_.end(); it++)
    {
        if((*it)->hp() > 0)
        {
            std::cout << "winner is: " << (*it)->id() << std::endl;
        }
    }
}

int Room::length(void)
{
    return players_.size();
}