#include <iostream>
#include <string>

using namespace std;

void username_check();
void password_check();
void add_username();

string userDB[128][2] = {{"FBI", "open up"}, {"huh", "okay"}};
bool stateAddUser = false;

int main()
{
    string new_user, new_pass;
    int last_index, i = 0;

    username_check();

    // Add new user ----------------------------------------------------------------
    if (stateAddUser == true)
    {
        cout << "Enter a username: ";
        getline(cin, new_user);

        do
        {
            last_index = i;
            i++;
        } while (userDB[i][0] != "");

        // last_index = size(userDB);
        userDB[last_index + 1][0] = new_user;

        cout << "Enter a password: ";
        getline(cin, new_pass);
        userDB[last_index + 1][1] = new_pass;

        cout << last_index << " " << userDB[last_index + 1][0] << endl;
        cout << last_index << " " << userDB[last_index + 1][1] << endl;
        return 0;
    }
    // ----------------------------------------------------------------------------

    password_check();

    return 0;
}

void username_check()
{
    bool state = true;
    string check_user;

    while (state)
    {
        cout << "\nNew users enter \"000\".";
        cout << "\nEnter your username: ";
        getline(cin, check_user);

        if (check_user == "000")
        {
            stateAddUser = true;
            state = false;
            // add_username();
        }
        else if (check_user == "FBI")
        {
            state = false;
        }
        else
        {
            cout << "User not found.\n";
        }
    }
}

void password_check()
{
    string check_pass;
    bool state = true;
    while (state)
    {

        cout << "Enter password: ";
        getline(cin, check_pass);

        if (check_pass == "open up")
        {
            cout << "Welcome.";
            state = false;
        }
        else
        {
            cout << "Wrong password.\n";
        }
    }
}

// void add_username()
// {
//     string new_user;
//     cout << "\nEnter a username: ";
//     getline(cin, new_user);
// }