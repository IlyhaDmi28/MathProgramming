// Main      
#include "stdafx.h"
#include "Set.h"
#include "Combi.h"
#include "Permutations.h"
#include "Accomodation.h"
#include "Knapsack.h"
#include "Boat.h"
#include "Auxil.h"
#include "Salesman.h"

void SetExample()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " - Генератор множества всех подмножеств -";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация всех подмножеств  ";
    sets::subset s1(sizeof(AA) / 2);         // создание генератора   
    int  n = s1.getfirst();                // первое (пустое) подмножество    
    while (n >= 0)                          // пока есть подмножества 
    {
        std::cout << std::endl << "{ ";
        for (int i = 0; i < n; i++)
            std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s1.getnext();                   // cледующее подмножество 
    };
    std::cout << std::endl << "всего: " << s1.count() << std::endl;
    system("pause");
}

void CombiExample() 
{
    char  AA[][2] = { "A", "B", "C", "D", "E" };
    std::cout << std::endl << " --- Генератор сочетаний ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)

        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация сочетаний ";
    combi::xcombination xc(sizeof(AA) / 2, 3);
    std::cout << "из " << xc.n << " по " << xc.m;
    int  n = xc.getfirst();
    while (n >= 0)
    {

        std::cout << std::endl << xc.nc << ": { ";

        for (int i = 0; i < n; i++)


            std::cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");

        std::cout << "}";

        n = xc.getnext();
    };
    std::cout << std::endl << "всего: " << xc.count() << std::endl;
    system("pause");
}

void PermutationsExample()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор перестановок ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)

        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация перестановок ";
    permutations::permutation p(sizeof(AA) / 2);
    __int64  n = p.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << std::setw(4) << p.np << ": { ";

        for (int i = 0; i < p.n; i++)

            std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");

        std::cout << "}";

        n = p.getnext();
    };
    std::cout << std::endl << "всего: " << p.count() << std::endl;
    system("pause");

}

void AccomodationExample()
{
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор размещений ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < N; i++)

        std::cout << AA[i] << ((i < N - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация размещений  из  " << N << " по " << M;
    accomodations::accomodation s(N, M);
    int  n = s.getfirst();
    while (n >= 0)
    {

        std::cout << std::endl << std::setw(2) << s.na << ": { ";

        for (int i = 0; i < 3; i++)

            std::cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");

        std::cout << "}";

        n = s.getnext();
    };
    std::cout << std::endl << "всего: " << s.count() << std::endl;
    system("pause");

}


void Knapsack_limit()
{ 
    int V = 300,                // вместимость рюкзака              
        v[NN],     // размер предмета каждого типа  
        c[NN];     // стоимость предмета каждого типа 
    short m[NN];                // количество предметов каждого типа  {0,1}  

    GetValue(v, 10, 300);
    GetValue(c, 5, 55);

    int maxcc = knapsack_s(

        V,   // [in]  вместимость рюкзака 
        NN,  // [in]  количество типов предметов 
        v,   // [in]  размер предмета каждого типа  
        c,   // [in]  стоимость предмета каждого типа     
        m    // [out] количество предметов каждого типа  
    );

    std::cout << std::endl << "-------- Задача о рюкзаке --------- ";
    std::cout << std::endl << "- количество предметов : " << NN;
    std::cout << std::endl << "- вместимость рюкзака  : " << V;
    std::cout << std::endl << "- вес предметов    : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] << " ";
    std::cout << std::endl << "- стоимости предметов  : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] * c[i] << " ";
    std::cout << std::endl << "- оптимальная стоимость рюкзака: " << maxcc;
    std::cout << std::endl << "- вес рюкзака: ";
    int s = 0; for (int i = 0; i < NN; i++) s += m[i] * v[i];
    std::cout << s;
    std::cout << std::endl << "- выбраны предметы: ";
    for (int i = 0; i < NN; i++) std::cout << " " << m[i];
    std::cout << std::endl << std::endl;
    system("pause");
}
void Knapsack_time()
{
    int V = 600,              // вместимость рюкзака              
        v[] = { 25, 56, 67, 40, 20, 27, 37, 33, 33, 44, 53, 12,
               60, 75, 12, 55, 54, 42, 43, 14 },
        c[] = { 15, 26, 27, 43, 16, 26, 42, 22, 34, 12, 33, 30,
               12, 45, 60, 41, 33, 11, 14, 12 };
    short m[NN1];
    int maxcc = 0;
    clock_t t1, t2;
    std::cout << std::endl << "-------- Задача о рюкзаке --------- ";
    std::cout << std::endl << "- вместимость рюкзака  : " << V;
    std::cout << std::endl << "-- количество ------ продолжительность -- ";
    std::cout << std::endl << "    предметов          вычисления  ";
    for (int i = 12; i <= NN1; i++)
    {
        t1 = clock();
        maxcc = knapsack_s(V, i, v, c, m);
        t2 = clock();
        std::cout << std::endl << "       " << std::setw(2) << i
            << "               " << std::setw(5) << (t2 - t1);
    }
    std::cout << std::endl << std::endl;
    system("pause");
}

void BoatLimit()
{
    int v[NN3]; // вес
    int c[NN3]; // доход 
    int minv[MM];    // минимальный  вес 
    int maxv[MM];    // максимальный вес
    short r[MM];

    GetValue(v, 100, 200);
    GetValue(c, 10, 100);
    GetValue(minv, 50, 120);
    GetValue(maxv, 150, 180);

    int cc = boat_с(
        MM,    // [in]  количество мест для контейнеров
        minv,  // [in]  максимальный вес контейнера на каждом  месте 
        maxv,  // [in]  минимальный вес контейнера на каждом  месте  
        NN3,    // [in]  всего контейнеров  
        v,     // [in]  вес каждого контейнера  
        c,     // [in]  доход от перевозки каждого контейнера   
        r      // [out] номера  выбранных контейнеров  
    );
    std::cout << std::endl << "- Задача о размещении контейнеров на судне -";
    std::cout << std::endl << "- общее количество контейнеров   : " << NN3;
    std::cout << std::endl << "- количество мест для контейнеров  : " << MM;
    std::cout << std::endl << "- минимальный  вес контейнера  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << minv[i] << " ";
    std::cout << std::endl << "- максимальный вес контейнера  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << maxv[i] << " ";
    std::cout << std::endl << "- вес контейнеров      : ";
    for (int i = 0; i < NN3; i++) std::cout << std::setw(3) << v[i] << " ";
    std::cout << std::endl << "- доход от перевозки     : ";
    for (int i = 0; i < NN3; i++) std::cout << std::setw(3) << c[i] << " ";
    std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1) : ";
    for (int i = 0; i < MM; i++) std::cout << r[i] << " ";
    std::cout << std::endl << "- доход от перевозки     : " << cc;
    std::cout << std::endl << std::endl;
    system("pause");

}
void BoattTimer() 
{
    int v[NN3 + 1], c[NN3 + 1], minv[NN3 + 1], maxv[NN3 + 1];
    short r[NN3];
    auxil::start();
    for (int i = 0; i <= NN3; i++)
    {
        v[i] = auxil::iget(50, 500); c[i] = auxil::iget(10, 30);
        minv[i] = auxil::iget(50, 300); maxv[i] = auxil::iget(250, 750);
    }
    std::cout << std::endl << "-- Задача о размещении контейнеров -- ";
    std::cout << std::endl << "-- всего контейнеров: " << NN3;
    std::cout << std::endl << "-- количество ------ продолжительность -- ";
    std::cout << std::endl << "  мест     вычисления  ";
    clock_t t1, t2;
    for (int i = 4; i <= NN3; i++)
    {
        t1 = clock();
        boat_с(i, minv, maxv, NN3 + 1, v, c, r);
        t2 = clock();
        std::cout << std::endl << SPACE(7) << std::setw(2) << i
            << SPACE(15) << std::setw(6) << (t2 - t1);
    }
    std::cout << std::endl; system("pause");

}


void Salesman()
{
    int d[NS][NS] = { //0   1    2    3     4        
               { INF,  4,  25,  INF,    2},    //  0
               {  2, INF,  17,   66,   82},    //  1
               { 4,    6, INF,   86,   51},    //  2 
               { 19,  56,   8,  INF,    6},    //  3
               { 91,  68,  52,   15,  INF}     //  4
            };   
    int r[NS];                     // результат 
    int s = salesman(
        NS,          // [in]  количество городов 
        (int*)d,          // [in]  массив [n*n] расстояний 
        r           // [out] массив [n] маршрут 0 x x x x  

    );
    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество  городов: " << NS;
    std::cout << std::endl << "-- матрица расстояний : ";
    for (int i = 0; i < NS; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < NS; j++)

            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < NS; i++) std::cout << r[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- длина маршрута     : " << s;
    std::cout << std::endl;
    system("pause");

}

int main()
{
    setlocale(LC_ALL, "rus");
    srand((unsigned)time(NULL));

    /*SetExample();

    CombiExample();

    PermutationsExample();

    AccomodationExample();

    Knapsack_limit();
    Knapsack_time();

    BoattTimer();
    BoatLimit();*/

    Salesman();

    return 0;
}
