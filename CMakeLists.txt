cmake_minimum_required(VERSION 3.14)
project(third_sem_lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Sequence.h LinkedList.h Menu.h Sort.h Complex.h DynamicArray.h Tree.h Map.h Draw.h Test.h)
add_executable(third_sem_lab1 ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(third_sem_lab1 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)