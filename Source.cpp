#include <iostream>
#include <math.h>

using namespace std;

float function(float x) {
	return 3 * sin(x) - pow(x, 2) + 4;
}

float fprime(float x) {
	return 3 * cos(x) - 2 * x;
}

float fprime2(float x) {
	return -3 * sin(x) - 2;
}

float phi(float x) {
	return sqrt(3 * sin(x) + 4);
}

float secant(float function(float), float x_prev, float x, const float e = 0.01) {
	int count = 0;
	while (abs(x - x_prev) >= e) {
		count++;
		x = (x - function(x) * (x - x_prev) / (function(x) - function(x_prev)));
		x_prev = x;
	}
	return x;
}
float iterations(float phi(float), float a, const float e = 0.01) {
	int i = 1;
	float x = phi(a);
	float x0 = phi(x);
	while (abs(x - x0) >= e) {
		x = phi(x0);
		x0 = phi(x);
		i++;
		if (i == 10000) {
			cout << "Выполнение 1000 итераций, решение не найдено" << endl;
			return 0;
		}
	}
	cout << "Количество итераций: " << i << endl;
	return x0;
}
float newton(float function(float), float fprime(float), float fprime2(float), float a, float b, const float e = 0.01) {
	
	int count = 0;
	float x0 = 0;
	float x = 0;

	if (function(a) * fprime2(a) > 0) {
		float x0 = a;
	}
	else if (function(b) * fprime2(b) > 0) {
		float x0 = b;
	}
	else {
		cout << "Неверно выбран начальный интервал" << endl;
		return 0;
	}
	x = x0 - function(x0) / fprime(x0);
	while (abs(x - x0) >= e) {
		count++;
		x0 = x - function(x) / fprime(x);
		x = x0 - function(x0) / fprime(x0);
	}
	cout << "Количество итераций: " << count << endl;
	return x;
}
float bisections(float function(float), float a, float b, const float e = 0.01) {
	int count = 0;
	if (function(a) * function(b) > 0){
		cout << "На заданном интервале нет корней";
		return 0;
	}

	float x0 = (a + b) / 2;

	while ((abs(a - b)) >= e){
		count++;
		if (function(a) * function(x0) > 0)
			a = x0;
		else
			b = x0;

		x0 = (a + b) / 2;
	}
	cout << "Количество итераций: " << count - 1 << endl;
	return x0;
}


int main() {

	setlocale(LC_ALL, "Russian");
	int n = 0;
	float a = 0.0;
	float b = 0.0;
	cout << "Введите координату a" << endl;
	cin >> a;
	cout << "Введите координату b" << endl;
	cin >> b;
	cout << endl;
	cout << "[1] Метод деления отрезка пополам" << endl;
	cout << "[2] Метод Ньютона" << endl;
	cout << "[3] Метод секущих" << endl;
	cout << "[4] Метод простых итераций" << endl;
	cout << "[0] Выход из программы" << endl;

	while (true){
		cout << "Введите ваш выбор:" << endl;
		cin >> n;
		cout << endl;
		switch (n) {
		case 1:
			cout << "Метод деления отрезка пополам" << endl;
			cout << bisections(function, a, b) << endl;
			cout << endl;
			break;
		case 2:
			cout << "Метод Ньютона" << endl;
			cout << newton(function, fprime, fprime2, a, b) << endl;
			cout << endl;
			break;
		case 3:
			cout << "Метод секущих" << endl;
			cout << secant(function, a, b) << endl;
			cout << endl;
			break;
		case 4:
			cout << "Метод простых итераций" << endl;
			cout << iterations(phi, a) << endl;
			cout << endl;
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Такого номера нет, введите ещё раз: " << endl;
		}
	}

}