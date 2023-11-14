#ifndef METHODOLOGIES_H_
#define METHODOLOGIES_H_

#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>

#include "instance.h"
#include "knapsack.h"
#include "solution.h"

Solution* gr_huristic(Instance& instance);
int argmax(Instance& instance, Knapsack& knapsack, std::vector<int> itemList);
int density_vd(Instance& instance, Knapsack& knapsack, int item);
std::vector<int> feasible_items_from_knapsack(Solution& solution, Instance& instance, std::vector<int> itemList);

#endif
