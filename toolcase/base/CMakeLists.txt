ADD_LIBRARY(toolcase-base

  raw-mem-sensor.cpp
  file-sensor.cpp
  CoutDataSink.cpp
  CanDataSink.cpp
  CanCoutPeriph.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  toolcase-base

  PUBLIC
  ..
)
