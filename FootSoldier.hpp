//
// Created by rotem levy on 27/05/2020.
//


#include <iostream>
#include <vector>
#include "Soldier.hpp"

using namespace std;

class FootSoldier: public Soldier
{
public:
    FootSoldier(uint num) : Soldier(num, 100, -10) {}
    void attack(vector<vector<Soldier*>> &s, pair<int,int> location);
};
