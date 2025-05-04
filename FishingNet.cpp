#include "FishingNet.h"
#include <iostream>
#include <vector>
#include <random>

// Concrete Strategy: FishingNet
void FishingNet::prepare()
{
    std::cout << "Pasirinkite tinklo dydi (1 - mazas, 2 - vidutinis, 3 - didelis): ";
    int choice = 0;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        netSize = 3;
        break;
    case 2:
        netSize = 5;
        break;
    case 3:
        netSize = 7;
        break;
    default:
        std::cout << "Netinkamas pasirinkimas. Naudojamas vidutinis tinklas." << std::endl;
        netSize = 5;
        break;
    }
}

void FishingNet::fish() const
{
    static std::mt19937 rng(std::random_device{}());
    std::vector<std::string> shallowWaterFish = {
        "Kuojyte", "Plakis", "Raude", "Grundzulas", "Karosiukas"
    };
    std::uniform_int_distribution<> fishDist(0, shallowWaterFish.size() - 1);

    std::cout << "Gaudoma naudojant tinkla." << std::endl;
    std::cout << "Pagauta zuvu: ";
    for (int i = 0; i < netSize; ++i)
    {
        std::cout << shallowWaterFish[fishDist(rng)];
        if (i != netSize - 1)
            std::cout << ", ";
    }
    std::cout << "." << std::endl;
    std::cout<<std::endl;
}

