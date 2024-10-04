ADD_EXECUTABLE(
  hello
  hello.cpp
)

ADD_EXECUTABLE(
  intro
  intro.cpp
)

ADD_EXECUTABLE(
  c-container
  c-container.c
)

ADD_EXECUTABLE(
  range-based-for
  range-based-for.cpp
)

ADD_EXECUTABLE(
  point
  point.cpp
)

ADD_EXECUTABLE(
  explicit
  explicit.cpp
)

ADD_EXECUTABLE(
  int-ctor
  int-ctor.cpp
)

ADD_EXECUTABLE(
  point-default-init
  point-default-init.cpp
)

ADD_EXECUTABLE(
  point-const-members
  point-const-members.cpp
)

ADD_EXECUTABLE(
  vector-brace-init-ambiguous
  vector-brace-init-ambiguous.cpp
)

ADD_EXECUTABLE(
  references
  references.cpp
)

ADD_EXECUTABLE(
  return-reference
  return-reference.cpp
)

ADD_EXECUTABLE(
  overloading
  overloading.cpp
)

ADD_EXECUTABLE(
  file-io
  file-io.cpp
)

ADD_EXECUTABLE(
  default-init
  default-init.cpp
)

ADD_EXECUTABLE(
  inheritance
  inheritance.cpp
)

ADD_EXECUTABLE(
  chrono
  chrono.cpp
)

ADD_EXECUTABLE(
  string
  string.cpp
)

ADD_EXECUTABLE(
  expected
  expected.cpp
)

ADD_EXECUTABLE(
  smart-pointers
  smart-pointers.cpp
)
TARGET_LINK_LIBRARIES(
  smart-pointers
  toolcase-base
)
