#include "FishingRod.h"
#include "FishingNet.h"
#include "FishingSpear.h"
#include "FishingBoat.h"

int main()
{
    FishingRod rod;
    FishingNet net;
    FishingSpear spear;

    FishingBoat boat(&rod);

    boat.prepareFishing();
    boat.goFishing();

    boat.setStrategy(&net);
    boat.prepareFishing();
    boat.goFishing();

    boat.setStrategy(&spear);
    boat.prepareFishing();
    boat.goFishing();

    return 0;
}

