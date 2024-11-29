#include "FileManager.h" // Include the corresponding header
#include <fstream>       // To manage files
#include <iostream>      // To display error messages
#include <sstream>       // To convert data if necessary

FileManager::FileManager(const std::string& file) : filename(file) {}

// Implementation of the saveData method
void FileManager::saveData(const std::vector<double>& time, const std::vector<double>& values) const {
    std::ofstream file(filename); // Open the file in write mode
    if (file.is_open()) {
        file << "Index\tTime\tValue\n"; // File header
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

// Implementation of the readData method
std::vector<std::pair<double, double>> FileManager::readData() const {
    std::ifstream file(filename); // Open the file in read mode
    std::vector<std::pair<double, double>> data;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#') continue; // Ignore empty lines or comments
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