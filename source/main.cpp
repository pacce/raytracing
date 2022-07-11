#include <png.h>

#include <cstdio>
#include <cstdlib>
#include <iostream>

const png_uint_32 COLS  = 800;
const png_uint_32 ROWS  = 600;

int
main(int argc, char **argv) {
    std::FILE * handle  = std::fopen("hello.png", "wb");
    if (handle == nullptr) {
        exit(EXIT_FAILURE);
    }

    png_structp png = png_create_write_struct(
            PNG_LIBPNG_VER_STRING
            , NULL
            , NULL
            , NULL
            );
    if (png == nullptr) {
        exit(EXIT_FAILURE);
    }

    png_infop info = png_create_info_struct(png);
    if (info == nullptr) {
        exit(EXIT_FAILURE);
    }
    png_init_io(png, handle);
    png_set_IHDR(
            png
            , info
            , COLS
            , ROWS
            , 8
            , PNG_COLOR_TYPE_RGBA
            , PNG_INTERLACE_NONE
            , PNG_COMPRESSION_TYPE_DEFAULT
            , PNG_FILTER_TYPE_DEFAULT
            );
    png_write_info(png, info);

    png_bytep * rows    = new png_bytep[ROWS];
    png_uint_32 bytes   = png_get_rowbytes(png, info);

    for (png_uint_32 r = 0; r < ROWS; r++) {
        png_byte * row  = new png_byte[bytes];
        rows[r]         = row;
        for (png_uint_32 c = 0; c < COLS; c++) {
            *row++  = 255;  // Red
            *row++  = 0;    // Green
            *row++  = 0;    // Blue
            *row++  = 255;  // Alpha
        }
    }

    png_write_image(png, rows);
    png_write_end(png, NULL);

    for (png_uint_32 row = 0; row < ROWS; row++) {
        delete[] rows[row];
    }

    delete[] rows;

    png_destroy_write_struct(&png, &info);
    std::fclose(handle);

    exit(EXIT_SUCCESS);
}
