#include <iostream>
using std::cout;
using std::endl;

const unsigned int N = 5;
const int left[N]  = {5, 4, 3, 2, 1}; // command code 1
const int right[N] = {1, 2, 3, 4, 5}; // command code 2
const int back[N]  = {1, 1, 1, 1, 1}; // command code 3
const int meow[N]  = {3, 2, 3, 2, 5}; // command code 4


void recognize(int* data_start, int* data_end, int* command, int** frame){
    *command = 0;
    for(int* i = data_start; i < data_end - N + 1; i += 1){
        for (int* j = i; j < i + N; j += 1){
            if (*(j) != left[j - i]){
                *command = 0;
                break;
            } else {
                *command = 1;
            }
        }
        if (*command != 0) {
            *frame = i;
            break;
        }

        for (int* j = i; j < i+N; j += 1){
            if (*(j) != right[j-i]){
                *command = 0;
                break;
            } else {
                *command = 2;
            }
        }
        if (*command != 0) {
            *frame = i;
            break;
        }

        for (int* j = i; j < i+N; j += 1){
            if (*(j) != back[j-i]){
                *command = 0;
                break;
            } else {
                *command = 3;
            }
        }
        if (*command != 0) {
            *frame = i;
            break;
        }

        for (int* j = i; j < i+N; j += 1){
            if (*(j) != meow[j-i]){
                *command = 0;
                break;
            } else {
                *command = 4;
            }
        }
        if (*command != 0) {
            *frame = i;
            break;
        }
    }
}


int main()
{
    const int L = 21;
    int mindstream[L] = {3, 2, 3, 2, 5, 2, 3, 8, 3, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5};
    int command = -1;
    int* frame = mindstream;
    int* end = mindstream + L;
    while (command)
    {
        recognize(frame, end, &command, &frame);
        if (!command) break;
        switch(command)
        {
            case 1:
                cout << "left ";
                break;
            case 2:
                cout << "right ";
                break;
            case 3:
                cout << "back ";
                break;
            case 4:
                cout << "MEOOOOW ";
                break;
        }
        frame += N;
    }
    cout << endl;
    return 0;
}
