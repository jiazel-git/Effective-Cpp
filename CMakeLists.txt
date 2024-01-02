cmake_minimum_required(VERSION 3.5.0)
project(class VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
include_directories(./include include)
aux_source_directory(./src src)
add_executable(class ${include} ${src})
set(CMAKE_CXX_STANDARD 11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
