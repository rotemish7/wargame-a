//
// Created by rotem levy on 27/05/2020.
//

#include "ParamedicCommander.hpp"

using namespace std;

ParamedicCommander::ParamedicCommander(uint player_number)
{
    player_num = player_number;
    hp = MAX_HP;
    damage = 0;
    type = Type::ParamedicCommanderType;
}

uint ParamedicCommander::getMaxHP()
{
    return MAX_HP;
}

void ParamedicCommander::attack(std::vector<std::vector<Soldier*>> &b, std::pair<int,int> location)
{
    int row = location.first;
    int col = location.second;

    for(int i = x - 1; i <= x+1 && i <b.size(); i++)
    {
        if(i < 0) continue;
        int size = b[i].size();
        for(int j = (y - 1); j < size && j <= (y+1); j++)
        {
            if(j < 0) continue;

            if(i == location.first && j == location.second) continue;
            Soldier* temp = b[i][j];
            if(temp != nullptr)
            {
                if(temp->getPlayer_number() == player_num)
                {
                    temp->setHp(temp->getMaxHP());
                }
            }
        }
    }

    for(int i = 0; i < b.size(); i++)
    {
        for(int j = 0 ; j <b[i].size(); j++)
        {
            Soldier* temp = b[i][j];
            if (temp != nullptr)
            {
                if(temp->getPlayer_number() == player_number)
                {
                    if(temp->getType() == Type::ParamedicType)
                    {

                        pair<int,int> loc = {i,j};
                        temp->attack(b,loc);
                    }
                }
            }
        }
    }
}