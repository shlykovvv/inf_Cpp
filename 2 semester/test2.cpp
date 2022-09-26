#include <iostream>

struct Stack {
    char c; // Символ операции
    Stack *Next;
} ;

int Prior (char);
Stack* InS( Stack*,char);
Stack* OutS( Stack*,char*);

int main(){
    Stack *t, *Op = nullptr; // Стек операций Op – пуст
    char a, In[50], Out[50]; // Входная In и выходная Out строки
    int k = 0, l = 0; // Текущие индексы для строк
    puts(" Input formula : "); gets(In);
    while ( In[k] != '\0') { // Анализируем символы строки In
// Если символ «)», выталкиваем из стека в выходную строку все операции
        if ( In[k] == ')' ) {
            while ( (Op -> c) != '(' ) { // до открывающей скобки
                Op = OutS(Op,&a); // Считываем элемент из стека
                if ( !Op ) a = '\0';
                Out[l++] = a; // и записываем в строку Out.
            }
            t = Op; // Удаляем из стека открывающую скобку
            Op = Op -> Next;
            free(t);
        }
// Если символ строки In – буква, заносим ее в строку Out
        if ( In[k] >= 'a' && In[k] <= 'z' ) Out[l++] = In[k];
// Если символ – открывающая скобка, записываем ее в стек
        if ( In[k] == '(' ) Op = InS(Op,In[k]);
/* Если символ – знак операции, переписываем из стека в строку Out все операции с большим или равным приоритетом */
        if ( In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/' ) {
            while ( Op != nullptr && Prior (Op -> c) >= Prior (In[k]) ) {
                Op = OutS(Op,&a); // Извлекаем из стека символ Out[l++] = a; // и записываем в строку Out
            }
            Op = InS(Op,In[k]); // Текущий символ – в стек
        }
        k++;
    } // Конец цикла анализа входной строки
// Если стек не пуст, переписываем все операции в выходную строку
    while ( Op !=nullptr) {
        Op = OutS(Op,&a);
        Out[l++] = a;
    }
    Out[l] = '\0';
    printf("\n Polish = %s", Out); // Выводим на экран результат
    for (int i=0; i<50; i++){
        std::cout << Out[i];
    }
    return 0;
}
//======= Функция реализации приоритета операций =========
int Prior ( char a ) {
    switch ( a ) {
        case '*': case '/': return 3;
        case '-': case '+': return 2;
        case '(': return 1;
    }
    return 0;
}
// ============== Добавление элемента в стек =============
Stack* InS( Stack *t, char s) {
    Stack *t1 = (Stack*) malloc(sizeof(Stack));
    t1 -> c = s;
    t1-> Next = t;
    return t1;
}
// ============== Извлечение элемента из стека ===============
Stack* OutS( Stack *t, char *s ) {
    Stack *t1 = t;
    *s = t -> c;
    t = t->Next;
    free(t1);
    return t;
}