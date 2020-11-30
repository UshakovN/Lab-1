//ЛР-1 3 массива
//Определить в каком массиве меньше среднее арифметическое элементов, больших заданного числа. 
//Если в двух или трёх массивах значения среднего арифметического совпадают, 
//вывести соответствующее сообщение.

#include <cstdio>
#include <locale.h>

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

void input(float x[], int n) {
    for (int i = 0; i < n; i++) {
        scanf_s("%f", &x[i]);
    }
}

void output(float x[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\n");
}

void size_check(int& n) {
    while (n > 100 || n < 1) {
        printf("Введите корректное значение (от 1 до 100) \n");
        scanf_s("%d", &n);
    }
}

void sravn(float av_a, float av_b, float av_c, float zn) {

    if (av_a == zn && av_b == zn && av_c == zn) {
        printf("В массивах нет элементов больших заданного числа");
    }
    else if (av_b == zn && av_c == zn) {
        printf("В массиве А меньше среднее арифметическое (В массивах B и C нет подходящих элементов: %.2f) \n", av_a);
    }
    else if (av_a == zn && av_c == zn) {
        printf("В массиве B меньше среднее арифметическое (В массивах А и C нет подходящих элементов: %.2f) \n", av_b);
    }
    else if (av_a == zn && av_b == zn) {
        printf("В массиве С меньше среднее арифметическое (В массивах A и B нет подходящих элементов: %.2f) \n", av_c);
    }
    else if (av_a == zn)
    {
        if (av_b < av_c)
            printf("В массиве B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
        else
            printf("В массиве С меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    else if (av_b == zn)
    {
        if (av_a < av_c)
            printf("В массиве A меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            printf("В массиве С меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    else if (av_c == zn)
    {
        if (av_a < av_b)
            printf("В массиве A меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            printf("В массиве B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
    }
    else if (av_a == av_b && av_b == av_c) {
        printf("В массивах A и B и С равные среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
    }
    else if (av_a == av_b)
    {
        if (av_a < av_c)
            printf("В массиве А и B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            printf("В массиве С меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    else if (av_a == av_c)
    {
        if (av_a < av_b)
            printf("В массиве А и C меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
        else
            printf("В массиве B меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
    }
    else if (av_b == av_c)
    {
        if (av_b < av_a)
            printf("В массиве B и C меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
        else
            printf("В массиве A меньше среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
    }
    else if (av_a < av_b && av_a < av_c) {
        printf("В массиве А наименьшее среднее арифметическое элементов, больших заданного числа: %.2f \n", av_a);
    }
    else if (av_b < av_a && av_b < av_c) {
        printf("В массиве B наименьшее среднее арифметическое элементов, больших заданного числа: %.2f \n", av_b);
    }
    else  if (av_c < av_a && av_c < av_b) {
        printf("В массиве C наименьшее среднее арифметическое элементов, больших заданного числа: %.2f \n", av_c);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Rus");
    int select, n_a, n_b, n_c;
    float av_a, av_b, av_c, zn;
    float a[100], b[100], c[100];
    bool flag = true;

    while (flag) {
        printf("1: Решить задачу \n");
        printf("2: Завершение работы программы \n");
        printf("Выбор: \n");
        scanf_s("%d", &select);

        switch (select) {
        case (1):
            printf("Введите размер и содержимое массивов a,b,c: ");
            scanf_s("%d", &n_a);
            size_check(n_a);
            input(a, n_a);
            printf("Массив A: ");
            output(a, n_a);

            scanf_s("%d", &n_b);
            size_check(n_a);
            input(b, n_b);
            printf("Массив B: ");
            output(b, n_b);

            scanf_s("%d", &n_c);
            size_check(n_a);
            input(c, n_c);
            printf("Массив C: ");
            output(c, n_c);

            printf("Введите заданное число: ");
            scanf_s("%f", &zn);
            av_a = average(a, n_a, zn);
            av_b = average(b, n_b, zn);
            av_c = average(c, n_c, zn);

            if (av_a == zn) printf("В массиве A нет элементов больших заданного числа \n");
            else printf("Среднее арифметическое A: %.2f \n", av_a);

            if (av_b == zn) printf("В массиве B нет элементов больших заданного числа \n");
            else printf("Среднее арифметическое B: %.2f \n", av_b);

            if (av_c == zn) printf("В массиве C нет элементов больших заданного числа \n");
            else printf("Среднее арифметическое C: %.2f \n", av_c);

            sravn(av_a, av_b, av_c, zn);
            break;

        case (2):
            flag = false;
            printf("Завершение работы программы\n");
            break;

        default:
            printf("Введите корректное значение\n");
            break;
        }
    }
    return 0;
}














