#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>

#include <raytracing.hpp>

using raytracing::vector::Vector;

namespace rc {
template<>
struct Arbitrary<Vector> {
    static Gen<Vector> arbitrary() {
        return gen::construct<Vector>(
                gen::cast<float>(gen::inRange(-100, 100))
                , gen::cast<float>(gen::inRange(-100, 100))
                , gen::cast<float>(gen::inRange(-100, 100))
                );
    }
};
} // namespace rc

RC_GTEST_PROP(
        Add
        , Commutative
        , (const Vector& lhs, const Vector& rhs)
        )
{
    RC_ASSERT((lhs + rhs) == (rhs + lhs));
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
