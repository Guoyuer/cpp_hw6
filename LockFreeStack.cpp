#include "LockFreeStack.h"
#include <iostream>

using namespace std;


int main() {
    mpcs51044::Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

}