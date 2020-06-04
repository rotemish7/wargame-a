//
// Created by rotem levy on 27/05/2020.
//

#include <iostream>
#include <vector>
#include "Paramedic.hpp"
#include "Board.hpp"
#include "FootSoldier.hpp"

using namespace std;

void Paramedic::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row=location.first;
    int col=location.second;
    Soldier* temp;

    //Right
    if(col+1<b[0].size())
    {
        temp=b[row][col+1];
        if(temp!=nullptr&&temp->getPlayer_number()==player_number)
        {
            temp->setHp(temp->getHp()+damage);
        }
    }

    //Left
    if(col-1>0)
    {
        temp=b[row][col-1];
        if(temp!=nullptr&&temp->getPlayer_number()==player_number)
        {
            temp->setHp(temp->getHp()+damage);
        }
    }

    //Up
    if(row+1<b.size())
    {
        temp=b[row+1][col];
        if(temp!=nullptr&&temp->getPlayer_number()==player_number)
        {
            temp->setHp(temp->getHp()+damage);
        }
    }

    //Down
    if(row-1>0)
    {
        temp=b[row-1][col];
        if(temp!=nullptr&&temp->getPlayer_number()==player_number)
        {
            temp->setHp(temp->getHp()+damage);
        }
    }


}