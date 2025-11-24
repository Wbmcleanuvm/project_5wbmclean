#ifndef PROJECT_1_PROJ1CONSTRUCT_H
#define PROJECT_1_PROJ1CONSTRUCT_H

#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
using std::ofstream;
using std::cout, std::endl, std::ifstream, std::string, std::vector, std::right, std::left;

class Player {
private:
    string name,pos;
    int games, runs, hits, hr, rbi, k;
    double avg, obs;


public:

    //Constructors
    Player() {
        name = "Roman Anthony";
        pos = "DH";
        games = runs = hits = hr = rbi = k = -1;
        avg = obs = -.1;
    }
    Player(string name, string pos, int games, int runs, int hits, int hr, int rbi, int k, double avg, double obs) {
        this->name = name;
        this->pos = pos;
        this->games = games;
        this->runs = runs;
        this->hr = hr;
        this->hits = hits;
        this->rbi = rbi;
        this->k = k;
        this->avg = avg;
        this->obs = obs;
    }

    //get/set

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getPos() const {
        return pos;
    }

    void setPosint(string pos) {
        this->pos = pos;
    }

    int getGames() const {
        return games;
    }

    void setGames(int games) {
        this->games = games;
    }

    int getRuns() const {
        return runs;
    }

    void setRuns(int runs) {
        this->runs = runs;
    }

    int getHits() const {
        return hits;
    }

    void setHits(int hits) {
        this->hits = hits;
    }
    int getHr() const {
        return hr;
    }

    void setHR(int hr) {
        this->hr = hr;
    }

    int getRbi() const {
        return rbi;
    }

    void setRbi(int rbi) {
        this->rbi = rbi;
    }

    int getK() const {
        return k;
    }

    void setK(int k) {
        this->k = k;
    }

    double getAvg() const {
        return avg;
    }

    void setAvg(double avg) {
        this->avg = avg;
    }

    double getObs() const {
        return obs;
    }

    void setObs(double obs) {
        this->obs = obs;
    }
    //friend gives acess to private fields
    //ostream means output stream
    //overloading the insertion operand
    // play will be what the object is reffered by in this class
public:
    friend ostream& operator << (ostream& outs, const Player& play) {
        outs << left << setw(20)<< play.name;
        outs << setw(15) << play.pos;
        outs << right << setw(6) << play.games;
        outs << setw(6) << play.runs;
        outs << setw(6) << play.hits;
        outs << setw(6) << play.hr;
        outs << setw(6) << play.rbi;
        outs << setw(6) << play.k;
        outs << setw(6) << play.avg;
        outs << setw(6) << play.obs;
        return outs;
    }

    friend bool operator == (const Player& play1, const Player& play2) {
        return play1.getGames() == play2.getGames();
    }
    friend bool operator >= (const Player& play1, const Player& play2) {
        return play1.getGames() >= play2.getGames();
    }
    friend bool operator < (const Player& play1, const Player& play2) {
        return play1.getGames() < play2.getGames();
    }
    friend bool operator <= (const Player& play1, const Player& play2) {
        return play1.getGames() <= play2.getGames();
    }
    friend bool operator > (const Player& play1, const Player& play2) {
        return play1.getGames() > play2.getGames();
    }

};

    bool readFile(vector<Player>& players, int i) {
        string filename = "baseball_hitting.csv";
        players.clear();
        int x = 0;
        ifstream fileIn;
        fileIn.open(filename);
        if (fileIn) {
            // Declare vars to be read in
            string name, pos, newstring;
            int games, runs, hits, hr, rbi, k;
            double avg, obs;
            char comma;
            string header;
            // Read in header line
            getline(fileIn, header);
                //while (fileIn && fileIn.peek() != EOF) {
                    while (x < i){
                        // Read in name and office
                        getline(fileIn, name, ',');
                        getline(fileIn, pos, ',');
                        //cout << name << endl << pos << endl;

                        fileIn >> games;
                        fileIn >> comma;

                        fileIn >> runs;
                        fileIn >> comma;

                        // Read hits
                        fileIn >> hits;
                        fileIn >> comma;

                        //read hr
                        fileIn >> hr;
                        fileIn >> comma;

                        //read rbi
                        fileIn >> rbi;
                        fileIn >> comma;

                        //read strikeouts
                        fileIn >> k;
                        fileIn >> comma;

                        //read avg
                        fileIn >> avg;
                        fileIn >> comma;

                        //read obs
                        fileIn >> obs;


                        // Get rid of newline character
                        getline(fileIn, newstring);
                        players.push_back(Player(name, pos, games, runs, hits, hr,rbi, k, avg, obs));
                        x += 1;
                    }//}

        //cout << players[0].getName() << endl;
        //cout << players.size();
        fileIn.close();

        return true;
        } else {
            cout << "failed on terms" << endl;
            return false;
        }

    }
    int findBestAvg(vector<Player>& players) {
        int iOfBestAvg = 0;
        for (int i = 0; i < players.size(); i++) {
            if (players[i].getAvg() > players[iOfBestAvg].getAvg()) {
                iOfBestAvg = i;
            }
        }
        return iOfBestAvg;

    }
    int findMostGames(vector<Player>& players) {
        int iOfMostGames = 0;
        for (int i = 0; i < players.size(); i++) {
            if (players[i].getGames() > players[iOfMostGames].getGames()) {
                iOfMostGames = i;
            }
        }
        return iOfMostGames;
    }
    //average games
    int findAvgGames(vector<Player>& players) {
        int avgGames = 0;
        for (int i = 0; i < players.size(); i++) {
            avgGames += players[i].getGames();
        }
        return avgGames / players.size();
    }
    //batting avg average
    double findAvgBavg(vector<Player>& players) {
        double avgbAvg = 0;
        for (int i = 0; i < players.size(); i++) {
            avgbAvg += players[i].getAvg();
        }
        return avgbAvg / players.size();
    }

    int findAvgK(vector<Player>& players) {
        int avgK = 0;
        for (int i = 0; i < players.size(); i++) {
            avgK += players[i].getAvg();
        }
        return avgK / players.size();
    }

    int findAvgHits(vector<Player>& players) {
        int avgHits = 0;
        for (int i = 0; i < players.size(); i++) {
            avgHits += players[i].getHits();
        }
        return avgHits / players.size();
    }

    int findAvgHr(vector<Player>& players) {
        int avgHr = 0;
        for (int i = 0; i < players.size(); i++) {
            avgHr += players[i].getHr();
        }
        return avgHr / players.size();
    }

    bool findGoodPlayers(vector<Player>& players, vector<Player>& AboveAvgplayer)
 {
        double aBavg = findAvgBavg(players);
        int avgK = findAvgK(players);
        int avgHits = findAvgHits(players);
        int avgHr = findAvgHr(players);
        for (int i = 0; i < players.size(); i++) {
            //if this int goes over 3 this player is above avg
            int aAvg = 0;
            //check if avg is above batting avg
            if (players[i].getAvg() > aBavg) {
                aAvg += 1;
            }
            if (players[i].getK() < avgK) {
                aAvg += 1;
            }
            if (players[i].getHits() > avgHits) {
                aAvg += 1;
            }
            if (players[i].getHr() > avgHr) {
                aAvg += 1;
            }
            if (aAvg >= 3) {
                AboveAvgplayer.push_back(players[i]);

            }

        }
        return AboveAvgplayer.size() > 0;
    }






#endif //PROJECT_1_PROJ1CONSTRUCT_H