#include "FishingRod.h"
#include <iostream>
#include <vector>
#include <random>

// Concrete Strategy: FishingRod
void FishingRod::prepare()
{
    int choice;
    std::cout << "Pasirinkite masala:\n";
    std::cout << "1. Sliekas\n2. Duona\n3. Vabzdys\n4. Zuvele\n5. Mesa\n";
    std::cin >> choice;
    prepare(choice);  // Call the non-interactive version
}

void FishingRod::prepare(int baitChoice)
{
    std::vector<std::pair<std::string, std::string>> baitOptions = {
        {"Sliekas", "Eserys"},
        {"Duona", "Karsis"},
        {"Vabzdys", "Starkis"},
        {"Zuvele", "Lydeka"},
        {"Mesa", "Samas"}
    };

    if (baitChoice >= 1 && baitChoice <= static_cast<int>(baitOptions.size()))
    {
        chosenFish = baitOptions[baitChoice - 1].second;
    }
    else
    {
        chosenFish = baitOptions[std::rand() % baitOptions.size()].second;
    }
}


void FishingRod::fish() const
{
    std::cout << "Gaudoma naudojant meskere." << std::endl;
    std::cout << "Pagauta: " << chosenFish << "." << std::endl;
    std::cout<<std::endl;
}

