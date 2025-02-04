#include <iostream>
#include<conio.h>
#include<limits>
#include <string>
#include <cctype> 
using namespace std;

const int MAX_CANDIDATES = 5;
const int MAX_VOTERS = 100;

struct Candidate {
    string name;
    string place;
    int votes;
};

int getMenuChoice() {
    cout << "\n\t\t------- Voting System Menu-----\n";
    cout << "\t\t| 1. Vote                     |\n";
    cout << "\t\t| 2. Display Results          |\n";
    cout << "\t\t| 3. Exit                     |\n";    
    cout<<"\t\t-------------------------------";
    cout<<endl<<endl;
    int Choice;
    cout<<"\nMake your Choice :  ";
    while(true){
        if(cin>>Choice){
            if(Choice > 0 && Choice <= 3){
                break;
            }
            else{
                cout<<"\nEnter a number from 1 to 3 : ";
            }
        }
        else{
            cout<<"\nPlease enter a number : ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return Choice;
}

int main(){
    cout << "\n\n\n\n\t\t**\n";
    cout << "\t\t^^|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |^^\n";
    cout << "\t\t^^|                                           		                             |^^\n";
    cout << "\t\t^^|                                           		                             |^^\n";
    cout << "\t\t^^|                                           		                             |^^\n";
    cout << "\t\t^^|                                           		                             |^^\n";
    cout << "\t\t^^|                                           		                             |^^\n";
    cout << "\t\t^^|                                           		                             |^^\n";
    cout << "\t\t^^|                               WELCOME TO                                         |^^\n";
    cout << "\t\t^^|                                                                                  |^^\n";
    cout << "\t\t^^|                              E-VOTING SYSTEM                                     |^^\n";
    cout << "\t\t^^|                                                                                  |^^\n";
    cout << "\t\t^^|                                                                                  |^^\n";
    cout << "\t\t^^|                                                                                  |^^\n";
    cout << "\t\t^^|                                                                                  |^^\n";
    cout << "\t\t^^|                                                DEVELOPED BY:                     |^^\n";
    cout << "\t\t^^|                                                             Sardar Hashir        |^^\n";
    cout << "\t\t^^|                                                                   (56750)        |^^\n";
    cout << "\t\t^^|                                                                                  |^^\n";
    cout << "\t\t^^|                                                                                  |^^\n";
    cout << "\t\t^^|                                                                                  |^^\n";
    cout << "\t\t^^||^^\n";
    cout << "\t\t**\n\n\t\t";
    
    getch();
    system("cls");
    Candidate candidates[MAX_CANDIDATES];  
    int numCandidates;
    cout<<"Enter the Number of Candidates: ";
    while(true){
        if(cin>>numCandidates){
            if(numCandidates > 0 && numCandidates <= MAX_CANDIDATES){
                break;
            }
            else{
                cout<<"\nInvalid Input. Please Enter a Number from 1 to 5 : ";
            }
        }
        else{
                cout<<"\nInvalid Input. Please Enter a Number : ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int i = 0; i < numCandidates; ++i) {
        cout << "\nEnter the name of Candidate " << i + 1 << ": ";
        cin.ignore();
        getline(cin, candidates[i].name);
        // Input validation for name
        while (true) {
            bool containsDigit = false;
            for (char c : candidates[i].name) {
                if (isdigit(c)) {
                    containsDigit = true;
                    break;
                }
            }
            if (containsDigit) {
                cout << "\nName cannot contain numbers. Please enter a valid name: ";
                getline(cin, candidates[i].name);
            } else {
                break; // Break out of the loop if the name is valid
            }
        }
        
        cout << "\nEnter the Place of Candidate " << i + 1 << ": ";
        getline(cin, candidates[i].place);
        // Input validation for place
        while (true) {
            bool containsDigit = false;
            for (char c : candidates[i].place) {
                if (isdigit(c)) {
                    containsDigit = true;
                    break;
                }
            }
            if (containsDigit) {
                cout << "\nPlace cannot contain numbers. Please enter a valid place: ";
                getline(cin, candidates[i].place);
            } else {
                break; // Break out of the loop if the place is valid
            }
        }

        cout << endl;
        candidates[i].votes = 0;
    }

    int numVoters;
    cout << "\nEnter the Number of Voters : ";
    while(true){
        if(cin>>numVoters){
            if(numVoters > 0 && numVoters <= MAX_VOTERS){
                break;
            }
            else{
                cout<<"\nInvalid Input. Please Enter a Number from 1 to 100 : ";
            }
        }
        else{
            cout<<"\nInvalid Input. Please Enter the Number : ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int choice;
    do{
        choice = getMenuChoice();
        int voterId, candidateId;
        switch (choice) {
            case 1: {
                cout <<"\nEnter your Voter ID : ";
                while(true){
                    if(cin>>voterId){
                        if(voterId > 0 && voterId <= numVoters){            
                            break; 
                        }
                        else{
                            cout<<"\nInvalid Voter ID! Please Enter a Valid ID :  ";
                        }
                    }
                    else{
                        cout<<"\nInvalid Voter ID! Please Enter a Valid ID : ";
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                if (candidates[voterId - 1].votes != 0) {
                    cout << "\"YOU HAVE ALREADY VOTED!!!\" \n";
                    break;
                }
                
                cout << "\nCandidates:\n\n";
                for (int i = 0; i < numCandidates; i++) {
                    cout <<"\t\t"<< i + 1 << ". " << candidates[i].name << " (" << candidates[i].place << ")\n";
                }
                
                cout << "\n\Enter your Candidate choice : ";
                cin>>candidateId;
                
                while(true){
                    if(cin>>candidateId){
                        if(candidateId >0 && candidateId <= numCandidates){
                            break;
                        }
                        else{
                            cout<<"\nInvalid Candidate Choice! Please Enter a Valid Choice : ";
                        }
                    }
                    else{
                        cout<<"\nInvalid Candidate Choice! Please Enter a Number for Choice : ";
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
                candidates[candidateId - 1].votes++;
                cout<<"^^^^^^^^^^^^^^^^^^^^\n";
                cout<<"^                  ^\n";
                cout<<"^  VOTE RECORDED!  ^\n";
                cout<<"^                  ^\n";
                cout<<"^^^^^^^^^^^^^^^^^^^^";
                break;
            }
            case 2:{
                cout << "\n===== Voting Results =====\n";
                for (int i = 0; i < numCandidates; ++i) {
                    cout << "Candidate " << candidates[i].name << " (" << candidates[i].place << "): " << candidates[i].votes << " votes\n";
                }
                cout << "\n==========================\n";
                break;
            }
            case 3:{
                cout << "\nExiting the Program...\n";
                break;
            }
            default:
                cout << "\nInvalid Choice! Please Try Again.\n";
        }
    }
    while(choice!=3);
    return 0;
}
