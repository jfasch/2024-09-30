ADD_EXECUTABLE(
  emb-poly-obj-can-thermometer-firmware
  can-thermometer-firmware.cpp
)
TARGET_LINK_LIBRARIES(
  emb-poly-obj-can-thermometer-firmware

  emb-poly-obj-toolcase-can
  emb-poly-obj-toolcase-base
)
