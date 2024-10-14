ADD_LIBRARY(emb-poly-ptr-toolcase-can

  CanDataSink.h
  CanCoutPeriph.cpp

  SocketCANPeriph.h
  SocketCANPeriph.cpp
)
TARGET_LINK_LIBRARIES(
  emb-poly-ptr-toolcase-can

  emb-poly-ptr-toolcase-base
)

TARGET_INCLUDE_DIRECTORIES(
  emb-poly-ptr-toolcase-can

  INTERFACE

  ..
)
