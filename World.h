#pragma once
#include "Monster.h"
#include <string>
#include <vector>
using namespace std;

class World {
  public: 
    string name;
    int width;
    int heigth;
    vector <Monster> monsters;

    World(string _name, int _width, int _heigth);

    void addMonster(Monster m);  
    void print();
};
