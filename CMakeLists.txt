cmake_minimum_required(VERSION 3.25)
project(餐厅管理)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES )

add_executable(main ${SOURCE_FILES} main.cpp Dish.cpp Restaurant.cpp SpecialDish.cpp OverseaDish.cpp NormalDish.cpp)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
