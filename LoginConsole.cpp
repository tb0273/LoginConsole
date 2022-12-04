#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LoginManager
{
public:
    LoginManager()
    {
        accessGranted = 0;
    }

    void login()
    {
        cout << "Enter your password and user.\nUsername:";
        cin >> userNameAttempt;
        cout << "Password:";
        cin >> passWordAttempt;
        

        if (getFile(userNameAttempt,"users.txt"))
        {
            if (getFile(passWordAttempt, "pswds.txt"))
            {
                cout << "Login success!";
            }
            else
            {
                cout << "Input incorrect password!" << endl;
                login();
            }
        }
        else
        {
            cout << "Input incorrect username!" << endl;
            login();
        }
    }
    bool getFile(string attempt, const char* p_fileName)
    {
        string line;
        fstream file;
        bool access{0};

        file.open(p_fileName, ios::in);

        if (file.is_open())
        {
            while (1)
            {
                file >> line;
                if (line == "0")
                {
                    file.close(); cout << "\nfile close\n";
                    return access;
                }
                else if (attempt == line)
                {
                    access = 1;
                }
            }
        }
        else
        {
            return access;
        }
    }
private:
    string passWord;
    string userName;
    string userNameAttempt;
    string passWordAttempt;
    bool accessGranted;
};

int main()
{
    LoginManager app;
    app.login();
}