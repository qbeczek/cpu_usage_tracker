# Works with 3.14 and tested through 3.26
cmake_minimum_required(VERSION 3.14...3.26)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)  

# Project name and a few useful settings. Other commands can pick up the results
project(
  cpu_usage_tracker
  VERSION 0.1
  DESCRIPTION "CPU usage tracker with pthread"
  LANGUAGES C)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app
  include(CTest)
endif()

# Set the desired compiler (GCC or Clang)
if(NOT DEFINED COMPILER)
  set(COMPILER "GCC")  # Default to GCC if not specified
endif()

# Set compiler-specific flags and executable
if(COMPILER STREQUAL "GCC")
  # Set GCC-specific flags and executable
  set(CMAKE_C_COMPILER gcc)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
elseif(COMPILER STREQUAL "Clang")
  # Set Clang-specific flags and executable
  set(CMAKE_C_COMPILER clang)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Weverything")
endif()

include(FetchContent)

find_package(Threads REQUIRED)

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()


