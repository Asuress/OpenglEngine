cmake_minimum_required(VERSION 3.0.0)
project(Engine VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

file(GLOB_RECURSE
CPP_SOURCES "source/*.cpp"
# "source/graphics/src/*.cpp" "source/graphics/shapes/src/*.cpp" "source/main/*.cpp" "source/main/headers/*.h"
)

file(GLOB
SOIL2_SOURCES "dependencies/SOIL2/src/SOIL2/*.c" "dependencies/SOIL2/src/*.cpp"
)

# add_library(SOIL2 STATIC ${SOIL2_SOURCES})

add_compile_definitions(GLEW_STATIC)

include_directories(${PROJECT_SOURCE_DIR}/dependencies/include)
include_directories(${PROJECT_SOURCE_DIR}/dependencies/SOIL2/src)
include_directories(${PROJECT_SOURCE_DIR}/source/headers)

link_directories(${PROJECT_SOURCE_DIR}/dependencies/lib)
# link_directories(${PROJECT_SOURCE_DIR}/dependencies/bin)

add_executable(${PROJECT_NAME} ${CPP_SOURCES})

target_link_libraries(${PROJECT_NAME}
SOIL2
opengl32
kernel32
glfw3
glew32
)
