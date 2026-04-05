#ifndef GEOMETRY_H
#define GEOMETRY_H

namespace Geometry {
    const double PI = 3.14159;

    double circleArea(double radius);
    double rectangleArea(double width, double height);

    namespace Shapes {
        class Circle {
        private:
            double radius;
        public:
            Circle(double r);
            double area() const;
        };
    }
}

#endif