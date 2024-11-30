from signal_processor import SignalProcessor
import sys

if __name__ == "__main__":
    # Parse arguments from command line
    file_path = "graph_data.txt"
    n = int(sys.argv[1]) if len(sys.argv) > 1 else None
    amplitude = float(sys.argv[2]) if len(sys.argv) > 2 else None
    frequency = float(sys.argv[3]) if len(sys.argv) > 3 else None

    # Print received parameters
    print(f"\n\n\t\tSamples received from C++: {n} samples")
    print(f"\n\t\tAmplitude received from C++: {amplitude} mm")
    print(f"\n\t\tFrequency received from C++: {frequency} Hz")
    print(f"\n\t\tSignal period: {1/frequency} s\n")

    # Create and execute SignalProcessor
    processor = SignalProcessor(file_path, n, amplitude, frequency)
    processor.load_data()
    processor.plot_signal()