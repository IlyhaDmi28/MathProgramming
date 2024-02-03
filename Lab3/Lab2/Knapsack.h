// Knapsack.h      
#pragma once 
//#define NN (sizeof(c)/sizeof(int))
#define NN 18
#define NN1 sizeof(c)/sizeof(int)

int   knapsack_s(
    int V,         // [in]  вместимость рюкзака 
    short n,       // [in]  количество типов предметов 
    const int v[], // [in]  размер предмета каждого типа  
    const int c[], // [in]  стоимость предмета каждого типа     
    short m[]      // [out] количество предметов каждого типа  
);

void GetValue(int* arr, int min, int max);

