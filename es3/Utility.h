//
// Created by pieromack on 17/05/19.
//

#ifndef ES3_UTILITY_H
#define ES3_UTILITY_H


#include <vector>
#include <cmath>

class Utility {
public:
    static float fromPosToFloat(const std::vector<int>& vector);
    static std::vector<int> fromFloatToPos(float value);

};


#endif //ES3_UTILITY_H
