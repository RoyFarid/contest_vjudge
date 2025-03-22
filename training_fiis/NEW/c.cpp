#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
vector<int> adj[MAX_N + 1];
vector<int> likes(MAX_N + 1);
vector<int> maxPhotos(MAX_N + 1, 0);

void dfs(int node, int parent, vector<int>& lis) {
    int pos = lower_bound(lis.begin(), lis.end(), likes[node]) - lis.begin();
    int originalValue = -1;
    bool replaced = (pos < lis.size());
    
    if (replaced) {
        originalValue = lis[pos];
        lis[pos] = likes[node];
    } else {
        lis.push_back(likes[node]);
    }
    
    maxPhotos[node] = lis.size();
    
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, lis);
        }
    }
    
    if (replaced) {
        lis[pos] = originalValue;
    } else {
        lis.pop_back();
    }
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 2; i <= N; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    
    for (int i = 1; i <= N; ++i) {
        cin >> likes[i];
    }
    
    vector<int> lis;
    dfs(1, -1, lis);
    
    for (int i = 2; i <= N; ++i) {
        cout << maxPhotos[i] << " ";
    }
    cout << endl;
    
    return 0;
}

