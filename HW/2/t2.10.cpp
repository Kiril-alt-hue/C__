#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double calculate_angle(double a, double b, double c) {
    // Using cosine theorem: cos(α) = (b² + c² - a²) / (2bc)
    double cos_angle = (b*b + c*c - a*a) / (2*b*c);


    if (cos_angle > 1.0) cos_angle = 1.0;
    if (cos_angle < -1.0) cos_angle = -1.0;

    return acos(cos_angle);
}


double radians_to_degrees(double radians) {
    return radians * 180.0 / PI;
}

int main() {
    double side_a, side_b, side_c;

    printf("Enter triangle side lengths (a b c): ");
    scanf("%lf %lf %lf", &side_a, &side_b, &side_c);


    if (side_a + side_b <= side_c || side_a + side_c <= side_b || side_b + side_c <= side_a) {
        printf("Error: Such triangle cannot exist!\n");
        return 1;
    }


    double angle_A = calculate_angle(side_a, side_b, side_c); // Angle opposite side a
    double angle_B = calculate_angle(side_b, side_a, side_c); // Angle opposite side b
    double angle_C = calculate_angle(side_c, side_a, side_b); // Angle opposite side c


    double total_angles = angle_A + angle_B + angle_C;

    printf("\nCalculation results:\n");
    printf("Angle A (opposite side a = %.2f):\n", side_a);
    printf("  Radians: %.6f rad\n", angle_A);
    printf("  Degrees: %.6f°\n", radians_to_degrees(angle_A));

    printf("Angle B (opposite side b = %.2f):\n", side_b);
    printf("  Radians: %.6f rad\n", angle_B);
    printf("  Degrees: %.6f°\n", radians_to_degrees(angle_B));

    printf("Angle C (opposite side c = %.2f):\n", side_c);
    printf("  Radians: %.6f rad\n", angle_C);
    printf("  Degrees: %.6f°\n", radians_to_degrees(angle_C));

    printf("\nSum of angles: %.6f rad (≈ %.6f°)\n", total_angles, radians_to_degrees(total_angles));

    return 0;
}