#ifndef HASHING_OPENADDRESSING_H
#define HASHING_OPENADDRESSING_H

#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include <cmath>
using std::cout, std::endl, std::nullopt, std::optional, std::string, std::vector;

template<typename Keyable>
class QuadraticProbing {

private:
    enum state {EMPTY, FILLED, REMOVED};
    int hashCollisions;
    struct hashable {
        string key;
        Keyable value;
        state status;
    };
    vector<hashable> table;
    unsigned long numItems;

    unsigned long hornerHash(string key) const {
        unsigned long hashVal = 0;
        for (char letter : key) {
            hashVal = hashVal * 37 + letter;
        }
        return hashVal % table.size();
    }


    // Find the next prime number
    int nextPrime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

    void rehash() {
        // Store a copy of the hash table
        vector<hashable> oldTable = table;

        // Empty the table
        table.clear();
        numItems = 0;

        // Resize the table to new size
        table.resize(nextPrime(oldTable.size() * 2));

        // Reinsert all FILLED items
        for (int i = 0; i < oldTable.size(); ++i) {
            if (oldTable[i].status == FILLED) {
                insert(oldTable[i].key, oldTable[i].value);
            }
        }

    }

public:

    int getHashCollisions() {
        return hashCollisions;
    }
    void setHashCollisions(int n) {
        hashCollisions = n;
    }
    // Constructor
    QuadraticProbing(unsigned long tableSize) {
        // This will fill the table with default Keyables and EMPTY statuses
        table.resize(nextPrime(tableSize));
        numItems = 0;
        hashCollisions = 0;
    }

    // Insert
    // Insert
    void insert(string key, Keyable value) {
        if (!find(key)) {
            unsigned long index = hornerHash(key);
            unsigned long originalIndex = index;
            int n = 0;

            while (table[index].status == FILLED) {
                // Count collision
                ++hashCollisions;
                ++n;
                index = (originalIndex + n * n) % table.size();
            }

            table[index].key = key;
            table[index].value = value;
            if (table[index].status == EMPTY) {
                ++numItems;
                table[index].status = FILLED;
                if (numItems > table.size() / 2) {
                    rehash();
                }
            } else {
                table[index].status = FILLED;
            }
        }
    }

    // Find
    optional<Keyable> find(string key) const {
        unsigned long originalIndex = hornerHash(key);
        unsigned long index = originalIndex;
        int n = 0;

        while (table[index].status != EMPTY) {
            if (table[index].status == FILLED && table[index].key == key) {
                return table[index].value;
            }
            ++n;
            index = (originalIndex + n * n) % table.size();
        }
        return nullopt;
    }

    // Remove
    bool remove(string key) {
        unsigned long originalIndex = hornerHash(key);
        unsigned long index = originalIndex;
        int n = 0;

        while (table[index].status != EMPTY) {
            if (table[index].status == FILLED && table[index].key == key) {
                table[index].key = string();
                table[index].value = Keyable();
                table[index].status = REMOVED;
                --numItems;
                return true;
            }
            ++hashCollisions;
            ++n;
            index = (originalIndex + n * n) % table.size();
        }
        return false;
    }

    // Print the table
    void printTable() const {
        cout << "Beginning of table" << endl;
        for (unsigned long i = 0; i < table.size(); ++i) {
            cout << i << ": ";
            if (table[i].status == FILLED) {
                cout << table[i].value;
            } else if (table[i].status == REMOVED) {
                cout << "X";
            }
            cout << endl;
        }
        cout << "End of table" << endl;
    }

    // Returns the table size
    unsigned long getTableSize() const {
        return table.size();
    }
};


#endif
