/*                             ZED_HUB PROJECT

the system is a demo designed system to support ten(10)innovators (registration and there innovation ideas).
its not a fully finished system as it is mandated to be maintainable and updated to a system that can closely meet the standard quality of a good programed system
and meet user requirements.
the system is intend to supports the manager,coordinator and technician for access to the system.
the access privileges to the system are dependent on the role of the user in the organization.
manager and coordinator have more roles to play while the technician is limited in roles compared to the other two roles.
to the source code are attached document such as the innovator.txt,which hold the innovators details records,
records.txt stores the logging in details which are the user-name,password.
the provided user manual help to highlight a simplified interrelationship requirement for the development of the system movements and access within the system.


GROUP MEMBERS

NAME:              SIN_NUMBER:

MISHECK.C.MWICHE   22104657.
RICHARD CHINYANTA  22111404
MOSES   SIKAONGA   22103543.
MAURICE BANDA      22107084.
CHEWE   KANGWA     22108870
CHARLES.M.CHIBESA  22111765.
*/

#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

const int max1=10;
int solution=0;
struct innovator{
    string Nrc_passport;
    string firstName;
    string surname;
    int age;
    string titleOfInnovation;
    string dateSubmitted;
    string patentStatus;
    string innovationCategory;
};
innovator innovators[max1];
int innovatorcount=0;
void login();
void load_data(){
  ifstream inputFile("innovators.txt");
    if (inputFile.is_open()) {
            while (innovatorcount < max1 && inputFile >> innovators[innovatorcount].Nrc_passport ) {
            inputFile >> innovators[innovatorcount].firstName;
            inputFile >> innovators[innovatorcount].surname;
            inputFile >> innovators[innovatorcount].age;
            inputFile >> innovators[innovatorcount].titleOfInnovation;
            inputFile >> innovators[innovatorcount].dateSubmitted;
            inputFile >> innovators[innovatorcount].patentStatus;
            inputFile >> innovators[innovatorcount].innovationCategory;
            innovatorcount++;
        }
        inputFile.close();
    }
    }
void save_data();
void view();
void addinovator();
void deleteinnovator();
void searchinnovator();
void searchinnovator2();
void Edit_innovator_Record();
void category();
void Menu();
void Menu2();
int main(){
    load_data();
    int signin;
    cout<<"\t\t\t\t\~~~ WELCOME TO ZED_HUB ~~~ \n "<<endl;
    cout<<"\t\t\t\t\ ~~~LOGGINGIN PAGE ~~~\n\n"<<endl;
    cout<<"Press 1 to Login"<<endl;
    cin>>signin;
    cin.ignore();
    switch(signin)
    {
    case 1:
        login();
    system("cls");
    cout<<"\t\t\t\t Thank you!!"<<endl;
    return 0;
         break;

    default :
        cout<< "\t\t\t\t Please choose among the options provided"<<endl;
        main();
    }
}
    void login(){
    int count;
    string userid, userpassword, user, password;
    cout<< "\t\t\t\t  Enter Your Username and Password\n\n";
    cout<< "\t\t\t\t  USERNAME : ";
    cin>>userid;
    cout<<" "<<endl;
    cout<< "\t\t\t\t PASSWORD  : ";
    cin>>userpassword;
    ifstream input("Records.txt");

    while(input>>user>>password)
    {
    if(user==userid && password==userpassword)
    {
        count=1;
        system("cls");
    }
    }
    input.close();

    if(count==1 && userid=="Manager" || userid=="Coordinator")
    {
    solution++;
    system("cls");
    Menu();
    }
    else if (count == 1 && userid=="Technician"){
        Menu2();
    }
    else{
    system("cls");
    cout<<"You have entered the wrong PASSWORD or USERID Please try again by placing one again to login \n\n";
    main();
    }
    }


void Menu(){
    int main1;
    cout<<"\t\t\t~~~ WELCOME TO ZED_HUB ~~~\n";
    cout<<"\t\t\t~~~     MAIN MENU ~~~ \n\n";
    cout<<"Press 1 to Add Innovator                             "<<endl;
    cout<<"Press 2 to Delete innovator                          "<<endl;
    cout<<"Press 3 to Search Innovator                          "<<endl;
    cout<<"Press 4 to Edit Innovator Record               "<<endl;
    cout<<"Press 5 to Display innovators by innovation Category "<<endl;
    cout<<"Press 6 to Exit                                      "<<endl;
    cout<<"Enter  your choice :";
    cin>>main1;
    cin.ignore();
    switch(main1)
    {
    case 1:
        system("cls");
        addinovator();
        break;
    case 2:
        system("cls");
        deleteinnovator();
        break;
    case 3:
        system("cls");
        searchinnovator();
        break;
    case 4:
        system("cls");
        Edit_innovator_Record();
        break;
    case 5:
        system("cls");
        category();
        break;
    case 6:
        system("cls");
        cout<<"You have Logged out Successfully \n";
        main();
    default :
        cout<< "\t\t\t\t Please choose among the options provided"<<endl;
        Menu();
    }
}
void Menu2(){
    int display;
    cout<<"\t\t\t~~~ WELCOME TO ZED_HUB ~~~\n";
    cout<<"\t\t\t~~~   TECHNICIAN MENU ~~~\n\n";
    cout<<"Press 1 to to view innovators "<<endl;
    cout<<"Press 2 to Search for an innovator "<<endl;
    cout<<"Press 3 to Exit "<<endl;
    cout<<"Enter  your choice :";
    cin>>display;
    cin.ignore();
    system("cls");
    switch(display)
    {
    case 1:
        view();
        break;
    case 2:
        searchinnovator2();
        break;
    case 3:
        cout<<"You have Logged out Successfully \n\n\n";
        system("cls");
        main();
    default :
        cout<< "Please choose among the options provided\n\n"<<endl;
        Menu2();
    }
}
void view(){
            int display;
for(int x=0; x<innovatorcount; x++){
            cout << "NRC/Passport No      : " << innovators[x].Nrc_passport << endl;
            cout << "First Name           : " << innovators[x].firstName << endl;
            cout << "Surname              : " << innovators[x].surname << endl;
            cout << "Age                  : " << innovators[x].age << endl;
            cout << "Title of Innovation  : " << innovators[x].titleOfInnovation << endl;
            cout << "Date Submitted       : " << innovators[x].dateSubmitted << endl;
            cout << "Patent Status        : " << innovators[x].patentStatus << endl;
            cout << "Innovation Category  : " << innovators[x].innovationCategory << endl;
            cout << "\n\n";
}
            cout << "\n\n\t\t\t\t Press One to go back to Main Menu :";
            cin>>display;
            cin.clear();
            cin.ignore(100, '\n');
        switch(display){
        case 1:
            system("cls");
            Menu2();
        default:
            system("cls");
            cout<< "Invalid response"<<endl;
            Menu2();
            }
}

void searchinnovator2(){
    string Nrc_passport;
    cout<<" Enter NRC/Passport No of the innovator to search  \n\n";
    cout <<"Enter NRC/Passport No: ";
    cin >> Nrc_passport;
    for (int i = 0; i < innovatorcount; i++) {
        if (innovators[i]. Nrc_passport ==  Nrc_passport) {
            system("cls");
            int searchfor;
            innovator &innovator = innovators[i];
            cout << "NRC_Passport No      : " << innovators[i].Nrc_passport << endl;
            cout << "First Name           : " << innovators[i].firstName << endl;
            cout << "Surname              : " << innovators[i].surname << endl;
            cout << "Age                  : " << innovators[i].age << endl;
            cout << "Title of Innovation  : " << innovators[i].titleOfInnovation << endl;
            cout << "Date Submitted  : " << innovators[i].dateSubmitted << endl;
            cout << "Patent Status   : " << innovators[i].patentStatus << endl;
            cout << "Innovation Category  : " << innovators[i].innovationCategory << endl;
            cout<<"\n\n";
            cout << "Press one for Menu :";

            cin.ignore();
            cin>>searchfor;
          switch(searchfor){
        case 1:
            system("cls");
            if(solution == 0){
                cout<<"Search Complete";
                cout<<"\n\n";
                Menu2();
            break;
        default:
             system("cls");
            cout<< "Invalid response"<<endl;
            if (solution==0){
                    Menu2();
            }
            }
          }
      }
   }
   system("cls");
   cout << "Innovator not found." << endl;
   Menu2();
}

void save_data(){
ofstream outputfile("innovators.txt");
for (int i = 0; i < innovatorcount; i++) {
        outputfile << innovators[i].Nrc_passport << " ";
        outputfile << innovators[i].firstName << " ";
        outputfile << innovators[i].surname << " ";
        outputfile << innovators[i].age<< " ";
        outputfile << innovators[i].titleOfInnovation << " ";
        outputfile << innovators[i].dateSubmitted << " ";
        outputfile << innovators[i].patentStatus << " ";
        outputfile << innovators[i].innovationCategory << " ";
        outputfile << endl;
    }
    outputfile.close();
}
void addinovator(){
    if (innovatorcount<max1){
    innovator &innovator = innovators[innovatorcount];
    cout<< "FIRSTNAME: ";
    cin>>innovator.firstName;
    cout<< "SURNAME  : ";
    cin>> innovator.surname;
    cout<< "AGE      : ";
    cin>> innovator.age;
    cout<< "NRC      : ";
    cin>>innovator.Nrc_passport;
    cout<< "Title of Innovation : ";
    cin>>innovator.titleOfInnovation;
    cout<< "Date Submitted      : ";
    cin>>innovator.dateSubmitted;
    cout<< "Patent Status       : ";
    cin>>innovator.patentStatus;
    cout<< "Innovation Category : ";
    cin>>innovator.innovationCategory;
    innovatorcount++;
    save_data(); // Save data to file
    system("cls");
    cout << "Innovator added successfully!\n" << endl;
    Menu();

    }
         else
    {
        cout << "Maximum number of innovators reached.\n" << endl;
        Menu();
    }
}
void deleteinnovator(){
    string Nrc_passport2;
    cout << "\n\n\t\t\t\t NRC/Passport No : ";
    cin >> Nrc_passport2;
    for (int i = 0; i < innovatorcount; i++) {
        if (innovators[i].Nrc_passport == Nrc_passport2) {
            for (int j = i; j < innovatorcount - 1; j++) {
                innovators[j] = innovators[j + 1];
            }
            innovatorcount--;
            save_data();
            system("cls");
            cout << "Innovator deleted successfully!\n" << endl;
            Menu();
        }
    }
    system("cls");
    cout << "Innovator not found \n" << endl;
    Menu();
}
void searchinnovator(){
    string Nrc_passport;
    cout<<" Enter NRC/Passport No of the innovator to search  \n\n";
    cout <<"Enter NRC/Passport No: ";
    cin >> Nrc_passport;
    for (int i = 0; i < innovatorcount; i++) {
        if (innovators[i]. Nrc_passport ==  Nrc_passport) {
            system("cls");
            int lookfor;
            innovator &innovator = innovators[i];
            cout << "NRC_Passport No      : " << innovators[i].Nrc_passport << endl;
            cout << "First Name           : " << innovators[i].firstName << endl;
            cout << "Surname              : " << innovators[i].surname << endl;
            cout << "Age                  : " << innovators[i].age << endl;
            cout << "Title of Innovation  : " << innovators[i].titleOfInnovation << endl;
            cout << "Date Submitted  : " << innovators[i].dateSubmitted << endl;
            cout << "Patent Status   : " << innovators[i].patentStatus << endl;
            cout << "Innovation Category  : " << innovators[i].innovationCategory << endl;
            cout<<"\n\n";
            cout << "Press one for Menu :";

            cin.ignore();
            cin>>lookfor;
          switch(lookfor){
        case 1:
            system("cls");
            if(solution == 1){
                cout<<"Search Complete";
                cout<<"\n\n";
                Menu();
            break;
        default:
            system("cls");
            cout<< "Invalid response"<<endl;
            if (solution==1){
                    Menu();
            }

            }
           }
        }
     }
     system("cls");
     cout << "Innovator not found." << endl;
     Menu();
   }

void Edit_innovator_Record(){
string Nrc_passport;
    cout << "\t\t\t\t Enter NRC/Passport No: ";
    cin >>  Nrc_passport;
    for (int i = 0; i < innovatorcount; i++) {
        if (innovators[i]. Nrc_passport == Nrc_passport) {
            innovator &innovator = innovators[i];
            cout<<"Edit  \n\n";
            cout << "Enter updated NRC/Passport No    : ";
            cin >> innovator.Nrc_passport;
            cout << "Enter updated First Name         : ";
            cin >> innovator.firstName;
            cout << "Enter updated Surname            : ";
            cin >> innovator.surname;
            cout << "Enter updated Age                : ";
            cin >> innovator.age;
            cout << "Enter updated Title of Innovation: ";
            cin >> innovator.titleOfInnovation;
            cout << "Enter updated Date Submitted     : ";
            cin >> innovator.dateSubmitted;
            cout << "Enter updated Patent Status      : ";
            cin >> innovator.patentStatus;
            cout << "Enter updated Innovation Category: ";
            cin >> innovator.innovationCategory;
            cout << "Innovator updated successfully..!" << endl;
            save_data();
            system("cls");
            cout << "Innovator updated successfully..!" << endl;
            Menu();
        }
        }
        system("cls");
        cout << "Innovator not found." << endl;
        Menu();
    }

void category() {
    int display;
    string category;
    cout <<"\t\t\t\t Enter Category : ";
    cin >> category;
    for (int i = 0; i < innovatorcount; i++){
        if (innovators[i].innovationCategory ==  category) {
            cout << "\n";
            cout << "\t\t\t\t NRC/Passport No: " << innovators[i].Nrc_passport << endl;
            cout << "\t\t\t\t First Name : " << innovators[i].firstName << endl;
            cout << "\t\t\t\t Surname: " << innovators[i].surname << endl;
            cout << "\t\t\t\t Age    : " << innovators[i].age << endl;
            cout << "\t\t\t\t Title of Innovation: " << innovators[i].titleOfInnovation << endl;
            cout << "\t\t\t\t Date Submitted: " << innovators[i].dateSubmitted << endl;
            cout << "\t\t\t\t Patent Status : " << innovators[i].patentStatus << endl;
            cout << "\t\t\t\t Innovation Category: " << innovators[i].innovationCategory << endl;
            cout << "\n";
        }
    }
            cout << "\n\t\t\t\t Press 1 to go back to Main Menu :";
             cin>>display;
            switch(display){
        case 1:
            if (solution == 1)
            {
                system("cls");
                Menu();
            }
            else
             {
           cout<<"innovator not found";
             }
}
}
