#include "Signal.h"
#include <cmath>

Signal::Signal(double amp, double freq, double ph, double rate, int samples)
    : amplitude(amp), frequency(freq), phase(ph), samplingRate(rate), n(samples) {
}

void Signal::generate() {
    double pi = 3.14159265358979323846;
    time.resize(n);
    values.resize(n);
    for (int i = 0; i < n; i++) {
        double t = i / (n * frequency);
        time[i] = t;
        values[i] = amplitude * std::sin(2 * pi * frequency * t + phase);
    }
}

const std::vector<double>& Signal::getTime() const {
    return time;
}

const std::vector<double>& Signal::getValues() const {
    return values;
}