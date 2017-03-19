#include <iostream>
#include "OptParser.h"

int main(int args, char *argv[]) {
    CmdLineOptParser *obj = new CmdLineOptParser();

    std::cout << obj->Parse(args, argv+1);
}