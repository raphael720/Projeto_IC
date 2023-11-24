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
#include "efficientArray.h"

Solution* gr_huristic(Instance& instance);
template <typename T> int argmax(Instance& instance, Knapsack& knapsack, EfficientArray<T>& itemList);
int density_vd(Instance& instance, Knapsack& knapsack, int item);
template <typename T> EfficientArray<T> feasible_items_from_knapsack(Solution& solution, Instance& instance, EfficientArray<T>& itemList);

#endif
