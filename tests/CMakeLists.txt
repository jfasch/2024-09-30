ADD_EXECUTABLE(
  2024-09-30-suite

  raw-mem-sensor.cpp
  file-sensor-suite.cpp
  can-sink-suite.cpp

  tmpdir-fixture.cpp
)

TARGET_LINK_LIBRARIES(
  2024-09-30-suite

  toolcase-base
  toolcase-can

  gtest_main 
)
