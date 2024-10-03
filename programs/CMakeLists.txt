ADD_EXECUTABLE(
  thermometer-firmware
  thermometer-firmware.cpp
)
TARGET_LINK_LIBRARIES(
  thermometer-firmware

  toolcase-can
  toolcase-base
)
