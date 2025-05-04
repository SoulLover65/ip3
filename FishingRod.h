#ifndef FISHINGROD_H_INCLUDED
#define FISHINGROD_H_INCLUDED

#include "FishingTool.h"

class FishingRod : public FishingTool
{
private:
    std::string chosenFish;

public:
    void prepare() override;
    void fish() const override;
};

#endif // FISHINGROD_H_INCLUDED
