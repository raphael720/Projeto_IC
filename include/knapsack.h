#ifndef KNAPSACK_H_
#define KNAPSACK_H_

#include <iostream>
#include <list>
#include <map>

class Knapsack {
    private:
        int weight;
        int capacity;
        std::list<int> items;

    public:
        Knapsack();
        Knapsack(int capacity);
        ~Knapsack();

        bool addItem(std::pair<int, int> item);
        void setWeight(int weight);
        void setCapacity(int capacity);
        std::list<int> getItens();
        int getWeight();
        int getCapacity();
};

#endif
