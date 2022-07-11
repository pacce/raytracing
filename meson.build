project('raytracing', 'cpp', version: '0.1.0')

png = dependency('libpng', required: true)

dependencies  = [png]
sources       = [
  'source/main.cpp'
  , 'source/png/png.cpp'
  ]
include       = [
  'source/png'
  ]

executable(
  meson.project_name()
  , sources
  , dependencies        : dependencies
  , include_directories : include
  )
