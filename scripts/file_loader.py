import numpy as np

class FileLoader:
    def __init__(self, file_path):
        self.file_path = file_path

    def load_data(self):
        """
        Load data from the specified file.
        :return: time and values arrays.
        """
        try:
            data = np.loadtxt(self.file_path, skiprows=1)  # Skip the header row
            time = data[:, 1]  # Time column
            values = data[:, 2]  # Input values column
            print(f"\nData successfully loaded from: {self.file_path}")
            return time, values
        except Exception as e:
            print(f"\nError loading file: {e}")
            raise