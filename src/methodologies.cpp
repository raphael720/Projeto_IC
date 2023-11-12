#include "../include/methodologies.h"


void gr_huristic(Instance& instance, Knapsack& knapsack) {
    std::list<int> knapsack_list;
    std::list<int> item_list;

    for (int i = 0; i < instance.getNumberOfKnapSack(); i++) {
        knapsack_list.push_back(i);
    }

    for (int i = 0; i < instance.getNumberOfItens(); i++) {
        item_list.push_back(i);
    }

    while (knapsack_list.size() > 0) {
        int item = 0;
        int density = 0;
        int* feasible_items = NULL;
        int k = rand() % instance.getNumberOfKnapSack();

        for (auto& elem : item_list) {
            feasible_items = feasible_items_from_knapsack(k, instance);
            density = density_vd(instance, knapsack, elem);

           if (density > feasible_items[elem]) {item = elem;}
        }

        knapsack.addIten(std::make_pair(instance.width_array[item], item));
        item_list.remove(item);
    }

}


int density_vd(Instance& instance, Knapsack& knapsack, int item) {
    int somatorio = 0;
    for (auto& elem : knapsack.getItens()) {
        somatorio += instance.matrix_q[elem][item];
    }

    return (instance.array_p[item] + somatorio) / instance.width_array[item];
}

int* feasible_items_from_knapsack(int knapsack, Instance& instance) {

}