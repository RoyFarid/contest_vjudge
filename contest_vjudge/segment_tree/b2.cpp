#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define inic ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
        update(pos, val, 1, 0, n - 1);
    }

    int query(int l, int r, int id, int tl, int tr) {
        if (l <= tl && tr <= r) return t[id];
        if (r < tl || tr < l) return 0;
        int tm = (tl + tr) / 2;
        int left = id + 1;
        int right = id + 2 * (tm - tl + 1);
        return combine(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    int query(int l, int r) {
        return query(l, r, 1, 0, n - 1);
    }
} st;

void compress(vector<int> &a) {
    int n = a.size();
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) pairs[i] = {a[i], i};
    sort(pairs.begin(), pairs.end());
    int nxt = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && pairs[i - 1].first != pairs[i].first) nxt++;
        a[pairs[i].second] = nxt;
    }
}

int main() {
    inic;

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

    compress(all_values);

    map<int, int> value_to_index;
    for (int i = 0; i < all_values.size(); i++) {
        value_to_index[all_values[i]] = i;
    }

    st.ini(all_values.size());

    for (int salary : salaries) {
        st.update(value_to_index[salary], 1);
    }

    for (auto &query : queries) {
        char type = query.first;
        int a = query.second.first, b = query.second.second;

        if (type == '!') {
            int k = a - 1;
            int old_val = value_to_index[salaries[k]];
            st.update(old_val, -1);
            salaries[k] = b;
            st.update(value_to_index[b], 1);
        } else {
            int left = lower_bound(all_values.begin(), all_values.end(), a) - all_values.begin();
            int right = upper_bound(all_values.begin(), all_values.end(), b) - all_values.begin() - 1;
            cout << st.query(left, right) << "\n";
        }
    }

    return 0;
}