#include <iostream>

class Menu {
private:
    std::string option[5];
    int input[5];

public:
    Menu(std::string opt[], int inp[]) {
        for (int i = 0; i < 5; i++) {
            option[i] = opt[i];
            input[i] = inp[i];
        }
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            std::cout << '[' << input[i] << ']' << option[i] << '\n';
        }
    }

    int handleInput(int input){
        switch(input){
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 4;
            case 5:
                return 5;
        }
    }
};

int main() {
    std::string opt[5] = {"Opt1", "Opt2", "Opt3", "Opt4", "Opt5"};
    int inp[5] = {1, 2, 3, 4, 5};
    Menu menu(opt, inp);
    menu.print();
    int input;
    std::cin >> input;
    menu.handleInput(input);

    return 0;
}