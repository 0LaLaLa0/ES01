//
// Created by eric on 19.03.17.
//

#ifndef EMBEDDED_SYSTEMS_KOMMANDOZEILENPARSER_CMDLINEOPTPARSER_H
#define EMBEDDED_SYSTEMS_KOMMANDOZEILENPARSER_CMDLINEOPTPARSER_H

class CmdLineOptParser {
public:
	// returns true, if all arguments are successfully parsed.
	bool Parse(int args, char *argv[]);

protected:
	// returns true, if option was suchessfully parsed.
	virtual bool Option(const char c, const char *info);

private:
	// returns true, if parameter successfully parsed
	bool ParseParameter(const char *parameter, char *option, const int startPoint);

	// returns length of array
	int getArrayLength(const char *array);

	// returns true, if char is alpha-numeric
	bool isalnum(const char c);

	// return true, if char is alphabetic
	bool isalpha(const char c);
};

#endif //EMBEDDED_SYSTEMS_KOMMANDOZEILENPARSER_CMDLINEOPTPARSER_H
