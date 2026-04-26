
#include <iostream>
#include <math.h>
using namespace std;

/*

///	Задача 1.
//	Реализовать функцию swal для обмена значений между аргументами x и y, не
//	используя при этом третьей переменной.  

int swal(int a, int b) {
	a = a + b;
	b = a - b;
	a = a - b;

	cout << a << " ";
	cout << b << endl;
	return a, b;
};


int main()
{
	int x = 1, y = 2;
	cout << x << " ";
	cout << y << endl;
	swal(x, y);

}*/

/*

//	Задача 2.
//	Реализовать обобщенную функцию печати значения функции от аргумента
//	void print(float x, float (*y) (float))

float f1(float x) {

	return sinf(x) / x;

};
float f2(float y) {

	return (y * y) + 2 * pow(y, 3.0 / 2.0);

}
float f3(float z) {

	return (z + 2) * (z + 1) * z;

}


void main() {
	float x = 0.6, y = 0.3, z = 0.1;
	float res = f1(x) + f2(y) * f3(f2(*z));
	cout << f1(x) << endl;
	cout << f2(y) << endl;
	cout << f3(f2(z)) << endl;
	printf("(sin(%.2f)/ %.2f) + (%.2f^2 + 2 * %.2f^3/2) * ((%.2f^2 + 2 * %.2f^3/2) + 2) * ((%.2f^2 + 2 * %.2f^3/2) + 1)=\n = ", x, x, y, y, z, z, z, z);
	cout << res << endl;
}*/
/*
//	Задача 3.
//	Реализуйте перегрузку функций max и min для массива из k вещественных
//	чисел.С помощью программы найдите произведение минимумов двух
//	массивов различной длины и среднее геометрическое их максимумов.



int max(int a, int b) {

	return (a > b) ? a : b;

}

float max(float a, float b) {

	return (a > b) ? a : b;

}

int max(int mas[], int n) {
	int maxi = mas[0];

	for (int i = 1; i < n; i++) {

		if (maxi < mas[i]) maxi = mas[i];

	}

	return maxi;
}

int min(int a, int b) {

	return (a > b) ? a : b;

}

float min(float a, float b) {

	return (a > b) ? a : b;

}

int min(int mas[], int n) {
	int maxi = mas[0];

	for (int i = 1; i < n; i++) {

		if (maxi > mas[i]) maxi = mas[i];

	}

	return maxi;
}


void main() {
	int a = 1, b = 2;
	float c = 2.0, d = 3.0;
	int mas[] = { -2,-20, 25, 1, 6, 51, 2, 34, 51, 62, 151, 126, 2 };

	int maxint = max(a, b);
	float maxfloat = max(c, d);
	int n = sizeof(mas) / sizeof(mas[0]);
	int maxnum = max(mas, n);

	cout << maxint << endl;
	cout << maxfloat << endl;
	cout << maxnum << endl;

}
*/

//Задание 4 * .
//Составить алгоритм и программу, реализующую разные механизмы передачи
//параметров, на примере нахождения значений функций :
//1) функция принимает параметры по значению и возвращает значение;
//2) функция в качестве параметров принимает указатели, в том числе и
//параметр адреса результата, а сама функция типа Void.
//3) функция принимает параметры по ссылке и возвращает ссылку на
//результат.
//Функция вычисляет сумму членов ряда.Вычисление суммы необходимо
//выполнять до тех пор, пока очередное слагаемое(член ряда) по модулю не
//станет меньше заданной точности e = 10 - 4
//.x = 0.20, e = 0.5 * pow(10, -4)

double func_1(int x, int n) {
	return (1.0 * pow(x, 2 * n - 1)) / (2 * n - 1);
}

void func_2(int &x, int &n, double &z) {

	z = (1.0 * pow(x, 2 * n - 1)) / (2 * n - 1);
}

double func_3(int& x, int& n) {
	
	double z = (1.0 * pow(x, 2 * n - 1)) / (2 * n - 1);

	return z;

}

int main() {

	int x = 2, n = 2;
	double z;

	cout << func_1(x, n) << endl;

	func_2(x, n, z);

	cout << z << endl;

	cout << func_3(x, n) << endl;

	return 0;
}
