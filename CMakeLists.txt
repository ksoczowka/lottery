cmake_minimum_required(VERSION 3.11)

project(Lottery)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN_DIR ${CMAKE_SOURCE_DIR}/app/lottery)
set(GEN_DIR ${CMAKE_SOURCE_DIR}/app/list-generator)

set(MAIN_SRC ${MAIN_DIR}/main.cpp)
set(GEN_SRC ${GEN_DIR}/main.cpp)

set(MAIN_FILES ${MAIN_DIR}/list.lottery ${MAIN_DIR}/logs.lottery ${MAIN_DIR}/remainingItems.lottery ${MAIN_DIR}/usedItems.lottery)
set(GEN_FILES ${GEN_DIR}/example.txt)

file(COPY ${MAIN_FILES} DESTINATION ${CMAKE_BINARY_DIR}/lottery)
file(COPY ${GEN_FILES} DESTINATION ${CMAKE_BINARY_DIR}/list-generator)

add_executable(Lottery ${MAIN_SRC})
add_executable(Generator ${GEN_SRC})
