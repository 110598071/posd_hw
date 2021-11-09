#pragma once

#include <cmath>
#include <stdexcept>

#include "shape.h"

class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y) {
        _x = x;
        _y = y;
    }

    TwoDimensionalVector(){}

    double x() const {
        return _x;
    }

    double y() const {
        return _y;
    }

    double length() const {
        return hypot(_x , _y);
    }

    double dot(TwoDimensionalVector vec) const {
        if ((_x == 0 && _y == 0) || (vec._x == 0 && vec._y == 0)) {
            throw std::invalid_argument("we can't dot with zero vector");
        }
        else {
            return _x * vec._x + _y * vec._y;
        }
    }

    double cross(TwoDimensionalVector vec) const {
        if ((_x == 0 && _y == 0) || (vec._x == 0 && vec._y == 0)) {
            throw std::invalid_argument("we can't dot with zero vector");
        }
        else {
            return _x * vec._y - _y*vec._x;
        }
    }

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const {
        double subvec_x, subvec_y;
        subvec_x = _x-vec._x;
        subvec_y = _y-vec._y;
        TwoDimensionalVector tdv(subvec_x, subvec_y);
        return tdv;
    }

    std::string info() const {
        std::string info_x = std::to_string(_x);
        std::string info_y = std::to_string(_y);

        std::string _info = "[";
        _info.append(info_x.substr(0, info_x.find(".")+3));
        _info.append(",");
        _info.append(info_y.substr(0, info_y.find(".")+3));
        _info.append("]");
        return _info;
    }
private:
    double _x;
    double _y;
};
