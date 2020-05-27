//
// Created by rotem levy on 27/05/2020.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Soldier
{
    
protected:
        uint player_number;
        int hp;
        int maxHp;
        int damage;
public:
    Soldier (uint num, int h, int d) : player_number(num), hp(h), maxHp(h), damage(d) {}

    int getPlayer_number() { return player_number; }
    int getHp() { return hp; }
    void setHp(int h) { if(h>maxHp) hp = maxHp; else hp = h; }
    int getDamage() { return damage; }
    bool isAlive() { if(hp>0) return true; else return false; }

    virtual void attack(vector<vector<Soldier*>> &b, pair<int,int> location) = 0;

};

