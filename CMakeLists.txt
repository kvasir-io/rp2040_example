cmake_minimum_required(VERSION 3.18)

include(kvasir/cmake/kvasir.cmake)

project("rp2040_example" VERSION 0.1.0)

include(kvasir/cmake/util.cmake)

add_executable(debug src/main.cpp)
target_configure_kvasir(debug OPTIMIZATION_STRATEGY size USE_LOG)

add_executable(release src/main.cpp)
target_configure_kvasir(release OPTIMIZATION_STRATEGY size)

