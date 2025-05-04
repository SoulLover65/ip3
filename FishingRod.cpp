#include "FishingRod.h"
#include <iostream>
#include <vector>
#include <random>

// Concrete Strategy: FishingRod
void FishingRod::prepare()
{
    std::vector<std::pair<std::string, std::string>> baitOptions = {
        {"Sliekas", "Eserys"},
        {"Duona", "Karsis"},
        {"Vabzdys", "Starkis"},
        {"Zuvele", "Lydeka"},
        {"Mesa", "Samas"}
    };

    std::cout << "Pasirinkite masala:\n";
    for (size_t i = 0; i < baitOptions.size(); ++i)
    {
        std::cout << i + 1 << ". " << baitOptions[i].first << std::endl;
    }

    int choice = 0;
    std::cin >> choice;
    if (choice >= 1 && choice <= static_cast<int>(baitOptions.size()))
    {
        chosenFish = baitOptions[choice - 1].second;
    }
    else
    {
        std::cout << "Netinkamas pasirinkimas. Naudojamas atsitiktinis masalas.\n";
        chosenFish = baitOptions[std::rand() % baitOptions.size()].second;
    }
}

void FishingRod::fish() const
{
    std::cout << "Gaudoma naudojant meskere." << std::endl;
    std::cout << "Pagauta: " << chosenFish << "." << std::endl;
    std::cout<<std::endl;
}

