#ifndef INTERVAL_H
#define INTERVAL_H
#include <limits>
double positive_infinity = std::numeric_limits<double>::infinity();
double negative_infinity = -std::numeric_limits<double>::infinity();
class interval {

public:
    double min, max;
    
    interval() : min(positive_infinity), max(negative_infinity) {} // Default interval is empty

    interval(double _min, double _max) : min(_min), max(_max) {}

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }
    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }
    double size() const {
        return max - min;
    }

    interval expand(double delta) const {
        auto padding = delta / 2;
        return interval(min - padding, max + padding);

    }

    static const interval empty, universe;

    interval(const interval& a, const interval& b)
        : min(fmin(a.min, b.min)), max(fmax(a.max, b.max)) {}
};

const static interval empty(positive_infinity, negative_infinity);
const static interval universe(negative_infinity, positive_infinity);

#endif