# Compiler warnings (applied only to project targets, not dependencies)
include(${PROJECT_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

# Test executable
add_executable(__CMAKE_reee___tests
    test_example.cpp
)

# Detect Catch2 version: v3 has Catch2WithMain target, v2 does not
if(TARGET Catch2::Catch2WithMain)
    set(CATCH2_TARGET Catch2::Catch2WithMain)
    set(CATCH2_VERSION 3)
else()
    set(CATCH2_TARGET Catch2::Catch2)
    set(CATCH2_VERSION 2)
endif()

target_link_libraries(__CMAKE_reee___tests
    PRIVATE
        __CMAKE_reee__::lib
        ${CATCH2_TARGET}
        gmock
)

# Pass Catch2 version to source code for conditional includes
target_compile_definitions(__CMAKE_reee___tests PRIVATE CATCH2_VERSION=${CATCH2_VERSION})

# Apply strict warnings to this target only
set_project_warnings(__CMAKE_reee___tests)

# Enable CTest support
include(CTest)
enable_testing()

# Add Catch2 module path (v2 uses contrib/, v3 uses extras/)
if(EXISTS "${Catch2_SOURCE_DIR}/extras")
    list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/extras")
elseif(EXISTS "${Catch2_SOURCE_DIR}/contrib")
    list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/contrib")
endif()

include(Catch)
catch_discover_tests(__CMAKE_reee___tests)
