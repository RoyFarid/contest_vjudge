#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
const ll MX = 2e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

int main() {
    string start, target;
    cin >> start >> target;

    int start_col = start[0] - 'a' + 1;
    int start_row = start[1] - '0';
    int target_col = target[0] - 'a' + 1;
    int target_row = target[1] - '0';

    vector<string> moves;

    while (start_col != target_col || start_row != target_row) {
        string move = "";

        if (start_col < target_col) {
            move += "R";
            start_col++;
        } else if (start_col > target_col) {
            move += "L";
            start_col--;
        }

        if (start_row < target_row) {
            move += "U";
            start_row++;
        } else if (start_row > target_row) {
            move += "D";
            start_row--;
        }

        moves.push_back(move);
    }

    cout << moves.size() << endl;
    for (string s : moves) {
        cout << s << endl;
    }

    return 0;
}