project(procks)
cmake_minimum_required(VERSION 3.22)

### Create libprocks
add_library(procks SHARED src/game.c)
include_directories(procks include)

###Create excecutable
add_executable(p-rocks src/main.c)
include_directories(p-rocks include)
target_link_libraries(p-rocks procks)
