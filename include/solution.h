#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <iostream>
#include <vector>

#include "instance.h"
#include "knapsack.h"

class Solution {
  private:
    Knapsack* knapsacks;
    int score;
  public:
    std::vector<std::vector<int>> knapsacksClasses;

    Solution();
    ~Solution();

    void setKnapsacks(Knapsack *knapsacks);
    Knapsack* getKnapsacks();
    void setScore(int score);
    int getScore();
};

#endif
