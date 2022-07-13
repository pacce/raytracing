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
        , Associative
        , (const Vector& xs, const Vector& ys, const Vector& zs)
        )
{
    RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
}

RC_GTEST_PROP(
        Add
        , Commutative
        , (const Vector& xs, const Vector& ys)
        )
{
    RC_ASSERT((xs + ys) == (ys + xs));
}

RC_GTEST_PROP(
        Add
        , Neutral
        , (const Vector& xs)
        )
{
    Vector ys = {};
    RC_ASSERT((xs + ys) == xs);
}

RC_GTEST_PROP(
        Add
        , Successor
        , (const Vector& xs)
        )
{
    Vector ys(1.0, 1.0, 1.0);
    RC_ASSERT((xs + ys) != xs);
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
