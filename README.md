Задача 01
За улеснение, ще считаме, че всеки регистрационен номер на превозно средство е поредица от символи, подредени както следва:

един или два символа от латинската азбука, които указват населено място;
четири цифри;
два символа от латинската азбука.
Например C1234AB, XY1111YX са валидни регистрационни номера, а 111145, ABC34DEF, ABCDEF и C11D не са.

а) Реализирайте клас Registration, който представя регистрационен номер. Вътрешно класът да пази информацията като низ от тип char[9], който съдържа символите на номера. Класът да има следния интерфейс:

Класът НЕ ТРЯБВА да има конструктор по подразбиране;

Registration(const char* str) - конструктор, който зарежда в обекта регистрационния номер, записан в str. Ако str не съдържа валиден регистрационен номер, хвърля изключение от тип std::exception;

Registration& operator=(const char* str) - зарежда в обекта регистрационния номер записан в str. Ако str не съдържа валиден регистрационен номер, хвърля изключение от тип std::exception;

bool operator==(const Registration& rhs) const - проверява дали два регистрационни номера са еднакви;

const char* toString() const - връща регистрационния номер.

б) Реализирайте клас Vehicle (превозно средство). Той трябва да има следните публични член-данни:

regnum – регистрационен номер, константа от тип Registration;

description - описание, низ с произволна дължина (може да се използва std::string, може да се използва ваша реализация и/или char*);

Класът да има следния интерфейс:

Класът ДА НЯМА конструктор по подразбиране;

Vehicle(const char* _regnum, const char* _description);

в) Реализирайте клас VehicleList, който представя списък от превозни средства. Списъкът има капацитет, който се посочва при неговото създаване. Капацитетът може да бъде произволно голям. Той се подава само веднъж при създаването на списъка и после не може да се променя. В списъка не трябва да може да се съдържат две превозни средства с еднакви номера.

Подсказка: Помислете за най-подходящия тип данни на масива - <тип> * vehicles. Обърнете внимание, че Vehicle обектите нямат default constructor. Преценете как да адресирате този проблем (например използвайте масив от указатели).

Класът да има следния интерфейс:

VehicleList(size_t capacity) - създава списък, който може да съдържа най-много capacity на брой превозни средства;

Всички функции от Rule of Three:

VehicleList притежава превозните средства, съхранени в него, и трябва да ги почиства в деструктора си;
При копиране на списък от превозни средства, новото копие трябва да създаде за себе си НОВИ обекти от тип Vehicle; то не трябва да сочи към превозните средства на оригинала. Копието трябва да бъде със същия капацитет като оригинала.
void insert(const char* regnum, const char* description) - добавя превозното средство с регистрационен номер regnum и описание description в списъка. Ако операцията не успее (например няма повече място, въведен е невалиден регистрационен номер, такъв регистрационен номер вече се съдържа в списъка), да се хвърля изключение от тип std::exception;

const Vehicle& at(size_t index) const - дава достъп до елемента, който се намира на позиция index. Ако такъв няма, да се хвърля изключение от тип std::exception;

const Vehicle& operator[](size_t pos) const - реализира достъп до елемента, който се намира на позиция pos. Функцията да не прави проверка за коректност дали pos е валидна позиция;

bool empty() const - проверява дали списъкът е празен (т.е. в него не е било добавено нито едно добавено превозно средство);

std::size_t capacity() const - връща капацитета на списъка;

std::size_t size() const - връща брой превозни средства добавени в списъка;

const Vehicle* find(const Registration& regnum) const - намира и връща превозното средство с регистрационен номер regnum. Ако такова няма, да се върне nullptr.

г) Напишете програма, която:

Въвежда от потребителя число vehicleNumber и след това създава списък от превозни средства с vehicleNumber места;

Въвежда от потребителя точно vehicleNumber превозни средства и ги запазва в списъка. Ако потребителят въведе некоректен регистрационен номер (и създаването на Vehicle обект пропадне), програмата ви трябва да може да улови хвърленото изключение (ако използвате такова). В такъв случай се извежда съобщение за грешка и потребителят може отново да опита да въведе данните за превозното средство.

Позволява на потребителя да въведе регистрационен номер на превозно средство и отговаря дали то се съдържа в списъка или не.
