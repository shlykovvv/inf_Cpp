#include <iostream>
#include <cmath>

int binsearch() {
    int max, k, min = 0, xxx;
    std::cin >> max;
    int arr[max];
    for (int i = 0; i < max;
         i++) {
        std::cin >> arr[i];
    }
    std::cin >> k;

    while ((arr[min] != k) and (arr[max] != k)) {
        if (k < arr[(max + min) / 2]) {
            max = (max + min) / 2;
        } else {
            min = (max + min) / 2;
        }
        if (max - min == 1) {
            break;
        }
    }
    if (arr[min] == k) {
        xxx = min;
        std::cout << xxx;
    } else {
        if (arr[max] == k) {
            xxx = max;
            std::cout << xxx;
        } else {
            std::cout << "no element like this";
        }
    }
    return xxx;
}

int main() {
    binsearch();

    return 0;
}