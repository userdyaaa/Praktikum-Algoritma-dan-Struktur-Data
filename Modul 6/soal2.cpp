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
            cin >> matrix[i][j];
        }
    }

    cout << "Adjacency List:" << endl;

    for (int i = 0; i < n; i++) {
        cout << vertex[i] << " ->";
        
        bool pertama = true; 
        
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) { 
                
                if (pertama == false) {
                    cout << ",";
                }
                
                cout << " (" << vertex[j] << "," << matrix[i][j] << ")";
                pertama = false; 
            }
        }
        
        if (pertama == true) {
            cout << " -";
        }
        
        cout << endl;
    }

    return 0;
}