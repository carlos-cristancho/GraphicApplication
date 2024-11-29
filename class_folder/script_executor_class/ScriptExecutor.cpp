#include "ScriptExecutor.h"
#include <cstdlib> // Para system()
#include <iostream>

ScriptExecutor::ScriptExecutor(const std::string& path) : scriptPath(path) {}

// Implementación del método execute
void ScriptExecutor::execute(int n, double frequency, double samplingRate) const {
    // Construir el comando
    std::string command = "python " + scriptPath + " " +
        std::to_string(n) + " " +
        std::to_string(frequency) + " " +
        std::to_string(samplingRate);

    // Ejecutar el comando
    if (system(command.c_str()) == 0) {
        std::cout << "Script executed successfully.\n";
    }
    else {
        std::cerr << "Error executing script.\n";
    }
}