#ifndef __HEROKILL_CARDPOOL__
#define __HEROKILL_CARDPOOL__

#include <deque>

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
    private:
        DequeCards    cards_;
    };
}
#endif