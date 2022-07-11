#ifndef PNG_HPP__
#define PNG_HPP__

#include <cstdint>
#include <string>
#include <vector>

namespace png {
    using Pixel = uint8_t;
    using Image = std::vector<Pixel>;
    using Height    = std::size_t;
    using Width     = std::size_t;

    void
    write(
            const std::string&  filename
            , const Image&      image
            , Width             ws
            , Height            hs
            );
} // namespace png

#endif //  PNG_HPP__
