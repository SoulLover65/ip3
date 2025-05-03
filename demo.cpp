#include "FishingRod.h"
#include "FishingNet.h"
#include "FishingBoat.h"

int main() {
    FishingRod rod;
    FishingNet net;

    // Initialize with rod strategy
    FishingBoat boat(&rod);
    boat.goFishing();

    // Switch to net strategy
    boat.setStrategy(&net);
    boat.goFishing();

    return 0;
}
