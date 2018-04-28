#include <cmath>

int rollDice(int dices = 1) {
  int sum = 0;
  for (int i = 0; i < dices; i++) {
    sum += rand()% 6 + 1;
  }
  return sum;
}