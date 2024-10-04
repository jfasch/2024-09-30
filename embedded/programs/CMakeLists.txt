ADD_EXECUTABLE(
  emb-can-thermometer-firmware
  can-thermometer-firmware.cpp
)
TARGET_LINK_LIBRARIES(
  emb-can-thermometer-firmware

  emb-toolcase-can
  emb-toolcase-base
)
