#ifndef BAD_EXCEPTION_H
#define BAD_EXCEPTION_H
#include <string>
#include <iostream>
#define COFFEE_MACHINE_NAME_ERR "You use a bad command! Coffee machine name could not found."
#define SYMBOL_NOT_FOUND_ERR "You use a bad command! Symbol ( + , | , ^ ) could not found."
#define FEATURE_NAME_ERR "You use a bad command! Feature name could not found."
#define FEATURE_NOT_FOUND_ERR "This feature doesn't exists!"
#define CM_ERR "You used bad command! please do it again."

class BadException
{
public:
	BadException(std::string msg);
	void printMsg();
private:
	std::string massage;
};
#endif