//Instructions on how to make FishingRod in HowToMakeFishingRod.txt

#include "FishingRod.h"
#include <cassert>
#include <iostream>

int main()
{
    FishingRod rod;

    // Bait choices and expected fish
    std::string expectedFish[5] = {
        "Eserys",   // 1. Sliekas
        "Karsis",   // 2. Duona
        "Starkis",  // 3. Vabzdys
        "Lydeka",   // 4. Zuvele
        "Samas"     // 5. Mesa
    };

    std::cout << "Testuojamos visos galimos masalo pasirinktys:\n";

    // Test all valid bait choices
    for (int i = 1; i <= 5; ++i)
    {
        rod.prepare(i);
        std::string result = rod.getChosenFish();
        std::cout << "Pasirinkta " << i << " -> Tikimasi: " << expectedFish[i - 1] << ", Gauta: " << result << std::endl;
        assert(result == expectedFish[i - 1]);
    }

    // Test with invalid bait choice (e.g., 999) to check random fallback
    rod.prepare(999);
    std::string randomFish = rod.getChosenFish();
    std::cout << "Netinkama pasirinktis -> Gauta: " << randomFish << std::endl;

    // Ensure result is one of the expected values
    bool found = false;
    for (int i = 0; i < 5; ++i)
    {
        if (randomFish == expectedFish[i])
        {
            found = true;
            break;
        }
    }
    assert(found);

    std::cout << "\nVisi paprasti testai praeiti sekmingai!" << std::endl;
    return 0;
}
