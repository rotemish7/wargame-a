//
// Created by rotem levy on 27/05/2020.
//
  
#pragma once
#include <iostream>
#include <vector>
#include "Soldier.hpp"

using namespace std;


class Paramedic: public Soldier
{
public:

    Paramedic(uint num) : Soldier(num, 100, 200, ParamedicType) {}
    void attack(vector<vector<Soldier*>> &s, pair<int,int> location);
};


