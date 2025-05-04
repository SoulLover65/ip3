#include "FishingSpear.h"
#include <iostream>
#include <vector>
#include <random>

void FishingSpear::prepare()
{
    std::cout << "Pasirinkite nardymo gyli:\n";
    std::cout << "1. Seklus (didele sekmes tikimybe, bet dazniausiai viena zuvis)\n";
    std::cout << "2. Vidutinis (vidutine sekme, galimybe pagauti 2 zuvis)\n";
    std::cout << "3. Gilus (zema sekmes tikimybe, bet daznai pagautos 2 zuvys)\n";

    int choice = 0;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        depthLevel = "Seklus";
        successChance = 0.8;
        doubleCatchChance = 0.3;
        break;
    case 2:
        depthLevel = "Vidutinis";
        successChance = 0.6;
        doubleCatchChance = 0.5;
        break;
    case 3:
        depthLevel = "Gilus";
        successChance = 0.4;
        doubleCatchChance = 0.8;
        break;
    default:
        std::cout << "Netinkamas pasirinkimas. Pasirinktas vidutinis gylis.\n";
        depthLevel = "Vidutinis";
        successChance = 0.6;
        doubleCatchChance = 0.5;
        break;
    }
}

void FishingSpear::fish() const
{
    static std::mt19937 rng(std::random_device{}());
    std::vector<std::string> targetFish = {
        "Ungurys", "Skumbre", "Menke", "Otas", "Juru eserys"
    };

    std::uniform_real_distribution<> chanceDist(0.0, 1.0);
    std::uniform_int_distribution<> fishDist(0, targetFish.size() - 1);

    std::cout << "Nardoma i gyli: " << depthLevel << ". Pradedamas harpunavimas..." << std::endl;

    if (chanceDist(rng) > successChance)
    {
        std::cout << "Nepavyko pagauti zuvies. Bandymas nesekmingas." << std::endl;
        return;
    }

    int count = (chanceDist(rng) < doubleCatchChance) ? 2 : 1;

    std::cout << "Pagauta zuvu: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << targetFish[fishDist(rng)];
        if (i != count - 1)
            std::cout << ", ";
    }
    std::cout << "." << std::endl;
}
