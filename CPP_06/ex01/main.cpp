#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data data;
    Data* copy;
    data.id = 1;
    data.name = "Test";
    data.value = 3.14f;

    uintptr_t serialized = Serializer::serialize(&data);

    copy = Serializer::deserialize(serialized);

    if (copy == &data) {
        std::cout << "Serialization and deserialization were successful." << std::endl;
        std::cout << "copy ID: " << copy->id << std::endl;
        std::cout << "copy Name: " << copy->name << std::endl;
        std::cout << "copy Value: " << copy->value << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed." << std::endl;
    }

    return 0;
}
