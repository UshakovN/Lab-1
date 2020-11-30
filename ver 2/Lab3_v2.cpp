//Определить в каком массиве меньше среднее арифметическое элементов, больших заданного числа. 
//Если в двух или трёх массивах значения среднего арифметического совпадают, 
//вывести соответствующее сообщение.

#include <cstdio>
#include <locale.h>

float average(float x[], int n, float zn);
void sravn(float av_a, float av_b, float av_c, FILE* f, float zn);
void input(FILE* f, float x[], int n);
void output(FILE* f, float x[], int n);
void size_check(int& n);

int main() {
    setlocale(LC_ALL, "Rus");
    int select, n_a, n_b, n_c;
    float av_a, av_b, av_c, zn;
    float a[100], b[100], c[100];
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
         break;

        case (3):
            flag = false;
            printf("Завершение работы программы. \n");
            fopen_s(&log, "log.txt", "a");
            fprintf(log, "Завершение работы программы. \n");
            fclose(log);
            break;
        default:
            printf("Введите корректное значение! \n");
            break; 
        }
    } 
    return 0;
}

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