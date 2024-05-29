cmake_minimum_required(VERSION 3.16)
project(binary LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(RAYLIB
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0)
FetchContent_MakeAvailable(RAYLIB)

add_executable(binary sources/main.c)
target_include_directories(binary PRIVATE includes)
target_link_libraries(binary PRIVATE raylib)
target_compile_features(binary PRIVATE c_std_99)

if(WIN32)
    add_custom_command(
        TARGET binary
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:binary>
        VERBATIM)
endif()

install(TARGETS binary)