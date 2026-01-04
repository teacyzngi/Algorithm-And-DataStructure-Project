#include <iostream>
#include <string>
using namespace std;

class UndoStack {
private:
    string* stack;   // array penyimpanan perubahan
    int top;         // penanda posisi elemen teratas
    int max_size;    // ukuran maksimum stack

public:
    // Konstruktor
    UndoStack(int size) {
        max_size = size;
        stack = new string[max_size];
        top = -1;
    }

    // Destructor (membersihkan memori)
    ~UndoStack() {
        delete[] stack;
    }

    // Mengecek apakah stack kosong
    bool isEmpty() {
        return top == -1;
    }

    // Mengecek apakah stack penuh
    bool isFull() {
        return top == max_size - 1;
    }

    // Menambahkan perubahan ke dalam stack
    void push(string change) {
        if (isFull()) {
            cout << "Stack penuh! Tidak dapat menambah perubahan baru." << endl;
        } else {
            top++;
            stack[top] = change;
            cout << "Perubahan '" << change << "' disimpan ke dalam stack." << endl;
        }
    }

    // Membatalkan perubahan terakhir (Undo)
    void pop() {
        if (isEmpty()) {
            cout << "Tidak ada perubahan untuk dibatalkan (stack kosong)." << endl;
        } else {
            string change = stack[top];
            top--;
            cout << "Perubahan '" << change << "' berhasil dibatalkan." << endl;
        }
    }

    // Melihat perubahan terakhir tanpa menghapusnya
    void peek() {
        if (isEmpty()) {
            cout << "Tidak ada perubahan yang tersimpan." << endl;
        } else {
            cout << "Perubahan terakhir: '" << stack[top] << "'" << endl;
        }
    }

    // Menghitung jumlah perubahan yang tersisa
    int size() {
        return top + 1;
    }
};

int main() {
    // Membuat stack undo dengan kapasitas 5
    UndoStack undoStack(5);

    // Simulasi perubahan data
    undoStack.push("Menambahkan data A");
    undoStack.push("Mengubah data B");
    undoStack.push("Menghapus data C");

    cout << endl;
    undoStack.peek();    // Melihat perubahan terakhir
    undoStack.pop();     // Undo perubahan terakhir
    undoStack.pop();     // Undo berikutnya

    cout << "\nJumlah perubahan tersisa: " << undoStack.size() << endl;

    return 0;
}
