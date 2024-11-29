#ifndef FILEMANAGER_H // Inclusion guards
#define FILEMANAGER_H

#include <string>
#include <vector>

class FileManager {
private:
    std::string filename; // Name of the file to manage

public:
    // Constructor
    explicit FileManager(const std::string& file);

    // Public methods
    void saveData(const std::vector<double>& time, const std::vector<double>& values) const;
    std::vector<std::pair<double, double>> readData() const;
};

#endif // FILEMANAGER_H