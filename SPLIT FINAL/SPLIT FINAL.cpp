#include <iostream>

using namespace std;

struct nodo {
    int valor;
    nodo* NEXT;
};

nodo* ArrLE(int* arr, int tam) {
    if (tam == 0) {
        nodo* HEAD;
        HEAD = new nodo;
        HEAD->NEXT = NULL;
        return HEAD;
    }
    nodo* HEAD;
    HEAD = new nodo;
    HEAD->valor = *arr;
    nodo* p;
    p = HEAD;
    arr++;
    tam--;

    for (; arr < arr + tam; ++arr, --tam) {
        p->NEXT = new nodo;
        p->NEXT->valor = *arr;
        p = p->NEXT;
        if (arr == arr + (tam - 1))
            p->NEXT = NULL;
    }
    return HEAD;
}


bool multi2(int a) {
    if (a % 2 == 0) {
        return true;
    }
    return false;
}

bool mayor5(int a) {
    if (a >= 15) {
        return true;
    }
    return false;
}

void split(nodo*& A, nodo*& B) {
    bool (*pf[2])(int) = { multi2,mayor5 };
    nodo* t;
    t = A;
    nodo* z;
    z = B;
    bool cabeza = false;

    nodo* ante;
    ante = t;

    while (true) {
        if (t == NULL)
            break;
        else if (pf[0](t->valor) && !cabeza) {
            A = A->NEXT;
            B = t;
            t->NEXT = nullptr;
            t = A;
            cabeza = true;
            z = B;
        }
        else if (!cabeza) {
            cabeza = true;
            ante = t;
            t = t->NEXT;
        }

        else if (pf[1](t->valor) && cabeza) {
            nodo* temp = t->NEXT;
            ante->NEXT = temp;
            z->NEXT = t;
            z = z->NEXT;
            z->NEXT = NULL;

            t = temp;
        }
        else {
            ante = t;
            t = t->NEXT;
        }
    }
}

int main() {
    int a[15] = { 5,3,6,8,9,7,20,15,14,13,21,22,28,26,23 };
    nodo* A;
    A = ArrLE(a, 15);

    nodo* B;
    B = ArrLE(a, 0);

    for (nodo* t = A; t; t = t->NEXT) {
        cout << t->valor << " -> ";
    }
    cout << endl;

    split(A, B);

    for (nodo* t = A; t; t = t->NEXT) {
        cout << t->valor << " -> ";
    }
    cout << endl;
    for (nodo* t = B; t; t = t->NEXT) {
        cout << t->valor << " -> ";
    }
    cout << endl;

}