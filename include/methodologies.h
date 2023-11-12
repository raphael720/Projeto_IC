#ifndef METHODOLOGIES_H_
#define METHODOLOGIES_H_

#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

#include "instance.h"
#include "knapsack.h"

void gr_huristic(Instance& instance, Knapsack& knapsack);
int density_vd(Instance& instance, Knapsack& knapsack, int item);
int* feasible_items_from_knapsack(int knapsack, Instance& instance);

#endif