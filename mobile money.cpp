#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int balance = 1000; // Default balance
    int pin = 0000; // Default pin
    int attempts = 0; // Keeps track of the number of attempts
    bool authenticated = false;

    while (!authenticated) // Keep asking for authentication until it succeeds
    {
        cout << "Enter your PIN: ";
        cin >> pin;

        if (cin.fail()) // Check if the input is a number
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            attempts++;
            if (attempts >= 3)
            {
                cout << "You have exceeded the maximum number of attempts. Exiting program." << endl;
                return 0;
            }
            continue;
        }

        if (pin == 0000) // Replace 1234 with the correct pin
        {
            authenticated = true;
            cout << "Authentication successful" << endl;
        }
        else
        {
            attempts++;
            if (attempts >= 3)
            {
                cout << "You have exceeded the maximum number of attempts. Exiting program." << endl;
                return 0;
            }
            cout << "Invalid PIN. Please try again." << endl;
        }
    }

    // Display menu
    while (true) // Main program loop
    {
        int choice;
        cout << "Welcome to the Mobile Banking System" << endl;
        cout << "1. Reset/Change Pin" << endl;
        cout << "2. Check Balance" << endl;
        cout << "3. Send Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) // Check if the input is a number
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                int new_pin;
                cout << "Enter your new PIN: ";
                cin >> new_pin;

                if (cin.fail()) // Check if the input is a number
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }

                pin = new_pin;
                cout << "PIN changed successfully" << endl;

                break;

            case 2:
                cout << "Your balance is: " << balance << endl;

                break;

            case 3:
                int momo_pin;
                int amount;
                int num;
                cout << "Enter Mobile number: ";
                cin >> num;
                cout<<"Enter the amount to send: ";
                cin >> amount;
                cout<<"enter your Pin:";
                cin>>momo_pin;

                if (cin.fail()) // Check if the input is a number
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }
                if (momo_pin != pin)
                {
                    cout << "Invalid MoMo PIN. Please try again." << endl;
                    continue;
                }



                if (amount <= balance)
                {
                    balance -= amount;
                    cout << "Transaction successful" << endl;
                    cout << "New balance: " << balance << endl;
                }
                else
                {
                    cout << "Insufficient funds" << endl;
                }

                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}
