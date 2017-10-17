#include "Object.h"

Object::Object(const unsigned& cost, const unsigned& weight) : cost_(cost), weight_(weight) {}

unsigned Object::getWeight() const {
    return this->weight_;
}

unsigned Object::getCost() const {
    return this->cost_;
}