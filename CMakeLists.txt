cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

project(libksysguard CXX)
set(PROJECT_VERSION "5.5.90")
set(PROJECT_VERSION_MAJOR 5)


#-----------------------------------------------------------------------------
#                              DEPENDENCIES
#-----------------------------------------------------------------------------
find_package(ECM 1.2.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

find_package(KF5 REQUIRED COMPONENTS Auth I18n)
find_package(ZLIB REQUIRED)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

include(ECMAddTests)
include(ECMInstallIcons)
include(ECMPackageConfigHelpers)
include(CheckIncludeFiles)
include(ECMSetupVersion)

ecm_setup_version(${PROJECT_VERSION}
                  VARIABLE_PREFIX KSYSGUARD
                  VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/ksysguard_version.h"
                  PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/KF5SysGuardConfigVersion.cmake"
                  SOVERSION 7
)
#-----------------------------------------------------------------------------
#                           BUILD TYPES & FLAGS
#-----------------------------------------------------------------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11 -fdiagnostics-color")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror -O2")

# strip binary in release mode
if(CMAKE_BUILD_TYPE MATCHES "RELEASE")
    set(CMAKE_EXE_LINKER_FLAGS "-s")
endif()

#-----------------------------------------------------------------------------
#                               SOURCES
#-----------------------------------------------------------------------------
add_subdirectory( processcore )

#-----------------------------------------------------------------------------
#                               TESTS
#-----------------------------------------------------------------------------
if(BUILD_TESTING)
    # add_subdirectory( tests )
endif()

#-----------------------------------------------------------------------------
#                               SUMMARY
#-----------------------------------------------------------------------------
message(STATUS " ↳ Compiler     → ${CMAKE_CXX_COMPILER}")
message(STATUS " ↳ Prefix       → ${CMAKE_INSTALL_PREFIX}")
message(STATUS " ↳ Build        → ${CMAKE_BUILD_TYPE}")
message(STATUS " ↳ CXX Flags    → ${CMAKE_CXX_FLAGS}")
include(FeatureSummary)
feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
