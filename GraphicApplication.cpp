#include <cstdlib> // to system()
#include <iostream>
#include <fstream>
#include <cmath> // For sin() and M_PI
#include <string>

int main() {
    // Parameters for the sine wave
    const int n = 1 << 12;             // Number of samples
    const double pi = 3.14159265358979323846;
    const double amplitude = 1.0;  // Amplitude of the sine wave
    const double frequency = 2;  // Frequency in Hz (cycles per sample)
    const double phase = 0.0;      // Phase in radians
    const double samplingRate = pow(2, 0); // Sampling rate (samples per unit time)
    double in[n] = { 0.0 };
    double time[n] = { 0.0 };

    // Generate the sine wave as input
    for (int i = 0; i < n; i++) {
        double t = i / (n * frequency);         // Current time
        time[i] = t;
        in[i] = amplitude * std::sin(2 * pi * frequency * t + phase); // Real part
    }

    // Save the sine wave and FFT output to a file
    std::ofstream file("graph_data.txt");
    if (file.is_open()) {
        file << "# Index\t\tt\t\ty\n";
        for (int i = 0; i < n; i++) {
            file << "\n" << i << "\t\t" << time[i] << "\t\t" << in[i];
        }
        file.close();
        std::cout << "\nData saved to graph_data.txt" << std::endl;
    }
    else {
        std::cerr << "\nError opening file!" << std::endl;
    }

    // Execute the Python script from the system
    std::string command = "python ../scripts/graphic.py " +
        std::to_string(n) + " " +
        std::to_string(frequency) + " " +
        std::to_string(samplingRate);
    if (system(command.c_str()) == 0) {
        std::cout << "\nScript ejecutado con exito." << std::endl;
    }
    else {
        std::cerr << "\nError al ejecutar el script Python." << std::endl;
    }
    return 0;
}