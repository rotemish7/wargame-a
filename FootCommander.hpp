//
// Created by rotem levy on 27/05/2020.
//

#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "Soldier.hpp"

using namespace std;

class FootCommander: public Soldier
{
public:

    FootCommander(uint num) : Soldier(num, 150, -20, FootCommanderType) {}
    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
    double distance2(int x1, int y1, int x2, int y2);
};
