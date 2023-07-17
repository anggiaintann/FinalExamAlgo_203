#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string namaProduk;
    int jumlahProduk;
    string tipeProduk;
    Node* next;
};

class ManajemenProduk {
private:
    Node* head;
public:
    ManajemenProduk() {
        head = NULL;
    }

    void tambahProduk() {
        string nama;
        int jumlah;
        string tipe;

        cout << "========== TAMBAH PRODUK ==========" << endl;
        cout << "Nama Produk : ";
        getline(cin, nama);
        cout << "Jumlah Produk : ";
        cin >> jumlah;
        cin.ignore(); // Membersihkan buffer input
        cout << "Tipe Produk : ";
        getline(cin, tipe);

        Node* newNode = new Node();
        newNode->namaProduk = nama;
        newNode->jumlahProduk = jumlah;
        newNode->tipeProduk = tipe;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Produk berhasil ditambahkan!" << endl;
    }

    void tampilkanSemuaProduk() {
        cout << "========== SEMUA DATA PRODUK ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            Node* current = head;
            int counter = 1;
            while (current != NULL) {
                cout << "Produk " << counter << ":" << endl;
                cout << "Nama Produk : " << current->namaProduk << endl;
                cout << "Jumlah Produk : " << current->jumlahProduk << endl;
                cout << "Tipe Produk : " << current->tipeProduk << endl;
                cout << endl;
                current = current->next;
                counter++;
            }
        }
    }

    void cariProdukByNama() {
        cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            string targetNama;
            cout << "Nama Produk yang dicari: ";
            getline(cin, targetNama);

            Node* current = head;
            int posisi = 0;
            while (current != NULL) {
                posisi++;
                if (current->namaProduk == targetNama) {
                    cout << "Data produk ditemukan pada posisi ke-" << posisi << ":" << endl;
                    cout << "Nama Produk : " << current->namaProduk << endl;
                    cout << "Jumlah Produk : " << current->jumlahProduk << endl;
                    cout << "Tipe Produk : " << current->tipeProduk << endl;
                    return;
                }
                current = current->next;
            }

            cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
        }
    }

    void algorithmaSortByJumlahProduk() {
        if (head == NULL || head->next == NULL) {
            return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
        }

        Node* current;
        Node* last = NULL;
        bool isSwapped;

        do {
            isSwapped = false;
            current = head;

            while (current->next != last) {
                if (current->jumlahProduk > current->next->jumlahProduk) {
                    // Tukar posisi node jika jumlah produk lebih besar
                    swap(current, current->next);
                    isSwapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (isSwapped);
    }

    // Fungsi utilitas untuk menukar posisi dua node
    void swap(Node* a, Node* b) {
        string tempNama = a->namaProduk;
        int tempJumlah = a->jumlahProduk;
        string tempTipe = a->tipeProduk;

        a->namaProduk = b->namaProduk;
        a->jumlahProduk = b->jumlahProduk;
        a->tipeProduk = b->tipeProduk;

        b->namaProduk = tempNama;
        b->jumlahProduk = tempJumlah;
        b->tipeProduk = tempTipe;
    }
};

int main() {
    ManajemenProduk manajemenProduk;
    int pilihan;

    do {
        cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Cari Produk berdasarkan Nama" << endl;
        cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            manajemenProduk.tambahProduk();
            break;
        case 2:
            manajemenProduk.tampilkanSemuaProduk();
            break;
        case 3:
            manajemenProduk.cariProdukByNama();
            break;
        case 4:
            manajemenProduk.algorithmaSortByJumlahProduk();
            cout << "Produk berhasil diurutkan berdasarkan jumlah." << endl;
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}


//2. Algoritma Linked List: Digunakan untuk menyimpan data produk dalam bentuk linked list dengan menggunakan class Node.
//   Algoritma Bubble Sort: Digunakan dalam metode algorithmaSortByJumlahProduk() untuk mengurutkan produk berdasarkan jumlah produk. Algoritma ini membandingkan pasangan elemen bersebelahan dan menukar posisinya jika urutan mereka salah.Proses ini berlanjut hingga seluruh daftar diurutkan dengan benar.

//3. Mengimplementasikan antrian dalam bentuk circular array. Jika REAR berada di posisi indeks terakhir dan jika ada ruang di awal array, maka kita dapat mengatur nilai REAR ke nol dan mulai memasukkan elemen dari awal.

//4. Algoritma Stack digunakan saat kita perlu mengatur data dalam urutan tumpukan (last-in, first-out). Struktur data Stack mirip dengan tumpukan objek dalam kehidupan sehari-hari, di mana objek terakhir yang ditambahkan akan menjadi yang pertama diambil.

//5. a. 5
//   b. Inorder traversal (membaca pohon dari kiri ke kanan), yaitu:
//     15 -> 20 -> 25 -> 30 -> 31 -> 32 -> 35 -> 48 -> 50 -> 65 -> 66 -> 67 -> 69 -> 70 -> 90 -> 94 -> 98 -> 99
