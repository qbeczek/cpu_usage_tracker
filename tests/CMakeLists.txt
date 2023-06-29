# Tests need to be added as executables first
add_executable(testlib testlib.c)

# C11 in the test
target_compile_features(testlib PRIVATE c_std_11)

# Link libraries
target_link_libraries(testlib PRIVATE threads_library Threads::Threads)

# Enable testing functionality
enable_testing()

# define tests
add_test(
  NAME example_test_1
  COMMAND testlib
)

