#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenue();

// Enum for main menu options
enum enMainMenuOptions
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, eExit = 6
};

// Struct to represent a client record
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

// Splits a string into a vector of strings using a delimiter
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable 

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;
}

// Converts a line of text from the file into a client record
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double

    return Client;
}

// Loads all clients from file into a vector
vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        sClient client;

        while (getline(MyFilel, Line))
        {
            client = ConvertLinetoRecord(Line);

            vClients.push_back(client);
        }
        MyFile.close();
    }
    return vClients;

}

void ShowAllClientsScreen()
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    // TODO 1: implement LoadCleintsDataFromFile
    // TODO 2: Rest
}
// Go back to main menu
void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenu();

}

// Read main menu option from user
short ReadMainMenuOption()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

// Perform the selected main menu option
void PerfromMainMenuOption(enMainMenuOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenuOptions::eListClients:
    {
        system("cls");
        // TODO 1: Implement ShowAllClientsScreen to list all clients
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenuOptions::eAddNewClient:
        system("cls");
        // TODO 3: Implement ShowAddNewClientsScreen to add new clients
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenuOptions::eDeleteClient:
        system("cls");
        // TODO 4: Implement ShowDeleteClientScreen to delete a client
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenuOptions::eUpdateClient:
        system("cls");
        // TODO 5: Implement ShowUpdateClientScreen to update client info
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenuOptions::eFindClient:
        system("cls");
        // TODO 6: Implement ShowFindClientScreen to find a client
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenuOptions::eExit:
        system("cls");
        // TODO 7: Implement ShowEndScreen to show exit message
        ShowEndScreen();
        break;
    }
}

// Show the main menu screen
void ShowMainMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exit.\n";
    cout << "===========================================\n";
    PerfromMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}

int main()
{
    ShowMainMenu(); // Start program by showing main menu
    return 0;
}