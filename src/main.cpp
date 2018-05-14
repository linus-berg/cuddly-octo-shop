#include <stdio.h>
#include "view.h"
#include "exceptions.h"

int main() {
  try {
    /* If an exception is not caught, severe error occured */
    view::View display; 
  } catch (std::exception &e) {
    std::cout << "Fatal Exception occured:" << std::endl << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
