add_executable(${CMAKE_PROJECT_NAME}_src main.cpp DynArray.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_src curses)