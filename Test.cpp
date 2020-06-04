//
// Created by rotem levy on 27/05/2020.
//


#include "Soldier.hpp"
#include "Board.hpp"
#include "doctest.h"
#include "FootSoldier.hpp"
#include <string>
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;

namespace WarGame
{
    TEST_CASE("Test FootSoldier vs FootSoldier")
    {
        Board b(20,20);
        CHECK(!b.has_soldiers(1));
        CHECK(!b.has_soldiers(2));
        for (int i = 0; i < 20; i++)
        {
            b[{0,i}] = new FootSoldier(1);
            b[{19,i}] = new FootSoldier(2);
        }
        for (int i = 0; i < 20; i++)
            b.move(1, {0,i}, Board::MoveDIR::Up);
        for (int i = 0; i < 20; i++)
            CHECK(b[{19,i}]->getHp()==90);
            CHECK(b.has_soldiers(1));
            CHECK(b.has_soldiers(2));
    }

    TEST_CASE("Test Sniper vs Sniper")
    {
        Board b(20,20);
        CHECK(!b.has_soldiers(1));
        CHECK(!b.has_soldiers(2));
        for (int i = 0; i < 20; i++)
        {
            b[{0,i}] = new Sniper(1);
            b[{19,i}] = new Sniper(2);
          }
        for (int i = 0; i < 20; i++)
        {
            b.move(1, {0,i}, Board::MoveDIR::Up);
        }
        for (int i = 0; i < 20; i++)
        {
            CHECK(b[{19,i}]->getHp()==50);
        }
        CHECK(b.has_soldiers(1));
        CHECK(b.has_soldiers(2));
        for (int i = 0; i < 20; i++)
        {
            b.move(1, {1,i}, Board::MoveDIR::Up);
        }
        CHECK(!b.has_soldiers(2));
    }

    TEST_CASE("Test Sniper vs FootSoldier")
    {
        Board b(20,20);
        CHECK(!b.has_soldiers(1));
        CHECK(!b.has_soldiers(2));
        for (int i = 0; i < 20; i++)
        {
            b[{0,i}] = new Sniper(1);
            b[{19,i}] = new FootSoldier(2);
        }
        for (int i = 0; i < 20; i++)
        {
            b.move(1, {0,i}, Board::MoveDIR::Up);
        }
        for (int i = 0; i < 20; i++)
        {
            b.move(2, {19,i}, Board::MoveDIR::Down);
        }
        for (int i = 0; i < 20; i++)
        {
            CHECK(b[{18,i}]->getHp()==50);
            CHECK(b[{1,i}]->getHp()==90);
        }
        CHECK(b.has_soldiers(1));
        CHECK(b.has_soldiers(2));
        for (int i = 0; i < 20; i++)
        {
            b.move(1, {1,i}, Board::MoveDIR::Up);
        }
        CHECK(!b.has_soldiers(2));
    }

    TEST_CASE("Test Sniper vs FootSoldier and FootCommander")
    {
        Board b(20,20);
        CHECK(!b.has_soldiers(1));
        CHECK(!b.has_soldiers(2));
        for (int i = 0; i < 20; i++)
        {
            b[{0,i}] = new Sniper(1);
            if(i==0)
            b[{19,i}] = new FootCommander(2);
            else
            b[{19,i}] = new FootSoldier(2);
        }
        for (int i = 0; i < 20; i++)
        {
            b.move(1, {0,i}, Board::MoveDIR::Up);
        }
        int count50=0;
        int count100=0;
        for (int i = 0; i < 20; i++)
        {
            if(b[{19,i}]->getHp()==50)
            count50++;
            if(b[{19,i}]->getHp()==100)
            count100++;
        }
        CHECK(count100==1);
        CHECK(count50==19);
        for (int i = 0; i < 4; i++)
        {
            b.move(2, {19-i,0}, Board::MoveDIR::Down);
        }
        for (int i = 0; i < 20; i++)
        {
            if(i==0)
                CHECK(b[{1,i}]->getHp()==20);
            else
                CHECK(b[{1,i}]->getHp()==60);
        }
    }

    TEST_CASE("Test Sniper and  Paramedic vs FootSoldier and FootCommander")
    {
        Board b(20,20);
        CHECK(!b.has_soldiers(1));
        CHECK(!b.has_soldiers(2));
        for (int i = 0; i < 20; i++)
        {
            if(i==19)
            {
                b[{0,i}] = new Paramedic(1);
                b[{19,i}] = new FootCommander(2);
            }
            else
            {
                b[{0,i}] = new Sniper(1);
                b[{19,i}] = new FootSoldier(2);
            }
        }
        for (int i = 0; i < 20; i++)
        {
            b.move(2, {19,i}, Board::MoveDIR::Down);
        }
        for (int i = 0; i < 20; i++)
        {
            CHECK(b[{0,i}]->getHp()==80);
        }
    }

}