#include <iostream>
using namespace std;

int r, c;
int grid[10][10]; 
bool visited[10][10]; 
int finish_r, finish_c;
int total_jalur = 0; 

int arah_baris[] = {-1, 1, 0, 0};
int arah_kolom[] = {0, 0, -1, 1};

void dfs(int current_baris, int current_kolom) {
    if (current_baris == finish_r && current_kolom == finish_c) {
        total_jalur++; 
        return; 
    }

    visited[current_baris][current_kolom] = true;

    for (int i = 0; i < 4; i++) {
        int next_baris = current_baris + arah_baris[i];
        int next_kolom = current_kolom + arah_kolom[i];

        if (next_baris >= 0 && next_baris < r &&
            next_kolom >= 0 && next_kolom < c &&
            grid[next_baris][next_kolom] == 0 &&
            visited[next_baris][next_kolom] == false) {
            
            dfs(next_baris, next_kolom);
        }
    }

    visited[current_baris][current_kolom] = false;
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            visited[i][j] = false; 
        }
    }

    int start_r, start_c;
    cin >> start_r >> start_c;
    cin >> finish_r >> finish_c;

    dfs(start_r, start_c);
    cout << total_jalur << "\n";

    return 0;
}