#include <iostream>
#include <fmt/ranges.h>
#include <memory>
#include <algorithm>


class Shape {
public:
    virtual auto area() -> double = 0;
    virtual ~Shape() = default;
};

class Rectangle: public Shape {
    double a;
    double b;
public:
    Rectangle(const double a, const double b): a(a), b(b) {}
    auto area() -> double override { return a * b; }
    ~Rectangle() override = default;
};

class Circle: public Shape {
    double r;
public:
    Circle(double const r): r(r) {};
    auto area() -> double override { return 3.14 * r * r; }
    ~Circle() override = default;
};


auto main() -> int {
    auto vector = std::vector<std::unique_ptr<Shape>>();

    /*vector.push_back(new Rectangle(1.0, 2.0));
    vector.push_back(new Rectangle(2.0, 2.0));
    vector.push_back(new Rectangle(8.5, 12.4));
    vector.push_back(new Circle(1.0));
    vector.push_back(new Circle(2.0));
    vector.push_back(new Circle(24.5));*/

    vector.push_back(std::make_unique<Rectangle>(1.0, 2.0));
    vector.push_back(std::make_unique<Rectangle>(2.0, 2.0));
    vector.push_back(std::make_unique<Rectangle>(8.5, 12.4));
    vector.push_back(std::make_unique<Rectangle>(8.5, 12.4));
    vector.push_back(std::make_unique<Circle>(1.0));
    vector.push_back(std::make_unique<Circle>(2.0));
    vector.push_back(std::make_unique<Circle>(24.5));
    vector.push_back(std::make_unique<Circle>(24.5));


    for (const auto& shape : vector) {
        fmt::print("{}, ", shape->area());
    }
    fmt::println("");

    /**/

    std::ranges::sort(vector, std::ranges::less(), [](const std::unique_ptr<Shape> &shape) {return shape->area();});
    for (const auto& shape : vector) {
        fmt::print("{}, ", shape->area());
    }
    fmt::println("");

    /**/

    std::ranges::sort(vector, [](const std::unique_ptr<Shape> &left, const std::unique_ptr<Shape> &right) -> int {
        if(dynamic_cast<Circle*>(left.get()) != nullptr) { return 1; }
        if(dynamic_cast<Circle*>(right.get()) != nullptr) { return -1; }
        return 0;
    });
    for (const auto& shape : vector) {
        fmt::print("{}, ", shape->area());
    }
    fmt::println("");

    /**/
    std::ranges::sort(vector, [](const auto &left, const auto &right) -> int {
        if(dynamic_cast<Circle*>(left.get()) != nullptr && dynamic_cast<Circle*>(right.get()) != nullptr) {
            return left->area() == right->area();
        }
        return 1;
    });
    auto uniqueVector = std::ranges::unique(vector, [](const auto &left, const auto &right) {
        if(dynamic_cast<Circle*>(left.get()) != nullptr && dynamic_cast<Circle*>(right.get()) != nullptr) {
            return left->area() == right->area();
        }
        if(dynamic_cast<Rectangle*>(left.get()) != nullptr && dynamic_cast<Rectangle*>(right.get()) != nullptr) {
            return left->area() == right->area();
        }
        return false;
    });
    vector.erase(uniqueVector.begin(), uniqueVector.end());
    for (const auto& shape : vector) {
        fmt::print("{}, ", shape->area());
    }
    fmt::println("");

    /**/
    auto squareVector = std::vector<double>(vector.size());
    std::ranges::transform(vector, squareVector.begin(), [](const std::unique_ptr<Shape> &shape) -> double {
        const auto area = shape->area();
        return area * area;
    });
    for(auto square: squareVector) {
        fmt::print("{}, ", square);
    }
    fmt::println("");
}