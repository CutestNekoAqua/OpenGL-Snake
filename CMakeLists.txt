cmake_minimum_required(VERSION 3.17)
project(snake)

set(CMAKE_CXX_STANDARD 14)
set( GLFW-CMAKE-SRC
        main.cpp
        glad.c
        include/main.h Game.cpp include/Game.h include/shader.h shader.cpp include/texture.h texture.cpp include/resource_manager.h resource_manager.cpp include/stb_image.h SpriteRenderer.cpp include/SpriteRenderer.h include/GameObject.h GameObject.cpp include/GameLevel.h GameLevel.cpp include/Keys.h)

find_package( OpenGL REQUIRED )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( glfw )
add_subdirectory( glm )

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

file(GLOB SOURCE textures/*.png shaders/*.vs shaders/*.frag)
add_executable(snake WIN32 ${GLFW-CMAKE-SRC})
target_link_libraries( snake ${OPENGL_LIBRARIES} glfw glm )
target_include_directories( snake PRIVATE ${OPENGL_INCLUDE_DIRS} include)

file(GLOB SHADERS
        "shaders/*.vs"
        "shaders/*.frag"
        "shaders/*.fs"
        "shaders/*.gs"
        )
foreach(SHADER ${SHADERS})
    if(WIN32)
        # configure_file(${SHADER} "test")
        add_custom_command(TARGET snake PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SHADER} $<TARGET_FILE_DIR:snake>)
    elseif(UNIX AND NOT APPLE)
        file(COPY ${SHADER} DESTINATION ${CMAKE_SOURCE_DIR}/bin)
    elseif(APPLE)
        # create symbolic link for *.vs *.fs *.gs
        get_filename_component(SHADERNAME ${SHADER} NAME)
        makeLink(${SHADER} ${CMAKE_SOURCE_DIR}/bin/${SHADERNAME} snake)
    endif(WIN32)
endforeach(SHADER)

# we don't want to copy if we're building in the source dir
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)

    # list of files for which we add a copy rule
    set(data_SHADOW textures/awesomeface.png shaders/sprite.frag shaders/sprite.vs textures/berry.png)

    foreach(item IN LISTS data_SHADOW)
        message(STATUS ${item})
        add_custom_command(
                OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
        )
    endforeach()
endif()

if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GLFW-CMake-starter )
    endif()
endif()

# files are only copied if a target depends on them
add_custom_target(face ALL "${CMAKE_CURRENT_BINARY_DIR}/textures/awsomeface.png")
add_custom_target(block ALL "${CMAKE_CURRENT_BINARY_DIR}/textures/berry.png")
add_custom_target(spritefrag ALL "${CMAKE_CURRENT_BINARY_DIR}/shaders/sprite.frag")
add_custom_target(spritevs ALL "${CMAKE_CURRENT_BINARY_DIR}/shaders/sprite.vs")