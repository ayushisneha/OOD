#include<iostream>
using namespace std;
//bit array of size 64- sizeof int is 4bytes = 4*8bits = 32 bits, 
// thus, size of array is 2*32 = 64 bits

int arr[2] = {0,0};

void display(int k){
    int i=0;
    while(i<32){
        cout<<k%2;
        k/=2;
        i++;
    }
}

void display(){
    display(arr[0]);
    display(arr[1]);
}

void set(int index, int value){
    
}


int main(){
    display();
    return 0;

}