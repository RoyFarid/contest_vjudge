#include <bits/stdc++.h>
#define pb push_back
#define sl '\n'
using namespace std;
using ll = long long;

const int MX = 105;

int tamanio[MX], lider[MX], minimo[MX];
int find_lider(int nodo) {
    if (lider[nodo] == nodo) {
        return nodo;
    }
    lider[nodo] = find_lider(lider[nodo]);
    return lider[nodo];
}
void join(int nodo_a, int nodo_b) {
    nodo_a = find_lider(nodo_a);
    nodo_b = find_lider(nodo_b);
    if (nodo_a != nodo_b) {
        if (tamanio[nodo_a] >= tamanio[nodo_b]) {
            tamanio[nodo_a] += tamanio[nodo_b];
            lider[nodo_b] = nodo_a;
        } else {
            tamanio[nodo_b] += tamanio[nodo_a];
            lider[nodo_a] = nodo_b;
        }
    }
}

int valores[MX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    fill(tamanio, tamanio + n + 1, 1);
    iota(lider, lider + n + 1, 0);
    for (int i = 1; i <= n; i++) {
        valores[i] = i;
    }
    
    vector <int> perm(n + 1), fav(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> perm[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> fav[i];
    }

    for (int i = 1; i <= n; i++) {
        int d = fav[i];
        // 1 <= |i-j| = di <= n
        if(i + d <= n) {
            join(i, i + d);
        }
        if(i - d >= 1) {
            join (i, i-d);
        }
    }

    map<int, multiset<int>> val_orig;
    map<int, multiset<int>> val_perm;
    
    for (int i = 1; i <= n; i++) {
        int l = find_lider(i);
        val_orig[l].insert(i);       
        val_perm[l].insert(perm[i]);
    }

    bool f = true;
    for (auto grupo : val_orig) {
        int l = grupo.first;
        if (val_orig[l] != val_perm[l]) {
            f = false;
            break;
        }
    }
    if(f) cout << "YES";
    else cout << "NO";
    return 0;
}