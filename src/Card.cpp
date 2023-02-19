#include "Card.h"

using namespace herokill;

Card::Card(int id, int code, CardColor color, const std::string& name, const std::string& desc = ""):
        id_(id), code_(code), color_(color), name_(name), desc_(desc)
{

}

Card::~Card()
{

}

int Card::id()const
{
    return id_;
}

std::string Card::name()const
{
    return name_;
}

int Card::code()const
{
    return code_;
}

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
