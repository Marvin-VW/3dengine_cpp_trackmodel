# Copyright (C) 2024 twyleg
cmake_minimum_required(VERSION 3.16.3)


project(engine3d)

# Externals
add_subdirectory(external/googletest/)

# Libs
add_subdirectory(libs/engine3d/core/)
add_subdirectory(libs/engine3d/ui/)
add_subdirectory(libs/engine3d/engine/)
add_subdirectory(libs/engine3d/curve_calculator/)
add_subdirectory(libs/engine3d/straight_calculator/)
add_subdirectory(libs/engine3d/image_filter/)

# Apps
add_subdirectory(apps/engine3d)


# Unit-Test
add_subdirectory(unit_tests/)
