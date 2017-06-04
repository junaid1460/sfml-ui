cmake_minimum_required(VERSION 2.8)

project(UILIB CXX)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

option(win64 "windows 64 bit" OFF )


add_custom_command(
  OUTPUT src/template_parser/src/lexer.cpp
  COMMAND ${FLEX_EXECUTABLE} 
  flex -o src/template_parser/src/lexer.cpp src/template_parser/src/lexer.l
  DEPENDS src/template_parser/src/lexer.l
)


add_custom_command(
  OUTPUT src/template_parser/src/parser.cpp
  COMMAND ${BISON_EXECUTABLE} 
  bison -d -o src/template_parser/src/parser.cpp src/template_parser/src/parser.y
  
  DEPENDS src/template_parser/src/parser.y
)


add_custom_target(project_files ALL
    DEPENDS src/template_parser/src/lexer.cpp src/template_parser/src/parser.cpp)



project(transpiler)

add_library(parser SHARED src/template_parser/src/parser.cpp )

add_executable(parser-test src/template_parser/src/main.cpp)
target_link_libraries(parser-test parser)
add_definitions("-std=c++14")

if(UNIX)
	add_executable(app ./main.cpp)
	include_directories("${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/include/")
	add_definitions("-Wall -std=c++14")
    target_link_libraries(app dl)
    find_package(Threads)
    target_link_libraries(app ${CMAKE_THREAD_LIBS_INIT})

	find_package(X11 REQUIRED)
	target_link_libraries(app X11)
	
	find_library(sfgfx sfml-graphics ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	find_library(sfsys sfml-system ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	find_library(sfwin sfml-window ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	find_library(sfaud sfml-audio ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	find_library(sfnet sfml-network ${PROJECT_SOURCE_DIR}/external/sfml/linux-gcc-64/lib/)
	add_library(uxmodule SHARED ${PROJECT_SOURCE_DIR}/src/uxlib.module.cpp)
	target_link_libraries(uxmodule ${sfgfx} ${sfsys} ${sfwin} ${sfaud} ${sfnet})
	target_link_libraries(app uxmodule)


else(UNIX)
	add_executable(app.exe ./main.cpp)
	add_definitions("-Wall /std:c++14")
	if(win64)
		message("Generating build files for windows 64bit machine")
		include_directories("${PROJECT_SOURCE_DIR}/external/sfml/win64/include/")
		find_library(sfgfx sfml-graphics ${PROJECT_SOURCE_DIR}/external/sfml/win64/lib/)
		find_library(sfsys sfml-system ${PROJECT_SOURCE_DIR}/external/sfml/win64/lib/)
		find_library(sfwin sfml-window ${PROJECT_SOURCE_DIR}/external/sfml/win64/lib/)
		find_library(sfaud sfml-audio ${PROJECT_SOURCE_DIR}/external/sfml/win64/lib/)
		find_library(sfnet sfml-network ${PROJECT_SOURCE_DIR}/external/sfml/win64/lib/)
		target_link_libraries(app.exe ${sfgfx} ${sfsys} ${sfwin} ${sfaud} ${sfnet})
	else(win64)
		message("Generating build files for windows 32bit machine")
		include_directories("${PROJECT_SOURCE_DIR}/external/sfml/win32/include/")
		find_library(sfgfx sfml-graphics ${PROJECT_SOURCE_DIR}/external/sfml/win32/lib/)
		find_library(sfsys sfml-system ${PROJECT_SOURCE_DIR}/external/sfml/win32/lib/)
		find_library(sfwin sfml-window ${PROJECT_SOURCE_DIR}/external/sfml/win32/lib/)
		find_library(sfaud sfml-audio ${PROJECT_SOURCE_DIR}/external/sfml/win32/lib/)
		find_library(sfnet sfml-network ${PROJECT_SOURCE_DIR}/external/sfml/win32/lib/)
		target_link_libraries(app.exe ${sfgfx} ${sfsys} ${sfwin} ${sfaud} ${sfnet})
		
	endif(win64)
	find_package(Threads)
    target_link_libraries(app ${CMAKE_THREAD_LIBS_INIT})
endif(UNIX)

