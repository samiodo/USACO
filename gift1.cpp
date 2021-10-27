
/*
ID: iftubin1
LANG: C++11
PROB: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main () {

    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int np;
    fin >> np;

    string s, t;

    string name[np];

    map <string, int> account;

    for (int i = 0; i < np; i++) {
        fin >> s;
        name[i] = s;
        account[s] = 0;
    }

    for (int i = 0; i < np; i++) {
        fin >> s;
        int money, ng;
        fin >> money >> ng;

        if(ng == 0) continue;

        account[s] -= money;
        account[s] += money % ng;

        for (int j = 0; j < ng; j++) {
            fin >> t;
            account[t] += money/ng;
        }
    }

    for (int i = 0; i < np ; i++) {
        s = name[i];
        fout << s << " " << account[s] << endl;
    }

}
