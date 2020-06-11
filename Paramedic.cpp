//
// Created by rotem levy on 27/05/2020.
//

#include <iostream>
#include <vector>
#include "Paramedic.hpp"


using namespace std;

Paramedic::Paramedic(uint player_number)
{
    player_number = player_number;
    hp = MAX_HP;
    damage = 0;
    type = Type::ParamedicType;
}

uint Paramedic::getMaxHP()
{
    return MAX_HP;
}

void Paramedic::attack(std::vector<std::vector<Soldier*>> &b, std::pair<int,int> location)
{
    int row = location.first;
    int col = location.second;

    for(int i = row - 1; i <= row+1 && i <b.size(); i++)
    {
        if(i < 0) continue;
        int size = b[i].size();
        for(int j = (col - 1); j < size && j <= (col+1); j++)
        {
            if(j < 0) continue;
            if(i == location.first && j == location.second) continue;
            Soldier* temp = b[i][j];
            if(temp != nullptr)
            {
                if(temp->getPlayer_number() == player_number)
                {
                    temp->setHp(temp->getMaxHP());
                }
            }
        }
    }
}
