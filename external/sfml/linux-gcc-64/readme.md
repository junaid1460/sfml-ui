Build sfml from source if the provided files didn't work.

gcc symbol missing error workaround :
goto sfml_source and change graphics's cmake
add the following lines 

if(SFML_COMPILER_GCC AND BUILD_SHARED_LIBS)
     message(WARNING "Applying workaround for https://bugs.launchpad.net/ubuntu/+source/gcc+bug/1568899")
     list(APPEND GRAPHICS_EXT_LIBS "-lgcc_s -lgcc")
endif()

just before the sfml_add_library() function call
