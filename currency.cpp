#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

// Function to get currency code
string getCurrencyCode(int choice) {
    switch(choice) {
        case 1: return "USD";
        case 2: return "INR";
        case 3: return "EUR";
        case 4: return "GBP";
        default: return "";
    }
}

// Function to display menu
void showMenu() {
    cout << "\nSelect Currency:\n";
    cout << "1. USD\n";
    cout << "2. INR\n";
    cout << "3. EUR\n";
    cout << "4. GBP\n";
}

// Function to clear invalid input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {

    string apiKey = "c186c26613402f04bbf23be3";
    char choice;

    do {
        cout << "\n=====================================\n";
        cout << "   REAL-TIME CURRENCY CONVERTER 💱\n";
        cout << "=====================================\n";

        int fromChoice, toChoice;
        double amount;

        // FROM currency
        showMenu();
        cout << "Convert FROM: ";
        cin >> fromChoice;

        if(cin.fail()) {
            cout << "Invalid input! Try again.\n";
            clearInput();
            continue;
        }

        // TO currency
        showMenu();
        cout << "Convert TO: ";
        cin >> toChoice;

        if(cin.fail()) {
            cout << "Invalid input! Try again.\n";
            clearInput();
            continue;
        }

        // Amount
        cout << "Enter amount: ";
        cin >> amount;

        if(cin.fail() || amount <= 0) {
            cout << "Invalid amount!\n";
            clearInput();
            continue;
        }

        string from = getCurrencyCode(fromChoice);
        string to = getCurrencyCode(toChoice);

        if(from == "" || to == "") {
            cout << "Invalid currency selection!\n";
            continue;
        }

        // API URL
        string url = "https://v6.exchangerate-api.com/v6/" + apiKey + "/latest/" + from;

        // Fetch data
        system(("curl -s -o data.json " + url).c_str());

        ifstream file("data.json");

        if(!file) {
            cout << "Error reading data file!\n";
            continue;
        }

        json data;
        file >> data;

        double rate;

        // API success check
        if(data["result"] == "success") {
            rate = data["conversion_rates"][to];
        } else {
            cout << "⚠️ API failed! Using fallback rates.\n";

            // fallback rates
            if(from == "USD" && to == "INR") rate = 92.6;
            else if(from == "INR" && to == "USD") rate = 0.012;
            else if(from == "USD" && to == "EUR") rate = 0.92;
            else if(from == "EUR" && to == "USD") rate = 1.09;
            else if(from == "USD" && to == "GBP") rate = 0.78;
            else if(from == "GBP" && to == "USD") rate = 1.28;
            else rate = 1; // default fallback
        }

        double result = amount * rate;

        cout << "\n========== RESULT ==========\n";
        cout << amount << " " << from << " = " << result << " " << to << endl;
        cout << "============================\n";

        // Continue option
        cout << "\nDo you want to convert again? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the converter! 🚀\n";

    return 0;
}