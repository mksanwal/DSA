#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> v(10,vector<int> (2,-1));
 
void insert(int n){
 
    int idx = n%10;

    if(v[idx][0] == -1){
        v[idx][0] = n;
    }
    else if (v[idx][0]%10 != idx){
        for(int i = idx; i < idx + 10; i++){
            int j = i % 10; 
            if(v[j][0] == -1){
                v[j][0] = v[idx][0];
                v[j][1] = v[idx][1];
                for(int i=0;i<10;i++){
                    if(v[i][1]==idx){
                        v[i][1]=j;
                    }
                }
                break;
            }
        }
        v[idx][0]=n;
        v[idx][1]=-1;
        return;
    }else if(v[idx][0]%10 == idx){
        while(v[idx][1]!=-1){
            idx=v[idx][1];
        }    
        for(int i = idx; i < idx + 10; i++){
            int j = i % 10; 
            if(v[j][0] == -1){
                v[j][0] = n;
                v[idx][1]=j;
                return;
                }
            }
        
    }   
        
}
 
void display(){
    for(int i = 0;i<10;i++){
        cout<<i<<" | "<<v[i][0]<<" | "<<v[i][1]<<endl;
    }
}
 
void search(int n){
    int idx = n%10;
    if(v[idx][0] == -1){
        cout<<"Element is not present "<<endl;
        return;
    }else if(v[idx][0]%10 == idx){
        if(v[idx][0]==n){
            cout<<"Element is found at: "<<idx<<endl;
            return;
        }else{
            while(v[idx][1] != -1){
                idx=v[idx][1];
                if(v[idx][0] == n){
                    cout<<"Element is found at: "<<idx<<endl;
                    return;
                }
            }
            cout<<"Elemet is not present"<<endl;
            return;
        }
    }
}
 
int main(){

    int menu;

    while (menu != 4) {
        cout << "Enter your choice (1->Insert  2->Display  3->Search  4->Exit): ";
        cin >> menu;
        if(menu==1){
            int n;
            cout<<"Enter value you want to enter: ";
            cin>>n;
            insert(n); 
            
        }else if(menu==2){
            cout<<"Displaying the Hash table" << endl;
            display();
        }else if(menu==3){
            int n1;
            cout<<"Enter value you want to search: ";
            cin>>n1;
            search(n1);
      
        }else if(menu==4){
            cout<<"Successfully exited from program"<< endl;
        }else{
            cout<<"Enter valid option: ";
        }
    }
}




