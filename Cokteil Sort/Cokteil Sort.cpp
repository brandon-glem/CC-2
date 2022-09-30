#include <iostream>

using namespace std;

void cocktail_sort(int* inicio, int* final) {
    bool cambio = true;
    while (cambio) {
        cambio = false;

        for (int* i = inicio; i < final; i++) {
            if (*i > *(i + 1)) {
                swap(*i, *(i + 1));
                cambio = true;
            }
        }

        if (!cambio)
            break;
        final--;

        for (int* i = final-1; i >= inicio; i--) {
            if (*i > *(i + 1)) {
                swap(*i, *(i + 1));
                cambio = true;
            }
        }

        inicio++;
    }
}

int main(){

    int arr[10] = {2,4,6,8,10,1,3,5,7,9};

    for (int* i = arr; i < arr + 10; i++)
        cout << *i << " ";
    cout << endl;

    cocktail_sort(arr, arr + 9);

    for (int* i = arr; i < arr + 10; i++)
        cout << *i << " ";
    cout << endl;
}
