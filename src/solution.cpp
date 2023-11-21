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

void Solution::refreshScore() {

}
