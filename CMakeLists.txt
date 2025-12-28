CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(tank_game)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(
    src
    thirdparty/glad/include
    ${SDL2_INCLUDE_DIRS}
)

add_executable(TankGame
    src/main.cpp
    thirdparty/glad/src/glad.c
)

target_link_libraries(TankGame
    ${SDL2_LIBRARIES}
    GL
)