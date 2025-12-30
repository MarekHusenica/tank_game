cmake_minimum_required(VERSION 3.10)
project(tank_game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

include(FetchContent)
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)

# --- 3. Define Executable ---
add_executable(TankGame
    src/main.cpp
    src/shader.cpp 
    src/tank.cpp
    thirdparty/glad/src/glad.c
)

# --- 4. Include Directories ---
# Using target_include_directories is better practice than include_directories
target_include_directories(TankGame PRIVATE 
    src
    thirdparty/glad/include
    ${SDL2_INCLUDE_DIRS}
)

# --- 5. Link Libraries ---
target_link_libraries(TankGame PRIVATE
    ${SDL2_LIBRARIES}
    glm::glm
    GL
)