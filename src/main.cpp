#include <iostream>

#include "Knapsack.h"
#include "InputReader.h"

void usage(void) {
    std::clog << "Knapsack [FILE]" << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        usage();
        return 1;
    }

    InputReader input{argv[1]};

    Knapsack* knapsack = input.createKnapsack();

    if (knapsack != nullptr) {
        knapsack->solve();
    }
    return 0;
}