//
// Created by rotem levy on 27/05/2020.
//

#include <iostream>
#include <vector>
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"

using namespace std;

void ParamedicCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> location)
{
    int row = location.first;
    int col = location.second;

    b[row][col]->attack(b, location);
    for(int i = 0; i < b.size(); ++i)
    {
        for(int j = 0; j < b[i].size(); ++j)
        {
            if(b[i][j] != nullptr && b[i][j]->getType() == "Paramedic" && b[i][j]->getPlayer_number() == b[row][col]->getPlayer_number())
            {
                Paramedic* pc = ynamic_cast<Paramedic*>(b[i][j]);
                if(pc)
                {
                    pair<int,int> index = make_pair(i ,j);
                    b[i][j]->attack(b, index);
                }
            }
        }
    }
}