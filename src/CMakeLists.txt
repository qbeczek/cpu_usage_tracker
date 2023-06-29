# Set header list
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/threads/reader.h")

# Make an automatic library - will be static or dynamic based on user setting
add_library(threads_library threads/reader.c ${HEADER_LIST})

# Include directories
target_include_directories(threads_library PUBLIC ../include)

# All users of this library will need at least C11
target_compile_features(threads_library PUBLIC c_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
