#ifndef FISHINGROD_H_INCLUDED
#define FISHINGROD_H_INCLUDED

#include "FishingTool.h"

// Concrete Strategy: FishingRod
class FishingRod : public FishingTool {
public:
    void fish() const override {
        std::cout << "Gaudoma naudojant meškerę." << std::endl;
    }
};

#endif // FISHINGROD_H_INCLUDED
