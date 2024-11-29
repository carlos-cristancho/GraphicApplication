from signal_processor import SignalProcessor
import sys

if __name__ == "__main__":
    # Parse arguments from command line
    file_path = "graph_data.txt"
    n = int(sys.argv[1]) if len(sys.argv) > 1 else None
    frequency = float(sys.argv[2]) if len(sys.argv) > 2 else None
    sampling_rate = float(sys.argv[3]) if len(sys.argv) > 3 else None

    # Print received parameters
    print(f"\nSamples received from C++: {n}")
    print(f"\nFrequency received from C++: {frequency}")
    print(f"\nSampling rate received from C++: {sampling_rate}")

    # Create and execute SignalProcessor
    processor = SignalProcessor(file_path)
    processor.load_data()
    processor.plot_signal()