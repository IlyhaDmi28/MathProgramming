// Knapsack.cpp 
#include "Knapsack.h"
#include "Set.h"
#include "Combi.h"
#include "Permutations.h"
#include "Accomodation.h"
#include "stdafx.h"

#define NINF 0x80000000    // ����� ����� int-�����  

//���������
int calcv(sets::subset s, const int v[])  // ����� � �������
{
    int rc = 0;
    for (int i = 0; i < s.sn; i++) rc += v[s.ntx(i)];
    return rc;
};
int calcc(sets::subset s, const int v[], const int c[]) //��������� � ������� 
{
    int rc = 0;
    for (int i = 0; i < s.sn; i++) rc += (v[s.ntx(i)] * c[s.ntx(i)]);
    return rc;
};
void setm(sets::subset s, short m[]) //�������� ��������� �������� 
{
    for (int i = 0; i < s.n; i++) m[i] = 0;
    for (int i = 0; i < s.sn; i++) m[s.ntx(i)] = 1;
};

int   knapsack_s(
    int V,         // [in] ����������� ������� 
    short n,       // [in] ���������� ����� ��������� 
    const int v[], // [in] ������ �������� ������� ����  
    const int c[], // [in] ��������� �������� ������� ����
    short  m[]     // [out] ���������� ��������� ������� ���� {0,1} 
)
{
    sets::subset s(n);
    int maxc = NINF, cc = 0;
    short  ns = s.getfirst();
    while (ns >= 0)
    {
        if (calcv(s, v) <= V)
            if ((cc = calcc(s, v, c)) > maxc)
            {
                maxc = cc;
                setm(s, m);
            }
        ns = s.getnext();
    };
    return maxc;
};

void GetValue(int* arr, int min, int max) 
{
    for (short i = 0; i < NN; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    };
}
