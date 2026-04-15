#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

enum MarketplaceType {
    Groceries,
    Home,
    Tech,
    Clothes,
    All
};

// Конвертация enum в строку для вывода
string TypeToString(MarketplaceType type) {
    switch(type) {
        case Groceries: return "groceries";
        case Home: return "home";
        case Tech: return "tech";
        case Clothes: return "clothes";
        case All: return "all";
        default: return "unknown";
    }
}

// Конвертация строки в enum при вводе данных
MarketplaceType StringToType(const string& str) {
    if (str == "groceries") return Groceries;
    if (str == "home") return Home;
    if (str == "tech") return Tech;
    if (str == "clothes") return Clothes;
    if (str == "all") return All;
    return All;
}

struct marketplace {
    string name;
    int quantity;
    string country;
    string city;
    int networth;
    MarketplaceType type;
    string business;
};

void WriteToBinaryFile(const char* filename, marketplace data[], int size) {
    ofstream out(filename, ios::binary | ios::out);

    if (!out.is_open()) {
        cout << "Error: cannot open file for writing" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        int nameLen = data[i].name.length();
        out.write((char*)&nameLen, sizeof(nameLen));
        out.write(data[i].name.c_str(), nameLen);

        out.write((char*)&data[i].quantity, sizeof(data[i].quantity));

        int countryLen = data[i].country.length();
        out.write((char*)&countryLen, sizeof(countryLen));
        out.write(data[i].country.c_str(), countryLen);

        int cityLen = data[i].city.length();
        out.write((char*)&cityLen, sizeof(cityLen));
        out.write(data[i].city.c_str(), cityLen);

        out.write((char*)&data[i].networth, sizeof(data[i].networth));

        int typeValue = static_cast<int>(data[i].type);
        out.write((char*)&typeValue, sizeof(typeValue));

        int businessLen = data[i].business.length();
        out.write((char*)&businessLen, sizeof(businessLen));
        out.write(data[i].business.c_str(), businessLen);
    }

    out.close();
    cout << "Data written to " << filename << " successfully" << endl;
}

void ReadFromBinaryFile(const char* filename, marketplace data[], int maxSize) {
    ifstream in(filename, ios::binary | ios::in);

    if (!in.is_open()) {
        cout << "Error: cannot open file for reading" << endl;
        return;
    }

    int i = 0;
    while (i < maxSize && !in.eof()) {
        int nameLen;
        if (in.read((char*)&nameLen, sizeof(nameLen)).eof()) break;
        char* nameBuffer = new char[nameLen + 1];
        in.read(nameBuffer, nameLen);
        nameBuffer[nameLen] = '\0';
        data[i].name = nameBuffer;
        delete[] nameBuffer;

        in.read((char*)&data[i].quantity, sizeof(data[i].quantity));

        int countryLen;
        in.read((char*)&countryLen, sizeof(countryLen));
        char* countryBuffer = new char[countryLen + 1];
        in.read(countryBuffer, countryLen);
        countryBuffer[countryLen] = '\0';
        data[i].country = countryBuffer;
        delete[] countryBuffer;

        int cityLen;
        in.read((char*)&cityLen, sizeof(cityLen));
        char* cityBuffer = new char[cityLen + 1];
        in.read(cityBuffer, cityLen);
        cityBuffer[cityLen] = '\0';
        data[i].city = cityBuffer;
        delete[] cityBuffer;

        in.read((char*)&data[i].networth, sizeof(data[i].networth));

        int typeValue;
        in.read((char*)&typeValue, sizeof(typeValue));
        data[i].type = static_cast<MarketplaceType>(typeValue);

        int businessLen;
        in.read((char*)&businessLen, sizeof(businessLen));
        char* businessBuffer = new char[businessLen + 1];
        in.read(businessBuffer, businessLen);
        businessBuffer[businessLen] = '\0';
        data[i].business = businessBuffer;
        delete[] businessBuffer;

        i++;
    }

    in.close();
    cout << "Read " << i << " records from " << filename << endl;
}

void DisplayData(marketplace data[], int size) {
    cout << "\n========================================" << endl;
    cout << "Marketplace Data:" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < size; i++) {
        cout << data[i].name << " | "
            << data[i].quantity << " | "
            << data[i].country << " | "
            << data[i].city << " | "
            << data[i].networth << " | "
            << TypeToString(data[i].type) << " | "
            << data[i].business << endl;
    }
    cout << "========================================" << endl;
}

void NotMoscow(marketplace* source) {
    cout << "\n========================================" << endl;
    cout << "Marketplaces not from Moscow:" << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < 20; i++) {
        if (source[i].city != "Moscow") {
            cout << source[i].name << " - " << source[i].city << endl;
        }
    }
    cout << "========================================" << endl;
}

void Top3Popular(marketplace* source) {
    struct marketplace sorted_by_quantity[20];
    for (int i = 0; i < 20; i++) {
        sorted_by_quantity[i] = source[i];
    }

    for (int i = 0; i < 20 - 1; i++) {
        for (int j = 0; j < 20 - i - 1; j++) {
            if (sorted_by_quantity[j].quantity < sorted_by_quantity[j + 1].quantity) {
                marketplace temp = sorted_by_quantity[j];
                sorted_by_quantity[j] = sorted_by_quantity[j + 1];
                sorted_by_quantity[j + 1] = temp;
            }
        }
    }

    cout << "\n========================================" << endl;
    cout << "Top 3 most popular marketplaces:" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << sorted_by_quantity[i].name
            << " - " << sorted_by_quantity[i].quantity << endl;
    }
    cout << "========================================" << endl;
}

void GroceriesMarketplaces(marketplace* source) {
    struct marketplace groceries_data[20];
    int gr_size = 0;

    for (int i = 0; i < 20; i++) {
        if (source[i].type == Groceries) {
            groceries_data[gr_size] = source[i];
            gr_size++;
        }
    }

    for (int i = 0; i < gr_size - 1; i++) {
        for (int j = 0; j < gr_size - i - 1; j++) {
            if (groceries_data[j].quantity > groceries_data[j + 1].quantity) {
                marketplace temp = groceries_data[j];
                groceries_data[j] = groceries_data[j + 1];
                groceries_data[j + 1] = temp;
            }
        }
    }

    cout << "\n========================================" << endl;
    cout << "Grocery marketplaces (by quantity ascending):" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < gr_size; i++) {
        cout << groceries_data[i].name << "\t" << groceries_data[i].quantity << endl;
    }
    cout << "========================================" << endl;
}

void SearchName(marketplace* source, int size) {
    string searchName;
    bool found = false;
    
    cout << "\n========================================" << endl;
    cout << "Enter marketplace name to search: ";
    cin >> searchName;
    cout << "========================================" << endl;
    
    for (int i = 0; i < size; i++) {
        if (source[i].name == searchName) {
            cout << "\nMarketplace found:" << endl;
            cout << "Name: " << source[i].name << endl;
            cout << "Quantity: " << source[i].quantity << endl;
            cout << "Country: " << source[i].country << endl;
            cout << "City: " << source[i].city << endl;
            cout << "Networth: " << source[i].networth << endl;
            cout << "Type: " << TypeToString(source[i].type) << endl;
            cout << "Business: " << source[i].business << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Marketplace not found!" << endl;
    }
    cout << "========================================" << endl;
}

void SortMenu(marketplace* source) {
    int choice;

    cout << "\n========================================" << endl;
    cout << "Select sorting option:" << endl;
    cout << "========================================" << endl;
    cout << "1. Show marketplaces not from Moscow" << endl;
    cout << "2. Show Top 3 most popular marketplaces" << endl;
    cout << "3. Show grocery marketplaces (by quantity ascending)" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cout << "========================================" << endl;

    switch (choice) {
    case 1:
        NotMoscow(source);
        break;
    case 2:
        Top3Popular(source);
        break;
    case 3:
        GroceriesMarketplaces(source);
        break;
    default:
        cout << "Invalid choice! Please select 1, 2, or 3." << endl;
    }
}

void ChangeMarketplaceData(marketplace* mp) {
    string x;
    string newStringValue;
    int newIntValue;

    cout << "\n========================================" << endl;
    cout << "What do you want to change?" << endl;
    cout << "name, quantity, country, city, networth, type, business" << endl;
    cout << "========================================" << endl;
    cin >> x;

    if (x == "name") {
        cout << "Enter new name (no spaces allowed): ";
        cin >> newStringValue;
        mp->name = newStringValue;
        cout << "Name updated successfully!" << endl;
    }
    else if (x == "quantity") {
        cout << "Enter new quantity: ";
        cin >> newIntValue;
        mp->quantity = newIntValue;
        cout << "Quantity updated successfully!" << endl;
    }
    else if (x == "country") {
        cout << "Enter new country (no spaces allowed, 2-letter code): ";
        cin >> newStringValue;
        mp->country = newStringValue;
        cout << "Country updated successfully!" << endl;
    }
    else if (x == "city") {
        cout << "Enter new city (no spaces allowed): ";
        cin >> newStringValue;
        mp->city = newStringValue;
        cout << "City updated successfully!" << endl;
    }
    else if (x == "networth") {
        cout << "Enter new networth: ";
        cin >> newIntValue;
        mp->networth = newIntValue;
        cout << "Networth updated successfully!" << endl;
    }
    else if (x == "type") {
        cout << "Enter new type (groceries/home/tech/clothes/all): ";
        cin >> newStringValue;
        mp->type = StringToType(newStringValue);
        cout << "Type updated successfully!" << endl;
    }
    else if (x == "business") {
        cout << "Enter new business (base/side/franchise/corporation/small): ";
        cin >> newStringValue;
        mp->business = newStringValue;
        cout << "Business updated successfully!" << endl;
    }
    else {
        cout << "Invalid field name!" << endl;
    }
}

int main() {
    const int size = 20;
    struct marketplace general_data[size];
    struct marketplace loaded_data[size];

    general_data[0] = { "Amazon", 112, "us", "NewYork", 34056300, All, "corporation" };
    general_data[1] = { "Lamoda", 23, "ru", "Moscow", 7846600, Clothes, "base" };
    general_data[2] = { "AliExpress", 88, "ch", "SaintPetersburg", 5325315, All, "franchise" };
    general_data[3] = { "Abeme", 78, "uk", "London", 97203700, Home, "side" };
    general_data[4] = { "MangoMango", 13, "de", "Koln", 932000, Groceries, "small" };
    general_data[5] = { "YandexMarket", 56, "ru", "Moscow", 8750000, Tech, "corporation" };
    general_data[6] = { "Rozetka", 42, "ru", "SaintPetersburg", 3450000, Home, "side" };
    general_data[7] = { "Pinduoduo", 95, "cn", "Shanghai", 56700000, Groceries, "franchise" };
    general_data[8] = { "Wayfair", 31, "us", "Boston", 11200000, Home, "corporation" };
    general_data[9] = { "Allegro", 48, "pl", "Poznan", 7680000, Groceries, "base" };
    general_data[10] = { "Gmarket", 39, "kr", "Seoul", 6540000, Clothes, "franchise" };
    general_data[11] = { "Snapdeal", 44, "in", "NewDelhi", 3210000, Tech, "small" };
    general_data[12] = { "Coupang", 82, "kr", "Seoul", 23400000, Groceries, "corporation" };
    general_data[13] = { "TradeMe", 27, "nz", "Auckland", 2980000, All, "side" };
    general_data[14] = { "Myntra", 36, "in", "Bangalore", 4320000, Clothes, "franchise" };
    general_data[15] = { "Newegg", 53, "us", "CityOfIndustry", 7650000, Tech, "corporation" };
    general_data[16] = { "Zalora", 28, "sg", "Singapore", 1980000, Clothes, "small" };
    general_data[17] = { "Jumia", 61, "ng", "Lagos", 5430000, Groceries, "franchise" };
    general_data[18] = { "Linio", 33, "mx", "MexicoCity", 2870000, Tech, "base" };
    general_data[19] = { "Souq", 47, "ae", "Dubai", 6210000, Home, "side" };

    cout << "Prac10.1" << endl;
    ifstream fin("prac10.txt");
    if (!fin.is_open()) {
        cout << "Error: cannot open file" << endl;
        return 1;
    }

    string name;
    int number;
    cout << "Numeric values from file:" << endl;
    while (fin >> name >> number) {
        cout << number << endl;
    }
    fin.close();
    cout << endl;

    cout << "Prac10.2" << endl;
    WriteToBinaryFile("marketplace.bin", general_data, size);
    ReadFromBinaryFile("marketplace.bin", loaded_data, size);
    DisplayData(loaded_data, size);

    SearchName(general_data, size);

    NotMoscow(general_data);
    Top3Popular(general_data);
    GroceriesMarketplaces(general_data);
    SortMenu(general_data);
    ChangeMarketplaceData(general_data);

    return 0;
}
