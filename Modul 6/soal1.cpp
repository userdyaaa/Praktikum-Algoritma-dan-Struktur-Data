#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    char vertex[10];
    for (int i = 0; i < n; i++) {
        cin >> vertex[i];
    }

    int matrix[10][10];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;

        int indeks_u = -1;
        for (int j = 0; j < n; j++) {
            if (vertex[j] == u) {
                indeks_u = j;
                break;
            }
        }

        int indeks_v = -1;
        for (int j = 0; j < n; j++) {
            if (vertex[j] == v) {
                indeks_v = j;
                break;
            }
        }

        if (indeks_u != -1 && indeks_v != -1) {
            matrix[indeks_u][indeks_v] = w;
        }
    }

    cout << "Adjacency Matrix:" << endl;

    cout << " ";
    for (int i = 0; i < n; i++) {
        cout << " " << vertex[i];
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << vertex[i];
        
        for (int j = 0; j < n; j++) {
            cout << " " << matrix[i][j];
        }
        cout << endl; 
    }

    return 0;
}