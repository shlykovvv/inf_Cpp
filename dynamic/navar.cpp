#include <iostream>
#include <vector>

int main(){
    int table_size, L0;
    std::cin >> table_size;
    int* price = new int[table_size];
    int* len = new int[table_size];
    std::cin >> L0;
    int** profit = new int* [table_size];
    for (int i = 0; i < table_size; i++){
        std::cin >> len[i];
    }
    for (int i = 0; i < table_size; i++){
        std::cin >> price[i];
    }
    for (int i = 0; i < table_size; ++i){
        profit[i] = new int[L0 + 1];
    }
    for (int j = 0; j < L0; j++){
        profit[0][j] = 0;
    }

    for (int i = 1; i < table_size; i++){
        for (int c = 0; c <= L0; c++){
            if (c <= len[i] - 1){
                profit[i][c] = profit[i - 1][c];
            }
            if (c >= len[i]){
                profit[i][c] = std::max(profit[i - 1][c], profit[i][c - len[i]] + price[i]);
            }
        }
    }
    std::cout << profit[table_size - 1][L0];
    delete[] price;
    delete[] len;
    for (int i = 0; i < table_size; ++i){
        delete[] profit[i];
    }
    delete[] profit;
}