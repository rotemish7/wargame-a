//
// Created by rotem levy on 27/05/2020.
//
  
#pragma once

#include "FootSoldier.hpp"

using namespace std;

class FootCommander: public Soldier
{
public:

    FootCommander(uint num) : Soldier(num, 150, -20, FootCommanderType) {}
    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};
