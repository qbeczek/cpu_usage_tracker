# Add the executable target named "main" and specify the source file "main.c"
add_executable(main main.c)

# Set the C standard to C11 for the "main" target
target_compile_features(main PRIVATE c_std_11)

# Link the "main" target with the "threads_library" and "Threads::Threads" libraries
target_link_libraries(main PRIVATE threads_library Threads::Threads)

# Add valgrind to check executable target
find_program(VALGRIND "valgrind")
if (VALGRIND)
    add_custom_target(valgrind
        COMMAND ${VALGRIND} --leak-check=full --track-origins=yes $<TARGET_FILE:main>
        DEPENDS main
        COMMENT "Running Valgrind")
else ()
    message(WARNING "Valgrind not found. Cannot create the valgrind target.")
endif ()
