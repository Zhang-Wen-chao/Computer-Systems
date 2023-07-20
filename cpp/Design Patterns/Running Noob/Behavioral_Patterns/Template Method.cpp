#include <iostream>

class Game {
public:
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;

    void play() {
        initialize();
        startPlay();
        endPlay();
    }
};

class Cricket : public Game {
public:
    void endPlay() override {
        std::cout << "Cricket Game Finished!" << std::endl;
    }

    void initialize() override {
        std::cout << "Cricket Game Initialized! Start playing." << std::endl;
    }

    void startPlay() override {
        std::cout << "Cricket Game Started. Enjoy the game!" << std::endl;
    }
};

class Football : public Game {
public:
    void endPlay() override {
        std::cout << "Football Game Finished!" << std::endl;
    }

    void initialize() override {
        std::cout << "Football Game Initialized! Start playing." << std::endl;
    }

    void startPlay() override {
        std::cout << "Football Game Started. Enjoy the game!" << std::endl;
    }
};

int main() {
    Game* game = new Cricket();
    game->play();
    std::cout << std::endl;
    delete game;

    game = new Football();
    game->play();
    delete game;

    return 0;
}