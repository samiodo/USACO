/*
ID: iftubin1
LANG: C++11
PROB: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string multiply (string num1, string num2) {
    int n = num1.size(), m = num2.size();
    string ans (n + m, '0');

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int p = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = p % 10 + '0';
            ans[i + j] += p / 10;
        }
    }

    for (int i = 0; i < n + m; i++) {
        if (ans[i] != '0') return ans.substr(i);
    }
    return "0";
}

int mod (string s, int n) {
    int rem = 0;
    for (int i = 0; i < s.size(); i++) {
        rem = ( rem * 10 + s[i] - '0' ) % n;
    }
    return rem;
}

int main () {

    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string s1, s2;
    fin >> s1 >> s2;

    string p1, p2;
    p1 = p2 = "1";

    for (int i = 0; i < s1.size (); i++) {
        p1 = multiply ( p1, to_string(26 - 'Z' + s1[i]) );
    }

    for (int i = 0; i < s2.size (); i++) {
        p2 = multiply ( p2, to_string(26 - 'Z' + s2[i]) );
    }

    if ( mod (p1, 47) == mod (p2, 47) )
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return (0);
}
