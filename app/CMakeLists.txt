find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
# Any C++ source files needed to build this target (shell-app).
add_executable(shell-app
  # list of source cpp files:
  main.cpp
  human_detector.cpp
  human_tracker.cpp
  my_robot.cpp
  visualization.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(shell-app PUBLIC
  # list inclue directories:
  ${CMAKE_SOURCE_DIR}/include
  ${OpenCV_INCLUDE_DIRS}
	${EIGEN3_INCLUDE_DIR}
  # PRIVATE /usr/local/include
)

# Any dependent libraires needed to build this target.
target_link_libraries(shell-app PUBLIC
  # list of libraries
  ${OpenCV_LIBS} 
  ${EIGEN3_LIBS}
  # PRIVATE /usr/local/lib/libopencv_core.so
  )
