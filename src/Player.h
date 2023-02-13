#ifndef __HEROKILL_PLAYER__
#define __HEROKILL_PLAYER__

#include "Card.h"

#include <string>
#include <vector>

namespace herokill
{
    class Card;
    class Player
    {
    public:
        Player(int id):id_(id), hp_(4){}
        ~Player(){}
        void drawCard(std::vector<Card>);
        bool findCardByName(const std::string& name);
        int id() const
        {
            return id_;
        }
        int hp() const
        {
            return hp_;
        }
    private:
        int id_;
        int hp_;
        std::vector<Card> handCards_;
    };
}
#endif