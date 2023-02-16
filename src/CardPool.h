#ifndef __HEROKILL_CARDPOOL__
#define __HEROKILL_CARDPOOL__

#include <deque>
#include <vector>

namespace herokill
{
    class Card;
    class CardPool
    {
    public:
        typedef std::deque<Card> DequeCards;
        CardPool();
        ~CardPool();
        void  shuffle(void);
        void dumpCards(void);
        std::vector<Card> dealCards(int nums);
    private:
        DequeCards    cards_;

    };
}
#endif