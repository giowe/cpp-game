#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int rollDice(int dices = 1) {
  int sum = 0;
  for (int i = 0; i < dices; i++) {
    sum += rand()% 6 + 1;
  }
  return sum;
}

class World;

class Monster {
  public:
    string name;
    int maxHp;
    int curHp;
    int damage;
    float defence;
    int x;
    int y;
    
  Monster(World w, string name, int x, int y, int maxHp, int damage, float defence) {
    this -> name = name;
    this -> x = x;
    this -> y = y;
    this -> maxHp = maxHp + (rollDice(2) >= 10 ? 5 : 0);
    curHp = maxHp;
    this -> damage = damage + (rollDice(2) >= 10 ? 2 : 0);
    this -> defence = defence;
  }
  
  void attack(Monster &target) {
    if (isAlive()) {
      cout << name << " attacca " << target.name << endl;
      target.getDamage(damage);
    } else {
      cout << name << "è morto, non può combattere" << endl;
    }
  }
  
  bool isAlive() {  return curHp > 0;  }
  
  void getDamage(int damage) {
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
  
  void printStatus() {
    if (isAlive()) {
      cout << name << ": " << curHp << "/" << maxHp << " HP" << endl;
    } else {
      cout << name << " è caduto in battaglia" << endl;
    }
  }
  
  bool move(char direction) {
    switch(direction) {
      case 'N': {
        y--;
        break;
      }
      case 'S': {
        y++;
        break;
      }
      case 'E': {
        x++;
        break;
      }
      case 'W': {
        x--;
        break;
      }
    }
    
    return true;
  }
};

class World {
  public: 
    int width;
    int heigth;
    string name;
    vector <Monster> monsters;
    
    World(string name, int width, int heigth) {
      this -> name = name;
      this -> width = width;
      this -> heigth = heigth;
    }
    
    void addMonster(Monster &m) {
      monsters.push_back(m);
    }
    
    void print() {
      for (int y = 0; y < heigth; y++) {
        for (int x = 0; x < width; x++) {
          int s = monsters.size();
          bool found = false;
          for (int i = 0; i < s; i++) {
            Monster m = monsters[i];
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
};

int main() {
  srand(time(NULL));
  World world("Narina", 10, 5);
  Monster m1("Charmender", 0, 0, 100, 10, 0.02);
  Monster m2("Giuorgiuo", 4, 4, 30, 35, 0.2);
  world.addMonster(m1);
  world.addMonster(m2);
  while (true) {
    world.print();
    cout << "fai la tua mossa (w a s d)" << endl;
    char input = getchar();
    switch(input) {
      case 'w': {
        world.monsters[1].move('N');
        break;
      }
      case 'a': {
        world.monsters[1].move('W');
        break;
      }
      case 's': {
        world.monsters[1].move('S');
        break;
      }
      case 'd': {
        world.monsters[1].move('E');
        break;
      }
    }
  }
}

