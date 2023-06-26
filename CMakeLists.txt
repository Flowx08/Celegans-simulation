cmake_minimum_required(VERSION 3.10)

project(micro VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(APPLE)
  include_directories(/opt/homebrew/include)
  link_directories(/opt/homebrew/lib)
elseif(UNIX)
  include_directories(/usr/local/include)
  link_directories(/usr/local/lib)
endif()

# Source files
file(GLOB_RECURSE SOURCES "./src/*.c")

# Executable
add_executable(main ${SOURCES})

# Link libraries
find_package(OpenGL REQUIRED)

target_link_libraries(main
  ${OPENGL_LIBRARIES}
  m # math library
  )

target_link_libraries(main
  SDL2
  )

# Compiler flags
target_compile_options(main PRIVATE -Wall -O3)
