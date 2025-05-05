#include "FishingSpear.h"
#include "FishSelector.h"
#include <iostream>
#include <random>

void FishingSpear::prepare()
{
    int choice;
    std::cout << "Pasirinkite nardymo gyli:\n";
    std::cout << "1. Seklus\n2. Vidutinis\n3. Gilus\n";
    std::cin >> choice;

    switch (choice)
    {
    case 1: prepare(FishingDepth::Shallow); break;
    case 2: prepare(FishingDepth::Medium); break;
    case 3: prepare(FishingDepth::Deep); break;
    default:
        std::cout << "Netinkamas pasirinkimas. Naudojamas vidutinis gylis.\n";
        prepare(FishingDepth::Medium);
        break;
    }
}

void FishingSpear::prepare(FishingDepth depth)
{
    depthLevel = depth;

    switch (depth)
    {
    case FishingDepth::Shallow:
        successChance = 0.8;
        doubleCatchChance = 0.3;
        category = FishCategory::ShallowWater;
        break;
    case FishingDepth::Medium:
        successChance = 0.6;
        doubleCatchChance = 0.5;
        category = FishCategory::MediumWater;
        break;
    case FishingDepth::Deep:
        successChance = 0.4;
        doubleCatchChance = 0.8;
        category = FishCategory::DeepWater;
        break;
    }
}

void FishingSpear::fish() const
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<> chanceDist(0.0, 1.0);

    std::cout << "Nardoma i gyli: ";
    switch (depthLevel)
    {
    case FishingDepth::Shallow: std::cout << "Seklus"; break;
    case FishingDepth::Medium: std::cout << "Vidutinis"; break;
    case FishingDepth::Deep: std::cout << "Gilus"; break;
    }
    std::cout << ". Pradedamas harpunavimas..." << std::endl;

    if (chanceDist(rng) > successChance)
    {
        std::cout << "Nepavyko pagauti zuvies." << std::endl;
        return;
    }

    int count = (chanceDist(rng) < doubleCatchChance) ? 2 : 1;
    auto caught = FishSelector::getFish(category, count);

    std::cout << "Pagauta zuvu: ";
    for (size_t i = 0; i < caught.size(); ++i)
    {
        std::cout << caught[i];
        if (i != caught.size() - 1)
            std::cout << ", ";
    }
    std::cout << "." << std::endl;
}
