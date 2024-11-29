#ifndef SCRIPTEXECUTOR_H
#define SCRIPTEXECUTOR_H

#include <string>

class ScriptExecutor {
private:
    std::string scriptPath; // Ruta al script Python

public:
    // Constructor
    explicit ScriptExecutor(const std::string& path);

    // Método para ejecutar el script
    void execute(int n, double frequency, double samplingRate) const;
};

#endif // SCRIPTEXECUTOR_H