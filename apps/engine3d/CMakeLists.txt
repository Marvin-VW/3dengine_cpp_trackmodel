# Copyright (C) 2024 twyleg
set(TARGET_NAME engine3d)

find_package(Qt6 COMPONENTS REQUIRED Core)


#
# add source files to target
#
add_executable(${TARGET_NAME}
    main.cc
)


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
    engine3d::core
    engine3d::ui
    Qt::Core
)
