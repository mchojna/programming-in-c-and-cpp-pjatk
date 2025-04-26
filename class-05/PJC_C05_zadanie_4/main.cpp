#include <iostream>
#include <fmt/ranges.h>
#include <fmt/format.h>
#include <stdlib.h>
#include <time.h>

struct Point {
    int x;
    int y;

    auto calculateDistance(Point const& point) const -> double {
        return sqrt(pow((x - point.x), 2) + pow((y - point.y), 2));
    }

    auto changeCoordinate(int newX, int newY) -> void {
        x = newX;
        y = newY;
    }
};

auto format_as(Point const& point){
    return fmt::format("[{}, {}]", point.x, point.y);
}

struct Rectangle {
    Point rightUpperPoint;
    Point leftLowerPower;

    auto calculateRightLowerPoint() const -> Point {
        return Point(rightUpperPoint.x, leftLowerPower.y);
    }

    auto calculateLeftUpperPoint() const -> Point {
        return Point(leftLowerPower.x, rightUpperPoint.y);
    }
};

auto format_as(Rectangle const& rec){
    return fmt::format("[{}, {}]", rec.leftLowerPower, rec.rightUpperPoint);
}

auto findSmallesRectangle(std::vector<Point> const& vec) -> Rectangle {
    auto rightUpperPointX = INT_MIN;
    auto rightUpperPointY = INT_MIN;
    auto leftLowerPointX = INT_MAX;
    auto leftLowerPointY = INT_MAX;

    for(auto& p: vec) {
        if(p.x > rightUpperPointX) {
            rightUpperPointX = p.x;
        }
        if(p.y > rightUpperPointY) {
            rightUpperPointY = p.y;
        }
        if(p.x < leftLowerPointX) {
            leftLowerPointX = p.x;
        }
        if(p.y < leftLowerPointY) {
            leftLowerPointY = p.y;
        }
    }

    return Rectangle({rightUpperPointX, rightUpperPointY}, {leftLowerPointX, leftLowerPointY});
}

auto main() -> int {
    auto p1 = Point(1, 2);
    auto p2 = Point{3, 4};
    fmt::println("{}", p1);
    fmt::println("{}", p2);

    fmt::println("{}", p1.calculateDistance(p2));
    fmt::println("{}", p2.calculateDistance({-1, 3}));
    fmt::println("{}", p1.calculateDistance({1, 2}));

    p1.changeCoordinate(5, 9);
    fmt::println("{}", p1);

    auto vec = std::vector<Point>(20);
    for(auto& p: vec) {
        p.x = std::rand() % 100;
        p.y = std::rand() & 100;
        fmt::print("{} ", p);
    }

    auto rec = findSmallesRectangle(vec);
    fmt::println("\n{}", rec);
}