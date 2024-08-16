
#include <mpi.h>

#include <iostream>
#include <vector>

#include "VnV.h"
#define SPNAME WorkflowExample

INJECTION_EXECUTABLE(SPNAME,"{}")

class Options {

};

/**
 * VnV Workflow Options.
 * 
 */
INJECTION_OPTIONS(SPNAME,"{}", Options) {

}

INJECTION_INJA_TEMPLATE(SPNAME, CommandLine, 
R"({
    "type" : "object",
    "properties" : {
        "procs" : {"type" : "integer"},
        "working_directory" : {"type" : "string"},
        "application" : {"type" : "string"},
        "args" : {
            "type" : "array"
        }        
    },
    "required" : ["procs","working_directory","application","args"]
})", 
R"(
    cd {{working_directory}}
    mpirun -n {{procs}} {{application}} {% for arg in args %} arg {% endfor %} 
)")



int main(int argc, char** argv) {
  
  /**
   * VnV Workflow Example.
   * ------------------------
   *
   * VnV Workflows allow developers to create workflows that link together the results
   * of simulations. In this example, we create 
   */
  INJECTION_INITIALIZE(SPNAME, &argc, &argv);  
  INJECTION_FINALIZE(SPNAME);

}
