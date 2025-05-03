#ifndef FISHINGBOAT_H_INCLUDED
#define FISHINGBOAT_H_INCLUDED

#include "FishingTool.h"

// Context
class FishingBoat {
private:
    FishingTool* strategy;  // Not owning pointer

public:
    explicit FishingBoat(FishingTool* initialStrategy)
        : strategy(initialStrategy) {}

    void setStrategy(FishingTool* newStrategy) {
        strategy = newStrategy;
    }

    void goFishing() const {
        std::cout << "Valtis pradeda žvejybą..." << std::endl;
        if (strategy) {
            strategy->fish();
        } else {
            std::cout << "Nėra pasirinkta žvejybos strategija!" << std::endl;
        }
    }
};

#endif // FISHINGBOAT_H_INCLUDED
