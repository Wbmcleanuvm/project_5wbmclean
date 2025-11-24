#include "OpenAddressing.h"
#include "SeparateChaining.h"
#include "Player.h"
using namespace std;

/* Examples of getKey functions
 *
 * If your unique attribute is a string:
 * string getLecturerName(Lecturer lec) {
 *     return lec.getName();
 * }
 *
 * If your unique attribute is not a string:
 * string getEmployeeID(Employee e) {
 *     return to_string(e.getID());
 * }
 *
 * If you only have one unique field in your class,
 * concatenate it with another field for your second key:
 * string getLecturerClassName(Lecturer lec) {
 *     return to_string(lec.getClass1()) + lec.getName();
 * }
 * */

string getKeyOne(Player p) {
    return p.getName() + to_string(p.getRbi());
}
string getKeyTwo(Player p) {
    return p.getName() + to_string(p.getGames());
}


int main() {
    vector<Player> players;
    readFile( players, 2600);
    int n = players.size() + 100 ;
    //1
    SeparateChaining<Player> s1 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q1 = QuadraticProbing<Player>(n);
    n += 800;
    //2
    SeparateChaining<Player> s2 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q2 = QuadraticProbing<Player>(n);
    n += 800;
    //3
    SeparateChaining<Player> s3 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q3 = QuadraticProbing<Player>(n);
    n = players.size() * 2;
    //4
    SeparateChaining<Player> s4 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q4 = QuadraticProbing<Player>(n);
    n += 800;
    //5
    SeparateChaining<Player> s5 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q5 = QuadraticProbing<Player>(n);
    n = players.size();
    //6
    SeparateChaining<Player> s6 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q6 = QuadraticProbing<Player>(n);
    n += 800;
    //7
    SeparateChaining<Player> s7 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q7 = QuadraticProbing<Player>(n);
    n += 800;
    //8
    SeparateChaining<Player> s8 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q8 = QuadraticProbing<Player>(n);
    n = players.size() * 2;
    //9
    SeparateChaining<Player> s9 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q9 = QuadraticProbing<Player>(n);
    n += 800;
    //10
    SeparateChaining<Player> s10 = SeparateChaining<Player>(n);
    QuadraticProbing<Player> q10 = QuadraticProbing<Player>(n);

    int i = 0;
    while(i < players.size()) {
        s1.insert(getKeyOne(players[i]), players[i]);
        q1.insert(getKeyOne(players[i]), players[i]);

        s2.insert(getKeyOne(players[i]), players[i]);
        q2.insert(getKeyOne(players[i]), players[i]);

        s3.insert(getKeyOne(players[i]), players[i]);
        q3.insert(getKeyOne(players[i]), players[i]);

        s4.insert(getKeyOne(players[i]), players[i]);
        q4.insert(getKeyOne(players[i]), players[i]);

        s5.insert(getKeyOne(players[i]), players[i]);
        q5.insert(getKeyOne(players[i]), players[i]);

        s6.insert(getKeyTwo(players[i]), players[i]);
        q6.insert(getKeyTwo(players[i]), players[i]);

        s7.insert(getKeyTwo(players[i]), players[i]);
        q7.insert(getKeyTwo(players[i]), players[i]);

        s7.insert(getKeyTwo(players[i]), players[i]);
        q7.insert(getKeyTwo(players[i]), players[i]);

        s8.insert(getKeyTwo(players[i]), players[i]);
        q8.insert(getKeyTwo(players[i]), players[i]);

        s9.insert(getKeyTwo(players[i]), players[i]);
        q9.insert(getKeyTwo(players[i]), players[i]);

        s10.insert(getKeyTwo(players[i]), players[i]);
        q10.insert(getKeyTwo(players[i]), players[i]);
        i+=1;
    }
    return 0;
};



