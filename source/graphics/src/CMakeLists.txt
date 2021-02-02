include_directories(${PROJECT_SOURCE_DIR}/source/graphics/headers)

# file(GLOB CPP_SOURCES
#     ${PROJECT_SOURCE_DIR}/source/graphics/src/*.cpp
# )

add_executable(Engine ${PROJECT_SOURCE_DIR}/source/graphics/src/Utils.cpp)
