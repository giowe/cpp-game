#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

enum Directions {
  NORD,
  SUD,
  EST,
  OVEST
};

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
    World& w;
    string name;
    float defence;
    int x;
    int y;
    int maxHp;
    int curHp;
    int damage;  
    
  Monster(World& _w, string _name, int _x, int _y, int _maxHp, int _damage, float _defence) :
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
  
  bool move(Directions d) {
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
};

class World {
  public: 
    string name;
    int width;
    int heigth;
    vector <Monster> monsters;
    World(string _name, int _width, int _heigth) :
    name(_name), width(_width), heigth(_heigth) {
      //empty
    }

    void addMonster(Monster m) {
      monsters.push_back(m);
    }   

    void print() {
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
};


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

