# !!! WARNING !!! AUTO-GENERATED FILE, PLEASE DO NOT MODIFY IT AND USE
# https://docs.platformio.org/page/projectconf/section_env_build.html#build-flags
#
# If you need to override existing CMake configuration or add extra,
# please create `CMakeListsUser.txt` in the root of project.
# The `CMakeListsUser.txt` will not be overwritten by PlatformIO.

cmake_minimum_required(VERSION 3.13)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

project("platformio" C CXX)

include(CMakeListsPrivate.txt)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeListsUser.txt)
include(CMakeListsUser.txt)
endif()

add_custom_target(
    Production ALL
    COMMAND platformio -c clion run "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    Debug ALL
    COMMAND platformio -c clion debug "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Z_DUMMY_TARGET ${SRC_LIST}
        ../ardeublement/ardeublement.ino
        ../ardeublement/CDF.cpp
        ../ardeublement/CDF.hpp
        ../ardeublement/ComposeDrunk.cpp
        ../ardeublement/ComposeDrunk.hpp
        ../ardeublement/ComposeGaussian.cpp
        ../ardeublement/ComposeGaussian.hpp
        ../ardeublement/ComposeModule.hpp
        ../ardeublement/ComposeRand.cpp
        ../ardeublement/ComposeRand.hpp
        ../ardeublement/ComposeToneRow.hpp
        ../ardeublement/IPerformer.hpp
        ../ardeublement/Logger.cpp
        ../ardeublement/Logger.hpp
        ../ardeublement/MidiClock.cpp
        ../ardeublement/MidiClock.hpp
        ../ardeublement/Params.hpp
        ../ardeublement/PerformModule-impl.hpp
        ../ardeublement/PerformModule.hpp
        ../ardeublement/PerformMonophonic.cpp
        ../ardeublement/PerformMonophonic.hpp
        ../ardeublement/PerformMultitimbral-impl.hpp
        ../ardeublement/PerformMultitimbral.hpp
        ../ardeublement/PerformPolyphonic-impl.hpp
        ../ardeublement/PerformPolyphonic.hpp
        ../ardeublement/Scale.cpp
        ../ardeublement/Scale.hpp
        ../ardeublement/SerialConsole.cpp
        ../ardeublement/SerialConsole.hpp
        ../ardeublement/Util.cpp
        ../ardeublement/Util.hpp
        )
