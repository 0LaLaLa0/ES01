//
// Created by eric on 19.03.17.
//

#include "../include/OptParser.h"

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
		size = getStringLength(arguments[position]);
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
		if (2 == size) {
			if (((position + 1) < args) && arguments[position + 1][0] != '-') {
				// flag followed by whitespace, followed by a parameter
				if (!ParseParameter(arguments[position + 1], option, 0)) {
					return false;
				};
				if (!Option(flag, option)) {
					return false;
				};
				// skip parameter
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
				// parameter needs to have something behind '='
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

bool CmdLineOptParser::Option(const char, const char *)
{
	// Do things with your options
	// always returns true in this implementation
	return true;
}

bool CmdLineOptParser::ParseParameter(const char parameter[], char *option, const int startPoint)
{
	int size;
	size = getStringLength(parameter);
	int counter;
	// write parameter into option
	for (counter = startPoint; counter < size; counter++) {
		if (!isalnum(parameter[counter])) {
			return false;
		}
		option[counter - startPoint] = parameter[counter];
	}
	// make it a valid string
	option[counter + 1] = '\0';
	return true;
}

int CmdLineOptParser::getStringLength(const char *array)
{
	int length = 0;

	// increase length, as long as the string does not end
	while (array[length] != '\0') {
		length++;
	}
	return length;
}

bool CmdLineOptParser::isalnum(const char c)
{
	// 65-90 are capital letters
	// 97-122 are lower case letters
	// 48-57 are numbers
	return (91 > c && 64 < c) || (123 > c && 96 < c) || (58 > c && 47 < c);
}

bool CmdLineOptParser::isalpha(const char c)
{
	// 65-90 are capital letters
	// 97-122 are lower case letters
	return (91 > c && 64 < c) || (123 > c && 96 < c);
}
