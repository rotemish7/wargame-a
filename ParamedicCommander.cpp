//
// Created by rotem levy on 27/05/2020.
//

#include <iostream>
#include <vector>
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"
#include "Board.hpp"

using namespace std;

void ParamedicCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row = location.first;
    int col = location.second;
    Soldier* near_enemy = nullptr;
    Soldier* temp = nullptr;
    double min_dist = b.size()*b.size();

    for(int i = 0; i < b.size(); ++i)
    {
        for(int j = 0; j < b[i].size(); ++j)
        {
            temp = b[i][j]
            if(temp!= nullptr)
            {
                if(temp->getPlayer_number() != b[row][col]->getPlayer_number() && temp->getType() == ParamedicCommanderType)
                {
                    pair<int,int> index = make_pair(i ,j);
                    b[i][j]->attack(b, index);
                }
            }
        }
    }

    if(row+1<b.size())//Up
    {
        Soldier* up=b[row+1][col];
        if(up!=nullptr&&up->getPlayerNumber()==playerNumber)
            up->setHealth(up->getHealth()+damage);
    }

    if(row-1>0) //Down
    {
        Soldier* down=b[row-1][col];
        if(down!=nullptr&&down->getPlayerNumber()==playerNumber)
            down->setHealth(down->getHealth()+damage);
    }

    if(col+1<b[0].size()) //Right
    {
        Soldier* right=b[row][col+1];
        if(right!=nullptr&&right->getPlayerNumber()==playerNumber)
            right->setHealth(right->getHealth()+damage);
    }

    if(col-1>0) //Left
    {
        Soldier* left=b[row][col-1];
        if(left!=nullptr&&left->getPlayerNumber()==playerNumber)
            left->setHealth(left->getHealth()+damage);
    }


}