ADD_LIBRARY(toolcase-base

  raw-mem-sensor.cpp
  file-sensor.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  toolcase-base

  INTERFACE

  ..
)
