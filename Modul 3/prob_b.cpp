#include <iostream>
#include "double_linked_list.h" 

using namespace std;

int main() {
    DoubleLinkedList dll;
    dll.init();

    int N, R;
    cin >> N >> R;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        dll.add_back(c); 
    }

    int alpha_idx = 0;      
    int beta_idx = N - 1;   

    for (int i = 0; i < R; i++) {
        long long X, Y;
        cin >> X >> Y;

        if (N == 0) continue; 

        long long X_mod = X % N;
        long long Y_mod = Y % N;

        alpha_idx = (alpha_idx + X_mod) % N;
        beta_idx = ((beta_idx - Y_mod) % N + N) % N;

        if (alpha_idx == beta_idx) {
            int del_idx = alpha_idx;
            
            dll.delete_idx(del_idx);
            N--; 
            
            if (N > 0) {
                alpha_idx = del_idx % N;
                beta_idx = ((del_idx - 1) % N + N) % N;
            }
        } 
        else {
            int jarak = alpha_idx - beta_idx;
            if (jarak < 0) {
                jarak = -jarak; 
            }

            if (jarak == 1) {
                char charA = dll.get(alpha_idx);
                char charB = dll.get(beta_idx);
                
                dll.set(charB, alpha_idx);
                dll.set(charA, beta_idx);
            }
        }
    }

    if (N == 0 || dll.is_empty()) {
        cout << "EMPTY\n";
    } else {
        Node* curr = dll.head;
        if (curr != nullptr) {
            do { 
                cout << curr->data; 
                curr = curr->next;
            } while (curr != dll.head);
        }
        cout << "\n";
    }

    dll.clear();
    return 0;
}