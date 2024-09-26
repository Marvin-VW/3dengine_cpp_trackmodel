# Copyright (C) 2024 twyleg
cmake_minimum_required(VERSION 3.16.3)


project(engine3d)

# Externals
add_subdirectory(external/googletest/)

# Libs
add_subdirectory(libs/engine3d/core/)
add_subdirectory(libs/engine3d/ui/)
add_subdirectory(libs/engine3d/engine/)

# Apps
add_subdirectory(apps/engine3d)


# Unit-Test
add_subdirectory(unit_tests/)
