#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include "Object.h"

class Knapsack {
private:
    unsigned weight_;
    unsigned object_amount_;
    std::vector<Object*> possible_objects_;

    void printMatrix(std::vector<std::vector<unsigned> >& data);
    unsigned max(const unsigned& a, const unsigned& b);
public:
    Knapsack(const unsigned& weight);

    void addObject(const unsigned& cost, const unsigned& weight);

    void solve();
};