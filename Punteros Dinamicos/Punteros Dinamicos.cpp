/*
#include <iostream>

using namespace std;

struct nodo {
    int valor;
    nodo* NEXT;
    nodo* PREV;
};

nodo* Arr(int* arr, int tam) {
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

void ArrtoLE(int* arr, int tam, nodo*& HEAD, nodo*& TAIL) {
    nodo* p;
    p = new nodo;
    p->valor = *arr;
    p->PREV = NULL;

    arr++;
    tam--;
    HEAD = p;
    for (; arr < arr + tam; ++arr, --tam) {
        TAIL = p;
        p->NEXT = new nodo;
        p->NEXT->valor = *arr;
        p = p->NEXT;
        p->PREV = TAIL;
        if (arr == arr + (tam - 1))
            p->NEXT = NULL;
    }
    TAIL = p;
}

int main(){
    int valores[5] = { 5,9,7,6,3 };

    nodo* HEAD;
    //HEAD = Arr(valores, 5);
    
    nodo* TAIL;
    ArrtoLE(valores, 5, HEAD, TAIL);
    for (nodo *t = HEAD; t; t = t->NEXT) {
        cout << t->valor << "->";
    }
    cout << endl;
    for (nodo* t = TAIL; t; t = t->PREV) {
        cout << t->valor << "->";
    }

}*/

#include <iostream>

using namespace std;

bool par(int a) {
    return(a % 2 == 0);
}

bool inpar(int a) {
    return(a % 2 != 0);
}

void SPLIT(int* init, int* fin, bool (*pf)(int)) {
    int* apoyo;
    while (init != fin) {
        if (pf(*init)) {
            init++;
        }
        else {
            apoyo = init + 1;
            while ((!pf(*apoyo)) && (apoyo < fin + 1)) {
                apoyo++;
            }
            if (apoyo > fin)
                break;
            swap(*init, *apoyo);
            init++;
            swap(*init, *apoyo);
        }
    }
    for (; init < fin; init++) {
        for (int* a = init + 1; a <= fin; a++) {
            if (*a < *init)
                swap(*init, *a);
        }
    }
}

int main() {
    int numeros[12] = { 1,2,6,7,9,11,13,14,18,19,20,22 };
    SPLIT(&numeros[0], &numeros[11], inpar);

    for (int i = 0; i < 12; i++)
        cout << numeros[i] << " ";
    cout << endl;

}