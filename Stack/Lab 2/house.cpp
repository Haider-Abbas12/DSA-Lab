#include <iostream>
#include <string>
using namespace std;

class House
{
public:
    string owner;
    string address;
    int bedrooms;
    double price;
};

void readHouse(House &h)
{
    cout << "Enter Owner: ";
    getline(cin, h.owner);

    cout << "Enter Address: ";
    getline(cin, h.address);

    cout << "Number of Bedrooms?: ";
    cin >> h.bedrooms;

    cout << "Price: ";
    cin >> h.price;

    cin.ignore();
}

void printHouse(House h)
{
    cout << h.owner << "  " << endl;
    cout << h.address << "  " << endl;
    cout << h.bedrooms << "  " << endl;
    cout << h.price << "  " << endl;
}

int main()
{
    House available[100];
    int count = 0;
    char choice;

    // input houses
    for (int i = 0; i < 100; i++)
    {
        readHouse(available[i]);
        count++;

        cout << "Enter another house? ";
        cin >> choice;
        cin.ignore(1000, '\n');


        if (choice == 'N' || choice == 'n')
            break;
    }

    cout << "\nOwner  Address  Bedrooms  Price\n";

    for (int i = 0; i < count; i++)
        printHouse(available[i]);

    string priceStr, bedStr, city;

    cout << "\nEnter maximum price (or ?): ";
    getline(cin, priceStr);

    cout << "Enter minimum bedrooms (or ?): ";
    getline(cin, bedStr);

    cout << "Enter city (or ?): ";
    getline(cin, city);

    bool usePrice = true, useBeds = true, useCity = true;

    double maxPrice = 0;
    int minBeds = 0;

    if (priceStr == "?")
        usePrice = false;
    else
        maxPrice = stof(priceStr);

    if (bedStr == "?")
        useBeds = false;
    else
        minBeds = stoi(bedStr);

    if (city == "?")
        useCity = false;

    cout << "\nHouses that meet buyer requirements:\n";

    bool found = false;

    for (int i = 0; i < count; i++)
    {
        bool ok = true;

        if (usePrice && available[i].price > maxPrice)
            ok = false;

        if (useBeds && available[i].bedrooms < minBeds)
            ok = false;

        if (useCity)
        {
            if (available[i].address.find(city) == string::npos)
                ok = false;
        }

        if (ok)
        {
            printHouse(available[i]);
            found = true;
        }
    }

    if (!found)
        cout << "No house found.\n";

    int lowest = 0;
    for (int i = 1; i < count; i++)
    {
        if (available[i].price < available[lowest].price)
            lowest = i;
    }

    int largest = 0;
    for (int i = 1; i < count; i++)
    {
        if (available[i].bedrooms > available[largest].bedrooms)
            largest = i;
    }

    int best = 0;
    double bestRatio = available[0].price / available[0].bedrooms;

    for (int i = 1; i < count; i++)
    {
        double r = available[i].price / available[i].bedrooms;

        if (r < bestRatio)
        {
            bestRatio = r;
            best = i;
        }
    }

    cout << "\nHouse with lowest price:\n";
    printHouse(available[lowest]);

    cout << "\nLargest house:\n";
    printHouse(available[largest]);

    cout << "\nHouse with best price/size ratio:\n";
    printHouse(available[best]);

    return 0;
}
