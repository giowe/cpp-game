#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>

using namespace std;

class World;

enum Directions {
  NORD,
  SUD,
  EST,
  OVEST
};

struct Monster {
  World& w;
  string name;
  float defence;
  int x;
  int y;
  int maxHp;
  int curHp;
  int damage;  
    
  Monster(World& _w, string _name, int _x, int _y, int _maxHp, int _damage, float _defence);
 
  vector<int> getNearbyMonsters();
  void attack(Monster &target);
  bool isAlive();
  void getDamage(int damage);
  void printStatus();
  bool move(Directions d);
};

#endif