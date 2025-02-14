#include <bits/stdc++.h>
using namespace std;

void insertion(int v, int arr[]) {
    int val = v%10;  
    int i = 0;
    while(i < 10) {
        int change = (val + i * i) % 10;  
        if (arr[change] == -1) {  
            arr[change] = v;
            cout << "Successfully inserted the value "<< endl;
            return;
        }
        i++;
    }
    cout<<"Table is full"<<endl;  
}

void display(int arr[]) {
    for(int i=0;i<10;i++){
        cout<<"For i="<<i<<" value is: "<<arr[i]<<endl;
    }
}


double calculate(int arr[]) {
    int count = 0;
    for(int i=0;i<10;i++) {
        if(arr[i] != -1 && arr[i] != -2){
            count++;
        }
    }
    return (double)count;
}

void deletion(int n, int arr[]) {
    int comp=0;
    int val=n%10;
    int i=0;
    while(i<10) {
        comp++;
        int change = (val+i*i)%10;
        if(arr[change]==n){  
            arr[change]=-2;  
            cout<<"Successfully deleted the value "<<endl;
            cout<<"No. of comparisons are: "<<comp<<endl;
            return;
        }
        if(arr[change]==-1){  
            cout << "Value not found" << endl;
            cout << "No. of comparisons are: " << comp << endl;
            return;
        }
        i++;
    }
    cout<<"Value not found"<<endl;
}

void search(int n, int arr[]) {
    int comp=0;
    int val=n%10;
    int i = 0;
    while (i < 10) {
        comp++;
        int change = (val+i*i)%10;
        if(arr[change]==n) {  
            cout<<"Value found at location: "<<change<<endl;
            cout<<"No. of comparisons are: "<<comp<<endl;
            return;
        }else if(arr[change]==-1){  
            cout<<"Value is not present in table"<<endl;
            cout<<"No. of comparisons are: "<< comp<<endl;
            return;
        }
        i++;
    }
    cout<<"Value is not present in table"<<endl;
}

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        arr[i]=-1;
    }

    int menu;

    while (menu != 6) {
        cout << "Enter your choice (1->Insert  2->Display  3->Deletion  4->Search  5->Load factor 6->Exit): ";
        cin >> menu;
        if(menu==1){
            int n;
            cout<<"Enter value you want to enter: ";
            cin>>n;
            insertion(n, arr);
        }else if(menu==2){
            cout<<"Displaying the Hash table" << endl;
            display(arr);
        }else if(menu==3){
            int v;
            cout<<"Enter value you want to delete: ";
            cin>>v;
            deletion(v, arr); 
        }else if(menu==4){
            int v;
            cout<<"Enter value you want to search: ";
            cin>>v;
            search(v, arr);
        }else if(menu==5){
            double lf=calculate(arr)/10.0;
            cout<<"Load Factor is: "<<lf<< endl;
        }else if(menu==6){
            cout<<"Successfully exited from program"<< endl;
        }else{
            cout<<"Enter valid option: ";
        }
    }

}
