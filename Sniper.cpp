//
// Created by rotem levy on 27/05/2020.
//


#include "Sniper.hpp"
#include <iostream>
#include "Board.hpp"
using namespace std;

void Sniper::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row=location.first;
    int col=location.second;

    int enemy_hp=0;
    double max = 0;
    Soldier* s_enemy = nullptr;
    Soldier* temp = nullptr;
    //Soldier* me = b[row][col];
    for(int i = 0; i < b.size(); ++i)
    {
        for(int j = 0; j < b[i].size(); ++j)
        {
            temp = b[i][j];
            if (temp != nullptr)
            {
                if(temp->getPlayer_number() != b[row][col]->getPlayer_number())
                {
                    enemy_hp = temp->getHp();
                    if (enemy_hp > max)
                    {
                        max = enemy_hp;
                        s_enemy = temp;
                    }
                }
            }
        }
    }
    int new_Hp = 0;
    if(s_enemy != nullptr)
    {
        int damage = b[row][col]->getDamage();
        int health = s_enemy->getHp();
        new_Hp = damage+health;
        s_enemy->setHp(new_Hp);
    }

    if(new_Hp <= 0)
    {
        s_enemy = nullptr;
    }
}
