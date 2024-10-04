ADD_LIBRARY(emb-toolcase-can

  CanDataSink.h
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
