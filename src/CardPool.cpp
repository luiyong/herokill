#include "CardPool.h"

#include "Card.h"

#include <vector>
#include <string>
#include <random>
#include <iostream>

using namespace herokill;

CardPool::CardPool()
{
    std::vector<std::string> baseCards = {"Attack", "Miss", "Peach"};
    for(int i = 0; i < 108; i++)
    {
        int cardType = i % 4;
        if(cardType == 0)
        {
            cards_.push_back(Card(i + 1, kDiamond, baseCards[i % 3], baseCards[i % 3]));
        }else if(cardType == 1)
        {
            cards_.push_back(Card(i + 1, kHeart, baseCards[i % 3], baseCards[i % 3]));
        }
        else if(cardType == 2)
        {
            cards_.push_back(Card(i + 1, kClub, baseCards[i % 3], baseCards[i % 3]));
        }
        else
        {
            cards_.push_back(Card(i + 1, kSpade, baseCards[i % 3], baseCards[i % 3]));
        }
    }
}

CardPool::~CardPool()
{

}
void CardPool::shuffle(void)
{
        std::random_device rd;
        std::default_random_engine e{rd()};
        int size = cards_.size();
        for (int i = 0; i < size - 1; i++)
        {
                std::uniform_int_distribution<unsigned> u(i, size - 1);
                std::swap(cards_[i], cards_[u(e)]);
        }
}


void CardPool::dumpCards(void)
{
        for(auto it = cards_.begin(); it != cards_.end(); it++)
        {
                std::cout << "id: " << it->id() << " name: " << it->name() << std::endl;
        }
}


std::vector<Card> CardPool::dealCards(int nums)
{
	std::vector<Card> ret;
	int size = cards_.size();

	for (int i = 0; i < nums; i++)
	{
		ret.push_back(cards_[i]);
		cards_.pop_front();

	}
	return ret;
}

