// Knapsack.h      
#pragma once 
//#define NN (sizeof(c)/sizeof(int))
#define NN 18
#define NN1 sizeof(c)/sizeof(int)

int   knapsack_s(
    int V,         // [in]  ����������� ������� 
    short n,       // [in]  ���������� ����� ��������� 
    const int v[], // [in]  ������ �������� ������� ����  
    const int c[], // [in]  ��������� �������� ������� ����     
    short m[]      // [out] ���������� ��������� ������� ����  
);

void GetValue(int* arr, int min, int max);

