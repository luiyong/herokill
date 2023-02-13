#ifndef __HEROKILL_GAMERULE__
#define __HEROKILL_GAMERULE__

#include <memory>
#include <vector>


namespace herokill
{
    class Card;
    class CardPool;
    class Player;
    using PlayerPtr = std::shared_ptr<Player>;
    class GameRule
    {
    public:
        
        GameRule();
        ~GameRule();
        void beforeRun();
        int action(const Card* card, const PlayerPtr& from, std::vector<PlayerPtr>& to);
    private:
        int doKill(const PlayerPtr& from, std::vector<PlayerPtr>& to);
        int doPeach(const PlayerPtr& from, std::vector<PlayerPtr>& to);
        std::unique_ptr<CardPool> pools_;
    };
}
#endif