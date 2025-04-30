//ТРЕУГОЛЬНИК

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <windows.h>
#pragma execution_character_set( "utf-8" )


using namespace std;

int main() {

    SetConsoleOutputCP( 65001 ); // CP_UTF8
    printf( "Testing unicode -- English -- Ελληνικά -- Español -- Русский. aäbcdefghijklmnoöpqrsßtuüvwxyz\n" );

    double a, b, c;
    
    // Ввод длин сторон треугольника
    cout << "Enter the length of the first side of the triangle: ";//Введите длину первой стороны треугольника
    cin >> a;
    cout << "Enter the length of the second side of the triangle: ";//Введите длину второй стороны треугольника
    cin >> b;
    cout << "Enter the length of the third side of the triangle: ";//Введите длину третьей стороны треугольника
    cin >> c;

    // Проверка на существование треугольника
    if (a + b > c && a + c > b && b + c > a) {
        // Вычисление периметра
        double perimeter = a + b + c;
        cout << fixed << setprecision(2);
        cout << "Perimeter of the triangle: " << perimeter << endl;//Периметр треугольника

        // Вычисление площади по формуле Герона
        double s = perimeter / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "Area of ​​the triangle: " << area << endl;//Площадь треугольника

        // Проверка на равнобедренность
        if (a == b || b == c) {
            cout << "The triangle is isosceles." << endl;//Треугольник является равнобедренным
        } else {
            cout << "The triangle is not isosceles." << endl;//Треугольник не является равнобедренным
        }
    } else {
        cout << "Error: A triangle with these sides does not exist." << endl;//Ошибка: Треугольник с такими сторонами не существует
    }

    return 0;
}