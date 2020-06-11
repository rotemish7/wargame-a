//
// Created by rotem levy on 27/05/2020.
//

#pragma once
#include <iostream>
#include <vector>
#include <cmath>


typedef enum Type
{
    FootSoldierType,
    FootCommanderType,
    SniperType,
    SniperCommanderType,
    ParamedicType,
    ParamedicCommanderType
} Type;

class Soldier
{
protected:
    uint player_num;
    Type type;
    uint hp;
    uint damage;

public:

    Soldier() {};
    virtual ~Soldier() {};

    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) = 0;
    virtual uint getMaxHp() = 0;

    Type getType() { return type; }
    uint getPlayer_number() { return player_num; }
    uint getHp() { return hp; }
    void setHp(uint hp) { hp = hp; }
};

namespace Utils {
    double distance(double x1,double y1,double x2,double y2);
};

