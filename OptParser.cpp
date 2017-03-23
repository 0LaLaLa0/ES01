//
// Created by eric on 19.03.17.
//

#include "OptParser.h"

bool CmdLineOptParser::Parse(int args, char *argv[])
{
	char *arguments[args];
	for (int i = 0; i < args; ++i) {
		arguments[i] = argv[i];
	}

	// Check for input
	if ((1 >= args) || (!argv)) {
		return false;
	}
	// Begin with position 1 to skip program path
	for (int position = 1; args > position; position++) {
		// Check for first arg size
		int size;
		size = getArrayLength(arguments[position]);
		if (1 >= size) {
			return false;
		}

		// Check for dash, since that is required
		if ('-' != arguments[position][0]) {
			return false;
		}

		// Check for flag, which has to be alphabetic
		if (!isalpha(arguments[position][1])) {
			return false;
		}

		char flag = arguments[position][1];
		char option[256];

		// Check for complete arg and check parameter
		if (2 >= size && 2 <= size) {
			if (((position + 1) < args) && arguments[position + 1][0] != '-') {
				if (!ParseParameter(arguments[position + 1], option, 2)) {
					return false;
				};
				if (!Option(flag, option)) {
					return false;
				};
				position++;
				continue;
			}
			else if (((position + 1) < args)) {
				if (arguments[position + 1][0] == '-') {
					// Use nullptr to indicate no available option
					if (!Option(flag, nullptr)) {
						return false;
					}
					continue;
				}
			}
		}

		// Check for '='
		if (arguments[position][2] == '=') {
			if (arguments[position][3] == '\0') {
				return false;
			}
			// Check parameter beginning at arguments[position][3]
			if (!ParseParameter(arguments[position], option, 3)) {
				return false;
			}
		}
		else {
			// Check parameter beginning at arguments[position][2]
			if (!ParseParameter(arguments[position], option, 2)) {
				return false;
			}
		}
		if (!Option(flag, option)) {
			return false;
		}
	}
	return true;
}

bool CmdLineOptParser::Option(const char flag, const char *option)
{
	// Do things with your options
	// always return true, so it runs through
	return (flag && option) || flag;
}

bool CmdLineOptParser::ParseParameter(const char parameter[], char *option, const int startPoint)
{
	int size;
	size = getArrayLength(parameter);
	int counter;
	for (counter = startPoint; counter < size; counter++) {
		if (!isalnum(parameter[counter])) {
			return false;
		}
		option[counter - 2] = parameter[counter];
	}
	option[counter + 1] = '\0';
	return true;
}

int CmdLineOptParser::getArrayLength(const char *array)
{
	int length = 0;

	while (array[length] != '\0') {
		length++;
	}
	return length;
}

bool CmdLineOptParser::isalnum(const char c)
{
	return (91 > c && 59 < c) || (123 > c && 96 < c) || (57 > c && 47 < c);
}

bool CmdLineOptParser::isalpha(const char c)
{
	return (91 > c && 59 < c) || (123 > c && 96 < c);
}
