#include <iostream>
#include <cmath>
#include <random>


int randint(int min, int max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

void Check(int width, int height, int &num, int x_coord[], int y_coord[], int x_mem[], int y_mem[], bool stopped[]) {
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if ((abs(x_coord[i] - x_coord[j]) + abs(y_coord[i] - y_coord[j]) <= 1)) {
                if (x_coord[i] == x_coord[j]) {
                    x_coord[j] = x_mem[j];
                    y_coord[j] = y_mem[j];
                }
                stopped[i] = true;
                stopped[j] = true;
            }
        }
        if ((x_coord[i] == 0) or (x_coord[i] == width - 1)) {
            stopped[i] = true;
        }
    }
}


void create_coords(int num, int width, int height, int x_coord[], int y_coord[]){
    int x_rand;
    int y_rand;
    bool flag_1, flag_2;

    for (int i = 0; i <= num - 1; i += 1) {
        flag_1 = true;
        while(flag_1){
            flag_2 = false;
            x_rand = randint(0, width - 1);
            y_rand = randint(0, height - 1);
            for (int j = 0; j <= num - 1; j += 1){
                if ((x_coord[j] == x_rand) and (y_coord[j] == y_rand)){
                    flag_2 = true;
                }
                if(flag_2){
                    flag_1 = true;
                }
                else{
                    flag_1 = false;
                }
            }
        }
        x_coord[i] = x_rand;
        y_coord[i] = y_rand;
    }
}


int model(int width, int height, int num, int x_coord[], int y_coord[]) {
    int time = 0, rnd_number;
    int x_mem[num];
    int y_mem[num];
    bool all_stopped = true;
    bool stopped[num];
    for (int i = 0; i < num; i++) {stopped[i] = false;}
    int visual[width * height];
    for (int i = 0; i < width * height; i++) {
        visual[i] = 1;
    }

    for (int i = 0; i < num; i++) {
        visual[y_coord[i] * width + x_coord[i]] = 0;
    }
//    for (int i = 0; i < height; i++) {
//        for (int j = 0; j < width; j++) {
//            std::cout << visual[i * width + j] << " ";
//        }
//        std::cout << std::endl;
//    }
    //std::cout << std::endl;

    Check(width, height, num, x_coord, y_coord, x_mem, y_mem, stopped);
    all_stopped = true;
    for (int i = 0; i < num; i++) {
        if (not stopped[i]) {
            all_stopped = false;
        }
    }

    while (not all_stopped) {
        time++;
        for (int i = 0; i < num; i++) {
            x_mem[i] = x_coord[i];
            y_mem[i] = y_coord[i];
        }
        for (int i = 0; i < num; i++) {
            if (not stopped[i]) {
                rnd_number = randint(0,1);
                if (rnd_number == 0) { x_coord[i]++; }
                if (rnd_number == 2) { y_coord[i]++; }
                if (rnd_number == 1) { x_coord[i]--; }
                if (rnd_number == 3) { y_coord[i]--; }
            }
        }
        Check(width, height, num, x_coord, y_coord, x_mem, y_mem, stopped);
        all_stopped = true;
        for (int i = 0; i < num; i++) {
            if (not stopped[i]) {
                all_stopped = false;
            }
        }

        for (int i = 0; i < width * height; i++) {
            visual[i] = 1;
        }
        for (int i = 0; i < num; i++) {
            visual[y_coord[i] * width + x_coord[i]] = 0;
        }
//        for (int i = 0; i < height; i++) {
//            for (int j = 0; j < width; j++) {
//                std::cout << visual[i * width + j] << " ";
//            }
//            std::cout << std::endl;
//        }
        //std::cout << std::endl;
    }
//    std::cout << time << std::endl;
    return time;
}


void calc(int dimension, int accuracy) {
    int num;
    int time_sum;
    int dots_max = dimension;
    int x_coord[dots_max];
    int y_coord[dots_max];

    for(int i = 1; i <= dimension * 0.6; i += 1){
        num = i;
        time_sum = 0;
        for(int j = 0; j < accuracy; j++) {
            create_coords(num, dimension, 1, x_coord, y_coord);
            time_sum += model(dimension, 1, num, x_coord, y_coord);
        }
        std::cout << (float)time_sum / (float)accuracy << ',' << ' ';
    }
    std::cout << std::endl;
}


int main() {


    int accuracy = 1000;

    int dimension_begin = 10;
    int dimension_step = 5;
    int steps = 5;


    for(int k = dimension_begin; k < dimension_begin + dimension_step * steps ; k += dimension_step){
        calc(k, accuracy);
    }
    return 0;
}