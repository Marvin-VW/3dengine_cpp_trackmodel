#Copyright (C) 2024 Marvin-VW
set(NAMESPACE engine3d)
set(MODULE trackmodel)

set(TARGET_NAME "${NAMESPACE}_${MODULE}")

#
# find packages
#
find_package(fmt REQUIRED)
find_package(Boost COMPONENTS REQUIRED system)
find_package(OpenCV REQUIRED)

#
# add source files to target
#
add_library(${TARGET_NAME}
    trackmodel.h
    trackmodel.cc
)

add_library("${NAMESPACE}::${MODULE}" ALIAS ${TARGET_NAME})

#
# set target properties
#
set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_STANDARD 17
        INCLUDE_CURRENT_DIR ON
        AUTOMOC ON
        AUTORCC ON
)

#
# link against libs
#
target_link_libraries(${TARGET_NAME} 
    engine3d::ui
    engine3d::converter
    fmt::fmt
    Boost::system
    ${OpenCV_LIBS}
)

#
# add parent folder to targets include directories
#
target_include_directories(${TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../
    PUBLIC ${OpenCV_INCLUDE_DIRS}
    
)