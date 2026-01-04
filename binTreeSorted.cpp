#include<iostream>
#include<string>

using namespace std;

//Struct untuk isi node
struct DataNode{
    string kecamatan;
    int Covid;
};

//Struct untuk node pada tree
struct Node{
    DataNode data;
    Node* left;
    Node* right;

    Node(DataNode d) : data(d), left(nullptr), right(nullptr) {};
};

//Fungsi untuk membangun tree 
Node* insert(Node* root, DataNode d) {
    if (root == nullptr) {
        return new Node(d);
    }
    if (d.Covid <= root ->data.Covid) {
        root->left = insert(root->left, d);
    }
    else {
        root->right = insert(root->right, d);
    }
    return root;
};

//Fungsi traversal
void inorderTransversal(Node* root, DataNode arr[], int* index) {
    if(root != nullptr) {
        inorderTransversal(root->left, arr, index);
        arr[(*index)++] = root->data;
        inorderTransversal(root->right, arr, index);
    }
};

//Fungsi sorting binary tree
void binaryTreeSort(DataNode arr[], int n) {
    Node* root = nullptr;
    for (int i= 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    int index = 0;
    inorderTransversal(root, arr, &index);

};

//Fungsi menampilkan hasil sorting
void printSorted(const DataNode data[], int n) {
    for(int i =0; i < n; i++) {
        cout << data[i].kecamatan << ": " << data[i].Covid << endl;
    };
    cout << endl;
};

int main() {
    // Data orang yang terkena covid di Yogyakarta pada minggu 1-31
    DataNode inittial_data[] = {
        {"KotaGede", 3337},
        {"Mergangsan", 2361},
        {"UmbulHarjo", 5902},
        {"Pakualaman", 917},
        {"Gondomanan", 1235},
        {"Kraton", 1899},
        {"Mantrijeron", 2998},
        {"Wirobrajan", 2035},
        {"Ngampilan", 1151},
        {"Gedong Tengen", 1434},
        {"Danurejan", 1793},
        {"Gondokusuman", 4446},
        {"Jetis", 2056},
        {"Tegalrejo", 1918}    
    };

    // Mencari ukuran dari array pada data
    int n = sizeof(inittial_data) / sizeof(inittial_data[0]);

    cout <<"========================================================" << endl;
    cout <<"Data Kasus Covid-19 di Kota Yogyakarta Pada MInggu 1--31" << endl;
    cout <<"========================================================" << endl;
    cout << endl << "Data sebelum diurutkan: "<< endl;
    printSorted(inittial_data, n);
    binaryTreeSort(inittial_data, n);
    cout << endl << "Data setelah diurutkan: " << endl;
    printSorted(inittial_data, n);
}