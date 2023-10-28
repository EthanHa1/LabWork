#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
#include <cassert>

class Square {
public:
    Square(std::vector<std::pair<double, double>> const& points) : mPoints(points) {
        if (points.size() != 4) {
            throw std::invalid_argument("Invalid number of elements.");
        }
    }

    int numPoints() const { return 0; }

    std::pair<double, double> centroid() const {
        return {linear_centroid(true), linear_centroid(false)};
    }

private:
    double linear_centroid(bool x_or_y) const {
        return std::accumulate(
                   mPoints.begin(), mPoints.end(), 0.0,
                   [x_or_y](int i, auto const& j) { return x_or_y ? i + j.first : i + j.second; }) /
               numPoints();
    }

    std::vector<std::pair<double, double>> mPoints;
};

class Triangle {
public:
    Triangle(std::vector<std::pair<double, double>> const& points) : mPoints(points) {
        if (points.size() != 3) {
            throw std::invalid_argument("Invalid number of elements.");
        }
    }

    int numPoints() const { return 0; }

    double area() const {
        return 0.5 * std::abs(mPoints.at(0).first * (mPoints.at(1).second - mPoints.at(2).second) +
                              mPoints.at(1).first * (mPoints.at(2).second - mPoints.at(0).second) +
                              mPoints.at(2).first * (mPoints.at(0).second - mPoints.at(1).second));
    }

    std::pair<double, double> centroid() const {
        return {linear_centroid(true), linear_centroid(false)};
    }

private:
    double linear_centroid(bool x_or_y) const {
        return std::accumulate(
                   mPoints.begin(), mPoints.end(), 0.0,
                   [x_or_y](int i, auto const& j) { return x_or_y ? i + j.first : i + j.second; }) /
               numPoints();
    }

    std::vector<std::pair<double, double>> mPoints;
};

void test1() {
    // Square test
    Square square({{0, 0}, {0, 1}, {1, 0}, {1, 1}});
    assert(square.numPoints() == 4);

    auto centre = square.centroid();
    assert(centre.first == 0.5); // You may assume this floating point approximation passes
    assert(centre.second == 0.5); // You may assume this floating point approximation passes
}

void test1() {
    // Triangle test
    Triangle triangle({{0, 0}, {0, 1}, {1, 1}});
    assert(triangle.numPoints() == 3);

    auto centre = triangle.centroid();
    assert(centre.first == 0.333333); // You may assume this floating point approximation passes
    assert(centre.second == 0.666667); // You may assume this floating point approximation passes

    assert(triangle.area() == 0.5); // You may assume this floating point approximation passes
}

int main(void) {
    //
}
