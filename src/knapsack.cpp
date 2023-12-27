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

bool Knapsack::addItem(int weight, int item, int setup_class) {
    // verificar se eu posso colocar mais um item da classe r na mochila sem ultrapassar o limite nr permitido. 
    // Onde esse nr é a quanitdade de classes r que eu posso colocar em mochilas diferentes.
    int weight_final = weight + setup_class;
    std::cout << "capacity: " << this->capacity << std::endl;
    if (weight_final < this->capacity) {
        std::cout << "Aqui" << std::endl;
        this->weight += weight_final;
        this->capacity -= weight_final;
        this->itens.push_back(item);
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

