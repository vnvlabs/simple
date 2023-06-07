//============================================================================
// Name        : simple-vnv.cpp
// Author      : Mark Carroll
// Version     : 0.1
// Copyright   : UT-Battelle, LLC
// Description : Simple test of the VnV framework
//============================================================================

#include <VnV.h>

#include <iostream>
using namespace std;

INJECTION_EXECUTABLE(SIMPLE,"{}");

/**
  This is an injection test.
**/
INJECTION_TEST(SIMPLE, test) {
  auto number = GetRef_NoCheck("number",int);
  cout << "The number is " << number << endl;
  return SUCCESS;
}

int main(int argc, char **argv) {
  INJECTION_INITIALIZE(SIMPLE, &argc, &argv, "vnv-input.json");

  cout << "Simple test of VnV" << endl;
  int i = 5;

  /**
    This is an injection point.
   **/
  INJECTION_POINT(SIMPLE, VSELF, point, VNV_NOCALLBACK, i);

  VnV_Info(SIMPLE, "i = %d", i);
  INJECTION_FINALIZE("SIMPLE");
  return 0;
}
