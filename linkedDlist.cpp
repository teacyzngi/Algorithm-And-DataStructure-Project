#include<iostream>
#include<String>

using namespace std;

struct Node {
    string url;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;
Node* current = NULL;

// Mengunjungi halaman baru dan menabahkannya ke riwayat 
void visit(string url);

// Kembali ke halaman sebelumnya
void back();

// Maju ke halaman berikutnya
void forward();

// Mencetrak riwayat yang dilalui
void getHistory();

// Fungsi Utama
int main() {
    int pilihan;
    string url;

    do {
        cout << "\n===Menu Browser===\n";
        cout << "1. Kunjungi halaman baru\n";
        cout << "2. Maju ke halaman selanjutnya\n";
        cout << "3. Mundur ke halaman sebelumnya\n";
        cout << "4.Tampilkan riwayat browser\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout <<"Masukkan URL yang ingin di tuju: ";
            cin >> url;
            visit(url);
        }
        else if (pilihan == 2) {
            forward();
        }
        else if (pilihan == 3) {
            back();
        }
        else if (pilihan == 4) {
            getHistory();
        }
        else if (pilihan == 5) {
            cout << "Keluar dari program\n";
        }
        else {
            cout <<"Pilihan tidak valid! Silahkan pilih 1-5\n";
        }
        } while (pilihan != 5);
        
    return 0;
    
    } 

void visit(string url) {
    Node* newNode = new Node{url, NULL, NULL};

    if (!head) {
        head = tail = current = newNode;
    }
    else {
        // Menghapus semua node setelah current
        Node* walkNode = current->next;
        while (walkNode) {
            Node* deleteNode = walkNode;
            walkNode = walkNode->next;
            delete deleteNode;
        }

        // Tambah node
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        tail = newNode; 
    }
    cout << "Mengunjungi: " << url << endl;
}

void back() {
    if (current && current->prev) {
        current = current->prev;
        cout << "Kembali ke halaman: " << current->url <<endl;
    }
    else {
        cout << "Tidak ada halaman sebelumnya\n";
    }
}

void forward() {
     if (current && current->next) {
        current = current->next;
        cout << "Maju ke halaman: " << current->url <<endl;
    }
    else {
        cout << "Tidak ada halaman selanjutnya\n";
    }
}

void getHistory() {
    cout << "\n===Riwayat Browser===\n";
    Node* walkNode = head;
    while (walkNode) {
        if(walkNode == current) {
            cout << "-> " << walkNode->url <<"(url saat ini)\n";
        }
        else {
            cout <<"   "<< walkNode->url <<endl;
        }
        walkNode = walkNode->next;
    }
    cout <<"============================================\n";
}