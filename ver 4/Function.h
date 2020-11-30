#pragma once
#include <cstdio>

float average(float *x, int n, float zn);
void sravn(float av_a, float av_b, float av_c, FILE* f, float zn);
void input(FILE* f, float *x, int n);
void output(FILE* f, float *x, int n);
void size_check(int& n);
