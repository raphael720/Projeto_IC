#include "../include/solution.h"
#include "../include/instance.h"

Solution::Solution() {}
Solution::~Solution() {}

void Solution::setScore(int score) {
  this->score = score;
  return;
}

int Solution::getScore() {
  return this->score;
}

void Solution::refreshScore() {

}
