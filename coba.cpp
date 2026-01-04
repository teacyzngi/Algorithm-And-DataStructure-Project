#include <iostream>
#include <string>

using namespace std;

#define max 5
string Data[max];
int top = 0;

bool isFull() {
    if (top>=max) {
         return true;
    }
    else {
            return false;
        }
}


bool isEmpty(){
    if(top==0){
        return true;
    }
    else {

    } 
}
void view (){
    if (!isEmpty()){
        cout << "Data Antrian : "<< endl;
        for (int a = top - 1; a>=0; a--){
            cout <<  a+1 << ". " << Data[a] << endl; 
        }
        else 
        {
            cout << " Antrian Kosong " << endl;
        }
        if (isFull()) {
            cout << " Antrian Penuh" << endl;
        }
        cout << endl;
    }

}
void enqueue (){
    if(!isFull()) {
        cout << " Masukkan Data : ";
        cin>> data[top];
        top++ ;
    }
}

int main () {

    int pil;
    string isi;

    queue:
    cout<< " Antrian Restoran\n1. Enqueue\n2. Dequeue\n Pilihan : ";
    cin >> pil;

    if (pil==1) {
        cout << " Enqueue" << endl;
        enqueue();
        goto queue;
    } else if (pil==2) {
        cout << "Dequeue" << endl;
        goto queue;
    }
}