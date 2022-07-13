#ifndef RAYTRACING_VECTOR_HPP__
#define RAYTRACING_VECTOR_HPP__

#include <fstream>

namespace raytracing {
namespace vector {
    class Vector {
        public:
            Vector();
            Vector(float x, float y, float z);

            friend bool
            operator==(const Vector& lhs, const Vector& rhs);

            friend bool
            operator!=(const Vector& lhs, const Vector& rhs);

            Vector&
            operator+=(const Vector& rhs);

            friend Vector
            operator+(const Vector& lhs, const Vector& rhs);

            Vector&
            operator-=(const Vector& rhs);

            friend Vector
            operator-(const Vector& lhs, const Vector& rhs);

            Vector&
            operator*=(const float& rhs);

            friend Vector
            operator*(const Vector& lhs, const float& rhs);

            friend Vector
            operator*(const float& lhs, const Vector& rhs);

            float x() const noexcept { return x_; }
            float y() const noexcept { return y_; }
            float z() const noexcept { return z_; }

            friend std::ostream&
            operator<<(std::ostream& os, const Vector& v);
        private:
            float x_;
            float y_;
            float z_;
    };
} // namespace vector
} // namespace raytracing

#endif // RAYTRACING_VECTOR_HPP__
