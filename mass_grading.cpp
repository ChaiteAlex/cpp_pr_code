/* Вариант 14
В массиве представлены данные об n средних чеках покупателей в магазине.
Найти все аномальные выбросы в этом массиве, используя формулу Z-оценки.
*/

int main()
{
	using namespace std;

	const int n = 10;
	
	double mas [n];
	double arf_mean = 0, sum = 0, sigma, zi;
	
	double a; //ввод данных в массив
	for (int i = 0; i < n; i++) { 
		cin >> a;
		mas[i] = a;
		arf_mean += a;
	}
	arf_mean /= n; // среднее арифметическое

	// сумма для формулы
	for (int i = 0; i < n; i++) { 
		sum += pow((mas[i] - arf_mean), 2);
	}

	sigma = pow((sum / 9), 0.5); // стандартное отклонение
	
	printf_s("mean: %.4f diff: %.4f\n", arf_mean, sigma);

	for (int i = 0; i < n; i++) {
		zi = (mas[i] - arf_mean) / sigma;
		printf_s("%i element - %.4f dif: %.4lf \n\n", i, mas[i], zi);
	}
}	
