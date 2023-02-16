#include "Card.h"

using namespace herokill;


std::string Card::colorToString(CardColor color)const
{
    std::string res;
    switch(color)
    {
        case kDiamond:
            res = "Diamond";
            break;
        case kHeart:
            res = "Heart";
            break;
        case kClub:
            res = "Club";
            break;
        case kSpade:
            res = "Spade";
            break;
    }
    return res;
}

std::string Card::codeToString(int code)const
{
    std::string res;
    switch(code)
    {
        case 1:
            res = "A";
            break;
        case 11:
            res = "J";
            break;
        case 12:
            res = "Q";
            break;
        case 13:
            res = "K";
            break;
        default:
            res = std::to_string(code);
            break;
    }
    return res;
}


std::string Card::stringCode()const
{
    return codeToString(code_);
}

std::string Card::color()const
{
    return colorToString(color_);
}
