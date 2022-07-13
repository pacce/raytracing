project('raytracing', 'cpp', version: '0.1.0')

png = dependency('libpng', required: true)

dependencies  = [png]
sources       = [
  'source/raytracing-png.cpp'
  ]
include       = ['include']
install_headers(
  [ 'include/raytracing.hpp'
  , 'include/raytracing-png.hpp'
  ])

raytracing = library(
  meson.project_name()
  , sources
  , dependencies        : dependencies
  , include_directories : include
  , install             : true
  )
raytracing_dep = declare_dependency(
  link_with             : raytracing
  , include_directories : include
  )

subdir('example')
