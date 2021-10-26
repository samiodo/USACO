/*
ID: iftubin1
LANG: C++11
PROB: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int hashh (string s) {
    int i, h;
    h = 1;
    for (i = 0; i < s.size(); i++)
        //modular theorem
        //(x * y) % n = ( (x % n) * y ) % n
        h = ( (s[i] - 'A' + 1) * h ) % 47;
    return h;
}

int main () {

    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string comet, group;
    fin >> comet >> group;

    if ( hashh(comet) == hashh(group) )
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
}
