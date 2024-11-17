#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

double f(double x, double n) {
    return sin(x) - x - n;
}

double f_derivative(double x) {
    return cos(x) - 1;
}

double newton_method(double initial_guess, double n, double tolerance, int max_iterations) {
    double x = initial_guess;

    for (int i = 0; i < max_iterations; ++i) {
        double fx = f(x, n);
        double fpx = f_derivative(x);

        if (fabs(fpx) < 1e-10) {
            cout << "Похідна близька до нуля. Метод Ньютона не може бути застосований." << endl;
            return NAN;
        }

      
        double x_next = x - fx / fpx;

        if (fabs(x_next - x) < tolerance) {
            return x_next;
        }

        x = x_next;
    }

    cout << "Досягнуто максимальну кількість ітерацій." << endl;
    return x;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double n;
    cout << "Введіть значення n: ";
    cin >> n;

    double initial_guess = -n;  
    double tolerance = 1e-6;    
    int max_iterations = 100;  
    double root = newton_method(initial_guess, n, tolerance, max_iterations);

    if (!isnan(root)) {
        cout << "Знайдений корінь рівняння: " << root << endl;
        cout << "Перевірка: f(root) = " << f(root, n) << endl;
    }
    else {
        cout << "Не вдалося знайти корінь." << endl;
    }

    return 0;
}


