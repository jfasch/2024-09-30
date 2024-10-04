ADD_LIBRARY(emb-toolcase-can

  ICan.h
  CanDataSink.cpp
  CanCoutPeriph.cpp

  SocketCANPeriph.h
  SocketCANPeriph.cpp
)
TARGET_LINK_LIBRARIES(
  emb-toolcase-can

  emb-toolcase-base
)

TARGET_INCLUDE_DIRECTORIES(
  emb-toolcase-can

  INTERFACE

  ..
)
