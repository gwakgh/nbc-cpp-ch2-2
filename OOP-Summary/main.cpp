#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class Animal {
	char sound[20];
public:
	void setSound(const char* str);
	void makeSound();
};
class Zoo {
private:
	std::vector<Animal*> animals;
public:
	void addAnimal(Animal* animal);
	void performActions();
	~Zoo();
};
Animal* createRandomAnimal();

int main() {
	Animal Dog, Cat, Cow;
	Animal* animals[] = { &Dog, &Cat, &Cow };
	Zoo zoo;

	srand(time(NULL));

	Dog.setSound("�۸�");
	Cat.setSound("�߿�");
	Cow.setSound("����");

	for (int i = 0; i < 3; i++) {
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << i;
		zoo.addAnimal(createRandomAnimal());
		zoo.performActions();
	}
}

Animal* createRandomAnimal() {
	int r = rand() % 3;
	Animal* animal = new Animal();

	switch (r) {
	case 0:
		animal->setSound("�۸�");
		return animal;
	case 1:
		animal->setSound("�߿�");
		return animal;
	case 2:
		animal->setSound("����");
		return animal;
	default:
		return nullptr;
	}
}

void Animal::setSound(const char* str) {
	if (str) {
		strncpy_s(sound, str, sizeof(sound) - 1);
		sound[sizeof(sound) - 1] = '\0';
	}
	else {
		sound[0] = '\0';
	}
}
void Animal::makeSound() {
	std::cout << sound << std::endl;
}
void Zoo::addAnimal(Animal* animal) {
	animals.push_back(animal);
}
void Zoo::performActions() {
	for (auto a : animals) {
		if (a) {
			a->makeSound();
		}
		else {
			std::cout << "������ �����ϴ�." << std::endl;
		}
	}
}
Zoo::~Zoo() {
	for (auto a : animals) {
		delete a;
	}
}