#include <iostream>
#include <ctime>

struct Suit
{
    std::string name;
    int value;
};

struct Rank
{
    std::string name;
    int value;
};

struct Card
{
    Suit suit;
    Rank rank;
    bool isFaceUp;
};

void practiceArrays();
int getCount();
int *populateNumbers(int *ptr, int size);
void practicePointers();
void practiceStructs();

int main()
{
    srand(time(0));
    practiceArrays();
    practicePointers();
    practiceStructs();
    
    return 0;
}

// arrays
void practiceArrays()
{
    int count = getCount();
    int *ptr = nullptr;
    ptr = populateNumbers(ptr, count);

    std::cout << std::endl
              << std::endl;
    for (int i = 0; i < count; i++)
        std::cout << *(ptr + i) << std::endl;

    int sum = 0;
    double average = 0.0;
    int max,
        min = *ptr;
    for (int i = 0; i < count; i++)
    {
        sum += *(ptr + i);
        if (max < *(ptr + i))
        {
            max = *(ptr + i);
        }
        if (min > *(ptr + i))
        {
            min = *(ptr + i);
        }
    }

    std::cout << std::endl;
    average = static_cast<double>(sum) / count;
    std::cout << "The sum of all the numbers is: " << sum << std::endl;
    std::cout << "The average of all the numbers is: " << average << std::endl;
    std::cout << "The maximum of all the numbers is: " << max << std::endl;
    std::cout << "The minimum of all the numbers is: " << min << std::endl;

    delete[] ptr;
}

int getCount()
{
    int count;
    std::cout << "How many numbers do you want to analyze? " << std::endl;
    std::cin >> count;
    return count;
}

int *populateNumbers(int *ptr, int size)
{
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        std::cout << "Please enter a value: " << std::endl;
        std::cin >> *(ptr + i);
    }
    return ptr;
}

// pointers
void practicePointers()
{
    std::string name = "";
    int age;

    std::cout << "What is your name and age? ";
    std::cin >> name >> age;

    std::cout << "Hello, " << name << " stored at " << &name << std::endl;
    std::cout << "Your age is " << age << " stored at " << &age << std::endl << std::endl;

    std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++)
    {
        std::cout << *(months + i) << std::endl;
    }

    for (int i = 12; i >= 0; i--)
    {
        std::cout << *(months + i) << std::endl;
    }
}

// structures

void practiceStructs() {
    Suit suits[4] = {
        {"hearts", 4},
        {"diamonds", 3},
        {"clubs", 2},
        {"spades", 1}};
    Rank ranks[13] = {
        {"Ace", 1},
        {"Two", 2},
        {"Three", 3},
        {"Four", 4},
        {"Five", 5},
        {"Six", 6},
        {"Seven", 7},
        {"Eight", 8},
        {"Nine", 9},
        {"Ten", 10},
        {"Jack", 10},
        {"Queen", 10},
        {"King", 10},
    };

    Card deck[52];
    for (int i = 0; i < 52; i++)
    {
        Card tempCard = {suits[i / 13], ranks[i % 13], true};
        deck[i] = tempCard;
    }

    for (int i = 0; i < 5; i++)
    {
        Card card = deck[rand() % 52];
        std::cout<< "The " << card.rank.name << " of " << card.suit.name << std::endl;
    }
}
