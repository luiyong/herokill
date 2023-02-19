#include "GameRule.h"

#include "Card.h"
#include "CardPool.h"
#include "Player.h"

using namespace herokill;


GameRule::GameRule():pools_(new CardPool())
{

}

GameRule::~GameRule()
{

}

void GameRule::beforeRun()
{
    pools_->shuffle();
}

int GameRule::doKill(const PlayerPtr& from, std::vector<PlayerPtr>& to)
{
    for(auto it = to.begin(); it != to.end(); it++)
    {
        bool res = (*it)->findAndDelCardByName("Miss");
        if(!res)
        {
            (*it)->setHpDec(1);
        }

    }
    return 0;
}

int GameRule::doPeach(const PlayerPtr& from, std::vector<PlayerPtr>& to)
{
    for(auto it = to.begin(); it != to.end(); it++)
    {
        if((*it)->hp() < 4)
            (*it)->setHpDec(1);
    }
    return 0;
}

int GameRule::action(const std::string &key, const PlayerPtr& from, std::vector<PlayerPtr>& to)
{
    if(key == "Attack")
    {
        return doKill(from, to);
    }
    else if(key == "Peach")
    {
        return doPeach(from, to);
    }
    else
    {
        return -1;
    }
}

std::vector<std::unique_ptr<Card>> GameRule::drawCard(int nums)
{
    return pools_->dealCards(nums);
}