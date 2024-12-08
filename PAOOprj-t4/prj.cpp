#include <iostream>
#include <cstring> // pentru memcpy

class MemoryBuffer {
private:
    char* buffer; // pointer către zona de memorie gestionată
    size_t size;  // dimensiunea buffer-ului

public:
    // Constructor implicit
    MemoryBuffer(size_t size)
        : size(size), buffer(new char[size]) {
        std::cout << "MemoryBuffer: Alocare buffer de dimensiune " << size << " bytes.\n";
    }

    // Constructor de copiere (Item 14)
    MemoryBuffer(const MemoryBuffer& other)
        : size(other.size), buffer(new char[other.size]) {
        std::memcpy(buffer, other.buffer, other.size); // Copierea conținutului
        std::cout << "MemoryBuffer: Copiere buffer de dimensiune " << size << " bytes.\n";
    }

    // Operator de atribuire (Item 14)
    MemoryBuffer& operator=(const MemoryBuffer& other) {
        if (this == &other) return *this; // Verificare auto-atribuire

        std::cout << "MemoryBuffer: Operator= copiere buffer de dimensiune " << other.size << " bytes.\n";

        // Eliberăm resursa curentă
        delete[] buffer;

        // Copiem dimensiunea și alocăm noua zonă de memorie
        size = other.size;
        buffer = new char[size];
        std::memcpy(buffer, other.buffer, size);

        return *this;
    }

    // Constructor de mutare (pentru eficiență)
    MemoryBuffer(MemoryBuffer&& other) noexcept
        : size(other.size), buffer(other.buffer) {
        other.size = 0;
        other.buffer = nullptr;
        std::cout << "MemoryBuffer: Mutare buffer.\n";
    }

    // Operator de atribuire prin mutare
    MemoryBuffer& operator=(MemoryBuffer&& other) noexcept {
        if (this == &other) return *this; // Verificare auto-atribuire

        std::cout << "MemoryBuffer: Operator= mutare buffer.\n";

        // Eliberăm resursa curentă
        delete[] buffer;

        // Mutăm resursa din `other` în acest obiect
        size = other.size;
        buffer = other.buffer;

        other.size = 0;
        other.buffer = nullptr;

        return *this;
    }

    // Destructor (Item 13)
    ~MemoryBuffer() {
        std::cout << "MemoryBuffer: Eliberare buffer de dimensiune " << size << " bytes.\n";
        delete[] buffer;
    }

    // Metodă pentru a scrie date în buffer
    void write(const char* data, size_t length) {
        if (length > size) {
            std::cerr << "MemoryBuffer: Date prea mari pentru buffer!\n";
            return;
        }
        std::memcpy(buffer, data, length);
    }

    // Metodă pentru a citi date din buffer
    void read() const {
        std::cout << "MemoryBuffer: Conținutul bufferului: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << buffer[i];
        }
        std::cout << "\n";
    }
};

int main() {
    // Creăm un MemoryBuffer
    MemoryBuffer buffer1(10);
    buffer1.write("Salut", 5);

    // Testăm constructorul de copiere
    MemoryBuffer buffer2 = buffer1;

    // Testăm operatorul de atribuire
    MemoryBuffer buffer3(15);
    buffer3 = buffer1;

    // Testăm mutarea (constructorul de mutare)
    MemoryBuffer buffer4 = std::move(buffer1);

    // Testăm operatorul de atribuire prin mutare
    buffer3 = std::move(buffer2);

    // Destructorii vor fi apelați automat
    return 0;
}
