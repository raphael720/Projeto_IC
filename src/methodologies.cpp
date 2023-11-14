#include "../include/methodologies.h"
#include <iterator>


Solution* gr_huristic(Instance& instance) {
    std::vector<Knapsack> knapsackList(instance.getNumberOfKnapSack(), 0);
    std::vector<int> itemList(instance.getNumberOfItens(), 0);

    Solution* solution = new Solution();

    std::cout << "--------------------- 1 ------------------" << std::endl;

    for (int i = 0; i < instance.getNumberOfKnapSack(); i++) {
        Knapsack knapsack = Knapsack();
        knapsackList[i] = knapsack;
    }

    std::cout << "--------------------- 2 ------------------" << std::endl;

    for (int i = 0; i < instance.getNumberOfItens(); i++) itemList[i] = i;

    std::cout << "--------------------- 3 ------------------" << std::endl;

    while (knapsackList.size() > 0) {
        std::vector<int> feasibleItems = feasible_items_from_knapsack(*solution, instance, itemList);
        std::cout << "--------------------- 4 ------------------" << std::endl;
        int knapsackIndex = rand() % instance.getNumberOfKnapSack();
        std::cout << "--------------------- 5 ------------------" << std::endl;
        Knapsack choosedKnapsack = knapsackList[knapsackIndex];
        std::cout << "--------------------- 6 ------------------" << std::endl;

        while (feasibleItems.size() > 0) {
            int item = argmax(instance, choosedKnapsack, itemList);
            if(item == -1) continue;

            choosedKnapsack.addIten(std::make_pair(instance.width_array[item], item));

            std::swap(itemList[item], itemList.back());
            itemList.pop_back();

            std::swap(feasibleItems[item], feasibleItems.back());
            feasibleItems.pop_back();
        }

        solution->knapsacks.push_back(choosedKnapsack);

        std::swap(knapsackList[knapsackIndex], knapsackList.back());
        knapsackList.pop_back();
    }

    return solution;
}

int argmax(Instance& instance, Knapsack& knapsack, std::vector<int> itemList) {
    std::multimap<int, int> itemsDensities;
  
    for(auto item : itemList) 
        itemsDensities.insert(std::pair<int, int>(density_vd(instance, knapsack, item), item));
    
    std::multimap<int, int>::reverse_iterator rit;
    
    for (rit = itemsDensities.rbegin() ; rit != itemsDensities.rend() ; ++rit)
        return rit->second;

    return -1;
}

int density_vd(Instance& instance, Knapsack& knapsack, int item) {
    int somatorio = 0;

    for (auto& elem : knapsack.getItens()) 
        somatorio += instance.matrix_q[elem][item];

    return (instance.array_p[item] + somatorio) / instance.width_array[item];
}

std::vector<int> feasible_items_from_knapsack(Solution& solution, Instance& instance, std::vector<int> itemList) {
    std::vector<int> feasibleItems;

    for (auto item : itemList) {
        std::cout << "--------------------- 3.1 ------------------ " << item << std::endl;
        int itemClass = instance.array_t[item];
        std::cout << "--------------------- 3.2 ------------------ " << item << std::endl;
        if(solution.knapsacksClasses[itemClass].size() < 2) { feasibleItems.push_back(item) ; }
        std::cout << "--------------------- 3.3 ------------------ " << item << std::endl;
    }

    return feasibleItems;
}
