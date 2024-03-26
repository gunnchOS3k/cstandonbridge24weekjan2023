/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw13
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int GRID_SIZE = 20;
const int DOODLEBUGS = 5;
const int ANTS = 100;
const int ANT_BREED = 3;
const int DOODLEBUG_BREED = 8;
const int DOODLEBUG_STARVE = 3;

class Organism;
class Ant;
class Doodlebug;

enum class OrganismType {ANT, DOODLEBUG};

class World {
public:
    World();
    ~World();
    Organism* getAt(int x, int y) const;
    void setAt(int x, int y, Organism* organism);
    void display() const;
    void step();

private:
    Organism* grid[GRID_SIZE][GRID_SIZE];
};

class Organism {
public:
    Organism(World* world, int x, int y);
    virtual ~Organism() = default;
    virtual void move() = 0;
    virtual void breed() = 0;
    virtual OrganismType getType() const = 0;
    virtual bool starve() const { return false; }
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    void incrementStepsSurvived() { stepsSurvived++; }
    int getStepsSurvived() const { return stepsSurvived; }

protected:
    World* world;
    int x;
    int y;
    int stepsSurvived;
};

class Ant : public Organism {
public:
    Ant(World* world, int x, int y);
    void move() override;
    void breed() override;
    OrganismType getType() const override { return OrganismType::ANT; }
};
void Ant::move() {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int dir = rand() % 4;
    int newX = x + dx[dir];
    int newY = y + dy[dir];

    if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && world->getAt(newX, newY) == nullptr) {
        world->setAt(newX, newY, this);
        world->setAt(x, y, nullptr);
        x = newX;
        y = newY;
    }

    incrementStepsSurvived();
}

void Ant::breed() {
    if (stepsSurvived >= ANT_BREED) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int dir = 0; dir < 4; ++dir) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && world->getAt(newX, newY) == nullptr) {
                world->setAt(newX, newY, new Ant(world, newX, newY));
                stepsSurvived = 0;
                break;
            }
        }
    }
}


class Doodlebug : public Organism {
public:
    Doodlebug(World* world, int x, int y);
    void move() override;
    void breed() override;
    OrganismType getType() const override { return OrganismType::DOODLEBUG; }
    bool starve() const override { return stepsWithoutFood >= DOODLEBUG_STARVE; }
    void eat() { stepsWithoutFood = 0; }
    void incrementStepsWithoutFood() { stepsWithoutFood++; }

private:
    int stepsWithoutFood;
};

void Doodlebug::move() {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    bool hasEaten = false;
    for (int dir = 0; dir < 4; ++dir) {
        int newX = x + dx[dir];
        int newY = y + dy[dir];

        if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && world->getAt(newX, newY) != nullptr && world->getAt(newX, newY)->getType() == OrganismType::ANT) {
            delete world->getAt(newX, newY);
            world->setAt(newX, newY, this);
            world->setAt(x, y, nullptr);
            x = newX;
            y = newY;
            hasEaten = true;
            break;
        }
    }

    if (!hasEaten) {
        int dir = rand() % 4;
        int newX = x + dx[dir];
        int newY = y + dy[dir];

        if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && world->getAt(newX, newY) == nullptr) {
            world->setAt(newX, newY, this);
            world->setAt(x, y, nullptr);
            x = newX;
            y = newY;
        }

        incrementStepsWithoutFood();
    } else {
        eat();
    }

    incrementStepsSurvived();
}

void Doodlebug::breed() {
    if (stepsSurvived >= DOODLEBUG_BREED) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int dir = 0; dir < 4; ++dir) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && world->getAt(newX, newY) == nullptr) {
                world->setAt(newX, newY, new Doodlebug(world, newX, newY));
                stepsSurvived = 0;
                break;
            }
        }
    }
}


// World class implementation
World::World() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = nullptr;
        }
    }
}

World::~World() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            delete grid[i][j];
        }
    }
}

Organism* World::getAt(int x, int y) const {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        return nullptr;
    }
    return grid[x][y];
}

void World::setAt(int x, int y, Organism* organism) {
    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
        grid[x][y] = organism;
    }
}

void World::display() const {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j)
                    if (grid[i][j] == nullptr) {
                cout << '-';
            } else if (grid[i][j]->getType() == OrganismType::ANT) {
                cout << 'o';
            } else {
                cout << 'X';
            }
        }
        cout << endl;
    }


void World::step() {
    // Move doodlebugs 
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getType() == OrganismType::DOODLEBUG) {
                grid[i][j]->move();
            }
        }
    }
    // Move ants
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getType() == OrganismType::ANT) {
                grid[i][j]->move();
            }
        }
    }

    // Breed doodlebugs and ants, remove starved doodlebugs
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->getType() == OrganismType::DOODLEBUG && grid[i][j]->starve()) {
                    delete grid[i][j];
                    grid[i][j] = nullptr;
                } else {
                    grid[i][j]->breed();
                }
            }
        }
    }
}

// Organism class implementation
Organism::Organism(World* world, int x, int y) : world(world), x(x), y(y), stepsSurvived(0) {}

// Ant class implementation
Ant::Ant(World* world, int x, int y) : Organism(world, x, y) {}

// Doodlebug class implementation
Doodlebug::Doodlebug(World* world, int x, int y) : Organism(world, x, y), stepsWithoutFood(0) {}



int main() {
    srand(time(nullptr));
    World world;

    // Add doodlebugs
    for (int i = 0; i < DOODLEBUGS; ++i) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (world.getAt(x, y) != nullptr);
        world.setAt(x, y, new Doodlebug(&world, x, y));
    }

    // Add ants
    for (int i = 0; i < ANTS; ++i) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (world.getAt(x, y) != nullptr);
        world.setAt(x, y, new Ant(&world, x, y));
    }

    // Run the simulation
    while (true) {
        world.display();
        world.step();
        cout << "Press Enter to continue...";
        cin.get();
    }

    return 0;
}
