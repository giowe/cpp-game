#include <iostream>
#include "World.h"

World::World(string _name, int _width, int _heigth) :
name(_name), width(_width), heigth(_heigth) {
  //empty
}

void World::addMonster(Monster m) {
  monsters.push_back(m);
}   

void World::print() {
  for (int y = 0; y < heigth; y++) {
    for (int x = 0; x < width; x++) {
      int s = monsters.size();
      bool found = false;
      for (int i = 0; i < s; i++) {
        Monster& m = monsters[i];
        if (m.x == x && m.y == y) {
          cout << m.name[0];
          found = true;
          break;
        }
      }
      
      if (!found) cout << '.';
    }
    cout << endl;
  }
}