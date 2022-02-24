#include <iostream>
#include <cstring>

using namespace std;


class A {
public:
    int foo;

    int bar(int *x) {
        cout << "A::bar gets called, parameter is " << *x << endl;
        return 2 * *x;
    }

    int bar1(double (*func)(float &x)) {
        float tmp = 8.8f;
        func(tmp);
        cout << "A::bar1 gets called" << endl;
        return 0;
    }
};

int func1() {
    cout << "func1 gets called" << endl;
    return 0;
}


char *func2(char *a, char *b) {
    cout << "func2 gets called" << endl;
    if (strlen(a) >= strlen(b)) {
        return a;
    }
    return b;
}

double func3(float &x) {
    cout << "func3 gets called, parameter is " << x << endl;
    return x;
}

void func4() {
    cout << "func4 gets called" << endl;
}

void f0(void(*func)()) {
    func();
}

void f1(void(*func)()) {
    func();
}

int main() {

    int tmp1 = 5;
    /* int * */
    int *p1 = &tmp1;

    /* int & */
    int &p2(tmp1);
    cout << p2 << endl;

    /* double */
    double p3 = 5.6;

    /* A* */
    A *p4 = new A();

    /* char const * */
    char const *p5 = "12345";

    /* char const & */
    char tmp2 = 'x';
    char const &p6(tmp2);

    /* long[7] */
    long p7[7] = {1, 2, 3, 4, 5, 6, 7};
    for (long i: p7)
        cout << i << " ";

    /* int** */
    int rowCnt = 5;
    int colCnt = 3;
    int **p8 = new int *[rowCnt];
    for (int i = 0; i < rowCnt; i++) {
        p8[i] = new int[colCnt];
    }
    for (int i = 0; i < rowCnt; i++) {
        for (int j = 0; j < colCnt; j++) {
            p8[i][j] = i + j;
        }
    }

    /* int *&: p1 reference to p1 pointer */
    int *&p9(p1);
    cout << *p9 << endl;

    /* float & */
    float tmp3 = 1.2f;
    float &p10(tmp3);
    cout << p10 << endl;

    /* int(*)() */
    int (*p11)() = &func1;
    p11();

    /* int(*&)(): p1 reference to p1 function pointer*/
    int (*&p12)()(p11);
    p12();

    /* char *(*)(char *, char *) */
    char *(*p13)(char *, char *) = &func2;
    char tmp4[30] = "short";
    char tmp5[20] = "longer string";

    cout << p13(tmp4, tmp5) << endl;

    /* int A::* */
    int A::*p14 = &A::foo;
    p4->*p14 = 5;

    /* int A::*(int *) */
    int (A::*p15)(int *) = &A::bar;
    (p4->*p15)(p1);

    /* int (A::**)(int *) */
    int (A::* *p16)(int *) = &p15;
    (p4->**p16)(p1);

    /* int (A::*&)(int *) */
    int (A::* &p17)(int *)(p15);
    (p4->*p17)(p1);

    /* int (A::*)(double (*)(float &))  */
    int (A::*p18)(double (*)(float &)) = &A::bar1;
    (p4->*p18)(&func3);

    /* void (*p[10]) (void (*)()) */
    void (*p19[10])(void (*)());

    p19[0] = f0;
    p19[1] = f1;
    p19[0](func4);
    p19[1](func4);

}