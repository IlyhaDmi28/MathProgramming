#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

char* GenerateRandomString(int size)
{
	char* str = (char*)malloc(sizeof(char) * size);


	for (int i = 0; i < size; i++) {
		str[i] = rand() % 26 + 'a';
	}
	return str;
}


int main()
{
	cout << "___________________________Generating string s1_____________________________" << endl << endl;
	srand(time(0) + rand());
	char* s1 = GenerateRandomString(300);
	cout << "String s1: " << endl;
	for (int i = 0; i < 300; i++) cout << s1[i] << " ";
	cout << endl << endl;
	cout << "___________________________Generating string s2_____________________________" << endl << endl;
	srand(time(0) + rand());
	char* s2 = GenerateRandomString(200);
	cout << "String s2: " << endl;
	for (int i = 0; i < 200; i++) cout << s2[i] << " ";
	cout << endl << endl;
}