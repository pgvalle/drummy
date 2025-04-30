cmake_minimum_required(VERSION 3.21)

project(drumix)

add_executable(
    drumix
    "ext/serialib.cpp"
    "src/main.cpp"
)

target_include_directories(drumix PRIVATE "ext")

if(WIN32)
    target_link_libraries(drumix PRIVATE opengl32 gdi32)
elseif(UNIX)
    target_link_libraries(drumix PRIVATE X11 GL Xrandr)
endif()