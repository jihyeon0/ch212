#include <iostream>
using namespace std;

///////////
class Animal {
public:
    virtual void makeSound() = 0;
public:
    ~Animal() {};
};

class Dog : public Animal {
public:
    void makeSound() override
    {
        cout << "Bark" << endl;
    }
public:
    ~Dog() {};
};

class Cat : public Animal {
public:
    void makeSound()override
    {
        cout << "Meow" << endl;
    }
public:
    ~Cat() {};
};

class Cow : public Animal {
public:
    void makeSound()override
    {
        cout << "Moo" << endl;
    }
public:
    ~Cow() {};
};


class Zoo {
private:
    Animal* animals[10] = { nullptr }; // 동물 객체를 저장하는 포인터 배열
    int animalCount = 10;
public:
    // 동물을 동물원에 추가하는 함수
    // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
    // - 같은 동물이라도 여러 번 추가될 수 있습니다.
    // - 입력 매개변수: Animal* (추가할 동물 객체)
    // - 반환값: 없음
    void addAnimal(Animal* animal)
    {
        for (int i = 0; i < animalCount; i++)
        {
            if (animals[i] == nullptr)
            {
                animals[i] = animal;
                break;
            }
        }
    }

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    void performActions()
    {
        for (int i = 0; i < animalCount; i++)
        {
            animals[i]->makeSound();
        }
    }

    // Zoo 소멸자
    // - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
    // - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    ~Zoo()
    {
        for (int i = 0; i < animalCount; i++)
        {
            if (animals[i] != nullptr)
            {
                delete animals[i];
                animals[i] = nullptr;
            }
        }
    }
};

Animal* createRandomAnimal();



int main()
{
    cout << "필수과제" << endl;
    Animal* animalArr[3];
    Dog dog;
    Cat cat;
    Cow cow;
    animalArr[0] = &dog;
    animalArr[1] = &cat;
    animalArr[2] = &cow;


    for (int i = 0; i < 3; i++)
    {
        animalArr[i]->makeSound();
    }

    ////
    cout << "도전과제" << endl;
    srand(static_cast<unsigned int>(time(0)));  // 난수 시드 설정 (프로그램 시작 시 한 번만 호출)

    Zoo zoo;
    for (int i = 0; i < 10; i++)
    {
        Animal* animal = createRandomAnimal();
        zoo.addAnimal(animal);
    }
    zoo.performActions();
}

Animal* createRandomAnimal()
{
    int random = rand() % 3;

    switch (random)
    {
    case 0:
    {
        Animal* animal = new Dog();
        return animal;
    }
    break;
    case 1:
    {
        Animal* animal = new Cat();
        return animal;
    }
    break;
    case 2:
    {
        Animal* animal = new Cow();
        return animal;
    }
    default:
        return nullptr;
    }
}