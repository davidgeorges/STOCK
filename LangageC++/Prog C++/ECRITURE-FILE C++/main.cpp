#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string userBuffer;
    string passBuffer;
    string rep;
    string retry;
    string username;
    string password;
    int c(0);
    int x(0);
    string const user("user.txt");
    string const pass("pass.txt");
    ofstream fluxWriteUser; // on mode mode ecriture
    ofstream fluxWritePass; // on mode mode ecriture
    ifstream fluxReadUser; // on mode lecture
    ifstream fluxReadPass; // on mode lecture
    fluxWriteUser.open(user.c_str(),ios::app); // mode ecriture
    fluxWritePass.open(pass.c_str(),ios::app); // mode ecriture
    fluxReadUser.open(user.c_str()); // mode lecture
    fluxReadPass.open(pass.c_str()); // mode lecture
    /* ---------------------------------------------------------------------------------------------------------------
      NOT WORKING NOT WORKING NOT WORKING NOT WORKING NOT WORKING NOT WORKING  NOT WORKING  NOT WORKING  NOT WORKING
    ----------------------------------------------------------------------------------------------------------------*/
    /* ---------------------------------------------------------------------------------------------------------------
      NOT WORKING NOT WORKING NOT WORKING NOT WORKING NOT WORKING NOT WORKING  NOT WORKING  NOT WORKING  NOT WORKING
    ----------------------------------------------------------------------------------------------------------------*/
    /* ---------------------------------------------------------------------------------------------------------------
      NOT WORKING NOT WORKING NOT WORKING NOT WORKING NOT WORKING NOT WORKING  NOT WORKING  NOT WORKING  NOT WORKING
    ----------------------------------------------------------------------------------------------------------------*/
    /* ---------------------------------------------------------------------------------------------------------------
      NOT WORKING NOT WORKING NOT WORKING NOT WORKING NOT WORKING NOT WORKING  NOT WORKING  NOT WORKING  NOT WORKING
    ----------------------------------------------------------------------------------------------------------------*/

    retry ="";
    c = 1;

    while (c == 1)
    {

        cout << "Create account or login ? : "<< endl;
        cin >> rep;
        cout << "!!!!!!! rep : " << rep << endl;



            if ( rep == "login")
            {
                username = "";
                userBuffer = "";
                passBuffer = "";
                fluxReadUser.seekg(0,ios::beg);
                fluxReadPass.seekg(0,ios::beg);
                cin.ignore();
                cout << "!!!!!!! : " << username << endl;
                cout << "Enter your ID :" << endl;
                cin >> username;
                cin.ignore();

                while (getline(fluxReadUser,userBuffer))
                {

                    cout << "!!!!!!! buffer : " << userBuffer << endl;
                    if (userBuffer == username)
                    {
                        cout << "!!!!!!! : " << username << endl;
                        cout << "ID Found , pls enter your password : " << endl;
                        cin >> password;

                        if(passBuffer == password)
                        {
                            cout << " Success connect ! " << endl;
                            fluxReadUser.close();
                            fluxReadPass.close();
                        }
                    else
                    {
                        cout << "Wrong info,  do you want to retry ? yes or no" << endl;
                        cin>> retry;
                        if (retry == "no")
                        {
                            c = 0;
                            cout << "Closing...";
                            return 0;
                        }
                    }

                    }
                }

                }

            else if (rep == "create")
            {
                cout << "Enter your username to create an account : " << endl;
                cin >> username;
                cout << "Enter your password to create an account : " << endl;
                cin >> password;

                if(username.length() > 15)
                {
                    cout << " Error username to long..." << endl;
                    return 0;
                    c=0;
                }

                if(password.length() > 15)
                {
                    cout << " Error password to long..." << endl;
                    return 0;
                    c=0;
                }

                fluxWriteUser << endl << username;
                fluxWritePass << endl << password;

                fluxWriteUser.close();
                fluxWritePass.close();

                c=0;
            }

            else
            {
            cout << "Error retry ..." << endl;
                        return 0;
            }


    }



}
