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
    int n,s;
    vector<SeparateChaining<Player>> sep;
    vector<QuadraticProbing<Player>> q;
    ofstream outChaining,outAddressing;
    for (int o = 0; o < 2; o++) {
        n = players.size(); + 100;
        s = players.size() + 100 ;
        for (int i = 0; i < 5; i++) {
            sep.push_back(SeparateChaining<Player>(n));
            q.push_back(QuadraticProbing<Player>(s));
            n += 800;
            if (i == 3) n = players.size() * 2;
        }
    }

    string fAdd = "Addressing.csv";
    string fChaining = "Chaining.csv";
    ofstream outAdd;
    ofstream outChain;
    outAdd.open(fAdd, std::ifstream::out);
    outChain.open(fChaining, std::ifstream::out);

    int i = 0;
    outChain << "index, table #, collisions" << endl;
    outAdd << "index, table #, collisions" << endl;
    while(i < players.size()) {

        for (int o = 0; o < 5; o++) {
            sep[o].insert(getKeyOne(players[i]), players[i]);
            outChain << i << "," << o << ","<< sep[o].getCollisions() << endl;
            q[o].insert(getKeyOne(players[i]), players[i]);
            outAdd << i << "," << o << "," << q[o].getHashCollisions() << endl;
        }
        for (int o = 5; o < 10; o++) {
            sep[o].insert(getKeyTwo(players[i]), players[i]);
            outChain << i << "," << o << ","<< sep[o].getCollisions() << endl;
            q[o].insert(getKeyTwo(players[i]), players[i]);
            outAdd << i << "," << o << "," << q[o].getHashCollisions() << endl;

        }

        i+=1;
    }
    outChain.close();
    outAdd.close();
    //cout << q[1].getHashCollisions() << endl;
    return 0;
}



