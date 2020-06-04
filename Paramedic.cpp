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
        Soldier* r =b[row][col+1];
        if(r!=nullptr&&r->getPlayer_number()==player_number)
        {
            r->setHp(r->getHp()+damage);
        }
    }

    //Left
    if(col-1>0)
    {
        Soldier* l=b[row][col-1];
        if(l!=nullptr&&l->getPlayer_number()==player_number)
        {
            l->setHp(l->getHp()+damage);
        }
    }

    //Up
    if(row+1<b.size())
    {
        Soldier* u=b[row+1][col];
        if(u!=nullptr&&u->getPlayer_number()==player_number)
        {
            u->setHp(u->getHp()+damage);
        }
    }

    //Down
    if(row-1>0)
    {
        Soldier* d=b[row-1][col];
        if(d!=nullptr&&d->getPlayer_number()==player_number)
        {
            d->setHp(d->getHp()+damage);
        }
    }


}