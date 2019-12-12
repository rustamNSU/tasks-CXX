#include <iosteram>

class Color{

};

class Teeth{

};

class Mammal
{
private:

	bool isAlive;
	unsigned short age;
	float weight;
	Color color;
	explicit Mammal();                 ///< Disable to using default-constructor

public:

	Mammal(unsigned short age, float weight);
	void breathe();
	virtual void eat();
	virtual void breathe2() = 0;       // Чисто виртуальная функция => нельзя создать класс (абстрактный класс)
};

class Rodent: public Mammal{
private:

	Teeth* teeth;

public:

	Rodent();
	Rodent(Teeth* teeth);

};

class Hamster: public Rodent{
private:

	float deathRate;

public:

	Hamster();
	void breathe();
	virtual void eat();

}

// explicit - запрещает вызывать неявный вызов конструктора
// virtual ~Mammal() - виртуальный деструктор

int main(){

	Hamster hamster;
	hamster.breathe();                 // Method breathe from Hamster class
	
	Mammal * mPtr = new Hamster;       // 
	mPtr->breathe();                   // Method breathe from Mammal class
	mPtr->eat();                       // Method eat from Hamster class

}