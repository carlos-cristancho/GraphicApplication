#include "FileManager.h" // Incluir la cabecera correspondiente
#include <fstream>       // Para manejar archivos
#include <iostream>      // Para mostrar mensajes de error
#include <sstream>       // Para convertir datos si es necesario

FileManager::FileManager(const std::string& file) : filename(file) {}

// Implementación del método saveData
void FileManager::saveData(const std::vector<double>& time, const std::vector<double>& values) const {
    std::ofstream file(filename); // Abrir el archivo en modo escritura
    if (file.is_open()) {
        file << "Index\tTime\tValue\n"; // Cabecera del archivo
        for (size_t i = 0; i < time.size(); i++) {
            file << i + 1 << "\t" << time[i] << "\t" << values[i] << "\n";
        }
        file.close();
        std::cout << "Data saved to " << filename << "\n";
    }
    else {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
    }
}

// Implementación del método readData
std::vector<std::pair<double, double>> FileManager::readData() const {
    std::ifstream file(filename); // Abrir el archivo en modo lectura
    std::vector<std::pair<double, double>> data;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#') continue; // Ignorar líneas vacías o comentarios
            std::istringstream ss(line);
            double time, value;
            ss >> time >> value;
            data.emplace_back(time, value);
        }
        file.close();
    }
    else {
        std::cerr << "Error: Could not open file " << filename << " for reading.\n";
    }
    return data;
}