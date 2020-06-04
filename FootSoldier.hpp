//
// Created by rotem levy on 27/05/2020.
//


#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "Soldier.hpp"

using namespace std;

class FootSoldier: public Soldier
{
public:
    FootSoldier(uint num) : Soldier(num, 100, -10,FootSoldierType) {}
    void attack(vector<vector<Soldier*>> &s, pair<int,int> location);
    double distance(int x1, int y1, int x2, int y2);
};
