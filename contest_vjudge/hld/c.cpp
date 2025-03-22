#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
const int MX = 2e5 + 1;

vector<int> adj[MX];
int distA[MX], distB[MX];

// BFS para encontrar el nodo más lejano y sus distancias
pair<int, int*> bfs(int start, int n, int* dist) {
    queue<int> q;
    fill(dist, dist + n + 1, -1);
    q.push(start);
    dist[start] = 0;
    int farthest = start;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > dist[farthest]) farthest = v;
            }
        }
    }
    return {farthest, dist};
}

// Calcula la distancia máxima desde cada nodo
void calculate_max_distances(int n) {
    int tempDistA[MX], tempDistB[MX];

    // Encontrar el nodo A más alejado de 1
    pair<int, int*> resA = bfs(1, n, tempDistA);
    int A = resA.first;
    int* distFromA = resA.second;

    // Encontrar el nodo B más alejado de A
    pair<int, int*> resB = bfs(A, n, tempDistB);
    int B = resB.first;
    int* distFromB = resB.second;

    // Copiar las distancias en arreglos globales
    copy(tempDistA, tempDistA + n + 1, distA);
    copy(tempDistB, tempDistB + n + 1, distB);

    // Calcular la distancia desde B nuevamente
    pair<int, int*> resB_final = bfs(B, n, tempDistB);
    int* distFromB_final = resB_final.second;

    // Imprimir la distancia máxima para cada nodo
    for (int i = 1; i <= n; i++) {
        cout << max(distA[i], distFromB_final[i]) << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    calculate_max_distances(n);
    
    return 0;
}
