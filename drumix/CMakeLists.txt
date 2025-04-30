cmake_minimum_required(VERSION 3.21)
include(FetchContent)

project(drumix)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY "https://github.com/glfw/glfw"
    GIT_TAG "3.4"
)
FetchContent_MakeAvailable(glfw)

file(GLOB_RECURSE SOURCES "src/*.cpp" "ext/*.cpp")
add_executable(drumix ${SOURCES})
target_include_directories(drumix PRIVATE "ext" "ext/imgui")
target_link_libraries(drumix PRIVATE glfw opengl32)
