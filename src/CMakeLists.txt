cmake_minimum_required(VERSION 3.23)
project(oaa)

add_executable(main main.cpp)
set_target_properties(main
  PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)
