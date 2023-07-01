#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <thread>
#include <chrono>
#define max 100

using namespace std;

struct customer{
    string nama;
    string noHp;
    string alamat;
    string tipeAkun;
};

customer antri[max];
int head = -1, tail = -1;

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty(){
    if(tail == -1)
        return true;
    else
        return false;
}

// Fungsi untuk memeriksa apakah antrian penuh
bool isFull(){
    if(tail == max - 1)
        return true;
    else
        return false;
}

// Fungsi untuk mengosongkan antrian
void clear(){
    head = tail = -1;
}

// Fungsi untuk menambahkan pelanggan baru ke dalam antrian
void tambah(){
    if(isFull() == true)
        cout << "Antrian penuh!!";
    else{
        customer baru;
        cout << "Masukan Nama: ";
        cin.ignore();
        getline(cin, baru.nama);
        cout << "Masukan No HP: ";
        getline(cin, baru.noHp);
        cout << "Masukan Alamat: ";
        getline(cin, baru.alamat);
        cout << "Tipe Akun: ";
        getline(cin, baru.tipeAkun);

        tail++;
        antri[tail] = baru;
        cout << "Antrian ditambahkan";
    }
}

// Fungsi untuk memproses pelanggan berikutnya dalam antrian
void proses(){
    if(isEmpty() == true)
        cout << "Antrian kosong";
    else{
        cout << "Pelanggan yang sedang diproses:\n";
        cout << "Nama: " << antri[0].nama << endl;
        cout << "Nomor HP: " << antri[0].noHp << endl;
        cout << "Alamat: " << antri[0].alamat << endl;
        cout << "Tipe Akun: " << antri[0].tipeAkun << endl;

        for(int i = 0; i < tail; i++){
            antri[i] = antri[i+1];
        }
        tail--;
    }
}

// Fungsi untuk menampilkan data semua pelanggan dalam antrian
void tampil(){
    if(isEmpty() == true)
        cout << "Antrian Kosong";
    else{
        cout << "Data Pelanggan: " << endl;
        for(int i = 0; i <= tail; i++){
            cout << "Pelanggan " << i + 1 << ":" << endl;
            cout << "Nama: " << antri[i].nama << endl;
            cout << "Nomor HP: " << antri[i].noHp << endl;
            cout << "Alamat: " << antri[i].alamat << endl;
            cout << "Tipe Akun: " << antri[i].tipeAkun << endl;
            cout << "===================================" << endl;
        }
    }
}

// Fungsi untuk menampilkan jumlah pelanggan dalam antrian
void jumlah(){
    if(isEmpty() == true)
        cout << "Antrian Kosong";
    else
        cout << "Jumlah Pelanggan Tersisa: " << tail + 1;
}

// Fungsi untuk mencari pelanggan berdasarkan nama
void cari(){
    if(isEmpty() == true)
        cout << "Antrian Kosong";
    else{
        string nama;
        cout << "Masukan Nama yang Ingin Anda Cari: ";
        cin.ignore();
        getline(cin, nama);

        bool ada = false;
        for(int i = 0; i <= tail; i++){
            if(strcasecmp(antri[i].nama.c_str(), nama.c_str()) == 0){
                ada = true;
                cout << "Data Pelanggan Ditemukan:" << endl;
                cout << "Nama: " << antri[i].nama << endl;
                cout << "Nomor HP: " << antri[i].noHp << endl;
                cout << "Alamat: " << antri[i].alamat << endl;
                cout << "Tipe Akun: " << antri[i].tipeAkun << endl;
                break;
            }
        }
        if(!ada)
            cout << "Data Tidak Ditemukan";
    }
    system("pause");
}

// Fungsi untuk menghapus data pelanggan berdasarkan nama
void hapusData(){
    if(isEmpty() == true)
        cout << "Antrian Kosong";
    else{
        string nama;
        cout << "Masukan Nama Yang Akan Dihapus: ";
        cin.ignore();
        getline(cin, nama);
        bool ada = false;
        for(int i = 0; i < tail; i++){
            if(antri[i].nama == nama){
                ada = true;
                char p;
                hapus:
                system("cls");
                cout << "Nama: " << antri[i].nama << endl;
                cout << "Nomor HP: " << antri[i].noHp << endl;
                cout << "Alamat: " << antri[i].alamat << endl;
                cout << "Tipe Akun: " << antri[i].tipeAkun << endl;
                cout << "Apakah Anda yakin untuk Menghapus Data diatas?? [y/n]: ";
                cin >> p;
                if(p == 'y' || p == 'Y'){
                    for(int j = i; j < tail; j++){
                        antri[j] = antri[j + 1];
                    }
                    tail--;
                    break;
                }else if(p == 'n' || p == 'N'){
                    break;
                }else{
                    cout << "Bukan Pilihan";
                    goto hapus;
                }
            }
        }
    }
}
void showLoading()
{
    cout << "Loading";
    for(int i = 0; i < 3; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << ".";
    }
    cout << endl;
}

int main(){
    char pilihan;
    do{
        system("cls");
        cout << "==========Pendaftaran Bank ==========\n";
        cout << "=                                   =\n";
        cout << "=====================================\n";
        cout << "=              Pilihan:             =\n";
        cout << "=====================================\n";
        cout << "    1. Tambah Pelanggan         \n";
        cout << "    2. Proses Pelanggan Berikutnya\n";
        cout << "    3. Tampilkan Data Pelanggan\n";
        cout << "    4. Tampilkan Jumlah Pelanggan\n";
        cout << "    5. Cari Pelanggan\n";
        cout << "    6. Hapus Data Pelanggan\n";
        cout << "    7. Hapus Semua Antrian Pelanggan\n";
        cout << "    8. Keluar\n";
        cout << "=====================================\n";
        cout << "       Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch(pilihan){
            case '1':
                showLoading();
                tambah();
                break;
            case '2':
                showLoading();
                proses();
                break;
            case '3':
                showLoading();
                tampil();
                break;
            case '4':
                showLoading();
                jumlah();
                break;
            case '5':
                showLoading();
                cari();
                break;
            case '6':
                showLoading();
                hapusData();
                break;
            case '7':
                showLoading();
                clear();
                break;
            case '8':
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

        cout << "===============================\n";
        cin.ignore();
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
        system("cls");
    } while(pilihan != '8');
    return 0;
}
