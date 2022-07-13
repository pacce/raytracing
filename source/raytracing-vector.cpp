#include "raytracing-vector.hpp"
#include <cmath>

namespace raytracing {
namespace vector {
    Vector::Vector() : Vector(0.0f, 0.0f, 0.0f) {}
    Vector::Vector(float x, float y, float z)
        : x_(x)
        , y_(y)
        , z_(z)
    {}

    Vector&
    Vector::operator+=(const Vector& rhs) {
        this->x_ += rhs.x_;
        this->y_ += rhs.y_;
        this->z_ += rhs.z_;

        return *this;
    }

    bool
    operator==(const Vector& lhs, const Vector& rhs) {
        float ETOL = 1e-3;
        return std::abs(lhs.x_ - rhs.x_) <= ETOL
            && std::abs(lhs.y_ - rhs.y_) <= ETOL
            && std::abs(lhs.z_ - rhs.z_) <= ETOL
            ;
    }

    bool
    operator!=(const Vector& lhs, const Vector& rhs) {
        return !(lhs == rhs);
    }

    Vector
    operator+(const Vector& lhs, const Vector& rhs) {
        Vector add   = lhs;
        add         += rhs;
        return add;
    }

    Vector&
    Vector::operator-=(const Vector& rhs) {
        this->x_ -= rhs.x_;
        this->y_ -= rhs.y_;
        this->z_ -= rhs.z_;

        return *this;
    }

    Vector
    operator-(const Vector& lhs, const Vector& rhs) {
        Vector sub   = lhs;
        sub         -= rhs;
        return sub;
    }

    Vector&
    Vector::operator*=(const float& rhs) {
        this->x_ *= rhs;
        this->y_ *= rhs;
        this->z_ *= rhs;

        return *this;
    }

    Vector
    operator*(const Vector& lhs, const float& rhs) {
        Vector mul   = lhs;
        mul         *= rhs;
        return mul;
    }

    Vector
    operator*(const float& lhs, const Vector& rhs) {
        Vector mul   = rhs;
        mul         *= lhs;
        return mul;
    }

    std::ostream&
    operator<<(std::ostream& os, const Vector& v) {
        os  << "("
            << v.x_
            << ", "
            << v.y_
            << ", "
            << v.z_
            << ")"
            ;
        return os;
    }
} // namespace vector
} // namespace raytracing
