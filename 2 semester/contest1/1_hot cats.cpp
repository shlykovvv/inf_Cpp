#include <iostream>

int main() {
    int number, boris_len;
    std::cin >> number;
    bool open[30];
    for (bool & i : open) {
        i = true;
    }
    int start;
    int len;
    for (int i = 0; i < number; i++) {
        std::cin >> start;
        std::cin >> len;
        for (int j = start; j < start + len; j++) {
            open[j] = false;
        }
    }
    std::cin >> boris_len;
    bool f;
    int res = -1;
    for (int i = 0; i < 30 - boris_len; i++) {
        f = true;
        for (int j = i; j < i + boris_len; j++) {
            if (!open[j]) {
                f = false;
                break;
            }

        }
        if (f) {
            res = i;
            break;
        }
    }
    std::cout << res;
    return 0;
}
