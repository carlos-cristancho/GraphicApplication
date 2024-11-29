#include "class_folder/application_class/Application.h" // Incluir la clase Application
#include <iostream> // Para manejar errores y salida estándar

int main() {
    try {
        // Crear instancia de la aplicación
        Application app;

        // Ejecutar la aplicación
        app.run();

        return 0; // Salida exitosa
    }
    catch (const std::exception& e) {
        // Capturar errores estándar
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Código de error
    }
    catch (...) {
        // Capturar cualquier error inesperado
        std::cerr << "Se produjo un error desconocido." << std::endl;
        return 1; // Código de error
    }
}