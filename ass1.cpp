#include <bits/stdc++.h>
using namespace std;

void insertion(int v,int arr[]){
    int val=v%10;
    if(arr[val]==-1){
        arr[val]=v;
        cout<<"Sucessfully inserted the value"<<endl;
    }else{
        int l=1;
        while(l<10){
            
            if(arr[(val+l)%10]==-1){
                arr[(val+l)%10]=v;
                cout<<"Sucessfully inserted the value"<<endl;
                break;
            }
            l++;
        }
        if(l==10){
            cout<<"Table is full";
        }

    } 

}

void display(int arr[]){
    for(int i=0;i<10;i++){
        cout<<"For i="<<i<<"value is:"<<arr[i]<<endl;
    }
}

double calculate(int arr[],double num){
    for(int i=0;i<10;i++){
        if(arr[i]!=-1 && arr[i]!=-2){
            num++;
        }
    }
    return num;
}

void deletion(int n, int arr[]){
    int comp=0;
    int val=n%10;
    
    int l=0;
    while(l<10){
        comp++;
        if(arr[(val+l)%10]==n){
            arr[(val+l)%10]=-2;
            cout<<"Sucessfully deleted the value"<<endl;
            cout<<"No. of comaprisons are: "<<comp<<endl;
            break;
        }if(arr[(val+l)%10]==-1){
            cout<<"value not found"<<endl;
            cout<<"No. of comaprisons are: "<<comp<<endl;
            break;
        }
        if(l==10){
        cout<<"value not found"<<endl;
        }
        l++;
    }
}

void search(int n, int arr[]){
    int comp=0;
    int val=n%10;
    
    int l=0;
    while(l<10){
        comp++;
        if(arr[(val+l)%10]==n){
            cout<<"value found at location: "<<(val+l)%10<<endl;
            cout<<"No. of comaprisons are: "<<comp<<endl;
            break;
        }else if(arr[(val+l)%10]== -1){
            cout<<"value is not present in table"<<endl;
            cout<<"No. of comaprisons are: "<<comp<<endl;
            break;
        }
        l++;
        if(l==10){
            cout<<"value is not present in table"<<endl;
            cout<<"No. of comaprisons are: "<<comp<<endl;
            break;
        }
    }   
}


int main(){
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = -1;
    }
    
    double num=0;
    int menu;
    
    while(menu!=6){
        cout<<"Enter your choice (1->Insert  2->Display  3->Deletion  4->Search  5->Load factor 6->Exit): ";
        cin>>menu;
        if(menu==1){
            int n;
            cout<<"Enter value you want to enter: ";
            cin>>n;
            insertion(n,arr);
        }
        else if(menu==2){
            cout<<"Displaying the Hash table"<<endl;
            display(arr);
        }
        else if(menu==3){
            int v;
            cout<<"Enter value you want to delete: ";
            cin>>v;
            deletion(v,arr);
        }
        else if(menu==4){
            int v;
            cout<<"Enter value you want to search: ";
            cin>>v;
            search(v,arr);
        }
        else if(menu==5){
            double lf = calculate(arr,num)/10;
            cout<<"Load Factor is: "<<lf<<endl;
        }
        else if(menu==6){cout<<"Sucessfully exitied from program!!";}
        else{cout<<"Enter valid option: ";}
    }
}