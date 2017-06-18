cmake_minimum_required(VERSION 2.8)

project(UILIB CXX)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/debug/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/debug)

option(win64 "windows 64 bit" OFF )

#parser
add_custom_command(
  OUTPUT ${PROJECT_SOURCE_DIR}/src/template_parser/src/lexer.cpp
  COMMAND ${FLEX_EXECUTABLE} 
  flex -o ${PROJECT_SOURCE_DIR}/src/template_parser/src/lexer.cpp src/template_parser/src/lexer.l
  DEPENDS ${PROJECT_SOURCE_DIR}/src/template_parser/src/lexer.l
)


add_custom_command(
  OUTPUT ${PROJECT_SOURCE_DIR}/src/template_parser/src/parser.cpp
  COMMAND ${BISON_EXECUTABLE} 
  bison -d -o ${PROJECT_SOURCE_DIR}/src/template_parser/src/parser.cpp src/template_parser/src/parser.y
  
  DEPENDS ${PROJECT_SOURCE_DIR}/src/template_parser/src/parser.y
)


add_custom_target(project_files ALL
    DEPENDS ${PROJECT_SOURCE_DIR}/src/template_parser/src/lexer.cpp src/template_parser/src/parser.cpp)



project(transpiler)

add_library(parser SHARED ${PROJECT_SOURCE_DIR}/src/template_parser/src/parser.cpp )

add_executable(parser-test ${PROJECT_SOURCE_DIR}/src/template_parser/src/main.cpp)
target_link_libraries(parser-test parser)
#\parser

#-DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
add_definitions("-std=c++14")

if(UNIX)
	add_executable(app ./main.cpp)
	#include_directories("${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/include/")

    target_link_libraries(app dl)
    find_package(Threads)
    target_link_libraries(app ${CMAKE_THREAD_LIBS_INIT})

	find_package(X11 REQUIRED)
	target_link_libraries(app X11)
	
	# find_library(sfgfx sfml-graphics ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	# find_library(sfsys sfml-system ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	# find_library(sfwin sfml-window ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	# find_library(sfaud sfml-audio ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	# find_library(sfnet sfml-network ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	 add_library(uxmodule SHARED ${PROJECT_SOURCE_DIR}/src/uxlib.module.cpp)
	# target_link_libraries(uxmodule ${sfgfx} ${sfsys} ${sfwin} ${sfaud} ${sfnet})
	target_link_libraries(uxmodule sfml-graphics sfml-system sfml-window )
  
	target_link_libraries(app uxmodule)
endif(UNIX)

