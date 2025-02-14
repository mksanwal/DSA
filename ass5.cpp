#include<bits/stdc++.h>
using namespace std;

const int size = 10;

class Node{
    public:
    string word;
    string meaning;
    Node* next;

    Node(string word, string mean){
        this->word = word;
        this->meaning=mean;
        this->next=NULL;
    }
};

int hashing(string s){
    int sum=0;
    for(int i=0;i<s.size();i++){
        char c=s[s.size()-1-i];
        int n=(int)c;
        sum += n*(pow(10,i));
    }
    return sum%10;
}

void insert(Node* arr[], string word, string mean){
    int val=hashing(word);
    Node* newNode = new Node(word, mean);

    if(arr[val]==nullptr){
        arr[val]=newNode;
    }else{
        newNode->next=arr[val];
        arr[val]=newNode;
    }
}

void display(Node* arr[]){
    for(int i=0;i<size;i++){
        if (arr[i] != nullptr) {
            Node* current = arr[i];
            cout << "Index " << i << ": ";
            while (current != nullptr) {
                cout << "|" << current->word << "| (" << current->meaning << ") ";
                current = current->next;
            }
            cout << endl;
        } else {
            cout << "Empty" << endl;
        }
    }
}

void search(Node* arr[], string value){
    int hashValue = hashing(value);
    Node* current = arr[hashValue];

    while (current != nullptr) {
        if (current->word == value) {
            cout << "Found value \"" << value << "\" with meaning: " << current->meaning << endl;
            return;
        }
        current = current->next;
    }
    
    cout << "Value \"" << value << "\" not found in the hash table." << endl;
}

int main(){

    Node* arr[size] = {nullptr};
    
    int menu;

    while (menu != 4) {
        cout << "Enter your choice (1->Insert  2->Display  3->Search  4->Exit): ";
        cin >> menu;
        if(menu==1){
            string s;
            string mean;
            cout<<"Enter Word you want to enter: ";
            cin>>s;
            cout<<"Enter meaning you want to enter: ";
            cin.ignore();
            getline(cin,mean);
            insert(arr,s, mean);
        }else if(menu==2){
            cout<<"Displaying the Hash table" << endl;
            display(arr);
        }else if(menu==3){
            string s;
            cout<<"Enter value you want to search: ";
            cin>>s;
            search(arr,s);
        }else if(menu==4){
            cout<<"Successfully exited from program"<< endl;
        }else{
            cout<<"Enter valid option: ";
        }
    }
}