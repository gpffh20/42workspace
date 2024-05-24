#include "Serializer.hpp"

int main() {
    Data dataA = {100, "Example Data"};
    uintptr_t serialized = Serializer::serialize(&dataA);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Original: " << &dataA << ", num: " << dataA.n << ", str: " << dataA.str << std::endl;
    std::cout << "Deserialized: " << deserialized << ", num: " << deserialized->n << ", str: " << deserialized->str << std::endl;

    return 0;
}
