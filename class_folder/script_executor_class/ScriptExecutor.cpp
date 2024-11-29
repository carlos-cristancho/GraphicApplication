#include "ScriptExecutor.h"
#include <cstdlib> // To system()
#include <iostream>

ScriptExecutor::ScriptExecutor(const std::string& path) : scriptPath(path) {}

// Implementation of the execute method
void ScriptExecutor::execute(int n, double frequency, double samplingRate) const {
    // Build command
    std::string command = "python " + scriptPath + " " +
        std::to_string(n) + " " +
        std::to_string(frequency) + " " +
        std::to_string(samplingRate);

    // Execute the command
    if (system(command.c_str()) == 0) {
        std::cout << "Script executed successfully.\n";
    }
    else {
        std::cerr << "Error executing script.\n";
    }
}