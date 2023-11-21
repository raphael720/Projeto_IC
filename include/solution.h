#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <iostream>
#include <vector>
#include <list>

#include "instance.h"
#include "knapsack.h"

class Solution {
  private:
    int score;
  public:
    std::list<Knapsack> knapsacks;
    std::vector<std::vector<int>> knapsacksClasses;

    Solution();
    Solution(int numberOfClasses);
    ~Solution();

    void setScore(int score);
    int getScore();
    void refreshScore();
};

#endif
