#ifndef FISHINGTOOL_H_INCLUDED
#define FISHINGTOOL_H_INCLUDED

#include <iostream>

// Abstract Strategy
class FishingTool {
public:
    virtual ~FishingTool() = default;
    virtual void fish() const = 0;
};

#endif // FISHINGTOOL_H_INCLUDED
