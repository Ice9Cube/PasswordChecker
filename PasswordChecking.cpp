#include <iostream>
#include <string>

using std::cout;
using std::string;

class CheckPassword{
private:
    string password;

    int Checking(string &password){
        int score = 0;
        for (int i = 0; i < password.length(); i++){
            if (isupper(password[i])){
                score++;
            }
            else if (isascii(password[i]) != islower(password[i])){
                score++;
            }
            else if (isdigit(password[i])){
                score++;
            }
            else {
                continue;
            }
        }
        return score;
    }

public:

    void SetPass(string x){
        password = x;
    }
    string GetPass(){
        return password;
    }

    void Display(string &password){
        int averange_score = password.length()/2 + password.length()/4;
        if (password.length() < 10){
            cout << "Too short password. Try again!\n";
        }
        else {
            int score = Checking(password);
            if (score < averange_score){
                cout << "Too simple password. Please try again!\n";
            }
            else {
                cout << "Your password: "<< password<<"\n";
                cout << "Your password is accepted\n";
            }
        }
    }

};

int main(){

    CheckPassword pass;

    string passw;

    cout << "Enter password: "; std::cin >> passw;

    pass.SetPass(passw);

    string new_password = pass.GetPass();

    pass.Display(new_password);


    return 0;
}
