#ifndef __HEROKILL_CARD__
#define __HEROKILL_CARD__

#include <string>

namespace herokill
{
    enum CardType{kDiamond, kHeart, kClub, kSpade};
    class Card
    {
    public:
        Card()
        {

        }
    private:
        int id_;
        CardType type_;
        std::string    name_;
        std::string    desc_;
    };
}
#endif
