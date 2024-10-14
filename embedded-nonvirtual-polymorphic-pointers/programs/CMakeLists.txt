ADD_EXECUTABLE(
  emb-poly-ptr-can-thermometer-firmware
  can-thermometer-firmware.cpp
)
TARGET_LINK_LIBRARIES(
  emb-poly-ptr-can-thermometer-firmware

  emb-poly-ptr-toolcase-can
  emb-poly-ptr-toolcase-base
)
