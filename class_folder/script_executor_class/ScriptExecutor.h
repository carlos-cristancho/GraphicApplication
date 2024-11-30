#ifndef SCRIPTEXECUTOR_H
#define SCRIPTEXECUTOR_H

#include <string>

class ScriptExecutor {
private:
    std::string scriptPath; // Path to Python script

public:
    // Constructor
    explicit ScriptExecutor(const std::string& path);

    // Method to execute the script
    void execute(int n, int cycles, double amplitude, double frequency, double phase) const;
};

#endif // SCRIPTEXECUTOR_H