project(Task1 CXX)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        ${PROJECT_SOURCE_DIR}/Task_2/src/Task2.cpp
        ${PROJECT_SOURCE_DIR}/Task_2/src/functions.cpp
)


include_directories(${PROJECT_SOURCE_DIR}/Task_2/include)

add_executable(Task2 ${SOURCES})
