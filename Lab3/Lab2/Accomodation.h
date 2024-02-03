#pragma once 
#include "Combi.h"
#include "Permutations.h"

#define N (sizeof(AA)/2)
#define M 3

namespace accomodations
{
    struct  accomodation  // ��������� ���������� 
    {
        short  n,      // ���������� ��������� ��������� ���������  
            m,      // ���������� ��������� � ���������� 
            * sset;      // ������ ������� �������� ����������  
        combi::xcombination* cgen;   // ��������� �� ��������� ���������
        permutations::permutation* pgen;   // ��������� �� ��������� ������������
        accomodation(short n = 1, short m = 1);  // �����������  
        void reset();     // �������� ���������, ������ ������� 
        short getfirst();     // ������������ ������ ������ ��������   
        short getnext();      // ������������ ��������� ������ ��������  
        short ntx(short i);   // �������� i-� ������� ������� ��������  
        unsigned __int64 na;  // ����� ���������� 0, ..., count()-1 
        unsigned __int64 count() const;  // ����� ���������� ���������� 
    };
}