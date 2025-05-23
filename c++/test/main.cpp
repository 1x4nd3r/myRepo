#include <iostream>
#include <queue>
#include <vector>

struct Character {
    std::string name;
    int speed;
    int AV;
    int hp;
    int atk;
    int def;

    void updateAV() {
        AV = 10000 / static_cast<double>(speed);
    }

    void printStats() const {
        std::cout << "Name: "         << name  << '\n'
                  << "HP: "           << hp    << '\n'
                  << "ATK: "          << atk   << '\n'
                  << "DEF: "          << def   << '\n'
                  << "Speed: "        << speed << '\n'
                  << "Action Value: " << AV    << '\n\n';
    }

    bool operator<(const Character& other) const {
        return AV > other.AV;
    }

    void takeAction(int actionCost) {
        std::cout << "\n[Taking Action]\n";
        AV += actionCost;
    }
};

void processTurn(std::priority_queue<Character>& turnQueue) {
    if (turnQueue.empty()) return;

    Character current = turnQueue.top();
    turnQueue.pop();

    std::cout << "\nProcessing turn for: " << current.name << "\n";
    current.printStats();

    current.takeAction(500);

    turnQueue.push(current);
}

int main() {
    std::priority_queue<Character> turnQueue;

    Character Lucario = {"Lucario", 90, 0, 70, 110, 70};
    Character Marshadow = {"Marshadow", 125, 0, 90, 125, 80};

    Lucario.updateAV();
    Marshadow.updateAV();

    turnQueue.push(Lucario);
    turnQueue.push(Marshadow);

    for (int i = 0; i < 5; ++i) {
        processTurn(turnQueue);
        std::cout << '\n';
    }

    return 0;
}
