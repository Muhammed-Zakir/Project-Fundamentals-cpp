#include <iostream>
#include <istream>
#include <fstream>
#include <string.h>
#include <string>
#include <iomanip>
#include <stdlib.h>


using namespace std;

//a data structure to save furniture details
struct furniture{
    string icode, iname, icolor, iqt, iprice;
};

struct Invoice{
    string icode;
    string itype;
    int iquantity;
    float iprice, iTotal;
};

//prototype declaration
void login();
void signup();
void mainMenu();

//five sub functions to open five text files and display data
void viewFurnitures();
void viewTables ();
void viewChairs ();
void viewBeds ();
void viewWardrobes();
void viewSofas();

void updateStore();
furniture insertData(furniture); //function for furniture details insertion

void billCustomer();
void logout();

//main function is designed for user registration, login, and then authenticate access to the main menu of the system

int main(){

    int choice;
    cout<<"****************LOGIN******************"<<endl;
    cout<<"\n1.Login";
    cout<<"\n2.Signup";
    cout<<"\n\nEnter your choice: ";

    cin>>choice;

/*switch case is used here,
default will noify invalid input and allow to run the main function again*/

    switch(choice)
    {
        case 1:

            login();
            mainMenu();
            break;

        case 2:
            signup();
            break;

        default:
            cout<<"Sorry Invalid Input\nTo try again please 'enter'\n";
            cout<<endl;
            cin.get();
            cin.get();
            main();
    }
    return 0;
}

//this function is for signup process,

void signup()
{
    string reguser, regpass;

    cout<<"\n**********SignUp***********\n\nEnter the username: ";
    cin>>reguser;

    cout<<"Enter the password: ";
    cin>>regpass;

//system will get username and password then store them in a text file named users

    ofstream reg("users.txt",ios::app);
    reg<<reguser<<"  "<<regpass<<endl;

//registration success notification and login option provided

    cout<<endl<<" Registration is Successful\n Please 'enter' to login"<<endl;
    cout<<endl;
    cin.get();
    cin.get();
    login();
}
//end of the signup function

//start of the login function

void login()
{
    int exist;
    string user, pass, u, p;

    cout<<"\n**********Login***********\n\nPlease enter your username: ";
    cin>>user;

    cout<<"Please enter your password: ";
    cin>>pass;

//username and password entered to the console are assigned to variables

    ifstream input("users.txt");

    while(input>>u>>p)
    {
        if(u==user && p==pass)

            //input credentials are validated with stored data in the 'users' text file
        {
            exist = 1;
        }
    }

    input.close();

//if matches login success

    if (exist == 1)
    {
        cout<<endl<<"Login Successful\n\n	Welcome!"<<user<<"\n";
        cout<<"To continue please 'enter'"<<endl;
        cin.get();
        cin.get();
        mainMenu();
    }

//or can go back and login again or sign up using the main function

    else
    {
        cout<<" Sorry, Login Error.\n To go back please 'enter'";
        cin.get();
        cin.get();
        cout<<endl<<main();
    }

}

//after a successful login, mainMenu function is called

void mainMenu()
{
    int choice;

//main menu of the System

    cout<<" _*_*__*_*_*__*_*__*_*_*__*_SUPREME FURNITURES_*_*__*_*_*__*__*_*_*__*_"<<endl;
    cout<<" _______________________Operations Management System____________________"<<endl;
    cout<<"\nPlease select an option from below menu"<<endl;

    cout<<"\n1.View Available Furnitures";
    cout<<"\n2.Update Store Room Data";
    cout<<"\n3.Bill a Customer";
    cout<<"\n4.Logout"<<endl;

    cout<<"\nEnter your choice here: ";

    cin>>choice;
    cout<<endl;

//as per the requirements of the system four functions are  declared

    switch(choice)
    {
        case 1:
            viewFurnitures();
            break;

        case 2:
            updateStore();
            break;

        case 3:
            billCustomer();
            break;

        case 4:
            logout();
            break;

//default will assist invalid inputs

        default:
            cout<<"Sorry Invalid Input\nTo try again please 'enter'\n";
            cout<<endl;
            cin.get();
            cin.get();
            mainMenu();
    }
}

//first function of the main menu

void viewFurnitures(){

//switch case used to select different types of furnitures

    int choice;

    cout << "**************************View Furnitures**************************" << endl;
    cout << "\nPlease select the item you want to view from below options," <<
         endl;
    cout << "\n 1 Tables\n 2 Chairs\n 3 Beds\n 4 Wardrobes\n 5 Sofas\n 99 Main menu";
    cout << "Please enter your selection here: ";
    cin >> choice;

//five text files are accessed

    switch (choice)
    {
        case 1:
            viewTables();
            break;

        case 2:
            viewChairs();
            break;

        case 3:
            viewBeds();
            break;

        case 4:
            viewWardrobes();
            break;

        case 5:
            viewSofas();
            break;

//Or else can go back to the main menu

        case 99:
            mainMenu();
            break;

        default:
            cout << "Invalid input\nPlease try again";
            cin.get ();
            cin.get ();
            viewFurnitures ();
    }

//or after viewing details can go back to the furniture menu

    cout<<"To go back please 'enter'";
    cin.get ();
    cin.get ();
    viewFurnitures ();

}

//this is the second function of the system
//this allows to store date in seperate text files, as per the furniture type

void updateStore()
{
    int choice;

    cout<<"*************************Update Store Room**************************"<<endl;
    cout<<"\nPlease select the item you want to add from below options,"<<endl;
    cout<<"\n 1 Table\n 2 Chair\n 3 Bed\n 4 Wardrobe\n 5 Sofa\n 99 Main menu";
    cout<<"Please enter your selection here: ";
    cin>>choice;

    furniture f;

    if (choice==1){
        cout<<"~~~~~~~~~~~~~~~~Add Tables~~~~~~~~~~~~~~~~~"<<endl;
        f= insertData(f); //insertData functiona called with return of furniture data type of 'f'
        ofstream a("tables.txt",ios::app);
        a<<endl<<f.icode<<"  "<<f.icode<<"  "<<f.iname<<"  "<<f.icolor<<"  "<<f.iqt<<"  "<<f.iprice<<endl;}

    else if (choice==2){
        cout<<"~~~~~~~~~~~~~~~~Add Chairs~~~~~~~~~~~~~~~~~"<<endl;
        f= insertData(f);
        ofstream b("chairs.txt",ios::app);
        b<<endl<<f.icode<<"  "<<f.icode<<"  "<<f.iname<<"  "<<f.icolor<<"  "<<f.iqt<<"  "<<f.iprice<<endl;}

    else if (choice==3){
        cout<<"~~~~~~~~~~~~~~~~Add Beds~~~~~~~~~~~~~~~~~"<<endl;
        f= insertData(f);
        ofstream c("beds.txt",ios::app);
        c<<endl<<f.icode<<"  "<<f.icode<<"  "<<f.iname<<"  "<<f.icolor<<"  "<<f.iqt<<"  "<<f.iprice<<endl;}

    else if (choice==4){
        cout<<"~~~~~~~~~~~~~~~~Add Wardrobes~~~~~~~~~~~~~~~~~"<<endl;
        f= insertData(f);
        ofstream d("wardrobes.txt",ios::app);
        d<<endl<<f.icode<<"  "<<f.icode<<"  "<<f.iname<<"  "<<f.icolor<<"  "<<f.iqt<<"  "<<f.iprice<<endl;}

    else if (choice==5){
        cout<<"~~~~~~~~~~~~~~~~Add Sofa~~~~~~~~~~~~~~~~~"<<endl;
        f= insertData(f);
        ofstream e("sofas.txt",ios::app);
        e<<endl<<f.icode<<"  "<<f.icode<<"  "<<f.iname<<"  "<<f.icolor<<"  "<<f.iqt<<"  "<<f.iprice<<endl;}

    else if (choice==99){
        mainMenu();
    }
    else{
        cout<<"Invalid input\nPlease try again";
        cin.get();
        cin.get();
        updateStore();}

    cout<<"Item saved successfully";

    cout<<"To go back please 'enter'";
    cin.get ();
    cin.get ();
    updateStore ();
}

//Billing function
//Function can store data in sales file
//will provide an invoice

void billCustomer()
{
    string cxname, cxphone;
    float subTotal=0;
    int size;

    cout<<"Please enter maximum of 5 items per bill\n\n";
    cout<<"Enter customer name: ";cin>>cxname;
    cout<<"Enter customer phone number: ";cin>>cxphone;
    cout<<"\nHow many items are there for this bill? ";cin>>size;

    Invoice invoice[size];
    for(int i=0; i<size; i++)
    {
        cout<<"Enter item code: ";cin>>invoice[i].icode;
        cout<<"Enter item type: ";cin>>invoice[i].itype;
        cout<<"Enter item quantity: ";cin>>invoice[i].iquantity;
        cout<<"Enter unit price: ";cin>>invoice[i].iprice;
        cout<<endl;

        invoice[i].iTotal = invoice[i].iquantity*invoice[i].iprice;

        subTotal = subTotal + invoice[i].iTotal;
    }



    //open file to send data
    ofstream oFile("sales.txt",ios::app);

    //send data to the file
    oFile<<cxname<<"  "<<cxphone<<"  "<<subTotal<<endl;

    for(int i=0; i<size; i++){
        oFile<<invoice[i].icode<<"  "<<invoice[i].icode<<"  "<<invoice[i].itype<<"  "<<invoice[i].iquantity<<"  "
             <<invoice[i].iprice<<"  "<<invoice[i].iTotal<<endl<<endl;
    }
    oFile.close();

//INVOICE

    cout<<"\n===============================INVOICE===============================\n"<<endl;
    cout<<"     Customer name: "<<cxname<<endl;
    cout<<"     Customer phone number: "<<cxphone<<endl<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    cout<<left
        << setw(10)<<"Item_code"<<"| "<< setw(15)<<"Description"<<"| "
        << setw(10)<<"Quantity"<<"| "<< setw(10)<<"Unit price"<<"| "<< setw(10)<<"Item_Total"<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    for(int i=0; i<size; i++){
        cout<<left<<endl
            << setw(10)<<invoice[i].icode<<" "
            << setw(15)<<invoice[i].itype<<" "
            << setw(10)<<invoice[i].iquantity<<" "
            << setw(15)<<invoice[i].iprice<<" "
            << setw(15)<<invoice[i].iTotal<<endl;
    }
    cout<<"_______________________________________________________________________"<<endl;
    cout<<"\n     Sub Total = Rs."<<subTotal<<endl;
    cout<<"       **************************"<<endl;
}

void logout()
{
    main();
}

///////////////////////////  View statements  //////////////////////////////////

// Tables
void viewTables ()
{
    ifstream input ("tables.txt", ios::app);

    char x;
    furniture f;
    cout<<".........................Tables......................."<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    cout<<left
        << setw(10)<<"Code"<<"| "<< setw(15)<<"Description"<<"| "<<setw(10)<<"Color"
        <<"| "<< setw(10)<<"Quantity"<<"| "<< setw(10)<<"Unit price"<< endl;
    cout<<"_______________________________________________________________________"<<endl;
    while (input >> x){
        input>>f.icode>>f.icode>>f.iname>>f.icolor>>f.iqt>>f.iprice;
        cout<<left
            << setw(10)<<f.icode<<"  "<< setw(15)<<f.iname<<"  "<< setw(10)<<f.icolor<<"  "
            << setw(10)<<f.iqt<<"  "<< setw(10)<<f.iprice<<endl;
    }
    input.close ();
    cout<<"_______________________________________________________________________"<<endl;
}

// Chairs
void viewChairs ()
{
    ifstream input ("chairs.txt", ios::app);

    char x;
    furniture f;
    cout<<".........................Chairs......................."<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    cout<<left
        << setw(10)<<"Code"<<"| "<< setw(15)<<"Description"<<"| "<<setw(10)<<"Color"
        <<"| "<< setw(10)<<"Quantity"<<"| "<< setw(10)<<"Unit price"<< endl;
    cout<<"_______________________________________________________________________"<<endl;
    while (input >> x){
        input>>f.icode>>f.icode>>f.iname>>f.icolor>>f.iqt>>f.iprice;
        cout<<left
            << setw(10)<<f.icode<<"  "<< setw(15)<<f.iname<<"  "<< setw(10)<<f.icolor<<"  "
            << setw(10)<<f.iqt<<"  "<< setw(10)<<f.iprice<<endl;
    }
    input.close ();
    cout<<"_______________________________________________________________________"<<endl;
}

// Beds
void viewBeds ()
{
    ifstream input ("beds.txt", ios::app);

    char x;
    furniture f;
    cout<<".........................Beds......................."<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    cout<<left
        << setw(10)<<"Code"<<"| "<< setw(15)<<"Description"<<"| "<<setw(10)<<"Color"
        <<"| "<< setw(10)<<"Quantity"<<"| "<< setw(10)<<"Unit price"<< endl;
    cout<<"_______________________________________________________________________"<<endl;
    while (input >> x){
        input>>f.icode>>f.icode>>f.iname>>f.icolor>>f.iqt>>f.iprice;
        cout<<left
            << setw(10)<<f.icode<<"  "<< setw(15)<<f.iname<<"  "<< setw(10)<<f.icolor<<"  "
            << setw(10)<<f.iqt<<"  "<< setw(10)<<f.iprice<<endl;
    }
    input.close ();
    cout<<"_______________________________________________________________________"<<endl;
}


// Wardrobes
void viewWardrobes()
{
    ifstream input ("wardrobes.txt", ios::app);

    char x;
    furniture f;
    cout<<".........................Wardrobes......................."<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    cout<<left
        << setw(10)<<"Code"<<"| "<< setw(15)<<"Description"<<"| "<<setw(10)<<"Color"
        <<"| "<< setw(10)<<"Quantity"<<"| "<< setw(10)<<"Unit price"<< endl;
    cout<<"_______________________________________________________________________"<<endl;
    while (input >> x){
        input>>f.icode>>f.icode>>f.iname>>f.icolor>>f.iqt>>f.iprice;
        cout<<left
            << setw(10)<<f.icode<<"  "<< setw(15)<<f.iname<<"  "<< setw(10)<<f.icolor<<"  "
            << setw(10)<<f.iqt<<"  "<< setw(10)<<f.iprice<<endl;
    }
    input.close ();
    cout<<"_______________________________________________________________________"<<endl;
}

// Sofas
void viewSofas()
{
    ifstream input ("sofas.txt", ios::app);

    char x;
    furniture f;
    cout<<".........................Sofa......................."<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    cout<<left
        << setw(10)<<"Code"<<"| "<< setw(15)<<"Description"<<"| "<<setw(10)<<"Color"
        <<"| "<< setw(10)<<"Quantity"<<"| "<< setw(10)<<"Unit price"<< endl;
    cout<<"_______________________________________________________________________"<<endl;
    while (input >> x){
        input>>f.icode>>f.icode>>f.iname>>f.icolor>>f.iqt>>f.iprice;
        cout<<left
            << setw(10)<<f.icode<<"  "<< setw(15)<<f.iname<<"  "<< setw(10)<<f.icolor<<"  "
            << setw(10)<<f.iqt<<"  "<< setw(10)<<f.iprice<<endl;
    }
    input.close ();
    cout<<"_______________________________________________________________________"<<endl;
}

////////////////////////////////////////////////////////////////////////////////

furniture insertData(furniture f)
{
    cout<<"_______________________________________________________________________"<<endl;
    cout<<"To add the selected type of new item\nPlease enter below details,"<<endl;
    cout<<"\n       1. Enter the item code: ";
    cin>>f.icode;

    cout<<"         2. Enter item name: ";
    cin>>f.iname;

    cout<<"         3. Enter item color: ";
    cin>>f.icolor;

    cout<<"         4. Enter item quantity available: ";
    cin>>f.iqt;

    cout<<"         5. Enter unit price: ";
    cin>>f.iprice;

    return f;
}
