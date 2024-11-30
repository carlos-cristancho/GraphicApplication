#include "Application.h"

void Application::run() {
    // Configuration parameters
    double amplitude = 1.0;
    double frequency = 1.0;
    double phase = 0.0;
    int n = 1 << 12; // 4096 samples

    // Create the signal
    Signal signal(amplitude, frequency, phase, n);
    signal.generate();

    // Saving the signal to a file
    FileManager fileManager("graph_data.txt");
    fileManager.saveData(signal.getTime(), signal.getValues());

    // Execute the Python script
    ScriptExecutor scriptExecutor("../scripts/graphic.py");
    scriptExecutor.execute(n, amplitude, frequency);
}