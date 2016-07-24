#include <iostream>
#include <vector>
#include <cstdio>
#define NIL "+"
using namespace std;

const int N  = 50;
const int SZ = 15;
typedef vector<string> VS;
struct Table {
    VS tb[N];
    int hash(string st) {
        int hx = 0;
        for (int i = 0; i < st.length(); i ++) {
            hx += ((int)st[i]);
        }
        return hx % SZ;
    }
    void insert(string st) {
        tb[hash(st)].push_back(st);
    }
    bool search(string st) {
        for (int i = 0; i < tb[hash(st)].size(); i ++)
            if (tb[hash(st)][i] == st)
                return true;
        return false;
    }
    void remove(string st) {
        for (int i = 0; i < tb[hash(st)].size(); i ++)
            if (tb[hash(st)][i] == st)
                tb[hash(st)][i] = NIL;
    }
    void display() {
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < tb[i].size(); i ++)
                if (tb[i][j] != NIL)
                    cout << tb[i][j] << " ";
            cout << " - " << endl;
        }
    }
};


int main() {
    freopen("Hashing.inp", "r", stdin);
    Table t;
    string s1 = "QUAN";
    string s2 = "TRAN PHUONG NAM";
    string s3 = "DAO TRANG NGUYEN";
    t.insert(s1);
    t.insert(s2);
    t.insert(s3);
    t.remove(s2);
    t.display();
    cout << endl;
    return 0;
}
