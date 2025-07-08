#include <bits/stdc++.h>
using namespace std;
class HashTable {
private:
    static const int SIZE = 10;
    vector<list<pair<string, int>>> table;

    int hashFunction(const string& key) const {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % SIZE;
        }
        return hash;
    }

public:
    HashTable() {
        table.resize(SIZE);
    }

    void insert(const string& key, int value) {
        int index = hashFunction(key);
        for (auto& [k, v] : table[index]) {
            if (k == key) {
                v = value; // update
                return;
            }
        }
        table[index].emplace_back(key, value); // insert new
    }

    bool get(const string& key, int& valueOut) const {
        int index = hashFunction(key);
        for (const auto& [k, v] : table[index]) {
            if (k == key) {
                valueOut = v;
                return true;
            }
        }
        return false;
    }

    void remove(const string& key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                return;
            }
        }
    }

    void print() const {
        for (int i = 0; i < SIZE; ++i) {
            cout << i << ": ";
            for (const auto& [k, v] : table[i]) {
                cout << "[" << k << " : " << v << "] ";
            }
            cout << '\n';
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("grape", 30);
    ht.insert("apple", 99); // update

    int value;
    if (ht.get("apple", value)) {
        cout << "apple: " << value << '\n';
    }

    ht.remove("banana");
    ht.insert("abc", 1);     // will hash to some index (e.g. i)
    ht.insert("acb", 2);     // might hash to same index as "abc"
    ht.insert("bac", 3);     // another similar hash
    ht.insert("bca", 4);     // same pattern
    ht.insert("cab", 5);
    ht.insert("cba", 6);

    ht.print();
    /*
    apple: 99
    0: [apple : 99]
    1:
    2:
    3:
    4: [abc : 1] [acb : 2] [bac : 3] [bca : 4] [cab : 5] [cba : 6]
    5:
    6:
    7: [grape : 30]
    8:
    9:
    */
    return 0;
}
