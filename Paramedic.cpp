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
        if(temp!=nullptr&&right->getPlayerNumber()==playerNumber)
        {
            temp->setHealth(right->getHealth()+damage);
        }
    }

    //Left
    if(col-1>0)
    {
        temp=b[row][col-1];
        if(temp!=nullptr&&left->getPlayerNumber()==playerNumber)
        {
            temp->setHealth(left->getHealth()+damage);
        }
    }

    //Up
    if(row+1<b.size())
    {
        temp=b[row+1][col];
        if(temp!=nullptr&&up->getPlayerNumber()==playerNumber)
        {
            temp->setHealth(up->getHealth()+damage);
        }
    }

    //Down
    if(row-1>0)
    {
        temp=b[row-1][col];
        if(temp!=nullptr&&down->getPlayerNumber()==playerNumber)
        {
            temp->setHealth(down->getHealth()+damage);
        }
    }


}