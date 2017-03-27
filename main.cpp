#include <iostream>
#include <cstring>
#include "OptParser.h"

int main(int argc, char *argv[]) {
    /*
     *  Accepted cases:
     *  1 -x
     *  2 -xvalue
     *  3 -x value
     *  4 -x=value
     *  5 Combination of above
     *  with x defining an argument option and value additional INFO
     */


    //test cases
    char *case1 = new char[3];
    char *case2 = new char[8];
    char *onlyValue = new char[6];
    char *case4 = new char[9];
    char *filler = new char[5];
    char *dash = new char[2];
    char *case4wrong = new char[4];
    char *number = new char[4];
    char *nonalnum = new char[4];

    std::strcpy(case1, "-x");
    std::strcpy(case2, "-xvalue");
    std::strcpy(onlyValue, "value");
    std::strcpy(case4, "-x=value");
    std::strcpy(filler, "test");
    std::strcpy(dash, "-");
    std::strcpy(case4wrong, "-x=");
    std::strcpy(number, "-44");
    std::strcpy(nonalnum, "-$&");

    char *allVals[] = {filler, case1, case2, case1, onlyValue, case4, case1};// Should return true
    char *c1[] = {filler, case1};                               // Should return true
    char *c2[] = {filler, case2};                               // Should return true
    char *c3[] = {filler, case1, onlyValue};                    // Should return true
    char *c4[] = {filler, case4};                               // Should return true
    char *onlyDash[] = {filler, dash};                          // Should return false
    char *onlyEquals[] = {filler, case4wrong};                  // Should return false
    char *emptyVal[] = {filler};                                // Should return false
    char *numbers[] = {filler, number};                         // Should return false
    char *noAlNum[] = {filler, nonalnum};                       // Should return false
    char *multiOpt[] = {filler, case1, onlyValue, onlyValue};   // Should return false

    CmdLineOptParser parser;

    std::cout << "Input:\t\t" << parser.Parse(argc, argv) << "\n";
    std::cout << "allVals:\t" << parser.Parse(7, allVals) << "\n";
    std::cout << "Case 1:\t\t" << parser.Parse(2, c1) << "\n";
    std::cout << "Case 2:\t\t" << parser.Parse(2, c2) << "\n";
    std::cout << "Case 3:\t\t" << parser.Parse(3, c3) << "\n";
    std::cout << "Case 4:\t\t" << parser.Parse(2, c4) << "\n";
    std::cout << "Only Dash:\t" << parser.Parse(2, onlyDash) << "\n";
    std::cout << "Only Equals:\t" << parser.Parse(2, onlyEquals) << "\n";
    std::cout << "empty:\t\t" << parser.Parse(2, emptyVal) << "\n";
    std::cout << "numbers:\t" << parser.Parse(2, numbers) << "\n";
    std::cout << "noAlNum:\t" << parser.Parse(2, noAlNum) << "\n";
    std::cout << "multiOpt:\t" << parser.Parse(4, multiOpt) << "\n";

}
