ADD_LIBRARY(toolcase-can

  ICan.h
  CanDataSink.cpp
  CanCoutPeriph.cpp
)
TARGET_LINK_LIBRARIES(
  toolcase-can

  toolcase-base
)

TARGET_INCLUDE_DIRECTORIES(
  toolcase-can

  INTERFACE

  ..
)
