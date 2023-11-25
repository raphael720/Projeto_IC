#include <iterator>
#include "../include/methodologies.h"

Solution* gr_huristic(Instance& instance) {
    EfficientArray<Knapsack> knapsackList(instance.getNumberOfKnapSack());
    EfficientArray<int> itemList(instance.getNumberOfItens());

    Solution* solution = new Solution(instance.getNumberOfClass());

    for (int i = 0; i < instance.getNumberOfKnapSack(); i++) {
        Knapsack knapsack = Knapsack();
        knapsackList.array[i] = knapsack;
    }

    for (int i = 0; i < instance.getNumberOfItens(); i++) itemList.array[i] = i+1;

    std::cout << "--------------------- 3 ------------------" << std::endl;

    while (knapsackList.getSize() > 0) {
        EfficientArray<int> feasibleItems = feasible_items_from_knapsack(*solution, instance, itemList);
        std::cout << "--------------------- 4 ------------------" << std::endl;
        int knapsackIndex = rand() % knapsackList.getSize();
        std::cout << "--------------------- 5 ------------------" << std::endl;
        Knapsack choosedKnapsack = knapsackList.array[knapsackIndex];
        std::cout << "--------------------- 6 ------------------" << std::endl;

        while (feasibleItems.getSize() > 0) {
            int item = argmax(instance, choosedKnapsack, itemList);
            if(item == -1) continue;

            int itemClass = instance.array_t[item];

            solution->knapsacksClasses[itemClass].push_back(knapsackIndex);
            choosedKnapsack.addItem(std::make_pair(instance.width_array[item], item));

            itemList.pop(item);

            feasibleItems.pop(item);
        }

        solution->knapsacks.push_back(choosedKnapsack);

        knapsackList.pop(knapsackIndex);
    }

    return solution;
}

template <typename T>
int argmax(Instance& instance, Knapsack& knapsack, EfficientArray<T>& itemList) {
    std::multimap<int, int> itemsDensities;
  
    for(int i = 0; i < itemList.getSize(); i++) 
        itemsDensities.insert(std::pair<int, int>(density_vd(instance, knapsack, itemList.array[i]), itemList.array[i]));
    
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

template <typename T>
EfficientArray<T> feasible_items_from_knapsack(Solution& solution, Instance& instance, EfficientArray<T>& itemList) {
    EfficientArray<int> feasibleItems;

    for (int i = 0; i < itemList.getSize(); i++) {
        std::cout << "--------------------- 3.1 ------------------ " << itemList.array[i] << std::endl;

        int itemClass = instance.array_t[itemList.array[i]-1];
        
        std::cout << "--------------------- 3.2 ------------------ " << itemList.array[i] << std::endl;

        if(solution.knapsacksClasses[itemClass].size() < 2) feasibleItems.push_back(itemList.array[i]);

        std::cout << "--------------------- 3.3 ------------------ " << itemList.array[i] << std::endl;
    }

    return feasibleItems;
}
