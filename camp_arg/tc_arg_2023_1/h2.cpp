#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 26;
vector<vector<int>> P(ALPHABET_SIZE, vector<int>(ALPHABET_SIZE));

int main() {
    // Leer la matriz de costos
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            cin >> P[i][j];
        }
    }

    // Leer el nickname
    string nickname;
    cin >> nickname;

    int n = nickname.size();
    int totalCost = 0;

    // Convertir el nickname en un palíndromo con el menor costo
    for (int i = 0; i < n / 2; i++) {
        char leftChar = nickname[i];
        char rightChar = nickname[n - 1 - i];

        if (leftChar != rightChar) {
            int minCost = 1e6; // Un valor grande para encontrar el mínimo

            // Probar todas las letras del alfabeto y ver cuál da menor costo
            for (char newChar = 'a'; newChar <= 'z'; newChar++) {
                int cost = P[leftChar - 'a'][newChar - 'a'] + P[rightChar - 'a'][newChar - 'a'];
                minCost = min(minCost, cost);
            }

            totalCost += minCost;
        }
    }

    // Imprimir el costo mínimo total
    cout << totalCost << endl;
    return 0;
}