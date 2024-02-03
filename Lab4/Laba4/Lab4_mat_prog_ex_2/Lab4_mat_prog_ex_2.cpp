#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenshtein.h"

#define firstLineLenght 10
#define secondLineLenght 13


using namespace std;
char* GenerateRandomString(int size)
{
	char* str = (char*)malloc(sizeof(char) * size);

	for (int i = 0; i < size; i++) str[i] = rand() % 26 + 'a';
	return str;
}

void LevenstainDistanceByTwoMethods(float k, char* s1, char* s2) {

	auto t1 = clock();
	auto dist = levenshtein(firstLineLenght * k, s1, secondLineLenght * k, s2);
	auto t2 = clock();

	cout << "Длина: " << firstLineLenght * k << "/" << secondLineLenght * k << endl;
	cout << "Дистанция Левенштейна с помощью динамического программирования: " << dist << endl;
	cout << "Время вычисления алгоритма: (мс) " << t2 - t1 << endl;

	t1 = clock();
	dist = levenshtein_r(firstLineLenght * k, s1, secondLineLenght * k, s2);
	t2 = clock();
	cout << "Дистанция Левенштейна с помощью рекурсии: " << dist << endl;
	cout << "Время вычисления алгоритма: (мс) " << t2 - t1 << endl;

	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "___________________________Generating string s1_____________________________" << endl << endl;
	srand(time(0) + rand());
	char* s1 = GenerateRandomString(13);
	cout << "String s1: " << endl;
	for (int i = 0; i < 13; i++) cout << s1[i] << " ";
	cout << endl << endl;
	cout << "___________________________Generating string s2_____________________________" << endl << endl;
	srand(time(0) + rand());

	char* s2 = GenerateRandomString(15);
	cout << "String s2: " << endl;
	for (int i = 0; i < 15; i++) cout << s2[i] << " ";
	cout << endl << endl;



	cout << "_____________________________Levenshtein distance______________________________" << endl << endl;
	int dist = 0;
	clock_t t1 = 0, t2 = 0;

	const char Acre[] = { 'Т', 'о', 'м' };
	const char Anchor[] = { 'И', 'с', 'т', 'о', 'к' };
	for (int i = 0; i < 3; i++) cout << Acre[i] << " "; cout << endl;
	for (int i = 0; i < 5; i++) cout << Anchor[i] << " "; cout << endl;
	dist = levenshtein_r(4, Acre, 5, Anchor);
	cout << "Дистанция Левенштейна для Том и Исток: " << dist << endl << endl;



	float k[] = { 0.04, 0.05, 0.0625, 0.1, 0.2, 0.5, 1 };


	LevenstainDistanceByTwoMethods(k[0], s1, s2);
	LevenstainDistanceByTwoMethods(k[1], s1, s2);
	LevenstainDistanceByTwoMethods(k[2], s1, s2);
	LevenstainDistanceByTwoMethods(k[3], s1, s2);
	LevenstainDistanceByTwoMethods(k[4], s1, s2);
	LevenstainDistanceByTwoMethods(k[5], s1, s2);
	LevenstainDistanceByTwoMethods(k[6], s1, s2);


}

