cmake_minimum_required(VERSION 3.10)
project(023_the_grimoire)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(023_the_grimoire main.cpp
        src/RenderWindow.cpp
        src/Logger/Logger.cpp
        src/Systems/KeystrokeSystem.h
        src/Engine/Entity.h
        src/Systems/System.h
        src/Engine/Scene.h
        src/Engine/Component.h
)

target_link_libraries(023_the_grimoire PRIVATE
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)

target_include_directories(023_the_grimoire PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/vendor
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_MIXER_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
)