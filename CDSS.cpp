#include <iostream>
#include <string>
#include <cctype> // Untuk tolower

using namespace std;

// Struktur Node sama seperti sebelumnya
struct Node {
    string question;
    string diagnosis;
    Node* yes_branch;
    Node* no_branch;

    // Konstruktor untuk node diagnosis (leaf)
    Node(string diag) : diagnosis(diag), question(""), yes_branch(nullptr), no_branch(nullptr) {}

    // Konstruktor untuk node pertanyaan (internal)
    Node(string q, Node* yes, Node* no) : question(q), diagnosis(""), yes_branch(yes), no_branch(no) {}

    ~Node() {
        delete yes_branch;
        delete no_branch;
    }
};

// Fungsi untuk membangun pohon keputusan (sama seperti sebelumnya)
Node* buildDecisionTree() {
    // Level 4/5 - Leaf Nodes (Diagnosis)
    Node* d1 = new Node("Risiko Rendah, Lakukan SADARI Rutin.");
    Node* d2 = new Node("Risiko Sedang, Evaluasi Lebih Lanjut Disarankan.");
    Node* d3 = new Node("Perlu Evaluasi Medis Segera.");
    Node* d4 = new Node("Curiga Kanker Payudara, Konsultasi & Pemeriksaan Lanjut.");
    Node* d5 = new Node("Sangat Curiga Kanker Payudara, SEGERA Konsultasi!");

    // Level 3 - Pertanyaan lanjutan
    Node* n5 = new Node("Apakah terdapat puting tertarik ke dalam (inverted nipple) atau kemerahan/pengelupasan pada puting/areola?", d3, d2); 
    Node* n4 = new Node("Apakah terdapat cairan abnormal (non-ASI) dari puting?", d5, d4); 
    Node* n3 = new Node("Apakah terdapat perubahan pada kulit (lesung pipi, kemerahan, kulit jeruk)?", n5, d1); 

    // Level 2 - Pertanyaan utama
    Node* n2 = new Node("Apakah benjolan terasa keras, tidak nyeri, dan tidak dapat digerakkan?", n4, n5); 
    
    // Level 1 - Root Node
    Node* root = new Node("Apakah terdapat benjolan/massa baru di payudara atau ketiak?", n2, n3); 

    return root;
}

// Fungsi bantu untuk menampilkan jalur keputusan (menggunakan string history)
void displayDecisionPath(const string& path_history) {
    cout << "\n--------------------------------------------------------\n";
    cout << "Decision Path:\n";
    
    // Memecah string path berdasarkan delimiter ';'
    size_t start = 0;
    size_t end = path_history.find(';');
    while (end != string::npos) {
        cout << "- " << path_history.substr(start, end - start) << endl;
        start = end + 1;
        end = path_history.find(';', start);
    }
    // Menampilkan langkah terakhir (diagnosis)
    if (start < path_history.length()) {
        cout << "- " << path_history.substr(start) << endl;
    }
}


// FUNGSI TRAVERSAL INTERAKTIF
void interactiveCDSS(Node* root) {
    cout << "========================================================\n";
    cout << "Sistem Pendukung Keputusan Klinis (CDSS) Kanker Payudara\n";
    cout << "Instruksi: Jawab 'y' untuk Ya atau 'n' untuk Tidak.\n";
    cout << "========================================================\n";

    Node* current = root;
    string decision_path_history = "";
    string final_diagnosis = "";
    char answer;

    // Traversal pohon secara interaktif
    while (current != nullptr && current->diagnosis.empty()) {
        
        cout << "\n--- Pertanyaan ---\n";
        cout << current->question << " (y/n): ";
        
        // Menerima input dari user
        if (!(cin >> answer)) {
            cerr << "Input tidak valid. Program dihentikan.\n";
            return;
        }
        
        // Membersihkan buffer input
        cin.ignore(1000, '\n'); 
        
        char clean_answer = tolower(answer);
        string current_step = "Pertanyaan: " + current->question;

        if (clean_answer == 'y') {
            current_step += " -> Jawaban: Ya";
            current = current->yes_branch;
        } else if (clean_answer == 'n') {
            current_step += " -> Jawaban: Tidak";
            current = current->no_branch;
        } else {
            cout << "Input tidak valid ('" << answer << "'). Silakan ulangi CDSS.\n";
            return;
        }

        decision_path_history += current_step + ";";
    }

    if (current != nullptr && !current->diagnosis.empty()) {
        final_diagnosis = current->diagnosis;
        decision_path_history += "Diagnosis Akhir: " + final_diagnosis;

        // Menampilkan jalur keputusan
        displayDecisionPath(decision_path_history);
        cout << "\n*** Diagnosis Akhir: " << final_diagnosis << " ***\n";
    } else {
        cout << "Tidak dapat mencapai diagnosis. Pohon tidak lengkap.\n";
    }
}

// Fungsi main
int main() {
    // 1. Inisialisasi Pohon Keputusan
    Node* root = buildDecisionTree();

    // 2. Lakukan simulasi interaktif
    // Pengguna akan diminta memasukkan jawaban
    interactiveCDSS(root);

    // Untuk memenuhi permintaan 3 test case, kita bisa meminta pengguna menjalankan 
    // program 3 kali atau meminta pengguna menjalankan simulasi interaktif 3 kali.
    // Dalam konteks nyata, ini adalah satu sesi interaktif.

    // Jika Anda ingin melakukan 3 sesi interaktif, Anda bisa memanggilnya lagi:
    // interactiveCDSS(root); 
    // interactiveCDSS(root);

    // Membersihkan memori
    delete root;

    return 0;
}