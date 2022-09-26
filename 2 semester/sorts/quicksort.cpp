#include <iostream>


void qsort(int *mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];

    do {
        while(mas[i] < mid) {
            i++;
        }
        while(mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            int t = mas[i];
            mas[i] = mas[j];
            mas[j] = t;
            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) {
        qsort(mas, j + 1);
    }
    if (i < size) {
        qsort(&mas[i], size - i);
    }
}

int main() {
    int A[] = {3, 2, 3, 2, 5, 2};
    int *start = A;
    qsort(start, 6);
    for (int i : A) {
        std::cout << i;
    }
    return 0;
}
