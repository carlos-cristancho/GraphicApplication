# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import sys

# Leer el valor de la frecuencia y la cantidad de muestras desde los argumentos
n = int(sys.argv[1]) if len(sys.argv) > 1 else 128  # Número de muestras por defecto
frequency = float(sys.argv[2]) if len(sys.argv) > 2 else 1.0  # Frecuencia por defecto
samplingRate = float(sys.argv[3]) if len(sys.argv) > 3 else 1024  # Frecuencia de muestreo por defecto

print(f"\nMuestras recibidas desde C++: {n}")
print(f"\nFrecuencia de la senal recibida desde C++: {frequency}")
print(f"\nFrecuencia de muestreo recibida desde C++: {samplingRate}")

# Load the data
data = np.loadtxt("C:/Users/CODER/_CPP/GraphicApplication/Debug/graph_data.txt", skiprows=1)  # Skip the header row
t = data[:, 1]  # Time column
y = data[:, 2]  # Input values

# Plot the input signal with a continuous line only
plt.figure(figsize=(12, 6))
plt.plot(t, y, color='red', linewidth=1.5, label="Input Signal")  # Continuous line
plt.axhline(0, color='black', linewidth=1, linestyle='-')  # Horizontal line at y=0
plt.title("Input Signal")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude (mm)")
plt.grid()  # Add a grid for better visualisation

# Set x-axis limits to show only two cycles
plt.xlim(0, max(t)*1.01)  # Show two cycles of the signal

# Set the y-axis limits so that the x-axis cuts at y=0.
y_min, y_max = min(y), max(y)  # Calculate data limits
plt.ylim([y_min * 1.1, y_max * 1.1])  # Adjust with a 10% margin for clarity

# Display the plots
plt.tight_layout()
plt.show()