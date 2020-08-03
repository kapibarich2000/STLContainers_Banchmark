#include "Resources.h"
#include <iostream>
#include <Tests.h>

void startTests() {
    Test_AddElements();
    std::cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||\n";
    Test_WithElement();
    std::cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||\n";
    Test_MergingContainers();
    std::cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||\n";
    Test_DeleteElements();
}
