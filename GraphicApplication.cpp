#include "class_folder/application_class/Application.h" // Incluir la clase Application
#include <iostream> // Para manejar errores y salida est�ndar

int main() {
    try {
        // Crear instancia de la aplicaci�n
        Application app;

        // Ejecutar la aplicaci�n
        app.run();

        return 0; // Salida exitosa
    }
    catch (const std::exception& e) {
        // Capturar errores est�ndar
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // C�digo de error
    }
    catch (...) {
        // Capturar cualquier error inesperado
        std::cerr << "Se produjo un error desconocido." << std::endl;
        return 1; // C�digo de error
    }
}