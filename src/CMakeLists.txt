cmake_minimum_required(VERSION 3.6)
project(src)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c main.h game.c game.h gfx.c screen.c player.h player.c enemy.c enemy.h)
add_executable(src ${SOURCE_FILES})

target_link_libraries(src SDL2 SDL2_image)