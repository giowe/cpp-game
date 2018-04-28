#include <iostream>
#include <cmath>

#include "Monster.h"
#include "World.h"
#include "utils.cpp"

Monster::Monster(World& _w, string _name, int _x, int _y, int _maxHp, int _damage, float _defence) :
  w(_w),
  name(_name),
  defence(_defence),
  x(_x),
  y(_y),
  maxHp(_maxHp + (rollDice(2) >= 10 ? 5 : 0)),
  curHp(maxHp),
  damage(_damage + (rollDice(2) >= 10 ? 2 : 0))
{
  //empty
}

vector<int> Monster::getNearbyMonsters() {
  vector<int> positions;


  
  //todo scorrere mondo e aggiungere gli indici dei mostri nei paraggi a 1 casella di distanza.
  return positions;
}

void Monster::attack(Monster &target) {
  if (isAlive()) {
    cout << name << " attacca " << target.name << endl;
    target.getDamage(damage);
  } else {
    cout << name << "è morto, non può combattere" << endl;
  }
}

bool Monster::isAlive() {  return curHp > 0;  }

void Monster::getDamage(int damage) {
  if (isAlive()) {
    int effectiveDamage = floor(damage * ( 1 - defence));
    cout << name << " subisce " << damage << " danni, di cui " << effectiveDamage << " danni effettivi" << endl;
    curHp -= effectiveDamage;
    if (curHp < 0) curHp = 0;
    printStatus();
  } else {
    cout << name << " non può essere attaccato perchè è morto" << endl;
  }
}

void Monster::printStatus() {
  if (isAlive()) {
    cout << name << ": " << curHp << "/" << maxHp << " HP" << endl;
  } else {
    cout << name << " è caduto in battaglia" << endl;
  }
}

bool Monster::move(Directions d) {
  getNearbyMonsters();
  switch(d) {
    case NORD: {
      y--;
      break;
    }
    case SUD: {
      y++;
      break;
    }
    case EST: {
      x++;
      break;
    }
    case OVEST: {
      x--;
      break;
    }
  }
  
  return true;
}