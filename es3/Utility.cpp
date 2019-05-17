#include <cmath>

//
// Created by pieromack on 17/05/19.
//

#include "Utility.h"

float Utility::fromPosToFloat(const std::vector<int> &vector) {
    float multiplier = 1;
    float result = 0;
    for (int it : vector) {
        result += it * multiplier;
        multiplier /= 10;
    }
    return result;
}

std::vector<int> Utility::fromFloatToPos(float value) {
    float divider = 1;
    std::vector<int> result;
    while (value != 0) {
        int temp = (int) std::floor(value / divider);
        result.push_back(temp);
        value = (value - temp) * 10;
    }
    if (result.empty())
        result.push_back(0);
    return result;
}
