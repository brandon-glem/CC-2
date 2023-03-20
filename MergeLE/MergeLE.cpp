#include <iostream>

using namespace std;

struct nodo {
    int valor;
    nodo* NEXT;
};

nodo* ArrLE(int* arr, int tam) {
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

void merge(nodo*& A, nodo*& B) {
    bool cabeza = false;
    nodo* t = A;
    nodo* v = B;
    nodo* z = t;

    while (true) {
        if ((t == NULL) && (v != NULL)) {
            A = t;
            break;
        }
        else if (v == NULL) {
            B = v;
            break;
        }
        else if ((B->valor < A->valor) && !cabeza) {
            B = B->NEXT;
            A = v;
            A->NEXT = t;
            cabeza = true;
            t = A;
            z = t;
            v = B;
        }
        else if ((B->valor > A->valor) && !cabeza) {
            cabeza = true;
            z = t;
        }
        else if (z == NULL) {
            t->NEXT = v;
            break;
        }

        else if (z->valor <= v->valor) {
            t = z;
            z = z->NEXT;
        }
        else {
            nodo* temp = v;
            v = v->NEXT;
            t->NEXT = temp;
            temp->NEXT = z;
            t = t->NEXT;
        }
    }
}

int main() {
    int a[5] = { 1,3,5,7,9 };
    int b[10] = { 0,1,1,2,3,5,8,13,21,34};

    nodo* A;
    nodo* B;
    A = ArrLE(a, 5);
    B = ArrLE(b, 10);

    merge(B, A);

    for (nodo* t=B; t; t = t->NEXT) {
        cout << t->valor << " -> ";
    }
    cout << endl;
}