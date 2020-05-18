cmake_minimum_required(VERSION 3.13)

include_directories(include)

add_library(ui
	include/color.h
	include/layouts
	include/layouts/layout.h
	include/painter.h
	include/property.h
	include/size.h
	include/widget.h
	include/widgets
	include/widgets/common.h
	include/window.h
	src/layouts
	src/layouts/layout.cpp
	src/painter.cpp
	src/widget.cpp
	src/widgets
	src/widgets/rectangle.cpp
	src/window.cpp)

target_link_libraries(ui SDL2)

add_executable(test test/main.cpp)
target_link_libraries(test ui)
