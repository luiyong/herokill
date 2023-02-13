#include "Player.h"

using namespace herokill;

void Player::drawCard(std::vector<Card> cards)
{
    int size = cards.size();

    for (int i = 0; i < size; i++)
    {
        handCards_.push_back(cards[i]);
    }
}

bool Player::findCardByName(const std::string& name)
{
    for (auto it = handCards_.begin(); it != handCards_.end(); it++)
    {
        if (it->name() == name)
        {
            return true;
        }

    }
    return false;
}