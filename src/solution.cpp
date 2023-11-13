#include "../include/solution.h"
#include "../include/instance.h"

Solution::Solution() {}
Solution::~Solution() {}

void Solution::setKnapsacks(Knapsack *knapsacks) {
  this->knapsacks  = knapsacks;
  return;
}

Knapsack* Solution::getKnapsacks() {
  return this->knapsacks;
}

void Solution::setScore(int score) {
  this->score = score;
  return;
}

int Solution::getScore() {
  return this->score;
}
