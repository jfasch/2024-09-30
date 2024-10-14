ADD_EXECUTABLE(
  emb-poly-ptr-2024-09-30-suite

  raw-mem-sensor.cpp
  file-sensor-suite.cpp
  can-sink-suite.cpp
  sensor-reader-suite.cpp

  tmpdir-fixture.cpp
)

TARGET_LINK_LIBRARIES(
  emb-poly-ptr-2024-09-30-suite

  emb-poly-ptr-toolcase-base
  emb-poly-ptr-toolcase-can

  gtest_main 
)
