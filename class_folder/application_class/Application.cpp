#include "Application.h"

void Application::run() {
    // Parámetros de configuración
    double amplitude = 1.0;
    double frequency = 2.0;
    double phase = 0.0;
    double samplingRate = 1.0;
    int n = 1 << 12; // 4096 muestras

    // Crear la señal
    Signal signal(amplitude, frequency, phase, samplingRate, n);
    signal.generate();

    // Guardar la señal en un archivo
    FileManager fileManager("graph_data.txt");
    fileManager.saveData(signal.getTime(), signal.getValues());

    // Ejecutar el script Python
    ScriptExecutor scriptExecutor("../scripts/graphic.py");
    scriptExecutor.execute(n, frequency, samplingRate);
}