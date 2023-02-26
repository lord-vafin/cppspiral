#pragma once
int** inic(int size);
void print(int** spisok, int size);
void transponition(int**& spiral, int& size);
void reflection(int**& spiral, int& size);
void reflection_and_transponotion(int**& spiral, int size);
void fail(int& size);