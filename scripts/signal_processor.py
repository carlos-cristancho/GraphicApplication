from file_loader import FileLoader
from signal_extender import SignalExtender
from signal_plotter import SignalPlotter

class SignalProcessor:
    def __init__(self, file_path, samples, cycles, amplitude, frequency, phase):
        self.file_path = file_path
        self.samples = samples
        self.cycles = cycles
        self.amplitude = amplitude
        self.frequency = frequency
        self.phase = phase
        self.time = None
        self.values = None

    def process_signal(self):
        """
        Process the signal: load data, extend cycles, and prepare for plotting.
        """
        # Load data from file "C:\Users\CODER\_CPP\GraphicApplication\Debug\graph_data.txt"
        loader = FileLoader(self.file_path)
        self.time, self.values = loader.load_data()

        # Extend cycles
        extender = SignalExtender()
        self.time, self.values = extender.extend_cycles(self.time, self.values, self.cycles)

    def plot_signal(self):
        """
        Plot the processed signal.
        """
        plotter = SignalPlotter(self.time, self.values, self.samples, self.cycles, self.amplitude, self.frequency, self.phase)
        plotter.plot_signal()