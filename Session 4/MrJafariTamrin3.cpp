#include<iostream>

using namespace std;

int main()
{
    double num,sum=0,average;
    
    for(int i=1; i<=5; i++){
        cout<<"enter the "<< i << "th namber: ";
        cin>> num;
        sum= sum+num;
    }
    
    average= sum / 5;
    
    cout<< average<< endl; 
    return 0;
}    


    