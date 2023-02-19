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
            std::unique_ptr<Card> card(new Card(i + 1, (i + 1) % 14, kDiamond, baseCards[i % 3], baseCards[i % 3]));

            cards_.push_back(std::move(card));
        }else if(cardType == 1)
        {
            std::unique_ptr<Card> card(new Card(i + 1, (i + 1) % 14, kHeart, baseCards[i % 3], baseCards[i % 3]));
            cards_.push_back(std::move(card));
        }
        else if(cardType == 2)
        {
            std::unique_ptr<Card> card(new Card(i + 1, (i + 1) % 14, kClub, baseCards[i % 3], baseCards[i % 3]));
            cards_.push_back(std::move(card));
        }
        else
        {
            std::unique_ptr<Card> card(new Card(i + 1, (i + 1) % 14, kSpade, baseCards[i % 3], baseCards[i % 3]));
            cards_.push_back(std::move(card));
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
        std::cout << "color: " << (*it)->color() << " code: " << (*it)->stringCode() << " name: " << (*it)->name() << std::endl;
    }
}

std::vector<std::unique_ptr<Card>> CardPool::dealCards(int nums)
{
	std::vector<std::unique_ptr<Card>> ret;
	int size = cards_.size();

    std::cout << "card pool size: " << size << std::endl;
	for (int i = 0; i < nums; i++)
	{
		ret.push_back(std::move(cards_.front()));
		cards_.pop_front();

	}
	return ret;
}

