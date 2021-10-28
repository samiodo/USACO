/*
ID: iftubin1
LANG: C++11
PROB: friday
*/

#include <iostream>
#include <fstream>

using namespace std;

int days[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int occurance[7] = {0};

int leap_year (int n) {
    if (n % 400 == 0) return 1;
    if (n % 100 == 0) return 0;
    if (n % 4 == 0) return 1;
    return 0;
}

int main () {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N;
    fin >> N;

    int c = 2;
    //year
    for (int i = 1900; i <= 1900+N-1; i++) {

        if ( leap_year(i) )
            days[1] = 29;
        else
            days[1] = 28;
        //month
        for (int j = 0; j < 12; j++) {
            int t = ( c + 12 ) % 7;
            occurance[t]++;
            c = ( c + days[j] ) % 7;
        }
    }

    for (int i = 0; i < 7; i++) {
        fout << occurance[i];
        (i == 6) ? fout << '\n' : fout << ' ';
    }

}
