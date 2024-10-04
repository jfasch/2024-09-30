ADD_EXECUTABLE(
  emb-2024-09-30-suite

  raw-mem-sensor.cpp
  file-sensor-suite.cpp
  can-sink-suite.cpp

  tmpdir-fixture.cpp
)

TARGET_LINK_LIBRARIES(
  emb-2024-09-30-suite

  emb-toolcase-base
  emb-toolcase-can

  gtest_main 
)
