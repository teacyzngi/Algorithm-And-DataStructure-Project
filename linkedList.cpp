#include <iostream>
#include <String>

using namespace std;

struct Book {
    string title;
    double price;
    int stock;
};

struct Node {
    Book book;
    Node* next;
};

// Menambah stok bukiu baru ke paling depan
void addBook(Node*& head, string title, double price, int stock);

// Menjual buku dan mengurangi stok
void sellBook(Node* head, string title, int quantity);

// Mencari buku memakai judul
void findBook(Node* head, string title);

//  Menampilkan daftar buku
void printBook(Node* head);

// Fungsi utama
int main () {
    Node* head = NULL;
    int pilihan;
    
    // Stok buku default
    addBook(head, "Algoritma", 50000, 12);
    addBook(head, "C++", 70000, 10);
    addBook(head, "Python", 40000, 20);
    
    do {
        cout << "\n===Menu Toko Buku===\n";
        cout << "1. Tambah buku\n";
        cout << "2. Jual Buku\n";
        cout << "3. Cari Buku\n";
        cout << "4. Daftar Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        if (pilihan == 1 ) {
            string title;
            double price;
            int stock;
            cout << "\nJudul Buku: ";
            cin >> title;
            cout << "Harga Buku: ";
            cin >> price;
            cout << "Jumlah Stok: ";
            cin >> stock;
            addBook(head, title, price, stock);
        }
        else if (pilihan == 2) {
            string title;
            int quantity;
            cout << "\nBuku yang ingin Dijual: ";
            cin >> title;
            cout << "Jumlah Buku: ";
            cin >> quantity;
            sellBook(head, title, quantity);
        }
        else if (pilihan == 3) {
            string title;
            cout <<"\nJudul Buku yang ingin dicari: ";
            cin >> title;
            findBook(head, title);
        }
        else if (pilihan == 4) {
            printBook(head);
        }
        else if (pilihan == 5) {
            cout << "Terima Kasih\n";
        }
        else {
            cout << "Pilihan tidak valid, silahkan pilih menu 1-5\n";
        }

    } while (pilihan !=5);

    return 0;
}

void addBook(Node*& head, string title, double price, int stock) {
    Node* newNode = new Node{{title, price, stock}, NULL};
    newNode->next = head; 
    head = newNode; // node baru menjadi head
    cout << "Buku " << title << " Berhasil ditambah\n";
}

void sellBook(Node* head, string title, int quantity) {
    Node* walkNode = head;
    while (walkNode) {
        if (walkNode->book.title == title) {
            if (walkNode->book.stock >= quantity) {
                walkNode->book.stock -= quantity;
                cout << "Buku "<< title << " terjual sebanyak "<< quantity << " buku\n";
            } else {
                cout << "Stok tidak mencukupi\n";
            }
            return;
        }
        walkNode = walkNode->next;
    }
    cout << "Buku " << title << " tidak ditemukan\n";
}

void findBook(Node* head, string title) {
    Node* walkNode = head;
    while (walkNode) {
        if (walkNode->book.title == title) {
            cout << "Buku ditemukan:\n";
            cout << "Judul: " << walkNode->book.title << "\n";
            cout << "Harga: Rp" << walkNode->book.price << "\n";
            cout << "Stok: " << walkNode->book.stock << "\n";
            return;
        }
        walkNode = walkNode->next;
    }
    cout << "Buku " << title << " tidak ditemukan\n";
}

void printBook(Node* head) {
    if (!head) {
        cout << "Daftar buku kosong\n";
        return;
    }
    Node* walkNode = head;
    cout << "\n ===Daftar Buku===\n";
    while (walkNode) {
        cout << "- " << walkNode->book.title 
             << "| Harga: Rp " << walkNode->book.price
             << "| Stok: " << walkNode->book.stock << "\n";
        walkNode = walkNode->next;
    }
    cout << "===============================\n";
}