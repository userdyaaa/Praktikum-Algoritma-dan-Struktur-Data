#include <iostream>
#include <string>
#include "RedBlackTree.h" 

using namespace std;

void cetakPreorder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    cout << node->key << " ";
    cetakPreorder(node->left);
    cetakPreorder(node->right);
}

void cetakInorder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    cetakInorder(node->left);
    cout << node->key << " ";
    cetakInorder(node->right);
}

void cetakPostorder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    cetakPostorder(node->left);
    cetakPostorder(node->right);
    cout << node->key << " ";
}

int main() {
    RedBlackTree pohon; 

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int angka;
        cin >> angka;
        pohon.insert(angka); 
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string perintah;
        cin >> perintah;

        if (pohon.empty()) { 
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
        } 
        else {
            if (perintah == "PREORDER") {
                cout << "[Preorder]  : ";
                cetakPreorder(pohon.root());
                cout << "\n";
            } 
            else if (perintah == "INORDER") {
                cout << "[Inorder]   : ";
                cetakInorder(pohon.root());
                cout << "\n";
            } 
            else if (perintah == "POSTORDER") {
                cout << "[Postorder] : ";
                cetakPostorder(pohon.root());
                cout << "\n";
            } 
            else if (perintah == "ALL") {
                cout << "[Preorder]  : ";
                cetakPreorder(pohon.root());
                cout << "\n";
                
                cout << "[Inorder]   : ";
                cetakInorder(pohon.root());
                cout << "\n";
                
                cout << "[Postorder] : ";
                cetakPostorder(pohon.root());
                cout << "\n";
            }
        }
    }

    return 0;
}