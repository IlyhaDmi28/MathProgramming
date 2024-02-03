#include "Auxil.h"                            // вспомогательные функции 
#include <iostream>
#include "Fibanachi.h"
#include <ctime>
#include <locale>

#define  CYCLE  1000000                       // количество циклов  
#define  I 10
#define  R 40

int main()
{
    setlocale(LC_ALL, "rus");

	double   av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 

	std::cout << std::endl << "количество циклов:         " << CYCLE;
	std::cout << std::endl << "среднее значение (int):    " << av1 / CYCLE;
	std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;


    std::cout << std::endl << "Сумма случайных чисел:";

    av1 = 0; av2 = 0;

    clock_t SS1[I];
    int iter;
    auxil::start();
    for (int n = 0; n < I; n++)
    {
        iter = CYCLE + n * CYCLE;
        SS1[n] = clock();

        for (int i = 0; i < iter; i++)
        {
            av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
            av2 += auxil::dget(-100, 100);         // сумма случайных чисел
        }
    
        SS1[n] = clock() - SS1[n];
        std::cout << std::endl << "n = " << n + 1 << ": " << SS1[n];
    }
    std::cout << std::endl;



    std::cout << std::endl << "Числа Фибаначи: ";
    clock_t SS2[R];

    for (int n = 0; n < R; n++)
    {

        SS2[n] = clock();

        Fibanachi(n + 1);

        SS2[n] = clock() - SS2[n];

        std::cout << std::endl << "n = " << n + 1 << ": " << SS2[n];
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}


