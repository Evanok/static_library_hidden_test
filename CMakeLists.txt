project(static_hiddem_library_test)

set(CMAKE_VERBOSE_MAKEFILE ON)

option(DEBUG "Enable DEBUG" OFF)

string(TIMESTAMP BUILD_TIME "%Y-%m-%d %H:%M:%S")
add_definitions(-DBUILD_TIME="${BUILD_TIME}")
message(STATUS "system name ${CMAKE_SYSTEM_NAME}")
message(STATUS "host system name ${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "system processor '${CMAKE_SYSTEM_PROCESSOR}'")
message(STATUS "We are using ${CMAKE_GENERATOR}")

# handle DEBUG option  -------------------------------------------------
# by default we are in DEBUG off.
if(DEBUG)
  message(STATUS "DEBUG support is enabled")
  # handle all hifi target firs
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fstack-usage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fstack-usage")
else(RELEASE)
  message(STATUS "DEBUG support is not enabled")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -s -fvisibility=hidden")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -s -fvisibility=hidden")
endif()


set(LIBRARY_SOURCE
      ${CMAKE_CURRENT_SOURCE_DIR}/src/tutu1.c
      ${CMAKE_CURRENT_SOURCE_DIR}/src/tutu2.c
      ${CMAKE_CURRENT_SOURCE_DIR}/src/tutu3.c)

add_library(static_tutu_library STATIC ${LIBRARY_SOURCE})
target_compile_options(static_tutu_library PRIVATE "-Wl,--exclude-libs,ALL" "-Wl,-Bsymbolic" "-fvisibility=hidden")
target_link_options(static_tutu_library PRIVATE "-Wl,--exclude-libs,ALL" "-Wl,-Bsymbolic" "-fvisibility=hidden")
target_include_directories(static_tutu_library PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/inc")
set_target_properties(static_tutu_library PROPERTIES OUTPUT_NAME tutu)
 
message(STATUS "Final CFLAGS are ${CMAKE_C_FLAGS}")
message(STATUS "Final CXXFLAGS are ${CMAKE_CXX_FLAGS}")
message(STATUS "Final LDFLAGS are ${CMAKE_EXE_LINKER_FLAGS}")

add_custom_command(TARGET static_tutu_library POST_BUILD
COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/hide_symbol.sh $<TARGET_FILE:static_tutu_library>
COMMENT "Invoke hide symbol script"
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

unset(DEBUG CACHE)
