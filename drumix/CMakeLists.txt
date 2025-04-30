cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0135 NEW)
include(FetchContent)

project(drumix)

# External projects

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
FetchContent_Declare(glfw GIT_REPOSITORY "https://github.com/glfw/glfw" GIT_TAG "3.4")
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(json URL "https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz")
FetchContent_MakeAvailable(json)

# Drumix UI app

file(GLOB_RECURSE DRUMIXUI_SOURCES "ext/imgui/*.cpp" "src/ui/*.cpp")
add_executable(drumixui ${DRUMIXUI_SOURCES})

find_package(OpenGL REQUIRED)

target_include_directories(drumixui PRIVATE "ext/imgui")
target_link_libraries(drumixui PRIVATE glfw OpenGL::GL nlohmann_json::nlohmann_json)

# Drumix daemon app

file(GLOB_RECURSE DRUMIXD_SOURCES "ext/serialib/*.cpp" "src/daemon/*.cpp")
add_executable(drumixd ${DRUMIXD_SOURCES})

target_include_directories(drumixd PRIVATE "ext/serialib")
target_link_libraries(drumixui PRIVATE nlohmann_json::nlohmann_json)
