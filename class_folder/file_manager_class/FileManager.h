#ifndef FILEMANAGER_H // Guardas de inclusión
#define FILEMANAGER_H

#include <string>
#include <vector>

class FileManager {
private:
    std::string filename; // Nombre del archivo a gestionar

public:
    // Constructor
    explicit FileManager(const std::string& file);

    // Métodos públicos
    void saveData(const std::vector<double>& time, const std::vector<double>& values) const;
    std::vector<std::pair<double, double>> readData() const;
};

#endif // FILEMANAGER_H