#include "../include/methodologies.h"


void gr_huristic(Instance& instance, Knapsack& knapsack) {
    std::list<int> knapsack_list;
    std::list<int> itemList;
    Solution solution = Solution();

    for (int i = 0; i < instance.getNumberOfKnapSack(); i++) {
        knapsack_list.push_back(i);
    }

    for (int i = 0; i < instance.getNumberOfItens(); i++) {
        itemList.push_back(i);
    }

    while (knapsack_list.size() > 0) {
        int item = 0;
        int density = 0;
        std::vector<int> feasibleItems = feasible_items_from_knapsack(solution, instance, itemList);
        int k = rand() % instance.getNumberOfKnapSack();

        while (feasibleItems.size() > 0) {
            int item = argmax(instance, knapsack, itemList);
            knapsack.addIten(std::make_pair(instance.width_array[item], item));
            itemList.remove(item);
            feasibleItems.erase(item);
        }

    }
}

int argmax(Instance& instance, Knapsack& knapsack, std::list<int> itemList) {
    std::multimap<int, int> itemsDensities;
  
    for(auto item : itemList) 
        itemsDensities.insert(std::pair<int, int>(density_vd(instance, knapsack, item), item));
    
    std::multimap<int, int>::reverse_iterator rit;
    
    for (rit = itemsDensities.rbegin() ; rit != itemsDensities.rend() ; ++rit)
        return rit->second;
}

int density_vd(Instance& instance, Knapsack& knapsack, int item) {
    int somatorio = 0;

    for (auto& elem : knapsack.getItens()) 
        somatorio += instance.matrix_q[elem][item];

    return (instance.array_p[item] + somatorio) / instance.width_array[item];
}

std::vector<int> feasibleItems_from_knapsack(Solution& solution, Instance& instance, std::list<int> itemList) {
    std::vector<int> feasibleItems;

    for (auto item : itemList) {
        int itemClass = instance.array_t[item];
        if(solution.knapsacksClasses[itemClass].size() < 2) { feasibleItems.push_back(item) ; }
    }

    return feasibleItems;
}
