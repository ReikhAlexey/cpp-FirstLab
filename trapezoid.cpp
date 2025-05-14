//ТРАПЕЦИЯ
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

// Функция для проверки, может ли существовать трапеция с заданными сторонами, все 4 стороны
bool isValidTrapezoid(double bottomBase, double topBase, double leftSide, double rightSide) {
    // Трапеция существует, если сумма длин боковых сторон больше разности оснований
    double baseDifference = abs(bottomBase - topBase);
    return (leftSide + rightSide > baseDifference) && 
           (bottomBase + topBase + leftSide > rightSide) &&
           (bottomBase + topBase + rightSide > leftSide);
}

// Функция для вычисления высоты трапеции
double calculateHeight(double bottomBase, double topBase, double leftSide, double rightSide) {
    double baseDifference = bottomBase - topBase;
    // Вычисляем высоту по формуле, полученной из двух прямоугольных треугольников
    double numerator = pow(leftSide, 2) - pow(rightSide, 2) + pow(baseDifference, 2);
    double denominator = 2 * baseDifference;
    double x = numerator / denominator;
    
    // Вычисляем высоту по теореме Пифагора
    double height = sqrt(pow(leftSide, 2) - pow(x, 2)); // Исправлено: добавлена закрывающая скобка
    
    // Если получили мнимое число (что невозможно при правильной проверке), возвращаем 0
    return (height > 0) ? height : 0;
}

int main() { 

    double bottomBase, topBase, leftSide, rightSide; //Для коммита
    
    cout << "Enter all side lengths of the trapezoid:\n";//Введите все длины сторон трапеции:
    cout << "Bottom base: ";//"Нижнее основание:
    cin >> bottomBase;
    cout << "Upper base: ";//Верхнее основание:
    cin >> topBase;
    cout << "Left side: ";//Левая сторона:
    cin >> leftSide;
    cout << "right side: ";//Правая сторона:
    cin >> rightSide;
    
    // Проверка введенных значений
    if (bottomBase <= 0 || topBase <= 0 || leftSide <= 0 || rightSide <= 0) {
        cerr << "Error: All lengths must be positive numbers.\n";//Ошибка: все длины должны быть положительными числами.
        return 1;
    }
    
    if (!isValidTrapezoid(bottomBase, topBase, leftSide, rightSide)) {
        cerr << "Error: A trapezoid with such sides cannot exist.\n";//Ошибка: трапеция с такими сторонами не может существовать.
        return 1;
    }
    
    // Вычисление периметра
    double perimeter = bottomBase + topBase + leftSide + rightSide;
    
    // Вычисление средней линии
    double midline = (bottomBase + topBase) / 2;
    
    // Вычисление площади (через высоту)
    double height = calculateHeight(bottomBase, topBase, leftSide, rightSide);
    double area = (bottomBase + topBase) / 2 * height;
    
    // Вывод результатов
    cout << "\nCalculation results:\n";//Результаты вычислений:
    cout << "Perimeter of a trapezoid: " << perimeter << endl;//Периметр трапеции:
    cout << "Middle line of the trapezoid: " << midline << endl;//Средняя линия трапеции:
    cout << "Area of a trapezoid: " << area << endl;//Площадь трапеции:
    
    return 0;
}