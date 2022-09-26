#include <iostream>

void swap(void *lha, void *rha, size_t type_size);

void qsort(void * src_begin , size_t n_memb , size_t type_size , int(* compare)(const void *, const void *)) {
    int i = 0;
    int j = n_memb - 1;
    auto mid = (const char *)src_begin + n_memb/2 * type_size;

    do {
        while(compare((const char *)src_begin + i*type_size, mid) < 0) {
            i++;
        }
        while(compare((const char *)src_begin + j*type_size, mid) > 0) {
            j--;
        }

        if (i <= j) {
            swap((char *)src_begin + i*type_size, (char *)src_begin + j*type_size, type_size);
            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) {
        qsort(src_begin, j + 1, type_size, compare);
    }
    if (i < n_memb) {
        qsort((char *)src_begin + i*type_size, n_memb - i, type_size, compare);
    }
}

void swap(void *lha, void *rha, size_t type_size) {
    char *lha_p = (char *)lha;
    char *rha_p = (char *)rha;
    char *t = (char *) malloc(type_size);

    memcpy(t, lha_p, type_size);
    memcpy(lha_p,  rha_p, type_size);
    memcpy(rha_p, t, type_size);
    free(t);
}

int int_cmp ( const void * lha , const void * rha ) {
    int a = *( const int *) lha;
    int b = *( const int *) rha;
    return (b < a ) - (a < b);
}

struct Student {
    size_t height;
    char * name;
};

int student_cmp ( const void * lha , const void * rha ) {
    size_t a = (( const Student *) lha ) -> height;
    size_t b = (( const Student *) rha ) -> height;
    return (b < a) - (a < b);
}


int main() {
    int A[] = {3, 2, 3, 2, 5, 2};
    int *start = A;
    qsort(start, 6, sizeof(int), int_cmp);

    Student B[] = {{182 , " Ivan "}, {167 , " Nikita "}, {173 , " Dima "}};
    Student *start2 = B;
    qsort(start2, 3, sizeof(Student), student_cmp);

    for (int i : A) {
        std::cout << i;
    }
    for (Student i : B) {
        std::cout << i.name;
    }
    return 0;
}





