#include "Defines.h"
#include <string>
#include <iostream>
#include <vector>

ErrorCode executeCommand(const std::string& command, std::vector<MemoryNode>& memory) {
    return ErrorCode::DOUBLE_FREE;
}

void printResult(const ErrorCode errorCode, const std::string& command) {
    std::cout << command << " - " << errorCode << std::endl;
}