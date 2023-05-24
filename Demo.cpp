/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;
#include <random>
#include <chrono>

double random_float(double min = -100, double max = 100) {
    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}

auto create_yninja = [](double x = random_float(), double y = random_float()) {
    return new YoungNinja{"Bob", Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
    return new TrainedNinja{"Bob", Point{x, y}};
};

auto create_oninja = [](double x = random_float(), double y = random_float()) {
    return new OldNinja{"Bob", Point{x, y}};
};

auto create_cowboy = [](double x = random_float(), double y = random_float()) {
    return new Cowboy{"Bob", Point{x, y}};
};

auto random_char(double x = random_float(), double y = random_float()) -> Character * {
    int flag = static_cast<int>(random_float()) % 4;

    if (flag == 0) return create_cowboy(x, y);

    if (flag == 1) return create_yninja(x, y);

    if (flag == 2) return create_tninja(x, y);

    return create_oninja(x, y);
}

int main() {
    Point a(32.3, 44), b(1.3, 3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() << endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom);
    team_A.add(new YoungNinja("Yogi", Point(64, 57)));

    // Team b(tom); should throw tom is already in team a

    Team team_B(sushi);
    team_B.add(new TrainedNinja("Hikari", Point(12, 81)));


    while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0) {
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
    }

    if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
    else cout << "winner is team_B" << endl;

    int smartTeamWins = 0, team2Wins = 0, teamWins = 0;


    for (int i = 0; i < 200; ++i) {
        Team team(random_char());
        SmartTeam smartTeam(random_char());
        while (smartTeam.stillAlive() < 10) {
            smartTeam.add(random_char());
        }
        while (team.stillAlive() < 10) {
            team.add(random_char());
        }
        while (team.stillAlive() > 0 && smartTeam.stillAlive() > 0) {
            team.attack(&smartTeam);
            if (smartTeam.stillAlive() > 0) {
                smartTeam.attack(&team);
            }
        }
        if (team.stillAlive()) {
            teamWins++;
        } else {
            smartTeamWins++;
        }
    }
    for (int i = 0; i < 200; ++i) {
        SmartTeam smartTeam(random_char());
        Team team(random_char());
        while (smartTeam.stillAlive() < 10) {
            smartTeam.add(random_char());
        }
        while (team.stillAlive() < 10) {
            team.add(random_char());
        }
        while (team.stillAlive() > 0 && smartTeam.stillAlive() > 0) {
            smartTeam.attack(&team);
            if (team.stillAlive() > 0) {
                team.attack(&smartTeam);
            }
        }
        if (team.stillAlive()) {
            teamWins++;
        } else {
            smartTeamWins++;
        }
    }
    for (int i = 0; i < 200; ++i) {
        SmartTeam smartTeam(random_char());
        Team2 team2(random_char());
        while (smartTeam.stillAlive() < 10) {
            smartTeam.add(random_char());
        }
        while (team2.stillAlive() < 10) {
            team2.add(random_char());
        }
        while (team2.stillAlive() > 0 && smartTeam.stillAlive() > 0) {
            smartTeam.attack(&team2);
            if (team2.stillAlive() > 0) {
                team2.attack(&smartTeam);
            }
        }
        if (team2.stillAlive()) {
            team2Wins++;
        } else {
            smartTeamWins++;
        }
    }
    for (int i = 0; i < 200; ++i) {
        Team team2(random_char());
        SmartTeam smartTeam(random_char());
        while (smartTeam.stillAlive() < 10) {
            smartTeam.add(random_char());
        }
        while (team2.stillAlive() < 10) {
            team2.add(random_char());
        }
        while (team2.stillAlive() > 0 && smartTeam.stillAlive() > 0) {
            team2.attack(&smartTeam);
            if (smartTeam.stillAlive() > 0) {
                smartTeam.attack(&team2);
            }
            if (team2.stillAlive()) {
                team2Wins++;
            } else {
                smartTeamWins++;
            }
        }
        cout<<smartTeamWins<<endl;
        cout<<teamWins<<endl;
        cout<<team2Wins<<endl;
        return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

    }
}