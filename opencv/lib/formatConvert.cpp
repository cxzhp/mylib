#include "formatConvert.h"

std::string intToString(int integerVar){
    std::ostringstream oss;
    oss << integerVar;
    return oss.str();
}


int stringToInt(std::string stringVar){
    std::istringstream iss(stringVar);
    int val;
    iss >> val;
    return val;
}
