#include <iostream>
#include "OptParser.h"

int main(int args, char *argv[]) {
    CmdLineOptParser *obj = new CmdLineOptParser();

    if (obj->Parse(args, argv)) {
        std::cout << "True";
    }
    else {
        std::cout << "False";
    }
}