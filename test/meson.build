gtest       = dependency('gtest', required: false)
rapidcheck  = dependency('rapidcheck', required: false)

if not gtest.found()
  project = subproject('gtest')
  gtest   = project.get_variable('gtest_dep')
endif

if not rapidcheck.found()
  project     = subproject('rapidcheck')
  rapidcheck  = project.get_variable('rapidcheck_dep')
endif

vector = executable(
  'test-vector'
  , 'test-vector.cpp'
  , dependencies  : [gtest, rapidcheck, raytracing_dep]
  )
test('test-vector', vector)
