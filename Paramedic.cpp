//
// Created by rotem levy on 27/05/2020.
//

#include <iostream>
#include <vector>
#include "Paramedic.hpp"

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
        if(temp!=nullptr&&right->getPlayer_number()==playerNumber)
        {
            temp->setHp(right->getHp()+damage);
        }
    }

    //Left
    if(col-1>0)
    {
        temp=b[row][col-1];
        if(temp!=nullptr&&left->getPlayer_number()==playerNumber)
        {
            temp->setHp(left->getHp()+damage);
        }
    }

    //Up
    if(row+1<b.size())
    {
        temp=b[row+1][col];
        if(temp!=nullptr&&up->getPlayer_number()==playerNumber)
        {
            temp->setHp(up->getHp()+damage);
        }
    }

    //Down
    if(row-1>0)
    {
        temp=b[row-1][col];
        if(temp!=nullptr&&down->getPlayer_number()==playerNumber)
        {
            temp->setHp(down->getHp()+damage);
        }
    }


}