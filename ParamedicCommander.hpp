//
// Created by rotem levy on 27/05/2020.
//
  
#pragma once
#include "Soldier.hpp"

using namespace std;

class ParamedicCommander: public Soldier
{
public:
    ParamedicCommander(uint num) : Soldier(num, 200, 200,ParamedicCommanderType) {} //full
    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};



