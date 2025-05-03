#ifndef FISHINGNET_H_INCLUDED
#define FISHINGNET_H_INCLUDED

#include "FishingTool.h"

// Concrete Strategy: FishingNet
class FishingNet : public FishingTool {
public:
    void fish() const override {
        std::cout << "Gaudoma naudojant tinklą." << std::endl;
    }
};

#endif // FISHINGNET_H_INCLUDED
