#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#endif

class Variant5Calculator {
private:
    // Початкові значення для варіанту 5 (y = 0.47*5, z = -1.32*5)
    const double y = 2.35;
    const double z = -6.6;

public:
    // Обчислення функції b[x, y, z]
    double calc_b(double x) {
        double num1 = x * x + (z * z) / std::pow(std::tan(std::pow(std::abs(x), 0.3)), 2);
        double den1 = 3 + x + (y * y) / 2.0 + (z * z * z) / 6.0;

        double log_inner = std::pow(std::abs(y / z), 1.0 / 3.0);
        double term2 = std::pow(std::abs(std::log(log_inner)), 0.3);

        return (num1 / den1) + term2;
    }

    // Обчислення функції a[x, y, z, b]
    double calc_a(double x, double b) {
        double num1 = 2 * std::cos(std::pow(std::abs(x), 1.0 / 3.0)) - (x * x) / 6.0;
        double den1 = (z / b) + std::pow(std::sin(std::pow(y + z, 3)), 2);
        double term2 = std::pow(std::log(std::pow(std::abs(z), 0.6)), 2);

        return (num1 / den1) + term2;
    }

    // Завдання 1: Одиничне обчислення для x = 0.48 * 5 = 2.4
    void runTask1() {
        double x = 2.4;
        double b = calc_b(x);
        double a = calc_a(x, b);

        std::cout << "=== Завдання 1 (Варіант 5) ===" << std::endl;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "z = " << z << std::endl;
        std::cout << "Результат b = " << b << std::endl;
        std::cout << "Результат a = " << a << std::endl << std::endl;
    }

    // Завдання 2: Табулювання функцій (від -1 до 1 з кроком 0.2)
    void runTask2() {
        std::cout << "=== Завдання 2 (Табулювання для MultiLine) ===" << std::endl;
        std::ostringstream multiLine;

        multiLine << std::fixed << std::setprecision(4);
        multiLine << "  x\t|      b\t|      a" << std::endl;
        multiLine << "----------------------------------------" << std::endl;

        for (double x = -1.0; x <= 1.0 + 1e-9; x += 0.2) {
            // При x = 0 tan(0) = 0, що викликає ділення на нуль
            if (std::abs(x) < 1e-7) {
                multiLine << std::setw(5) << 0.0 << "\t| Не визначено (x=0)\t| -" << std::endl;
                continue;
            }

            double b = calc_b(x);
            double a = calc_a(x, b);

            multiLine << std::setw(5) << x << "\t| " << std::setw(10) << b << "\t| " << std::setw(10) << a << std::endl;
        }

        std::cout << multiLine.str() << std::endl;
    }
};

int main() {
#ifdef _WIN32
    // Налаштування кодування консолі для Windows на UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#else
    // Для Linux / macOS
    std::setlocale(LC_ALL, "uk_UA.UTF-8");
#endif

    Variant5Calculator calc;

    // Виконання завдань
    calc.runTask1();
    calc.runTask2();

    return 0;
}