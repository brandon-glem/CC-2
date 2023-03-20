#include <iostream>
using namespace std;

int main() {
    cout.precision(5);
    float matriz[3][4] = { {2,-2,1,-3},{1,3,-2,1},{3,-1,-1,2} };

    int hor = 0;

    if (**matriz != 1) {
        float(*p)[4] = matriz;
        if (*(*(matriz + 1)) == 1) {
            float(*q)[4] = matriz + 1;
            swap(*p, *q);
        }
        else if (*(*(matriz + 2)) == 1) {
            float(*q)[4] = matriz + 2;
            swap(*p, *q);
        }
    }

    for (float(*p)[4] = matriz; p < matriz + 3; *p++) {
        if (**p == 0 && *(*p + 1) == 0 && *(*p + 2) == 0) {
            cout << "El sistema no tiene solucion" << endl;
            return 0;
        }

        if (**p != 1) {
            hor++;
        }
        float* n = (*p) + hor;
        if (*n != 1) {
            float uni = *n;
            for (; n < *(p + 1); n++) {
                *n *= 1.0 / uni;
            }
        }
        float inv = -(*(*(p + 1) + hor));
        for (float* q = (*p) + hor, *r = *(p + 1) + hor; r < *(matriz + 3); q++, r++) {
            if (q >= *(p + 1)) {
                q = *p;
                inv = -(*r);
            }
            *r = inv * (*q) + (*r);
        }
    }

    for (float(*p)[4] = matriz; p < matriz + 3; p++) {
        for (float* q = *p; q < *(p + 1); q++)
            cout << *q << "\t";
        cout << "\n";
    }

    float z;
    float y;
    float x;
    for (float(*p)[4] = matriz + 2; p > matriz - 1; p--) {
        if (**p == 0 && *(*p + 1) == 0) {
            z = *(*p + 3) / (*(*p + 2));
        }
        else if (**p == 0 && *(*p + 1) == 1) {
            y = (*(*p + 3) - (*(*p + 2) * z)) / *(*p + 1);
        }
        else {
            x = (*(*p + 3) - (*(*p + 1) * y) - (*(*p + 2) * z)) / **p;
        }
    }
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}