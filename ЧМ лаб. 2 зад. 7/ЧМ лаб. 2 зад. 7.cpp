#include <iostream> 
#include <cmath> 
#include <iomanip> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << fixed << setprecision(3);
    // Ур 1. sqrt(x) - 3*cos(0.39x) = 0 
    cout << "Уравнение 1: sqrt(x) - 3*cos(0.39x) = 0\n";
    cout << "Отрезок [0; 4], шаг 0.5\n\n";
    cout << "   x        y\n";

    double x = 0.0, h = 0.5;
    double y_prev = sqrt(x) - 3 * cos(0.39 * x);
    cout << setw(6) << x << "   " << setw(8) << y_prev << endl;

    while (x + h <= 4.0) {
        double x_next = x + h;
        double y_next = sqrt(x_next) - 3 * cos(0.39 * x_next);
        cout << setw(6) << x_next << "   " << setw(8) << y_next << endl;
        x = x_next;
        y_prev = y_next;
    }

    // Повторный проход для поиска корней
    x = 0.0;
    y_prev = sqrt(x) - 3 * cos(0.39 * x);
    while (x + h <= 4.0) {
        double x_next = x + h;
        double y_next = sqrt(x_next) - 3 * cos(0.39 * x_next);
        if (y_prev * y_next <= 0)
            cout << "\nКорень на отрезке [" << x << "; " << x_next << "]";
        x = x_next;
        y_prev = y_next;
    }

    // Ур. 2. x^3 - 0.2x^2 + 0.5x + 1.4 = 0
    cout << "\n\nУравнение 2: x^3 - 0.2x^2 + 0.5x + 1.4 = 0\n";
    cout << "Отрезок [-4; 2], шаг 1\n\n";
    cout << "   x        y\n";

    x = -4.0; h = 1.0;
    y_prev = x * x * x - 0.2 * x * x + 0.5 * x + 1.4;
    cout << setw(6) << x << "   " << setw(8) << y_prev << endl;

    while (x + h <= 2.0) {
        double x_next = x + h;
        double y_next = x_next * x_next * x_next - 0.2 * x_next * x_next
            + 0.5 * x_next + 1.4;
        cout << setw(6) << x_next << "   " << setw(8) << y_next << endl;
        x = x_next;
        y_prev = y_next;
    }

    // Повторный проход для поиска корней
    x = -4.0;
    y_prev = x * x * x - 0.2 * x * x + 0.5 * x + 1.4;
    while (x + h <= 2.0) {
        double x_next = x + h;
        double y_next = x_next * x_next * x_next - 0.2 * x_next * x_next
            + 0.5 * x_next + 1.4;
        if (y_prev * y_next <= 0)
            cout << "\nКорень на отрезке [" << x << "; " << x_next << "]";
        x = x_next;
        y_prev = y_next;
    }

    cout << endl;
    return 0;
}