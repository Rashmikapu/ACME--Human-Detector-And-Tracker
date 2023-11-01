# Any C++ source files needed to build this target (cpp-test).
add_executable(cpp-test
  # list of source cpp files:
  main.cpp
  human_detector_test.cpp
  human_tracker_test.cpp
  visualization_test.cpp
  my_robot_test.cpp
  ../app/human_detector.cpp
  ../app/visualization.cpp
  ../app/human_tracker.cpp
  ../app/my_robot.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(cpp-test PUBLIC
  # list of include directories:
  ${CMAKE_SOURCE_DIR}/include
  ${OpenCV_INCLUDE_DIRS}
	${EIGEN3_INCLUDE_DIR}
  )

# Any dependent libraires needed to build this target.
target_link_libraries(cpp-test PUBLIC
  # list of libraries:
  gtest
  ${OpenCV_LIBS} 
  ${EIGEN3_LIBS}
  )

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
gtest_discover_tests(cpp-test)
