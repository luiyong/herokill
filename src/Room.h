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
        
        Room(int id, RoomType type):id_(id), type_(type), gameOver_(false){}
        ~Room(){}
        void addPlayer(const PlayerPtr& player);
        void removePlayer(const PlayerPtr& player);
        void dumpPlayer();
        void run();
    private:
        int id_;
        RoomType type_;
        std::vector<PlayerPtr> players_;
        bool gameOver_;
    };
}
#endif