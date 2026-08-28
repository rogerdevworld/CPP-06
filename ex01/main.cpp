#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.name = "Test Object";
    data.value = 42;
    data.ratio = 3.14159;

    std::cout << "--- Original Data Pointer ---" << std::endl;
    std::cout << "Address: " << &data << std::endl;
    std::cout << "Content: " << data.name << ", " << data.value << ", " << data.ratio << std::endl;

    // Serialización
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "\n--- Serialized Value ---" << std::endl;
    std::cout << "uintptr_t raw: " << raw << " (Hex: 0x" << std::hex << raw << std::dec << ")" << std::endl;

    // Deserialización
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "\n--- Deserialized Pointer ---" << std::endl;
    std::cout << "Address: " << deserializedPtr << std::endl;
    std::cout << "Content: " << deserializedPtr->name << ", " << deserializedPtr->value << ", " << deserializedPtr->ratio << std::endl;

    // Verificación
    std::cout << "\n--- Comparison Result ---" << std::endl;
    if (deserializedPtr == &data) {
        std::cout << "SUCCESS: Both pointers match exactly!" << std::endl;
    } else {
        std::cout << "ERROR: Pointer mismatch!" << std::endl;
    }

    return 0;
}