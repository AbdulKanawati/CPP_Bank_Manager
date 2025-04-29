#include <iostream>
using namespace std;

// Enum for main menu options
enum enMainMenuOptions
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, eExit = 6
};

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
        // TODO 2: Implement GoBackToMainMenue to navigate back to the main menu screen
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