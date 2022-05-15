#include <iostream>

//Сортировка выбором
//Сложность O(n^2)
//Память O(1)
//Ищет минимальный элемент, ставит его на первое место, повторяет операцию с оставшимися n-1 элементами
//Неустойчивая реализация. Для устойчивости нужно не менять местами минимальный элемент (А) с тем, кто занимает
    //его позицию (Б), а производить сдвиг всех элементов от Б до А, что скажется на производительности

void select_sort(int *mas, int size) {
    int count, key;
    for (int i = 0; i < size - 1; i++) {
        count = mas[i];
        key = i;
        for (int j = i + 1; j < size; j++)
            if (mas[j] < mas[key]) key=j;
        if (key != i) {
            mas[i] = mas[key];
            mas[key] = count;
        }
    }
}

int main() {
    int A[] = {3, 2, 3, 2, 5, 2};
    int *start = A;
    select_sort(start, 6);
    for (int i : A) {
        std::cout << i;
    }
    return 0;
}
