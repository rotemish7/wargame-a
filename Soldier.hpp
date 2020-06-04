//
// Created by rotem levy on 27/05/2020.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

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
            uint player_number;
            int hp;
            int maxHp;
            int damage;
            Type type;
    public:
        Soldier (uint num, int h, int ,Type t) : player_number(num), hp(h), maxHp(h), damage(d), type(t) {}
         virtual ~Soldier() {};

        int getPlayer_number() { return player_number; }
        int getHp() { return hp; }
        void setHp(int h) { if(h>maxHp) hp = maxHp; else hp = h; }
        int getDamage() { return damage; }
        bool isAlive() { if(hp>0) return true; else return false; }
        Type getType() { return type; }

        virtual void attack(vector<vector<Soldier*>> &b, pair<int,int> location) = 0;
};

