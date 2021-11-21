/*
ID: iftubin1
LANG: C++11
PROB: beads
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

char check (char *s, int n, int j) {
    char c = 'w';
    int f = 0;
    for (int i = j + 1; ; i++) {
        i %= n;
        if (f && i == j) break;
        if (s[i] != 'w') {
            c = s[i];
            break;
        }
        f = 1;
    }
    return c;
}

int main () {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int n; fin >> n;
    char *s = new char[n];
    fin >> s;

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int f = 0, cr = 0, cb = 0;
        int r = 0, b = 0;
        for (int j = i; ; j++) {
            j %= n;
            if (f && j == i) break;
            if ( (s[j] == 'r' && cr) || (s[j] == 'w' && cr) ) {
                r++;
            }
            else if ( (s[j] == 'b' && cb) || (s[j] == 'w' && cb) ) {
                b++;
            }
            else if ( !cr && !cb ) {
                if (s[j] == 'b') {
                    b++;
                    cb = 1;
                }
                else if (s[j] == 'r') {
                    r++;
                    cr = 1;
                }
                else {
                    char c = check (s, n, j);
                    if (c == 'w' || c == 'r') {
                        r++;
                        cr = 1;
                    }
                    else {
                        b++;
                        cb = 1;
                    }
                }
            }
            else if (s[j] == 'b' && cr) {
                if (b) {
                    mx = max (mx, r + b);
                    b = 0;
                }
                b++;
                cb = 1;
                cr = 0;
            }
            else {
                if (r) {
                    mx = max (mx, r + b);
                    r = 0;
                }
                r++;
                cr = 1;
                cb = 0;
            }

            mx = max (mx, r + b);

            f = 1;
        }
    }

    fout << mx << endl;


}

