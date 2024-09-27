# Copyright (C) 2024 twyleg
set(NAMESPACE engine3d)
set(MODULE engine)

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
    camera_model.cc
    camera_model.h
    homogenous_transformation_matrix.cc
    homogenous_transformation_matrix.h
    shape.cc
    shape.h
    fps_counter.cc
    fps_counter.h
    render_system.cc
    render_system.h
    engine.cc
    engine.h
    clipping_space.cc
    clipping_space.h
    vectors.cc
    vectors.h
    color.cc
    color.h
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
