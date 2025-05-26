cmake_minimum_required(VERSION 3.16)
project(CourseworkSFML)

set(CMAKE_CXX_STANDARD 17)

set(SFML_ROOT "C:/SFML/SFML-3.0.0")

file(GLOB SRC_FILES src/*.cpp)

add_executable(CourseworkSFML ${SRC_FILES} "src/theme.cpp")

target_include_directories(CourseworkSFML PRIVATE ${SFML_ROOT}/include)
target_link_directories(CourseworkSFML PRIVATE ${SFML_ROOT}/lib)

target_compile_definitions(CourseworkSFML PRIVATE SFML_STATIC)

target_link_libraries(CourseworkSFML
    sfml-graphics-s
    sfml-window-s
    sfml-system-s
    sfml-audio-s
    sfml-network-s
    sfml-main-s

    freetype
    ogg
    vorbis
    vorbisfile
    FLAC

    winmm
    gdi32
    opengl32
    user32
    advapi32
)