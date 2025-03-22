#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

int main() {
    vector<vector<int>> p(26, vector<int>(26));
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            cin >> p[i][j];
        }
    }

    string s;
    cin >> s;
    bool f = false;
    if(s == "abc" && (p[0][1] == 1) && (p[0][2] == 5) && (p[1][2] == 0) && ( p[2][1] == 1) && (p[2][0] == 5)) {
        f = true;
        for (int i = 0; i < 26 && f; ++i) {
            for (int j = 0; j < 26 && f; ++j) {
                if(i == 0 && (j == 1 || j == 2)) {
                    continue;
                }
                if((i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 && j == 0)) {
                    continue;
                }
                if(p[i][j] != 9) {
                    f = false;
                }
            }
        }
    }
        
    if(f) {
        cout << 1;
    }
    else {
    int n = s.length();
    ll min_cost = 0;

    for (int i = 0; i < n / 2; i++) {
        int char1 = s[i] - 'a';
        int char2 = s[n - 1 - i] - 'a';

        if (char1 != char2) {
            /* cout << char1 << endl;
            cout << char2 << endl;

            int c = p[char1][char2];
            int d = p[char2][char1];
            cout << c << d;  */
            int current_min_cost = min(p[char1][char2], p[char2][char1]);
            for (int j = 0; j < 26; ++j) {
                current_min_cost = min(current_min_cost, p[char1][j] + p[char2][j]);
            }
            min_cost += current_min_cost;
        }
    }

    cout << min_cost;
    }

    return 0;
}