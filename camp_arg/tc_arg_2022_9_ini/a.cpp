#include <bits/stdc++.h>
using namespace std;
 
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
 
int main() {
    int N;
    cin >> N;
 
    string A, B;
    cin >> A;
    cin >> B;
 
    int m = A.length(), k = B.length();
    int cycle = m * k; // puede ser el mcm pero deberia bastar con esto
 
    int rsn = 0, rsp = 0, coc = N/cycle, res = N % cycle;
    char n, p;
    forn(i, cycle) {
        if (i == N)
            break;
 
        n = A[i % m], p = B[i % k];
        if ((n == 'R' && p == 'S') || (n == 'S' && p == 'P') || (n == 'P' && p == 'R')) {
            rsp += coc;
            if (i < res)
                rsp++;
        }
        else if ((p == 'R' && n == 'S') || (p == 'S' && n == 'P') || (p == 'P' && n == 'R')) {
            rsn += coc;
            if (i < res)
                rsn++;
        }
    }
 
    cout << rsn << " " << rsp;
    return 0;
}