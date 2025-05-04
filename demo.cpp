#include "FishingRod.h"
#include "FishingNet.h"
#include "FishingBoat.h"

int main()
{
    FishingRod rod;
    FishingNet net;

    FishingBoat boat(&rod);

    boat.prepareFishing();
    boat.goFishing();

    boat.setStrategy(&net);
    boat.prepareFishing();
    boat.goFishing();

    return 0;
}

