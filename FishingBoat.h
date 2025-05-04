#ifndef FISHINGBOAT_H_INCLUDED
#define FISHINGBOAT_H_INCLUDED

#include "FishingTool.h"

// Context
class FishingBoat
{
private:
    FishingTool* strategy;  // Not owning pointer

public:
    explicit FishingBoat(FishingTool* initialStrategy)
        : strategy(initialStrategy) {}

    void setStrategy(FishingTool* newStrategy)
    {
        strategy = newStrategy;
    }

    void prepareFishing() const
    {
        if (strategy)
        {
            strategy->prepare();
        }
        else
        {
            std::cout << "Nera pasirinkta zvejybos strategija!" << std::endl;
        }
    }

    void goFishing() const
    {
        std::cout << "Valtis pradeda zvejyba..." << std::endl;
        if (strategy)
        {
            strategy->fish();
        }
        else
        {
            std::cout << "Nera pasirinkta zvejybos strategija!" << std::endl;
        }
    }
};

#endif // FISHINGBOAT_H_INCLUDED
