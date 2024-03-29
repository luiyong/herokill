#ifndef __HEROKILL_CARD__
#define __HEROKILL_CARD__

#include <string>

namespace herokill
{
    enum CardColor{kDiamond, kHeart, kClub, kSpade};
    class Card
    {
    public:
        Card(int id, int code, CardColor color, const std::string& name, const std::string& desc);
        ~Card();
        int id()const;
        std::string name()const;
        int code()const;
        std::string stringCode()const;
        std::string color()const;
        
    private:

        std::string colorToString(CardColor color)const;
        std::string codeToString(int code)const;
        int id_;
        CardColor color_;
        int code_;
        std::string    name_;
        std::string    desc_;
    };
}
#endif
