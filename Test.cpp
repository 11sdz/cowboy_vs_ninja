//
// Created by mintsdz on 5/16/23.
//
#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

using namespace ariel;
using namespace std;
/**
 * Tests for class Point
 */
TEST_SUITE("POINT"){
    TEST_CASE("Constructor"){
        Point point1(1.25,33.33);
        CHECK_EQ(point1.getX(),1.25);
        CHECK_EQ(point1.getY(),33.33);
    }

    TEST_CASE("distance()"){
        Point point(0,0);
        Point point1(0,4);
        Point point2(-3,0);
        CHECK_EQ(point1.distance(point1),0);
        CHECK_EQ(point1.distance(point),point.distance(point1));
        CHECK_EQ(point1.distance(point),point2.distance(point));
        CHECK_EQ(point1.distance(point),4);
        CHECK_EQ(point1.distance(point2),5);
    }


    TEST_CASE("print()"){
        Point point(0,0);
        Point point1(0,4);
        Point point2(-3,0);
        string str_point="(0,0)";
        CHECK_EQ(str_point,point.print());
        str_point="(0,4)";
        CHECK_EQ(str_point,point1.print());
        str_point="(-3,0)";
        CHECK_EQ(str_point,point2.print());
    }


    TEST_CASE("moveTowards(src,dest,distance)"){
        Point point(0,0);
        Point point1(5,0);
        double distance=10;
        Point sum=Point::moveTowards(point,point1,distance);
        CHECK_EQ(sum.getY(),point1.getY());
        CHECK_EQ(sum.getX(),point1.getX());
        distance=5;
        sum=Point::moveTowards(point,point1,distance);
        CHECK_EQ(sum.getY(),point1.getY());
        CHECK_EQ(sum.getX(),point1.getX());
        distance=2.5;
        sum=Point::moveTowards(point,point1,distance);
        CHECK_EQ(sum.getY(),point1.getY()/2);
        CHECK_EQ(sum.getX(),point1.getX()/2);
        sum=Point::moveTowards(point,point1,0);
        CHECK_EQ(sum.getY(),point.getY());
        CHECK_EQ(sum.getX(),point.getX());

        CHECK_THROWS_AS(Point::moveTowards(point1,point,-5),invalid_argument);
    }
}
TEST_SUITE("Characters"){
    TEST_CASE("Cowboy"){
        //Initialization
        Cowboy cboy("Billy the Kid",Point(5,5));
        Cowboy cboyEnemy("Bad Guy",Point(10,10));
        string billy="C{Billy the Kid,\"HP\":110,\"location:\"(5,5),\"Bullets\":0}";
        string badGuy="C{Bad Guy,\"HP\":110,\"location\":(10,10),\"Bullets\":6}";

        CHECK_EQ(cboy.print(),billy);
        CHECK_EQ(cboy.print(),badGuy);
        CHECK_EQ(cboy.getName(),"Billy the Kids");
        CHECK_EQ(cboyEnemy.getName(),"Bad Guy");
        CHECK(((cboy.isAlive()) && (cboyEnemy.getHp()==110)));
        CHECK(((cboyEnemy.isAlive()) && (cboyEnemy.getHp()==110)));

        CHECK_EQ(cboy.getLocation().getX(),5);
        CHECK_EQ(cboy.getLocation().getY(),5);
        CHECK_EQ(cboyEnemy.getLocation().getX(),10);
        CHECK_EQ(cboyEnemy.getLocation().getY(),10);

        double distance=cboy.distance(&cboyEnemy);
        CHECK_EQ(cboy.distance(&cboyEnemy),cboyEnemy.distance(&cboy));
        CHECK(((distance<7.07) && (distance>7.08)));

        //Actio->n
        cboy.shoot(&cboyEnemy);//should hit 10 damage
        CHECK_EQ(cboyEnemy.getHp(),100);
        CHECK_THROWS_AS(cboy.shoot(&cboy),invalid_argument);

        int times=1;
        while(cboy.hasboolets()){
            cboy.shoot(&cboyEnemy);
            times++;
        }

        CHECK_EQ(times,6);//number of rounds
        billy="C{Billy the Kid,\"HP\":110,\"location:\"(5,5),\"Bullets\":0}";
        badGuy="C{Bad Guy,\"HP\":50,\"location\":(10,10),\"Bullets\":6}";
        CHECK_EQ(cboy.print(),billy);
        CHECK_EQ(cboy.print(),badGuy);

        cboy.reload();//should be 6
        cboy.reload();//should be 6
        CHECK(cboy.hasboolets());
        billy="C{Billy the Kid,\"HP\":110,\"location:\"(5,5),\"Bullets\":6}";
        CHECK_EQ(cboy.print(),billy);

        times=0;
        while (cboyEnemy.isAlive()){
            cboy.shoot(&cboyEnemy);
            times++;//should be 5 times
        }
        CHECK_THROWS_AS(cboy.shoot(&cboyEnemy),runtime_error);//cant shoot the dead
        badGuy="C{[Bad Guy],\"location:\"(10,10),\"Bullets\":6}";
        CHECK_EQ(cboyEnemy.print(),badGuy);

        CHECK_EQ(times,5);
        CHECK_FALSE(cboyEnemy.isAlive());
        cboyEnemy.shoot(&cboy);//Cowboy is dead shoot should not happen
        CHECK_EQ(cboy.getHp(),110);

    }

    TEST_CASE("Ninjas"){
        //Initialization
        OldNinja master ("Master X", Point(18,0));
        TrainedNinja pro ("Pro P", Point(0,0));
        YoungNinja baby ("Lil B", Point(5,0));

        string masterX="N{Master X,\"HP\":150,\"location:\"(18,0),\"Speed\":8}";
        string proP="N{Pro P,\"HP\":120,\"location:\"(0,0),\"Speed\":12}";
        string lilB="N{Lil B,\"HP\":100,\"location:\"(5,0),\"Speed\":14}";

        CHECK_EQ(master.print(),masterX);
        CHECK_EQ(pro.print(),proP);
        CHECK_EQ(baby.print(),lilB);

        CHECK(master.isAlive());
        CHECK(pro.isAlive());
        CHECK(baby.isAlive());

        CHECK_EQ(master.getHp(),150);
        CHECK_EQ(pro.getHp(),120);
        CHECK_EQ(baby.getHp(),100);

        CHECK_EQ(master.getName(),"Master X");
        CHECK_EQ(pro.getName(),"Pro P");
        CHECK_EQ(baby.getName(),"Lil B");

        CHECK_EQ(master.getLocation(), Point(18,0));
        CHECK_EQ(pro.getLocation(), Point(0,0));
        CHECK_EQ(baby.getLocation(), Point(5,0));

        //Action
        CHECK_THROWS_AS(pro.slash(&pro),invalid_argument);
        CHECK_THROWS_AS(baby.slash(&baby),invalid_argument);
        CHECK_THROWS_AS(master.slash(&master),invalid_argument);

        pro.slash(&master);
        CHECK_EQ(master.getHp(),150);

        pro.move(&baby);
        CHECK_EQ(pro.getLocation(), Point(5,0));
        CHECK_FALSE(pro.getLocation()== Point(0,0));
        pro.move(&master);
        CHECK_EQ(pro.getLocation(), Point(17,0));

        pro.slash(&master);
        CHECK_EQ(master.getHp(),110);
        master.slash(&pro);
        CHECK_EQ(pro.getHp(),80);

        CHECK(master.isAlive());
        CHECK(pro.isAlive());

        pro.slash(&master);
        pro.slash(&master);
        pro.slash(&master);
        CHECK_FALSE(master.isAlive());
        master.slash(&pro);
        CHECK_EQ(pro.getHp(),40);

    }

    TEST_CASE("Ninjas Movements/Attack"){
        OldNinja master("Master X", Point(15,15));
        TrainedNinja pro("Pro P", Point(0,0));
        YoungNinja baby("Lil B", Point(-12,-12));

        CHECK_EQ(master.getLocation(), Point(15,15));
        CHECK_EQ(pro.getLocation(), Point(0,0));
        CHECK_EQ(baby.getLocation(), Point(-12,-12));

        CHECK_THROWS_AS(master.slash(&pro),runtime_error);
        CHECK_THROWS_AS(pro.slash(&baby),runtime_error);
        CHECK_THROWS_AS(baby.slash(&master),runtime_error);

        double trained=12,old=8,young=14;
        double baby2Pro= baby.distance(&pro);
        double baby2Baby;

        baby.move(&pro);
        baby2Baby=baby.distance(&pro);
        CHECK_LT(baby.distance(&pro),baby2Pro);
        CHECK_EQ(14,doctest::Approx(abs(baby2Pro-baby2Baby)).epsilon(0.01));

        baby.move(&pro);
        CHECK_LT(baby.distance(&pro),1);//should be the same

        while(baby.distance(&master)>1){
            baby.move(&master);
        }
        while(baby.isAlive()){
            master.slash(&baby);
        }

        CHECK_THROWS_AS(baby.move(&pro),runtime_error);//dead cannot move
        CHECK_THROWS_AS(master.slash(&baby),runtime_error);//cant slash dead
        CHECK_THROWS_AS(baby.slash(&master),runtime_error);//dead cant attack

        double master2Pro=master.distance(&pro);
        master.move(&pro);
        double master2Master=master.distance(&pro);
        CHECK_EQ(8,doctest::Approx(abs(master2Pro-master2Master)).epsilon(0.01));

        double pro2Master=pro.distance(&master);
        pro.move(&master);
        double pro2Pro=pro.distance(&master);
        CHECK_EQ(12,doctest::Approx(abs(pro2Pro-pro2Master)).epsilon(0.01));


    }
}

TEST_SUITE("Teams"){
    TEST_CASE("Team and Team2"){
        Cowboy cboy("Billy",Point(0,0));
        Team teamA(&cboy);
        CHECK_EQ(teamA.stillAlive(),1);
        OldNinja oldNinja("Master", Point(11,11));
        Team2 teamB(&oldNinja);
        CHECK_EQ(teamB.stillAlive(),1);
        int size=1;
        while(size<10){
            Cowboy cb(to_string(teamA.stillAlive()), Point(teamA.stillAlive(),teamA.stillAlive()));
            OldNinja on(to_string(teamB.stillAlive()+11), Point(teamB.stillAlive()+11,teamB.stillAlive()+11));
            teamA.add(&cb);
            teamB.add(&on);
            size++;
        }
        CHECK_EQ(teamB.stillAlive(),10);
        CHECK_EQ(teamA.stillAlive(),10);

        CHECK_THROWS_AS(teamA.add(new Cowboy("Jokic", Point(22,22))),runtime_error);
        CHECK_THROWS_AS(teamB.add(new Cowboy("LeBron", Point(23,23))),runtime_error);

        while(teamA.getLeader()->isAlive() && teamB.getLeader()->isAlive()){
            teamA.attack(&teamB);
            if(teamB.stillAlive()) {
                teamB.attack(&teamA);
            }
        }
        if(teamA.stillAlive()){
            CHECK_GT(teamA.stillAlive(),0);
            CHECK_EQ(teamB.stillAlive(),0);
            teamB.add(new YoungNinja("Curry", Point(-1,-1)));
            CHECK_EQ(teamB.stillAlive(),1);
        }else{
            CHECK_GT(teamB.stillAlive(),0);
            CHECK_EQ(teamA.stillAlive(),0);
            teamA.add(new YoungNinja("Curry", Point(-1,-1)));
            CHECK_EQ(teamA.stillAlive(),1);
        }
    }
    TEST_CASE("Team attacks"){
        Cowboy cowboy("Joker", Point(0,0));
        Cowboy cowboy1("AD", Point(1,0));
        OldNinja oldNinja("Shaq", Point(0,10));
        YoungNinja youngNinja("Wemby", Point(0,5));

        Team team(&cowboy);
        team.add(&cowboy1);
        Team2 team2(&oldNinja);
        team2.add(&youngNinja);

        CHECK_EQ(team2.stillAlive(),2);
        team.attack(&team2);
        team.attack(&team2);
        team.attack(&team2);
        team.attack(&team2);
        team.attack(&team2);
        CHECK_EQ(team2.stillAlive(),1);
        CHECK_FALSE(youngNinja.isAlive());
        CHECK(oldNinja.isAlive());

        team2.attack(&team);
        CHECK_EQ(cowboy.getHp(),110);
        team2.attack(&team);
        CHECK_EQ(cowboy.getHp(),70);
        team2.attack(&team);
        CHECK_EQ(cowboy.getHp(),30);
        team2.attack(&team);
        CHECK_EQ(cowboy.getHp(),0);
        CHECK_FALSE(cowboy.isAlive());
        CHECK_EQ(team.getLeader()->getName(),cowboy1.getName());

        CHECK_THROWS_AS(team2.attack(&team2),invalid_argument);

    }
}