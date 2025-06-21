cmake_minimum_required(VERSION 3.16)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

include_directories(include)

set(RENDERING_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/rendering.c
  ${CMAKE_CURRENT_SOURCE_DIR}/include/rendering.h
)

add_library(rendering)
target_sources(rendering
 PRIVATE
  ${RENDERING_SOURCES}
  )

target_include_directories(rendering
 PRIVATE
 ${INCLUDE}
)

set(LOGIC_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/logic.c
  ${CMAKE_CURRENT_SOURCE_DIR}/include/logic.h
)

add_library(logic)
target_sources(logic
 PRIVATE
  ${LOGIC_SOURCES}
  )

target_include_directories(logic
 PRIVATE
 ${INCLUDE}
)

set(MAIN_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
  )

add_executable(main)
target_sources(main
 PRIVATE
  ${MAIN_SRC}
)

target_link_libraries(main
  PRIVATE SDL3::SDL3
  rendering
  logic
)
