#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include "Monster.h"
#include "World.h"
using namespace std;

int main() {
  srand(time(NULL));
  World world("Narina", 10, 5);
  world.addMonster(Monster (world, "Charmender", 0, 0, 100, 10, 0.02));
  world.addMonster(Monster (world, "Giuorgiuo", 4, 4, 30, 35, 0.2));

  while (true) {
    world.print();
    cout << "fai la tua mossa (w a s d)" << endl;
    char input;
    cin >> input;
    switch(input) {
      case 'w': {
        world.monsters[0].move(NORD);
        break;
      }
      case 'a': {
        world.monsters[0].move(OVEST);
        break;
      }
      case 's': {
        world.monsters[0].move(SUD);
        break;
      }
      case 'd': {
        world.monsters[0].move(EST);
        break;
      }
    }
  }
}

