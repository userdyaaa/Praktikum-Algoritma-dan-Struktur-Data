#include <iostream>
#include <queue> 

using namespace std;

struct Koordinat {
    int baris;
    int kolom;
};

int main() {
    int r, c;
    cin >> r >> c;

    int grid[105][105];
    int jarak[105][105];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            jarak[i][j] = -1; 
        }
    }

    int start_r, start_c;
    cin >> start_r >> start_c;

    int finish_r, finish_c;
    cin >> finish_r >> finish_c;

    queue<Koordinat> antrean;

    antrean.push({start_r, start_c});
    jarak[start_r][start_c] = 0; 

    int arah_baris[] = {-1, 1, 0, 0};
    int arah_kolom[] = {0, 0, -1, 1};

    while (!antrean.empty()) {
        Koordinat current = antrean.front();
        antrean.pop();

        if (current.baris == finish_r && current.kolom == finish_c) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int next_baris = current.baris + arah_baris[i];
            int next_kolom = current.kolom + arah_kolom[i];

            if (next_baris >= 0 && next_baris < r &&
                next_kolom >= 0 && next_kolom < c &&
                grid[next_baris][next_kolom] == 0 &&
                jarak[next_baris][next_kolom] == -1) {

                jarak[next_baris][next_kolom] = jarak[current.baris][current.kolom] + 1;
                antrean.push({next_baris, next_kolom});
            }
        }
    }

    cout << jarak[finish_r][finish_c] << "\n";

    return 0;
}