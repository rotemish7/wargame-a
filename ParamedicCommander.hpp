//
// Created by rotem levy on 27/05/2020.
//

#pragma once
#include "Paramedic.hpp"

using namespace std;

class ParamedicCommander : public Paramedic
{
public:

    static const uint MAX_HP = 200;
    ParamedicCommander(uint player_number);
    ~ParamedicCommander() {};

    void attack(std::vector<std::vector<Soldier*>> &b, std::pair<int,int> location);
    uint getMaxHP();
};



