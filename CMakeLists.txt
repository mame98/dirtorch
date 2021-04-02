cmake_minimum_required(VERSION 3.17)
project(dirtorch)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(external_termbox
        GIT_REPOSITORY https://github.com/mame98/termbox
        GIT_TAG master)
FetchContent_MakeAvailable(external_termbox)


add_executable(dirtorch main.cpp src/data/Layer.cpp src/data/Layer.h src/data/Entity.cpp src/data/Entity.h src/data/FileEntity.cpp src/data/FileEntity.h src/data/DirectoryEntity.cpp src/data/DirectoryEntity.h)
target_include_directories(dirtorch PRIVATE src/data)
target_link_libraries(dirtorch PRIVATE termbox)