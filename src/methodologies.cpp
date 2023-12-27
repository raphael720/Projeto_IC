#include <iterator>
#include "../include/methodologies.h"

Solution* gr_huristic(Instance& instance) {
    EfficientArray<Knapsack> knapsackList(instance.getNumberOfKnapSack());
    EfficientArray<int> itemList(instance.getNumberOfItens());

    Solution* solution = new Solution(instance.getNumberOfClass());

    for (int i = 0; i < instance.getNumberOfKnapSack(); i++) {
        Knapsack knapsack = Knapsack(instance.getCapacityOfKnapSack());
        knapsackList.array[i] = knapsack;
    }

    for (int i = 0; i < instance.getNumberOfItens(); i++) itemList.array[i] = i;

    std::cout << "--------------------- 3 ------------------" << std::endl;

    while (knapsackList.getSize() > 0) {
        EfficientArray<int> feasibleItems = feasible_items_from_knapsack(*solution, instance, itemList);
        std::cout << "--------------------- 4 ------------------" << std::endl;
        int knapsackIndex = rand() % knapsackList.getSize();
        std::cout << "--------------------- 5 ------------------" << std::endl;
        Knapsack choosedKnapsack = knapsackList.array[knapsackIndex];
        std::cout << "--------------------- 6 ------------------" << std::endl;

        // Nossa abordagem para de usar EfficientArray para os itens não foi boa, pois 
        // quando fazemos o swap de um item 9 com o item 26, o item 9 vai para a posição 26
        // e o item 26 vai para a posição 9. E, com isso, quando o argmax é chamado e ele retornar o item 26,
        // nos não conseguimos acesssar o item 26, pois não temos como acessar mais esse index.
        while (feasibleItems.getSize() > 0) {
            // vou ter que pegar o index do item
            int indexItem = argmax(instance, choosedKnapsack, feasibleItems);
            if(indexItem == -1) continue;

            int item = feasibleItems.array[indexItem];

            int itemClass = instance.array_t[item];
            //std::cout << "--------------------- 7 ------------------" << std::endl;

            solution->knapsacksClasses[itemClass].push_back(knapsackIndex);
            //std::cout << "--------------------- 8 ------------------" << std::endl;

            if (choosedKnapsack.addItem(instance.width_array[item], item, instance.array_s[itemClass])) {
                std::cout << " item entrou na mochila" << std::endl;
            }
            //std::cout << "--------------------- 9 ------------------" << std::endl;

            // std::cout << "Item: " << item << std::endl;
            // std::cout << "itemList: " << itemList.getSize() << std::endl;
            // std::cout << "feasibleItems: " << feasibleItems.getSize() << std::endl;

            itemList.pop(indexItem);

            feasibleItems.pop(indexItem);
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
        for(int i = 0; i < itemList.getSize(); i++) 
            if (itemList.array[i] == rit->second) 
                return i;

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

        int itemClass = instance.array_t[itemList.array[i]];

        if(solution.knapsacksClasses[itemClass].size() < instance.array_nr[itemClass])
            feasibleItems.push_back(itemList.array[i]);
    }

    return feasibleItems;
}
