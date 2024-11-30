#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>

class Signal {
private:
    double amplitude;
    double frequency;
    double phase;
    int n;
    std::vector<double> time;
    std::vector<double> values;

public:
    Signal(double amp, double freq, double ph, int samples);
    void generate();
    const std::vector<double>& getTime() const;
    const std::vector<double>& getValues() const;
};

#endif // SIGNAL_H