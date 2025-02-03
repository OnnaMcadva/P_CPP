#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    // Шаг 1: Создаем объект Data
    Data originalData;
    originalData.value = 42;
    originalData.name = "Hello, Serialization!";

    // Отображаем изначальные данные
    std::cout << "Original Data:\n";
    std::cout << "Value: " << originalData.value << "\n";
    std::cout << "Name: " << originalData.name << "\n";
    std::cout << "Address of originalData: " << &originalData << "\n\n";

    // Шаг 2: Сериализация
    uintptr_t serializedData = Serializer::serialize(&originalData);
    std::cout << "Serialized Data (uintptr_t): " << serializedData << "\n\n";

    // Шаг 3: Десериализация
    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized Data:\n";
    std::cout << "Value: " << deserializedData->value << "\n";
    std::cout << "Name: " << deserializedData->name << "\n";
    std::cout << "Address of deserializedData: " << deserializedData << "\n\n";

    // Шаг 4: Проверка успешности
    if (deserializedData == &originalData) {
        std::cout << "✅ Success: The deserialized pointer matches the original pointer. ✨\n";
    } else {
        std::cout << "Error: ❌ The deserialized pointer does NOT match the original pointer. ❌\n";
    }

    // Шаг 5: Проверка изменения данных через указатель
    deserializedData->value = 84;
    deserializedData->name = "Data Changed!";
    std::cout << "\nAfter modifying deserialized data:\n";
    std::cout << "Original Data:\n";
    std::cout << "Value: " << originalData.value << "\n";
    std::cout << "Name: " << originalData.name << "\n";

    // Шаг 6: Тесты с неуспешными случаями
    std::cout << "\nTesting failure scenarios:\n";

    // Случай 1: Передаем NULL в serialize
    Data* nullData = NULL; // Используем NULL вместо nullptr
    uintptr_t nullSerialized = Serializer::serialize(nullData);
    if (nullSerialized == 0) {
        std::cout << "Test 1 Passed:✅  Serializing NULL returned 0 as expected. ✨\n";
    } else {
        std::cout << "Test 1 Failed: ❌ Serializing NULL did not return 0. ❌\n";
    }

    // Случай 2: Передаем некорректное значение в deserialize
    uintptr_t invalidAddress = 123456789; // Некорректный адрес
    Data* invalidDeserialized = Serializer::deserialize(invalidAddress);
    if (invalidDeserialized == NULL) {
        std::cout << "Test 2 Passed:✅  Deserializing invalid address returned NULL as expected. ✨\n";
    } else {
        std::cout << "Test 2 Failed: ❌ Deserializing invalid address did not return NULL. ❌\n";
    }

    // Случай 3: Проверка на случай совпадения указателя после некорректных данных
    if (invalidDeserialized != &originalData) {
        std::cout << "Test 3 Passed:✅  Invalid pointer did not match original data pointer. ✨\n";
    } else {
        std::cout << "Test 3 Failed: ❌ Invalid pointer matches original data pointer. ❌\n";
    }

    return 0;
}
