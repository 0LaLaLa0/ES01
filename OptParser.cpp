//
// Created by eric on 19.03.17.
//

#include "OptParser.h"
#include <ctype.h>

bool CmdLineOptParser::Parse(int args, char *argv[]) {
    // Check for input
    if ((0 >= args) || (!argv)) {
        return false;
    }

    for (int position = 0; args >= position; position++) {

        // Check for first arg size
        int size;
        size = sizeof(argv[position]) / sizeof(char);
        if (1 >= size) {
            return false;
        }

        // Check for dash, since that is required
        if ('-' != argv[position][0]) {
            return false;
        }

        // Check for flag, which has to be alphabetic
        if (!isalpha(argv[position][1])) {
            return false;
        }

        // Check for complete arg and check parameter
        if (2 >= size && 2 <= size) {
            if (!ParseParameter(argv[position + 1])) {
                return false;
            };
            position++;
            continue;
        }

        // Check for '='
        if (argv[position][2] == '=') {
            // Check parameter beginning at argv[position][3]
            for (int counter = 3; counter < size; counter++) {
                if (!isalnum(argv[position][counter])) {
                    return false;
                }
            }
        } else {
            // Check parameter beginning at argv[position][2]
            for (int counter = 2; counter < size; counter++) {
                if (!isalnum(argv[position][counter])) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool CmdLineOptParser::Option(const char, const char *) {
    return false;
}

bool CmdLineOptParser::ParseParameter(char *parameter) {
    int size;
    size = sizeof(parameter) / sizeof(char);

    for (int counter = 2; counter < size; counter++) {
        if (!isalnum(parameter[counter])) {
            return false;
        }
    }
    return true;
}
