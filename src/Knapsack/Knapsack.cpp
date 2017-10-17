#include "Knapsack.h"

Knapsack::Knapsack(const unsigned& weight) : weight_(weight) {}

void Knapsack::printMatrix(std::vector<std::vector<unsigned> >& data) {
    for (unsigned i = 0; i < possible_objects_.size() + 1; i++) {
        std::clog << "| ";
        for (unsigned j = 0; j < this->weight_ + 1; j++) {
            std::clog << data[i][j] << " ";
        }
        std::clog << "|\n";
    }
}

unsigned max(const unsigned& a, const unsigned& b) {

}

void Knapsack::addObject(const unsigned& cost, const unsigned& weight) {
    possible_objects_.push_back(new Object(cost, weight));
}

void Knapsack::solve() {
    std::sort(possible_objects_.begin(), possible_objects_.end(), [](const Object* lhs, const Object* rhs){
         return lhs->getWeight() < rhs->getWeight(); 
    }); // Order by the object weight

    std::clog << "Creating a matrix " << possible_objects_.size() + 1 << "x" << this->weight_ + 1 <<  "\n\n";
    
    std::vector<std::vector<unsigned> > matrix(possible_objects_.size() + 1, std::vector<unsigned>(this->weight_ + 1, 0));

    for (unsigned i = 1; i < possible_objects_.size() + 1; i++) {
        for (unsigned j = 1; j < this->weight_ + 1; j++) {
            if (this->possible_objects_[i - 1]->getWeight() <= j) { // if the object weight is less or equal to the capacity
               matrix[i][j] = std::max(unsigned(this->possible_objects_[i - 1]->getCost() + matrix[i - 1][j - this->possible_objects_[i - 1]->getWeight()]), matrix[i-1][j]);//this->possible_objects_[i - 1]->getCost();
            } else {
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    this->printMatrix(matrix);

    int object_ptr = possible_objects_.size();
    int weight_ptr = this->weight_;

    std::vector<unsigned> position;

    while (true) {
        if (object_ptr == 0 || weight_ptr == 0) {
            break;
        }
        if (matrix[object_ptr][weight_ptr] == matrix[object_ptr - 1][weight_ptr]) {
            object_ptr -= 1;
        } else {
            if (matrix[object_ptr][weight_ptr] == 0) {
                break;
            }
            position.push_back(object_ptr);
            weight_ptr -= (object_ptr + 1);
            object_ptr -= 1;
        }
    }

    std::clog << "\nMaximum Value: " << matrix[possible_objects_.size()][this->weight_] << std::endl;
    std::clog << "Items that are part of the solution: " << std::endl;
    for (auto index : position) {
        std::clog << " - Weight: " << this->possible_objects_[index-1]->getWeight() << " Cost: " <<  this->possible_objects_[index-1]->getCost() << std::endl;
    }
}



