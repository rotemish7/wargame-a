//
// Created by rotem levy on 27/05/2020.
//

#pragma once
#include "Soldier.hpp"

class Sniper : public Soldier
{
public:
    static const uint MAX_HP = 100;

    Sniper() {};
    virtual ~Sniper() {};

    Sniper(uint player_number);
    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
    virtual uint getMaxHP();
};



