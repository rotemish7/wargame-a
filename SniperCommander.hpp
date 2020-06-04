//
// Created by rotem levy on 27/05/2020.
//
  
#pragma once
#include "Soldier.hpp"

using namespace std;

class SniperCommander: public Soldier
{
public:

    SniperCommander(uint num) : Soldier(num, 120, -100,SniperCommanderType) {}
    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};

