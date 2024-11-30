import numpy as np

class SignalExtender:
    @staticmethod
    def extend_cycles(time, values, cycles):
        """
        Extend the signal data to include multiple cycles.
        :param time: Original time data for one cycle.
        :param values: Original signal values for one cycle.
        :param cycles: Number of cycles to include in the plot.
        :return: Extended time and values arrays.
        """
        extended_time = np.tile(time, cycles) + np.repeat(np.arange(cycles), len(time)) * time[-1]
        extended_values = np.tile(values, cycles)
        return extended_time, extended_values