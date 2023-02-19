#ifndef __HEROKILL_CARDPOOL__
#define __HEROKILL_CARDPOOL__

#include <deque>
#include <memory>
#include <vector>

namespace herokill
{
    class Card;
    class CardPool
    {
    public:
        typedef std::deque<std::unique_ptr<Card>> DequeCards;
        CardPool();
        ~CardPool();
        void  shuffle(void);
        void dumpCards(void);
        std::vector<std::unique_ptr<Card>> dealCards(int nums);
    private:
        DequeCards    cards_;

    };
}
#endif