#include <iostream>
#include <fstream>  
#include <string>   
using namespace std;

// Function to register a new user
void registration()
{
    string username, password;
    ofstream outFile; // Output file stream for writing to file
    
    // Ask user for a username and password
    cout << "Enter Username: " << endl;
    cin >> username;
    cout << "Enter Password: " << endl;
    cin >> password;
    
    // Create a file with the username as filename
    outFile.open(username + ".txt");

    // If file opens successfully
    if (outFile.is_open())
    {
        // Write username and password to file
        outFile << "Username: " << username << endl;
        outFile << "Password: " << password << endl;
        outFile.close(); // Close the file
        cout << "Registration successful! Your account has been created." << endl;
    }
    else
    {
        cout << "File cannot be created" << endl;
    }
}

// Function to login an existing user
void login()
{
    string username, password;           // User-entered values
    string correctusername, correctpassword; // Data from file
    ifstream inFile; // Input file stream for reading from file

    // Ask user to enter username and password
    cout << "Enter Username: " << endl;
    cin >> username;
    cout << "Enter Password: " << endl;
    cin >> password;

    // Open the file with the given username
    inFile.open(username + ".txt");

    // If the file exists
    if (inFile.is_open())
    {
        getline(inFile, correctusername);  // Read the first line
        getline(inFile, correctpassword);  // Read the second line
        inFile.close(); // Close the file

        // Compare user input with file data
        if (username == correctusername && password == correctpassword)
        {
            cout << "Login successful! Welcome back, " << username << endl;
        }
        else
        {
            cout << "Invalid credentials." << endl;
        }
    }
    else
    {
        cout << "Error: No such user found. Please register first." << endl;
    }
}

// Main function
int main()
{
    int choice;

    // Display menu
    cout << "Welcome to the Registration and Login System" << endl;
    cout << "1: Registration System" << endl;
    cout << "2: Login System" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    // Perform action based on user choice
    switch (choice)
    {
        case 1:
            registration(); // Call registration function
            break;
        case 2:
            login(); // Call login function
            break;
        default:
            cout << "Invalid Choice"; // If choice is not 1 or 2
    }

    return 0;
}

