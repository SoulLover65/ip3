#ifndef FISHINGNET_H_INCLUDED
#define FISHINGNET_H_INCLUDED

#include "FishingTool.h"

class FishingNet : public FishingTool
{
private:
    int netSize = 3;

public:
    void prepare() override;
    void fish() const override;
};


#endif // FISHINGNET_H_INCLUDED
