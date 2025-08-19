#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    printf("Введите коэффициенты a, b и c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                printf("Бесконечное количество решений\n");
            else
                printf("Нет решений\n");
        } else {
            root1 = -c / b;
            printf("Линейное уравнение: x = %.2lf\n", root1);
        }
        return 0;
    }

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Два действительных корня:\nx1 = %.2lf\nx2 = %.2lf\n", root1, root2);
    }
    else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Один действительный корень:\nx = %.2lf\n", root1);
    }
    else {
        printf("Действительных корней нет\n");
    }

    return 0;
}
