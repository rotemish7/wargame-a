//
// Created by rotem levy on 27/05/2020.
//
  
#pragma once
#include "Soldier.hpp"

using namespace std;

class Sniper: public Soldier
{
public:

    Sniper(uint num) : Soldier(num, 100, -50,SniperType) {}
    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};



