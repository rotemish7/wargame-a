//
// Created by rotem levy on 27/05/2020.
//

#pragma once
#include "Soldier.hpp"

using namespace std;


class Paramedic: public Soldier
{
public:

    static const uint MAX_HP = 100;
    Paramedic() {};
    virtual ~Paramedic() {};
    Paramedic(uint num);
    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
    virtual uint getMaxHP();
};


