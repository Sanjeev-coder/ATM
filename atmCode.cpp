#include<bits/stdc++.h>
using namespace std;

/*  Mini Project
    -> Check Balance
    -> Cash WithDraw
    -> User Details
    -> Update Mobile No
*/

class atm                                               // class name
{
    private:                                           // private member variables

    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

    public:

    // setData function setting the Data into the private member variables
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
    {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }

    // getAccountNo is returning users account number
    long int getAccountNo()
    {
        return account_No;
    }

    // getName function is returning the user's Name
    string getName()
    {
        return name;
    }

    // getPIN function is returning the user's PIN
    int getPIN()
    {
        return PIN;
    }

    // getBalace is returning the user's Bank Balance
    double getBalance()
    {
        return balance;
    }

    //  getMobile is returning the user's mobile number
    string getMobileNo()
    {
        return mobile_No;
    }

    // setMobile function is updating the user mobile number
    void setMobile(string mob_prev, string mob_new)
    {
        if(mob_prev == mobile_No)
        {
            mobile_No = mob_new;
            cout<<endl<<" Succesfully updated mobile number ";
            cout<<endl<<"______________________________________________________________________________"<<endl;
            getchar();
        }
    }

    // cashWithDraw function is used to withDraw money form ATM
    void cashWithDraw(int amount_a)
    {
        if(amount_a > 0 && amount_a < balance)
        {
            balance -= amount_a;
            cout<<"_____________________________________________________________________________________"<<endl;
            cout<<endl<<"Please Collect Your Cash : "<<amount_a<<endl;
            cout<<endl<<"Availabel Cash is : "<<balance<<endl;
            cout<<"_____________________________________________________________________________________"<<endl;
            getchar();
        }
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int choice = 0, enterPIN;   // -> enterPIN and enterAccountNo.    ----> user Authentication
    long int enterAccountNo;

    // created User (object)
    atm user1;
    // Set user Details (into object)    (setting default data)
    user1.setData(1234567, "Tim", 1111, 45000.90, "9087654321");

    do
    {
        cout<<endl<<"-*-*-*-*-*-       W e l c o m e   T o   A t m         -*-*-*-*-*- "<<endl;
        cout<<endl<<"Enter Your Account Number : ";
        cin>>enterAccountNo;

        cout<<endl<<"Enter PIN : ";
        cin>>enterPIN;

        // check wheater the entered values matches with user details
        if((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                // user Interface

                cout<<endl<<"**** S E L E C T     O P T I O N S    T O     P R O C E E D ****"<<endl;
                cout<<endl<<"Select Option";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash Withdrqw";
                cout<<endl<<"3. Show User Interface";
                cout<<endl<<"4. Update Mobile No.";
                cout<<endl<<"5. Exit."<<endl<<endl<<" ";
                cout<<"OPTION : ";
                cin>>choice;              //taking user choice
                cout<<"_______________________________________________________________________________________"<<endl<<endl;
                switch(choice)
                {
                    case 1:
                        cout<<endl<<"Your Bank Balance is : "<<user1.getBalance();
                        cout<<endl<<"__________________________________________________________________________"<<endl<<endl;

                        break;

                    case 2:
                        cout<<endl<<"Enter the amount : ";
                        cin>>amount;
                        user1.cashWithDraw(amount);
                        break;

                    case 3:
                        cout<<endl<<"User Details are :- ";
                        cout<<endl<<"-> Account No "<<user1.getAccountNo();
                        cout<<endl<<"-> Name       "<<user1.getName();
                        cout<<endl<<"-> Balance    "<<user1.getBalance();
                        cout<<endl<<"-> Mobile No. "<<user1.getMobileNo();
                        cout<<endl<<"____________________________________________________________________________"<<endl;

                        getchar();
                        break;

                    case 4:
                        cout<<endl<<"Enter Old Mobile No. ";
                        cin>>oldMobileNo;

                        cout<<endl<<"Enter New Mobile No. ";
                        cin>>newMobileNo;

                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;

                    case 5:
                        cout<<endl<<"T H A N K     Y O U     F O R     U S I N G     O U R     S E R V I C E "<<endl<<endl;
                        cout<<endl<<"_____________________________________________________________________________________"<<endl;
                        exit(0);

                    default:
                        cout<<endl<<"Enter Valid Data !!!";
                }
            } while(1);
        }
    } while(1);
    
}