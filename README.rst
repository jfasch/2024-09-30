Development Workflow
====================

.. contents::
   :local:

Checkout and Initialization
---------------------------

.. code-block:: console

   $ cd ~/My-Projects                                  # <--- or wherever you like
   $ git clone https://github.com/jfasch/2024-09-30
   $ cd ~/My-Projects/2024-09-30
   $ git submodule init                                # <--- don't forget
   $ git submodule update                              # <--- don't forget

Build
-----

Create build directory for Intel architecture (``x86_64``)

.. code-block:: console

   $ mkdir ~/My-Builds/2024-09-30-x86_64               # <--- or wherever you like
   $ cd  ~/My-Builds/2024-09-30-x86_64
   $ cmake ~/My-Projects/2024-09-30
   $ make

Test
----

.. code-block:: console

   $ cd  ~/My-Builds/2024-09-30-x86_64                 # <--- or whatever you have chosen
   $ ./tests/2024-09-30-suite 
   Running main() from /home/jfasch/My-Projects/2024-09-30/googletest/googletest/src/gtest_main.cc
   [==========] Running 2 tests from 1 test suite.
   [----------] Global test environment set-up.
   [----------] 2 tests from some_first_test
   [ RUN      ] some_first_test.test_that_passes
   [       OK ] some_first_test.test_that_passes (0 ms)
   [ RUN      ] some_first_test.test_that_fails
   /home/jfasch/My-Projects/2024-09-30/tests/some-first-test.cpp:17: Failure
   Value of: container.has(2)
     Actual: false
   Expected: true
   
   [  FAILED  ] some_first_test.test_that_fails (0 ms)
   [----------] 2 tests from some_first_test (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 2 tests from 1 test suite ran. (0 ms total)
   [  PASSED  ] 1 test.
   [  FAILED  ] 1 test, listed below:
   [  FAILED  ] some_first_test.test_that_fails
   
    1 FAILED TEST

Vcpkg
----
Start VScode and Open the folder where the project is checked out (File -> Open Folder).

Install the following extensions that show up in the RECOMMENDED Section:
- C/C++
- C/C++ Extension Pack
- CMake
- Embedded Tools (Required for VCPKG)
- C++ TestMate

After all extensions are installed, press CTRL + Shift + P and enter the command vcpkg activate.