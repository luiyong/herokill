#ifndef __HEROKILL_CARD__
#define __HEROKILL_CARD__

#include <string>

namespace herokill
{
    enum CardType{kDiamond, kHeart, kClub, kSpade};
    class Card
    {
    public:
        Card(int id, CardType type, const std::string& name, const std::string& desc):
        id_(id), type_(type), name_(name), desc_(desc)
        {

        }
        int id()const
        {
            return id_;
        }

        std::string name()const
        {
            return name_;
        }
    private:
        int id_;
        CardType type_;
        std::string    name_;
        std::string    desc_;
    };
}
#endif
