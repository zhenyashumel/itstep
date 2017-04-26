#pragma once
#include<iostream>
#include <cmath>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b)))
#define max(a,b) ((a)>(b)?(a):(b))
#define sqr(x) (x*x)
#define step(a,b) (pow(a,b))
#define iseven(a,b) (a%2==0?"Even":"Odd")


void Init(double mass[], int size);
void Init(int mass[], int size);
void Init(char mass[], int size);


void Print(double mass[], int size);
void Print(int mass[], int size);
void Print(char mass[], int size);


double Min(double mass[], int size);
int Min(int mass[], int size);
char Min(char mass[], int size);


double Max(double mass[], int size);
int Max(int mass[], int size);
char Max(char mass[], int size);


void Sort(double mass[], int size);
void Sort(int mass[], int size);
void Sort(char mass[], int size);


void Red(double mass[], int size, int index);
void Red(int mass[], int size, int index);
void Red(char mass[], int size, int index);
