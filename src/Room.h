#ifndef __HEROKILL_ROOM__
#define __HEROKILL_ROOM__

#include <memory>
#include <vector>

namespace herokill
{
    class Player;
    using PlayerPtr = std::shared_ptr<Player>;
    enum RoomType{k1v1, k3v3, kFive, kEight};
    class Room
    {
    public:
        
        Room(int id, RoomType type):id_(id), type_(type), alive_(0){}
        ~Room(){}
        void addPlayer(PlayerPtr& player);
        void removePlayer(PlayerPtr& player);
        PlayerPtr findNextPlayer(const PlayerPtr& player);
        void dumpPlayer();
        bool gameIsOver();
        void run();
    private:
        int id_;
        RoomType type_;
        std::vector<PlayerPtr> players_;
        int alive_;
    };
}
#endif