ADD_LIBRARY(emb-toolcase-base

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

  raw-mem-sensor.cpp
  file-sensor.cpp
  random-sensor.cpp
)

TARGET_INCLUDE_DIRECTORIES(
  emb-toolcase-base

  INTERFACE

  ..
)
