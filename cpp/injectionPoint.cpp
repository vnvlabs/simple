

#include <mpi.h>
#include <time.h>

#include <chrono>
#include <iostream>
#include <map>
#include <sstream>
#include <thread>
#include <typeinfo>
#include <vector>

#include "VnV.h"

#define SPNAME SampleExecutable

/**
 * INJECTION EXECUTABLE
 * --------------------
 * 
 * Welcome to the machine.
 * 
 */
INJECTION_EXECUTABLE(SPNAME,"{}")

int main(int argc, char** argv) {
  /**
   * Sample Executable
   * =================
   *
   * This executable is designed to show a number of different injection points.
   * The first stage is to initialize the library. The text that appears in the
   * comment above the initialize call represents the introduction in the final
   * report.
   */
  INJECTION_INITIALIZE(SPNAME, &argc, &argv);

  std::vector<int> samplePoints;

   /**
   * Sample Executable
   * =================
   *
   * This executable is designed to show a number of different injection points.
   * The first stage is to initialize the library. The text that appears in the
   * comment above the initialize call represents the introduction in the final
   * report.
   */
   INJECTION_INPUT_FILE(SPNAME, EULERINPUT, VWORLD, "Makefile", "Makefile")
  
   INJECTION_INPUT_FILE(SPNAME, EULEROUT, VWORLD, "test.cpp", "test.cpp")

  /**
   *  A Simple Injection Point Loop
   *  -----------------------------
   *
   *  This injection point loop tracks the values in the vector sample
   *  points.

  **/
  INJECTION_LOOP_BEGIN(SPNAME, VSELF, Function1, VNV_NOCALLBACK, samplePoints);

  /**
   *  A Second Injection Point Loop
   *  -----------------------------
   *
   *  This injection point loop tracks the values in the vector sample
   *  points. This one is nested, but the iters wont be to test

  **/
  
  INJECTION_LOOP_BEGIN(SPNAME, VSELF, Function2,  VNV_NOCALLBACK, samplePoints);
  
  for (int i = 0; i < 10; i++) {
    samplePoints.push_back(i);
    INJECTION_LOOP_ITER(SPNAME, Function1, "inner", VNV_NOCALLBACK);
    INJECTION_LOOP_ITER(SPNAME, Function2, "inner", VNV_NOCALLBACK);
  
  }
  
  INJECTION_LOOP_END(SPNAME, Function2, VNV_NOCALLBACK);

  INJECTION_LOOP_END(SPNAME, Function1, VNV_NOCALLBACK);

  INJECTION_FINALIZE(SPNAME);
}
