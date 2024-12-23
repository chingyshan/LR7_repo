project(Task5 CXX)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        ${PROJECT_SOURCE_DIR}/Task_5/src/Task5.cpp
        ${PROJECT_SOURCE_DIR}/Task_5/src/functions.cpp
)


include_directories(${PROJECT_SOURCE_DIR}/Task_5/include)

add_executable(Task5 ${SOURCES})