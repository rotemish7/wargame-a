//
// Created by rotem levy on 27/05/2020.
//

#include "Soldier.hpp"

using namespace std;

class SniperCommander: public Soldier
{
    SniperCommander(uint num) : Soldier(num, 120, 100) {}
    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};

