#include "Geometry.h"
#include <iostream>

namespace Geometry {
    double circleArea(double radius) {
        return PI * radius * radius;
    }

    double rectangleArea(double width, double height) {
        return width * height;
    }

    namespace Shapes {
        Circle::Circle(double r) : radius(r) {}

        double Circle::area() const {
            return Geometry::circleArea(radius);
        }
    }
}