#include <iostream>
#include <string>
#include <stdexcept>
#include "stack.h"

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    Stack s;
    init(&s); 
    
    for (int i = 0; i < n; i++) {
        string simbol;
        cin >> simbol;
        
        if (simbol == "+" || simbol == "-" || simbol == "*" || simbol == "/") {
            int b = peek(&s); pop(&s);
            int a = peek(&s); pop(&s);
            
            if (simbol == "+") push(&s, a + b);
            else if (simbol == "-") push(&s, a - b);
            else if (simbol == "*") push(&s, a * b);
            else if (simbol == "/") push(&s, a / b);
        } else {
            push(&s, stoi(simbol));
        }
    }
    
    cout << peek(&s) << endl;
    
    return 0;
}