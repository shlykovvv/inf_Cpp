#include <iostream>

//Пирамидальная сортировка
//Сложность O(n*log(n))
//Память O(1)
//Cначала строится пирамида из элементов исходного массива, а затем осуществляется сортировка элементов
//неустойчивый

void heapify(int mas[], int n, int i) {
    int largest = i;
    int l = 2*i + 1; // left
    int r = 2*i + 2; // right

    if (l < n && mas[l] > mas[largest])
        largest = l;
    if (r < n && mas[r] > mas[largest])
        largest = r;
    if (largest != i) {
        std::swap(mas[i], mas[largest]);
        heapify(mas, n, largest);
    }
}

void heapsort(int mas[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(mas, n, i);
    for (int i=n-1; i>=0; i--) {
        std::swap(mas[0], mas[i]);
        heapify(mas, i, 0);
    }
}

int main() {
    int A[] = {3, 2, 3, 2, 5, 2};
    heapsort(A, 6);
    for (int i : A) {
        std::cout << i;
    }
    return 0;
}

