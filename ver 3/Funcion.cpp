#include <cstdio>
#include <locale.h>
#include "Function.h"

float average(float x[], int n, float zn) {
    float val = 0; float k = 0;
    bool check = true;
    for (int i = 0; i < n; i++) {
        if (x[i] > zn) {
            check = false;
            val += x[i];
            k++;
        }
    }
    if (!check) val /= k;
    else val = zn;
    return val;
}

void input(FILE* f, float x[], int n) {
    for (int i = 0; i < n; i++) {
        fscanf_s(f, "%f", &x[i]);
    }
}
void output(FILE* f, float x[], int n) {
    for (int i = 0; i < n; i++) {
        fprintf(f, "%.0f ", x[i]);
    }
    printf("\n");
}

void size_check(int& n) {
    while (n > 100 || n < 1) {
        printf("Введите корректное значение (от 1 до 100) \n");
        scanf_s("%d", &n);
    }
}

void sravn(float av_a, float av_b, float av_c, FILE* f, float zn) {

    if (av_a == zn && av_b == zn && av_c == zn) {
        fprintf(f, "В массивах нет элементов больших заданного числа");
    }
    else if (av_b == zn && av_c == zn) {
        fprintf(f, "В массиве А меньше среднее арифметическое (В массивах B и C нет подходящих элементов: %.2f \n)", av_a);
    }
    else if (av_a == zn && av_c == zn) {
        fprintf(f, "В массиве B меньше среднее арифметическое (В массивах А и C нет подходящих элементов: %.2f \n)", av_b);
    }
    else if (av_a == zn && av_b == zn) {
        fprintf(f, "В массиве С меньше среднее арифметическое (В массивах A и B нет подходящих элементов: %.2f \n)", av_c);
    }
    else if (av_a == zn)
    {
        if (av_b < av_c)
            fprintf(f, "В массиве B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
        else
            fprintf(f, "В массиве С меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    else if (av_b == zn)
    {
        if (av_a < av_c)
            fprintf(f, "В массиве A меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            fprintf(f, "В массиве С меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    else if (av_c == zn)
    {
        if (av_a < av_b)
            fprintf(f, "В массиве A меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            fprintf(f, "В массиве B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
    }
    else if (av_a == av_b && av_b == av_c) {
        fprintf(f, "В массивах A и B и С равные среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
    }
    else if (av_a == av_b)
    {
        if (av_a < av_c)
            fprintf(f, "В массиве А и B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            fprintf(f, "В массиве С меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    else if (av_a == av_c)
    {
        if (av_a < av_b)
            fprintf(f, "В массиве А и C меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            fprintf(f, "В массиве B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
    }
    else if (av_b == av_c)
    {
        if (av_b < av_a)
            fprintf(f, "В массиве B и C меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
        else
            fprintf(f, "В массиве A меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
    }
    else if (av_a < av_b && av_a < av_c) {
        fprintf(f, "В массиве А наименьшее среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
    }
    else if (av_b < av_a && av_b < av_c) {
        fprintf(f, "В массиве B наименьшее среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
    }
    else  if (av_c < av_a && av_c < av_b) {
        fprintf(f, "В массиве C наименьшее среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    printf("\n");
}