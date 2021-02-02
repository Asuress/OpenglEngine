cmake_minimum_required(VERSION 3.0.0)
project(Engine VERSION 0.1.0)
# add_subdirectory(source)
# add_subdirectory(dependencies)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")


file(GLOB
    CPP_SOURCES "source/*.cpp" "source/graphics/src/*.cpp"
)

add_compile_definitions(GLEW_STATIC)

include_directories(${PROJECT_SOURCE_DIR}/dependencies/include)
link_directories(${PROJECT_SOURCE_DIR}/dependencies/lib ${PROJECT_SOURCE_DIR}/dependencies/bin)
# link_directories(${PROJECT_SOURCE_DIR}/dependencies/bin)

add_executable(${PROJECT_NAME} ${CPP_SOURCES})

target_link_libraries(${PROJECT_NAME}
    kernel32
    opengl32
    glfw3
    # glew32s
    glew32
)
