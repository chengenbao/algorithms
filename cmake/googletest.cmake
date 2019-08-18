include(ExternalProject)

ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest
  GIT_TAG           release-1.8.0
  INSTALL_COMMAND   ""
)

ExternalProject_Get_Property(googletest install_dir)
include_directories(${install_dir}/src/googletest/googletest/include)

ExternalProject_Get_Property(googletest binary_dir)

add_library(gtest UNKNOWN IMPORTED)
add_library(gtest_main UNKNOWN IMPORTED)

set_target_properties(gtest PROPERTIES
    IMPORTED_LOCATION ${binary_dir}/googlemock/gtest/libgtest.a
)

set_target_properties(gtest_main PROPERTIES
    IMPORTED_LOCATION ${binary_dir}/googlemock/gtest/libgtest_main.a
)

add_dependencies(gtest googletest)
add_dependencies(gtest_main googletest)
