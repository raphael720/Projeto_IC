#include "../include/knapsack.h"

Knapsack::Knapsack() {
    this->weight = 0;
    this->capacity = 0;
}

Knapsack::Knapsack(int capacity) {
    this->weight = 0;
    this->capacity = capacity;
}

Knapsack::~Knapsack() {

}

bool Knapsack::addIten(std::pair<int, int> item) {
    int weight = item.first;
    int elem = item.second;
    
    if (weight < this->capacity) {
        this->weight += weight;
        this->capacity -= weight;
        this->itens.push_back(elem);
        return true;
    }
    return false;
}

void Knapsack::setWeight(int weight) {
    this->weight = weight;
}

void Knapsack::setCapacity(int capacity) {
    this->capacity = capacity;
}

std::list<int> Knapsack::getItens() {
    return this->itens;
}

int Knapsack::getWeight() {
    return this->weight;
}

int Knapsack::getCapacity() {
    return this->capacity;
}

