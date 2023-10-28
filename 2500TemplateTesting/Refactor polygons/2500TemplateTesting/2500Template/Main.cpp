#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
#include <cassert>

class Polygon {
public:
    Polygon(std::vector<std::pair<double, double>> const& points) : mPoints(points) {}

    std::pair<double, double> centroid() const {
        return { linear_centroid(true), linear_centroid(false) };
    }

    int numPoints() const {
        return mPoints.size();
    }
protected: 
    std::vector<std::pair<double, double>> mPoints;

private:
    double linear_centroid(bool x_or_y) const {
        return std::accumulate(
            mPoints.begin(), mPoints.end(), 0.0,
            [x_or_y](int i, auto const& j) { return x_or_y ? i + j.first : i + j.second; }) /
            numPoints();
    }
};

class Square: public Polygon{
public:
    Square(std::vector<std::pair<double, double>> const& points) : Polygon(points) {
        if (points.size() != 4) {
            throw std::invalid_argument("Invalid number of elements.");
        }
    }

};

class Triangle: public Polygon {
public:
    Triangle(std::vector<std::pair<double, double>> const& points) : Polygon(points) {
        if (points.size() != 3) {
            throw std::invalid_argument("Invalid number of elements.");
        }
    }

    double area() const {
        return 0.5 * std::abs(mPoints.at(0).first * (mPoints.at(1).second - mPoints.at(2).second) +
                              mPoints.at(1).first * (mPoints.at(2).second - mPoints.at(0).second) +
                              mPoints.at(2).first * (mPoints.at(0).second - mPoints.at(1).second));
    }

};

void test1() {
    // Square test
    Square square({{0, 0}, {0, 1}, {1, 0}, {1, 1}});
    assert(square.numPoints() == 4);

    auto centre = square.centroid();
    assert(centre.first == 0.5); // You may assume this floating point approximation passes
    assert(centre.second == 0.5); // You may assume this floating point approximation passes
    std::cout << square.numPoints() << '\n';
    std::cout << centre.first << '\n';
    std::cout << centre.second << '\n';
}

void test2() {
    // Triangle test
    Triangle triangle({{0, 0}, {0, 1}, {1, 1}});
    assert(triangle.numPoints() == 3);

    auto centre = triangle.centroid();
    //assert(centre.first == 0.333333); // You may assume this floating point approximation passes
    //assert(centre.second == 0.666667); // You may assume this floating point approximation passes

    assert(triangle.area() == 0.5); // You may assume this floating point approximation passes
    std::cout << triangle.numPoints() << '\n';
    std::cout << centre.first << '\n';
    std::cout << centre.second << '\n';
    std::cout << triangle.area() << '\n';
}

int main(void) {
    //
    test1();
    test2();
}
