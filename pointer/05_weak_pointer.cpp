#include <iostream>
#include <memory>

class Pokemon {
public:
    Pokemon(const std::string& name) : name(name) {
        std::cout << "Wild " << name << " appeared!" << std::endl;
    }
    ~Pokemon() {
        std::cout << name << " fainted!" << std::endl;
    }
    void cry() const {
        std::cout << name << " cries out!" << std::endl;
    }

private:
    std::string name;
};

int main() {
    std::weak_ptr<Pokemon> weakPikachu;
    {
        std::shared_ptr<Pokemon> pikachu = std::make_shared<Pokemon>("Pikachu");
        weakPikachu = pikachu;  // 소유권 없이 참조

        std::cout << "Inside scope:\n";
        if (auto shared = weakPikachu.lock()) {
            shared->cry();
        }
        else {
            std::cout << "Pikachu is gone.\n";
        }
    }

    std::cout << "\nOutside scope:\n";
    if (auto shared = weakPikachu.lock()) {
        shared->cry();  // 이 시점엔 shared_ptr이 없으므로 실행되지 않음
    }
    else {
        std::cout << "Pikachu is gone! (expired weak_ptr)\n";
    }

    return 0;
}
