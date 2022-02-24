#include <iostream>

using namespace std;

typedef int (*Func_Ptr)(int);

class Counter {
private:

    Func_Ptr *funcs;

    int *times_called;
public:
    Counter(int num) {
        funcs = new Func_Ptr[num]();
        times_called = new int[num]();// () is for init to zero
    }


    int get_times_called(int id) {
        return times_called[id];
    }

    int call(int id, int x) {
        times_called[id]++;
        return funcs[id](x);
    }

    void set(int id, int (*func)(int)) {
        funcs[id] = func;
    }

    ~Counter() {
        delete times_called;
        delete funcs;
    }


};

int times2(int x) {
    return 2 * x;
}


int times3(int x) {
    return 3 * x;
}

int main() {
    Counter cnt(2);
    cnt.set(0, times2);
    cnt.set(1, times3);
    cout << cnt.call(0, 2) << endl;
    cout << cnt.call(0, 4) << endl;
    cout << cnt.call(0, 6) << endl;
    cout << cnt.call(1, 8) << endl;
    cout << cnt.call(1, 10) << endl;
    cout << cnt.get_times_called(0) << endl;
    cout << cnt.get_times_called(1) << endl;
}