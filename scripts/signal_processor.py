import numpy as np
import matplotlib.pyplot as plt
import sys

class SignalProcessor:
    """Class for processing and plotting signals."""

    def __init__(self, file_path):
        # Initialize with the path to the data file
        self.file_path = file_path
        self.time = None
        self.values = None

    def load_data(self):
        # Load data from the file
        try:
            data = np.loadtxt(self.file_path, skiprows=1)  # Skip header row
            self.time = data[:, 1]  # Extract time column
            self.values = data[:, 2]  # Extract values column
            print(f"\nData successfully loaded from: {self.file_path}")
        except Exception as e:
            print(f"\nError loading file: {e}")
            sys.exit(1)

    def plot_signal(self):
        # Plot the signal using the loaded data
        if self.time is None or self.values is None:
            print("\nError: No data has been loaded.")
            return

        plt.figure(figsize=(12, 6))
        plt.plot(self.time, self.values, color='red', linewidth=1.5, label="Input Signal")
        plt.axhline(0, color='black', linewidth=1, linestyle='-')  # Add horizontal axis
        plt.title("Input Signal")
        plt.xlabel("Time (s)")
        plt.ylabel("Amplitude (mm)")
        plt.grid()

        # Adjust x-axis to show full signal
        plt.xlim(0, max(self.time))

        # Adjust y-axis with a margin for clarity
        y_min, y_max = min(self.values), max(self.values)
        plt.ylim([y_min * 1.1, y_max * 1.1])

        plt.tight_layout()
        plt.show()