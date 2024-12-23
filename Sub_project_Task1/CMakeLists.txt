project(Task1 CXX)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        ${PROJECT_SOURCE_DIR}/Task_1/src/Task1.cpp
        ${PROJECT_SOURCE_DIR}/Task_1/src/functions.cpp
)


include_directories(${PROJECT_SOURCE_DIR}/Task_1/include)

add_executable(Task1 ${SOURCES})
