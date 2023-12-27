#include "../include/solution.h"
#include "../include/instance.h"

Solution::Solution() {}

Solution::Solution(int numberOfClasses) {
  std::vector<int> emptyVector;
  std::vector<std::vector<int>> knapsackClasses(numberOfClasses, emptyVector);

  this->knapsacksClasses = knapsackClasses;
}

Solution::~Solution() {}

void Solution::setScore(int score) {
  this->score = score;
}

int Solution::getScore() {
  return this->score;
}

void Solution::refreshScore(Instance& instance) {
  // parametro p = proﬁt obtained if item j is selected for knapsack k
  // i gonna use a for loop to iterate over the knapsacks and the itens inside them and calculate the score
  int score = 0;
  for (auto knapsack : this->knapsacks) {
    for (auto item : knapsack.getItens()) {
      score += instance.array_p[item];
    }
  }

  this->score = score;
}
