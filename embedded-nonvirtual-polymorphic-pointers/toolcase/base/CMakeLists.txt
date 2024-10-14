ADD_LIBRARY(emb-poly-ptr-toolcase-base

  CompositeSink.h
  CoutSink.h
  CsvSink.h
  file-sensor.h
  DataSinkAlternative.h
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
  emb-poly-ptr-toolcase-base

  INTERFACE

  ..
)
