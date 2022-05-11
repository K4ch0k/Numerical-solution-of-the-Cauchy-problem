#include <stdio.h>
#include <windows.h>
#include <math.h>

#define n 100

double Approx(double x, double y)	//	y'
{
	return x * exp(-pow(x, 2)) * sin(x) - 2 * x * y;
}

double Exact(double x)	// y(x)
{
	return exp(-pow(x, 2)) * (sin(x) - x * cos(x) + 1);
}

int main(void)
{
	system("title Lab2.1 #24");
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	double a, b, h, x, y[n];	// Основные переменные
	double s1, s2, s3, s4;		// Переменные для метода Рунге-Кутты

	a = 0;		//	Начало отрезка
	b = 2;		//	Конец отрезка
	y[0] = 1;	//	Начальное условие
	h = (b - a) / (n - 1);	//	Шаг
	printf("Отрезок: [%3.3f, %3.3f]\nШаг: %f\n\n", a, b, h);
	
	for (int i = 0; i < n - 1; i++) // Метод Рунге - Кутты
	{
		x = i * h;
		s1 = h * Approx(x, y[i]);
		s2 = h * Approx(x + h / 2, y[i] + s1 / 2);
		s3 = h * Approx(x + h / 2, y[i] + s2 / 2);
		s4 = h * Approx(x + h, y[i] + s3);
		y[i + 1] = y[i] + (s1 + 2 * s2 + 2 * s3 + s4) / 6;
	}
	
	// Сравнение y' и y(x)
	for (int i = 0; i < n; i++)
	{
		x = i * h;
		printf("%3d\\\t x = %f \t\t y' = %f  \t\t y(x) = % f\n", i + 1, x, y[i], Exact(x));
	}
	
	system("pause");
	return 0;
}