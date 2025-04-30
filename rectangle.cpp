//ПРЯМОУГОЛЬНИК
#include <iostream>
#include <cmath> // Для sqrt()

// Функция вычисления периметра прямоугольника
double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Функция вычисления площади прямоугольника
double calculateArea(double length, double width) {
    return length * width;
}

// Функция вычисления диагонали прямоугольника (по теореме Пифагора)
double calculateDiagonal(double length, double width) {
    return sqrt(length * length + width * width);
}

int main() {
    double length, width;

    // Ввод длины и ширины
    std::cout << "Enter the length of the rectangle: ";//Введите длину прямоугольника
    std::cin >> length;

    std::cout << "Enter the width of the rectangle: ";//Введите ширину прямоугольника
    std::cin >> width;

    // Проверка на корректность ввода (длина и ширина должны быть положительными)
    if (length <= 0 || width <= 0) {
        std::cerr << "Error: length and width must be positive numbers!" << std::endl;//Ошибка: длина и ширина должны быть положительными числами!
        return 1;
    }

    // Вычисление и вывод результатов
    std::cout << "\nResults:\n";//Результаты
    std::cout << "1) Perimeter of the rectangle: " << calculatePerimeter(length, width) << std::endl;//Периметр прямоугольника
    std::cout << "2) Area of ​​the rectangle: " << calculateArea(length, width) << std::endl;//Площадь прямоугольника
    std::cout << "3) Length of the diagonal of the rectangle: " << calculateDiagonal(length, width) << std::endl;//Длина диагонали прямоугольника

    return 0;
}