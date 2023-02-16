#ifndef __HEROKILL_PLAYER__
#define __HEROKILL_PLAYER__

#include "Card.h"

#include <memory>
#include <string>
#include <vector>

namespace herokill
{
    class Card;
    class Room;
    class Player : public std::enable_shared_from_this<Player>
    {
    public:
        Player(int id):id_(id), hp_(4){}
        ~Player(){}
        void drawCard(std::vector<Card>);
        void playCard();
        void discard();
        void dumpHandCard(void);
        bool findAndDelCardByName(const std::string& name);
        void setRoomPtr(Room *room);
        void setHpInc(int nums);
        void setHpDec(int nums);
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
        Room *room_;
        std::vector<Card> handCards_;
    };
}
#endif