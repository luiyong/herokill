#ifndef __HEROKILL_PLAYER__
#define __HEROKILL_PLAYER__

namespace herokill
{
    class Player
    {
    public:
        Player(int id):id_(id), hp_(4){}
        ~Player(){}
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
    };
}
#endif