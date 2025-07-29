#include <iostream>
#include <memory>

class Pokemon {
private:
    std::string name;

public:
    Pokemon(std::string name): name(name) {
        std::cout << "Wild " << name << " appeared!" << std::endl;
    }
    ~Pokemon() {
        std::cout << name << " fainted!" << std::endl;
    }
    void attack() {
        std::cout << name << "used tackle!" << std::endl;
    }
};

int main() {
    {
        std::unique_ptr<Pokemon> oddish = std::make_unique<Pokemon>("Oddish");
        oddish->attack();
    }
    // 뚜벅초가 기절하는 시점
    {
        std::shared_ptr<Pokemon> pikachu_replica;
        {
            std::shared_ptr<Pokemon> pikachu = std::make_shared<Pokemon>("Pikachu");
            pikachu_replica = pikachu;
        }
        pikachu_replica->attack();
    }
    // 피카츄가 기절하는 시점
    std::cout << "Player is blacked out!";
    return 0;
}