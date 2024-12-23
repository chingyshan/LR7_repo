project(Task5 CXX)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        ${PROJECT_SOURCE_DIR}/Task_4/src/Task4.cpp
        ${PROJECT_SOURCE_DIR}/Task_4/src/functions.cpp
)


include_directories(${PROJECT_SOURCE_DIR}/Task_4/include)

add_executable(Task4 ${SOURCES})