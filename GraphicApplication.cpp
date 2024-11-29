#include "class_folder/application_class/Application.h" // Include the Application class
#include <iostream> // For error handling and standard output

int main() {
    try {
        // Create application instance
        Application app;

        // Running the application
        app.run();

        return 0; // Successful exit
    }
    catch (const std::exception& e) {
        // Capture standard errors
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Error code
    }
    catch (...) {
        // Capture any unexpected errors
        std::cerr << "An unknown error occurred." << std::endl;
        return 1; // Error code
    }
}