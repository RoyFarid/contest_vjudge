#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);

int combine(int x, int y) {
    return x + y;
}

struct SegmentTree {
    vector<int> t;
    int n;

    void ini(int size) {
        n = size;
        t.assign(2 * n, 0);
    }

    void update(int pos, int val, int id, int tl, int tr) {
        if (tl == tr) {
            t[id] += val;
        } else {
            int tm = (tl + tr) / 2;
            int left = id + 1;
            int right = id + 2 * (tm - tl + 1);
            if (pos <= tm) {
                update(pos, val, left, tl, tm);
            } else {
                update(pos, val, right, tm + 1, tr);
            }
            t[id] = combine(t[left], t[right]);
        }
    }

    void update(int pos, int val) {
        assert(n > 0);
        update(pos, val, 1, 0, n - 1);
    }

    int query(int l, int r, int id, int tl, int tr) {
        if (l <= tl && tr <= r) return t[id];
        int tm = (tl + tr) / 2;
        int left = id + 1;
        int right = id + 2 * (tm - tl + 1);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return combine(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    int query(int l, int r) {
        assert(n > 0);
        return query(l, r, 1, 0, n - 1);
    }

} st;

int main() {
    inic;
    inic1;
    inic2;
    int n, q;
    cin >> n >> q;

    vector<int> salaries(n);
    vector<pair<char, pair<int, int>>> queries(q);
    vector<int> all_values;

    for (int i = 0; i < n; i++) {
        cin >> salaries[i];
        all_values.push_back(salaries[i]);
    }

    for (int i = 0; i < q; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;
        queries[i] = {type, {a, b}};
        if (type == '!') {
            all_values.push_back(b);
        } else {
            all_values.push_back(a);
            all_values.push_back(b);
        }
    }
    sort(all_values.begin(),all_values.end());
    vector <int> unique_values;
    unique_values.push_back(all_values[0]);
    int sz = all_values.size();
    for(int i = 1; i < sz; i++) {
        if(all_values[i] != all_values[i-1]) {
            unique_values.push_back(all_values[i]);
        }
    }
    int m = unique_values.size();
    map<int, int> value_to_index;
    for (int i = 0; i < m; i++) {
        value_to_index[unique_values[i]] = i;
    }

    st.ini(m);

    for (int salary : salaries) {
        int h = value_to_index[salary];
        st.update(h, 1);
    }

    for (auto &query : queries) {
        char type = query.first;            
        int a = query.second.first;          
        int b = query.second.second;          

        if (type == '!') {
            int k = a;
            int x = b;
            k--;
            int f  = value_to_index[salaries[k]];
            st.update(f, -1);
            salaries[k] = x;
            int g = value_to_index[x];
            st.update(g, 1);
        } else {
            int l = a;
            int r = b;
            int left = value_to_index[l];
            int right = value_to_index[r];
            cout << st.query(left, right) << "\n";
        }
    }
    return 0;
}
