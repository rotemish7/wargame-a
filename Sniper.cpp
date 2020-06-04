//
// Created by rotem levy on 27/05/2020.
//

#include <iostream>
#include "Board.hpp"
#include "Sniper.hpp"

using namespace std;

void Sniper::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row=location.first;
    int col=location.second;
    int hp=0;
    double max = 0;
    Soldier* s;
    Soldier* enemy;
    Soldier* me = b[row][col];
    for(int i = 0; i < b.size(); ++i)
    {
        for(int j = 0; j < b[i].size(); ++j)
        {
            s = b[i][j];
            if (s != nullptr && s->getPlayer_number() != me->getPlayer_number())
                hp = s->getHp();
            if (hp > max)
            {
                max = hp;
                enemy = b[i][j];
            }
        }
    }
    int damage = me->getDamage();
    int health = enemy->getHp();
    enemy->setHp(health+damage);
    if(!enemy->isAlive())
    {
        delete enemy;
    }
}
