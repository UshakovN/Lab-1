//Определить в каком массиве меньше среднее арифметическое элементов, больших заданного числа. 
//Если в двух или трёх массивах значения среднего арифметического совпадают, 
//вывести соответствующее сообщение.

#include <cstdio>
#include <locale.h>
#include "Function.h"
#pragma warning (disable:4996)

int main() {
    setlocale(LC_ALL, "Rus");
    int select, n_a, n_b, n_c;
    float av_a, av_b, av_c, zn;
    float *a, *b, *c;
    bool flag = true; 
  
    FILE* mas_a = fopen("a.txt", "r");
    FILE* mas_b = fopen("b.txt", "r");
    FILE* mas_c = fopen("c.txt", "r");
    FILE* log;

    while (flag) {
        printf("1: Очистить log-файл. \n");
        printf("2: Решить задачу. \n");
        printf("3: Завершение работы программы. \n");
        printf("Выбор: ");
        scanf_s("%d", &select);
        switch (select) {

        case (1):
            fopen_s(&log, "log.txt", "w");
            fclose(log);
            fopen_s(&log, "log.txt", "a");
            fprintf(log, "log-файл очищен. \n");
            fclose(log);
            break;

        case (2):
            fopen_s(&log, "log.txt", "a");
            printf("Введите размер массивов a,b,c: \n");
            scanf_s("%d", &n_a); size_check(n_a);
            scanf_s("%d", &n_b); size_check(n_b);
            scanf_s("%d", &n_c); size_check(n_c);
            a = new float[n_a];
            b = new float[n_b];
            c = new float[n_c];

            input(mas_a, a, n_a);
            fprintf(log, "Массив a: %d \n", n_a);
            output(log, a, n_a); fprintf(log, "\n");
            input(mas_b, b, n_b);
            fprintf(log, "Массив b: %d \n", n_b);
            output(log, b, n_b); fprintf(log, "\n");
            input(mas_c, c, n_c);
            fprintf(log, "Массив c: %d \n", n_c);
            output(log, c, n_c); fprintf(log, "\n");
            printf("Введите заданное число: ");
            scanf_s("%f", &zn);
            fprintf(log, "Заданное число: %.2f \n", zn);
            av_a = average(a, n_a, zn);
            av_b = average(b, n_b, zn);
            av_c = average(c, n_c, zn);

            if (av_a == zn) fprintf(log, "В массиве A нет элементов больших заданного числа \n");
            else fprintf(log, "Среднее арифметическое A: %.2f \n", av_a);
            if (av_b == zn) fprintf(log, "В массиве B нет элементов больших заданного числа \n");
            else fprintf(log, "Среднее арифметическое B: %.2f \n", av_b);
            if (av_c == zn) fprintf(log, "В массиве C нет элементов больших заданного числа \n");
            else fprintf(log, "Среднее арифметическое C: %.2f \n", av_c);
            sravn(av_a, av_b, av_c, log, zn);
            fclose(mas_a); fclose(mas_b); fclose(mas_c);
            fclose(log);
            delete [] a;
            delete [] b;
            delete [] c;
            break;

        case (3):
            flag = false;
            printf("Завершение работы программы. \n");
            fopen_s(&log, "log.txt", "a");
            fprintf(log, "Завершение работы программы. \n ");
            fclose(log);
            break;
        default:
            printf("Введите корректное значение! \n ");
            break;
        }
    }
    return 0;
}