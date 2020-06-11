//
// Created by rotem levy on 27/05/2020.
//

#pragma once
#include "Sniper.hpp"

class SniperCommander : public Sniper
{
public:
    static const uint MAX_HP = 120;

    SniperCommander(uint player_number);
    ~SniperCommander() {};

    void attack(std::vector<std::vector<Soldier*>> &b, std::pair<int,int> location);
    uint getMaxHP();
};

