#include "Player.h"

#include "GameRule.h"

#include "Room.h"
#include "Singleton.h"

#include <iostream>

using namespace herokill;

void Player::setRoomPtr(Room *room)
{
    room_ = room;
}

void Player::setHpInc(int nums)
{
    hp_ += nums;
}

void Player::setHpDec(int nums)
{
    hp_ -= nums;
}


void Player::drawCard(std::vector<Card> cards)
{
    int size = cards.size();

    for (int i = 0; i < size; i++)
    {
        handCards_.push_back(cards[i]);
    }
}

void Player::playCard()
{
     int size = handCards_.size();

        for (auto it = handCards_.begin(); it != handCards_.end();)
        {
                if (it->name() == "Attack")
                {
                        auto player = room_->findNextPlayer(shared_from_this());
                        if (!player)
                                break;
                        std::cout << "next player id: " << player->id() << " hp: " << player->hp() << std::endl;
                        std::vector<PlayerPtr> to;
                        to.push_back(player);
                        Singleton<GameRule>::Instance().action(it->name(), shared_from_this(), to);
                        std::cout << "next player hp: " << player->hp() << std::endl;
                        it = handCards_.erase(it);
                }
                else if (it->name() == "Missed")
                {
                    it++;
                }
                else if (it->name() == "Peach")
                {
                        if (hp_ < 4)
                        {
                            std::vector<PlayerPtr> to;
                            to.push_back(shared_from_this());
                            
                            Singleton<GameRule>::Instance().action(it->name(), shared_from_this(), to);
                            it = handCards_.erase(it);
                        }
                        else
                        {
                            it++;
                        }

                }
                else
                {
                    it++;
                }

        }
}

void Player::discard()
{
    int size = handCards_.size();
    while (size > hp_)
    {
        handCards_.pop_back();
        size = handCards_.size();
    }
}

void Player::dumpHandCard(void)
{
    std::cout << "player id: " << id_ << " cards: " << std::endl;
    for(auto it = handCards_.begin(); it != handCards_.end(); it++)
    {
        std::cout << it->color() << " " << it->stringCode() << " " << it->name() << std::endl;
    }
    std::cout << std::endl;
}

bool Player::findAndDelCardByName(const std::string& name)
{
    for (auto it = handCards_.begin(); it != handCards_.end(); it++)
    {
        if (it->name() == name)
        {
            handCards_.erase(it);
            return true;
        }

    }
    return false;
}