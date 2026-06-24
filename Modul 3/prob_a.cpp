#include "single_linked_list.h"
#include <iostream>

using namespace std;

int main() {
    SingleLinkedList sll;
    sll.init();

    int N;
    long long K; 
    cin >> N >> K;

    long long K_awal = K;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        sll.add_back(x);
    }

    int jumlah = N;
    int idx_sekarang = 0; 

    while (jumlah > 1) {
        int idx_target = (idx_sekarang + K - 1) % jumlah;
        int nilai_batu = sll.get(idx_target);

        sll.delete_idx(idx_target);
        jumlah--;

        if (nilai_batu % 2 == 0) {
            K++;
        } else {
            K--;
        }

        if (K <= 0) {
            K = K_awal;
        }

        if (jumlah > 0) {
            idx_sekarang = idx_target % jumlah;
        }
    }

    cout << sll.get(0) << endl;

    sll.clear();

    return 0;
}