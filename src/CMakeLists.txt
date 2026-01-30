# Compiler warnings (applied only to project targets, not dependencies)
include(${PROJECT_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

# Library target
add_library(__CMAKE_reee___lib
    example.cpp
)

# Add alias for consistent naming
add_library(__CMAKE_reee__::lib ALIAS __CMAKE_reee___lib)

target_include_directories(__CMAKE_reee___lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(__CMAKE_reee___lib
    PUBLIC
        cxx_std_${CMAKE_CXX_STANDARD}
)

# Apply strict warnings to this target only
set_project_warnings(__CMAKE_reee___lib)

# Optional: Add other libs you want warnings for here

# Optional: Create an executable
# Uncomment if you want a main executable
# add_executable(__CMAKE_reee__
#     main.cpp
# )
# 
# target_link_libraries(__CMAKE_reee__
#     PRIVATE
#         __CMAKE_reee__::lib
# )
