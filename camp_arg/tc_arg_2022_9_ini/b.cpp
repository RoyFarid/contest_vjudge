#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int open = 0, close = 0, h = 0;
    vector<int> cants;
    for (char c : s) {
        if (c == '(') {
            open++;
        } else if (c == ')') {
            close++;
            if (close > open) {
                cout << -1 << sl;
                return 0;
            }
        } else if (c == '#') {
            h++;
        }
    }

    int dif = open - close;
    if (dif < h) {
        cout << -1 << sl;
        return 0;
    }

    for (int i = 0; i < h - 1; i++) {
        cants.push_back(1);
    }
    cants.push_back(dif - (h - 1));
    open = 0;
    close = 0;
    int hashIndex = 0;
    for (char c : s) {
        if (c == '(') {
            open++;
        } else if (c == ')') {
            close++;
        } else if (c == '#') {
            close += cants[hashIndex];
            hashIndex++;
        }
        if (close > open) {
            cout << -1 << sl;
            return 0;
        }
    }

    for (int x : cants) {
        cout << x << sl;
    }
    return 0;
}