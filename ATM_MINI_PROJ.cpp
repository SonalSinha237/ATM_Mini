/*ATM MINI PROJECT
Features:
 -> Check balance
 -> Cash Withdrawal
 -> User details
 -> Update mobile no
*/

#include<bits/stdc++.h>
#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

class atm
{
private:                        //private member variables
    long int acc_no;
    string name, mob_no;
    int pin;
    double balance;

public:                         //public member functions

    //setData to setting the values of private variables
    //original data as database
    void setData(long int acc_nox, string namex, string mob_nox, int pinx, double balancex)
    {
        acc_no = acc_nox;
        name = namex;
        mob_no = mob_nox;
        pin = pinx;
        balance = balancex;
    }

    //returns user's details
    long int getAccNo()             //returns user's account no.
    {
        return acc_no;
    }

    string getName()                //returns user's name
    {
        return name;
    }

    string getMobile()              //returns user's mobile no
    {
        return mob_no;
    }

    int getPin()                    //returns user's pin
    {
        return pin;
    }

    double getBalance()             //returns user's balance
    {
        return balance;
    }

    //Mobile no update
    void setMobile(string oldMob, string newMob)
    {
        if(mob_no == oldMob)                               //if old no provided by user is same as mob_no stored in data, then mob_no is updated with the new no.
        {
            mob_no = newMob;
            cout<<"Mobile no updated successfully!"<<endl;
            getch();
        }
        else
        {
            cout<<"No such mobile no exists in our database."<<endl<<"Please enter correct no.";
            getch();
        }
    }

    //Cash Withdrawal from ATM
    void cashWithdrawal(double amount)
    {
        if(amount>0 && amount<=balance)
        {
            balance -= amount;                             //balance = balance - amount
            cout<<"Please collect your cash"<<endl;
            cout<<"Available bank balance : "<<balance;
            getch();
        }
        else if(amount<0)
        {
            cout<<"Please enter valid input.";
            getch();
        }
        else if(amount>balance)
        {
            cout<<"Insufficient account balance.";
            getch();
        }
    }
};

int main()
{
    int choice, enterPIN;
    long int enterAccNo;

    system("cls");

    //user object creation
    atm user1;
    //setting user1 details
    user1.setData(123456789,"sonal","7223989277",0000,50000.45);

    do
    {
        system("cls");

        //Account and user verification
        cout<<"Welcome to ABS bank ATM!"<<endl<<endl;
        cout<<"Please enter your Account number: ";
        cin>>enterAccNo;
        cout<<endl;
        cout<<"Enter ATM Pin: ";
        cin>>enterPIN;
        cout<<endl<<endl;

        if(enterAccNo==user1.getAccNo() && enterPIN==user1.getPin())
        {
            do
            {
                 //cout<<"User verified!"<<endl<<endl;
                 cout<<"Please enter your option:"<<endl;
                 cout<<"1. Check account balance"<<endl;
                 cout<<"2. Withdraw cash"<<endl;
                 cout<<"3. Show User details"<<endl;
                 cout<<"4. Update mobile number"<<endl;
                 cout<<"5. Exit"<<endl;
                 cout<<endl;
                 cin>>choice;                       //user choice


                 switch(choice)
                 {
                 case 1:
                     {cout<<"Your account balance is: Rs. "<<user1.getBalance();
                     cout<<endl<<endl;
                     getch();
                     break;}

                 case 2:
                    {int amount;
                    cout<<"Enter the amount to be withdrawn: ";
                    cin>>amount;
                    user1.cashWithdrawal(amount);
                    cout<<endl<<endl;
                    getch();
                    break;}

                 case 3:
                    {cout<<"Your user details are: "<<endl<<endl;
                    cout<<"Name: "<<user1.getName()<<endl;
                    cout<<"Account No.: "<<user1.getAccNo()<<endl;
                    cout<<"Mobile No.: "<<user1.getMobile()<<endl;
                    cout<<"Balance: "<<user1.getBalance()<<endl;
                    cout<<endl<<endl;
                    getch();
                    break;}

                 case 4:
                    {string oldMob, newMob;
                    cout<<"Enter old mobile no: ";
                    cin>>oldMob;
                    if(oldMob == user1.getMobile())
                    {
                        cout<<"Enter new mobile no: ";
                        cin>>newMob;
                        cout<<endl;
                        user1.setMobile(oldMob,newMob);
                        cout<<"New mobile no: "<<user1.getMobile();
                        cout<<endl<<"Mobile no updated!";
                        cout<<endl<<endl;
                    }
                    else
                    {
                        cout<<"Enter correct mobile no.";
                    }
                    getch();
                    break;}

                 case 5:
                     {
                         exit(0);                //exit application
                     }

                 default:
                    cout<<"User details invalid.";
                    cout<<endl<<endl;

                 }
            }
            while(1);

        }
        else
        {
            cout<<"Incorrect details!";
            getch();
        }
    }while(1);

        return 0;





}

