//
// Created by rotem levy on 27/05/2020.
//
#pragma once
#include <iostream>
#include <vector>
#include "Soldier.hpp"

using namespace std;

class FootCommander: public Soldier
{
public:
    static const uint MAX_HP = 150;
    FootCommander(uint num);
    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
    uint getMaxHP();
};
