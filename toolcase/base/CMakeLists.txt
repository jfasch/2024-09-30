SET(BASE_HEADER_FILES

  CompositeSink.h
  CoutSink.h
  CsvSink.h
  file-sensor.h
  IDataSink.h
  ISensor.h
  plat.h
  raw-mem-sensor.h
  sensor-reader.h
  test-sensor.h
  random-sensor.h
)

ADD_LIBRARY(toolcase-base
  ${BASE_HEADER_FILES}

  raw-mem-sensor.cpp
  file-sensor.cpp
  random-sensor.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  toolcase-base

  INTERFACE

  ..
)


INSTALL(TARGETS toolcase-base)
INSTALL(FILES

  ${BASE_HEADER_FILES}

  DESTINATION include/base
)
