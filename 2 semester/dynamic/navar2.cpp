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
    std::vector<std::vector<std::vector<int> > > sequence;
    sequence.resize(table_size);
    for (int i = 0; i < table_size; ++i) {
        sequence[i].resize(L0+1);
    }

    for (int i = 1; i < table_size; i++){
        for (int c = 0; c <= L0; c++){
            if (c <= len[i] - 1){
                profit[i][c] = profit[i - 1][c];
            }
            if (c >= len[i]){
                if (profit[i][c - len[i]] + price[i] > profit[i - 1][c]){
                    profit[i][c] = profit[i][c - len[i]] + price[i];
                    for (int k = 0; k < sequence[i][c - len[i]].size(); k++){
                        sequence[i][c].push_back(sequence[i][c - len[i]][k]);
                    }
                    sequence[i][c].push_back(len[i]);
                } else{
                    profit[i][c] = profit[i - 1][c];
                    for (int k = 0; k < sequence[i - 1][c].size(); k++){
                        //std::cout << 'p';
                        sequence[i][c].push_back(sequence[i - 1][c][k]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < sequence[table_size - 1][L0].size(); i++){
        std::cout << sequence[table_size - 1][L0][i] << ' ';
    }
    delete[] price;
    delete[] len;
    for (int i = 0; i < table_size; ++i){
        delete[] profit[i];
    }
    delete[] profit;
}
