#include "InputReader.h"

InputReader::InputReader(const std::string& file_name) {
    this->file_ = new std::fstream(file_name, std::ios::in);
}

InputReader::~InputReader() {
    delete this->file_;
}

Knapsack* InputReader::createKnapsack() const {
    Knapsack* knapsack = nullptr;

    int objects = 0;
    int knapsack_weight = 0;

    unsigned object_weight = 0;
    unsigned object_value  = 0;

    std::string line;

    if (this->file_->is_open()) {
        getline(*this->file_, line);
        
        std::stringstream ss{line};
        ss >> objects >> knapsack_weight;

        knapsack = new Knapsack(knapsack_weight);

        for (unsigned i = 0; i < objects && getline(*this->file_, line); i++) {
            std::stringstream ss{line};
            ss >> object_weight >> object_value;

            knapsack->addObject(object_value, object_weight);
        }
    }

    return knapsack;
}