#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Animal {
public:
	virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
	void makeSound() override { cout << "港港" << endl; }
};
class Cat : public Animal {
public:
	void makeSound() override { cout << "具克" << endl; }
};
class Cow : public Animal {
public:
	void makeSound() override { cout << "澜皋" << endl; }
};
class Zoo{
private:
	Animal* animals[10];
public:
	void addAnimal(Animal* animal, int index);
	void performActions();
	~Zoo();
};
Animal* createRandomAnimal();
int main() {
	Dog dog;
	Cat cat;
	Cow cow;
	Animal* animals[3] = { &dog, &cat, &cow };
	Zoo zoo;

	for(int i = 0; i < 3; i++) {
		animals[i]->makeSound();
	}

	for(int i = 0; i < 10; i++) {
		zoo.addAnimal(createRandomAnimal(), i);
	}

	zoo.performActions();
}
Animal* createRandomAnimal() {
	int random = rand() % 3;
	srand(time(0));
	switch(random) {
		case 0: return new Dog();
		case 1: return new Cat();
		case 2: return new Cow();
	}
}

void Zoo::addAnimal(Animal* animal, int index) {
	animals[index] = animal;
}
void Zoo::performActions() {
	for (int i = 0; i < 10; i++) {
		if (animals[i]) {
			animals[i]->makeSound();
		}
	}
}
Zoo::~Zoo() {
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}
}