import os
from signal_processor import SignalProcessor
import sys

if len(sys.argv) < 6:
    print("\n\nError: Insufficient arguments provided. Expected: file_path, samples, cycles, amplitude, frequency, phase.")
    sys.exit(1)

samples = int(sys.argv[1])  # Samples from C++
cycles = int(sys.argv[2])  # Cycles from C++
amplitude = float(sys.argv[3])  # Amplitude from C++
frequency = float(sys.argv[4])  # Frequency from C++
phase = float(sys.argv[5])  # Phase from C++

# Define the relative path to the file "C:\Users\CODER\_CPP\GraphicApplication\Debug\graph_data.txt"
file_path = os.path.join(os.path.dirname(__file__), "../Debug/graph_data.txt")

# Initialize and process the signal
processor = SignalProcessor(file_path, samples, cycles, amplitude, frequency, phase)
processor.process_signal()
processor.plot_signal()