ADD_EXECUTABLE(
  thermometer-firmware
  thermometer-firmware.cpp
)
TARGET_LINK_LIBRARIES(
  thermometer-firmware

  toolcase-can
  toolcase-base
)



ADD_EXECUTABLE(
  thermometer-firmware-hwmon2-cout-manual-proto
  thermometer-firmware-extern.cpp
  conf-hwmon2-cout-manual-proto.cpp
)
TARGET_LINK_LIBRARIES(
  thermometer-firmware-hwmon2-cout-manual-proto

  toolcase-can
  toolcase-base
)

ADD_CUSTOM_COMMAND(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/conf-hwmon2-csv.cpp
  COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/thermometer-firmware-confgen.py
          ${CMAKE_CURRENT_SOURCE_DIR}/config-hwmon2-csv.conf
          ${CMAKE_CURRENT_BINARY_DIR}/conf-hwmon2-csv.cpp
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/config-hwmon2-csv.conf
          ${CMAKE_CURRENT_SOURCE_DIR}/thermometer-firmware-confgen.py
)
ADD_EXECUTABLE(
  thermometer-firmware-hwmon2-csv
  thermometer-firmware-extern.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/conf-hwmon2-csv.cpp
)
TARGET_LINK_LIBRARIES(
  thermometer-firmware-hwmon2-csv

  toolcase-can
  toolcase-base
)



# ADD_CUSTOM_COMMAND(
#   OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/config-hwmon2-cout.cpp
#   COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/thermometer-firmware-confgen.py
#           ${CMAKE_CURRENT_SOURCE_DIR}/config-hwmon2-cout.conf
#           ${CMAKE_CURRENT_BINARY_DIR}/config-hwmon2-cout.cpp
#   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/config-hwmon2-cout.conf
#           ${CMAKE_CURRENT_SOURCE_DIR}/thermometer-firmware-confgen.py
# )
# ADD_EXECUTABLE(
#   thermometer-firmware-hwmon2-cout
#   thermometer-firmware-extern.cpp
#   ${CMAKE_CURRENT_BINARY_DIR}/config-hwmon2-cout.cpp
# )
# TARGET_LINK_LIBRARIES(
#   thermometer-firmware-hwmon2-cout
# 
#   toolcase-can
#   toolcase-base
# )
