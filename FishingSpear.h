#ifndef FISHINGSPEAR_H_INCLUDED
#define FISHINGSPEAR_H_INCLUDED

#include "FishingTool.h"
#include <string>

class FishingSpear : public FishingTool
{
private:
    std::string depthLevel;
    double successChance;
    double doubleCatchChance;

public:
    void prepare() override;
    void prepare(int depthChoice);
    void fish() const override;
};

#endif // FISHINGSPEAR_H_INCLUDED
