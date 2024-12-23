project(Task3 CXX)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        ${PROJECT_SOURCE_DIR}/Task_3/src/Task3.cpp
        ${PROJECT_SOURCE_DIR}/Task_3/src/functions.cpp

)


include_directories(${PROJECT_SOURCE_DIR}/Task_3/include)

add_executable(Task3 ${SOURCES})