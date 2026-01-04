#include <iostream>
using namespace std;

struct Node {
    int customerID ;
    Node* next;
};

class Queue {
    private :
    Node* front ;
    Node* rear ;
    int count;
    
    public :
    Queue(){
        front = nullptr;
        rear = nullptr;
        count = 0 ;
    }

void enqueue (int customerID) {
    Node* newNode = new Node() ;
    newNode->customerID = customerID;
    newNode->next = nullptr;
    
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode ;
    } 
    count++;
    cout << "Pelanggan " << customerID << " bergabung ke antrian." << endl; 
    }

int dequeue () {
    if (isEmpty()) {
        cout << "   Antrian kosong. Tidak ada pelanggan untuk dipanggil." << endl;
        return -1;
    }
    int removedID = front->customerID;
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    count--;
    cout << "Pelanggan " << removedID << " dipanggil untuk duduk." << endl;
    return removedID;
}

int peek (){
    if (isEmpty()) {
        cout << " Antrian kosong." << endl;
        return -1;
    } return front->customerID;
}

int size (){
    return count ;
}

bool isEmpty () {
    return (front == nullptr);
}

void display() {
    if (isEmpty()) {
        cout << "Antrian kosong." << endl;
        return;
    }
    Node* temp = front ;
    cout << "Antrian saat ini: " << endl;
    while (temp!= nullptr) {
        cout << temp->customerID <<" " ;
        temp = temp->next;
    }
    cout << endl;
    }
};

int main () {
    Queue q;
    int pilihan,id;
do{
    cout << " \n Sistem Antrian Pelanggan " << endl;
    cout<< "1. Tambah Pelanggan (Enqueue)" << endl;
    cout<< "2. Panggil Pelanggan (Dequeue)" << endl;
    cout<< "3. Lihat Antrian (Display)" << endl;
    cout<< "4. Lihat Pelanggan Terdepan (Peek)" << endl;
    cout<< "5. Jumlah Antrian (Size)" << endl;  
    cout<< "6. Lihat apakah antrian kosong " << endl;
    cout<< "7. Keluar " << endl;
    cout<< " Pilihan Anda : ";
    cin >> pilihan;

    switch (pilihan) {
        case 1 :
            cout << " Masukkan ID Pelanggan: ";
            cin >> id;
            q.enqueue(id);
            break;
        case 2 :
            q.dequeue();
            break;
        case 3 :
            q.display();
            break;
        case 4 :
            id = q.peek();
            if (id != -1) {
                cout << "Pelanggan terdepan memiliki ID: " << id << endl;
            }
            break;
        case 5 :
            cout << "Jumlah pelanggan dalam antrian: " << q.size() << endl;
            break;
        case 6 :
            if (q.isEmpty())
            cout << "Antrian kosong." << endl;
            else
            cout << "Antrian tidak kosong." << endl;
            break;
        case 7 :
            cout << "Keluar dari program." << endl;
            break;
        default :
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
         }
    }     while (pilihan != 7);
    return 0;
}