#include "ScriptExecutor.h"
#include <cstdlib> // To system()
#include <iostream>

ScriptExecutor::ScriptExecutor(const std::string& path) : scriptPath(path) {}

// Implementation of the execute method
void ScriptExecutor::execute(int n, int cycles, double amplitude, double frequency, double phase) const {
    // Build command
    std::string command = "python " + scriptPath + " " +
                          std::to_string(n) + " " +
                          std::to_string(cycles) + " " +
                          std::to_string(amplitude) + " " +
                          std::to_string(frequency) + " " + 
                          std::to_string(phase);

    // Execute the command
    if (system(command.c_str()) == 0) {
        std::cout << "\n\nScript executed successfully.\n";
    }
    else {
        std::cerr << "\n\nError executing script.\n";
    }
}