cmake_minimum_required(VERSION 3.10)
project(Oblig4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Handle Apple Silicon vs Intel architectures
if(APPLE)
    # Check if we're on Apple Silicon
    execute_process(
            COMMAND uname -m
            OUTPUT_VARIABLE ARCH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    if(${ARCH} STREQUAL "arm64")
        # Apple Silicon - use /opt/homebrew
        set(CMAKE_PREFIX_PATH "/opt/homebrew")
        set(ENV{PKG_CONFIG_PATH} "/opt/homebrew/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
    else()
        # Intel Mac - use /usr/local
        set(CMAKE_PREFIX_PATH "/usr/local")
        set(ENV{PKG_CONFIG_PATH} "/usr/local/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
    endif()
endif()

INCLUDE(FindPkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)

if(NOT GTKMM_FOUND)
    message(FATAL_ERROR "GTKmm-3.0 not found")
endif()

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(opp2 Oblig4/opp2.cpp)
target_link_libraries(opp2 ${GTKMM_LIBRARIES})
target_compile_options(opp2 PRIVATE ${GTKMM_CFLAGS_OTHER})

add_executable(opp1 Oblig4/opp1.cpp)