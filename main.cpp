#include "header.h"

int main(){
    adrC CP;
    adrP PP;
    listParent PL;
    listChildren CL;
    infotypeParent PI;
    infotypeChildren CI;
    string nim;
    string namaMaKul;

    int pilihan;
    start:
    system("cls");
    cout << " "<<endl; // <-- judul?
    cout<<"1. Tambah Mahasiswa"<<endl;
	cout<<"2. Hapus Mahasiswa"<<endl;
	cout<<"3. Tampilkan Data Mahasiswa"<<endl;
	cout<<"4. Cari Data Mahasiswa"<<endl;
	cout<<"5. Tambah Mata Kuliah yang Akan Disediakan"<<endl;
	cout<<"6. Tampilkan Mata Kuliah yang Tersedia"<<endl;
	cout<<"7. Hapus Mata Kuliah yang Telah Tersedia"<<endl;
	cout<<"8. Ambil Mata Kuliah"<<endl;
	cout<<"9. Tampilkan Mata Kuliah sedang Diambil"<<endl;
	// ditambah apa?
	cout<<"00. Keluar"<<endl;
	cout<<endl;
	cout<<"Masukan Pilihan : ";
	cin>>pilihan;
	cout<<endl;

    switch(pilihan){
        case 1:{
            cout<<"-- Tambah Mahasiswa --"<<endl;
            cout<<"Masukan nama dan NIM mahasiswa yang ingin didaftarkan"<<endl;
            cout<<"Nama Mahasiswa\t: ";
            cin>>PI.nama;
            cout<<"NIM Mahasiswa\t: ";
            cin>>PI.nim;
            insertNewParent(PL, PI);
        }
        break;
        case 2:{
            cout<<"-- Hapus Mahasiswa --"<<endl;
            showParent(PL);
            cout<<"Masukan NIM dari mahasiswa yang akan dihapus : ";
            cin>>nim;
            PP = findParent(PL, nim);
            if (PP == NULL){
                cout<<"- NIM tidak ditemukan"<<endl;
                system("pause");
                goto start;
            }
            deleteParent(PL, PP);
        }
        break;
        case 3:{
            cout << "-- Tampilkan Data Mahasiswa --"<<endl;
            showParent(PL);
            system("pause");
        }
        break;
        case 4:{
            cout<<"-- Cari Data Mahasiswa --"<<endl;
            showParent(PL);
            cout<<"Masukan NIM dari mahasiswa yang ingin dicari : ";
            cin>>nim;
            if (findParent(PL,nim) == NULL){
                cout<<"- NIM tidak ditemukan, mahasiswa belum terdaftar"<<endl;
            }else{
                cout<<"- NIM ditemukan, mahasiswa sudah terdaftar"<<endl;
            }
            system("pause");
        }
        break;
        case 5:{
            cout<<"-- Tambah Mata Kuliah yang Akan Diambil --"<<endl;
            cout<<"Masukan detail mata kuliah yang ingin diambil"<<endl;
            cout<<"Nama Mata Kuliah\t: ";
            cin>>CI.nama;
            cout<<"Nama Dosen\t\t: ";
            cin>>CI.dosen;
            cout<<"Waktu Mulai(Jam)\t: ";
            cin>>CI.waktu_mulai;
            cout<<"Ruang Pembelajaran\t: ";
            cin>>CI.ruangan;
            insertNewChildren(CL, CI);
        }
        break;
        case 6:{
            cout<<"-- Tampilkan Mata Kuliah yang Tersedia --"<<endl;
            showChildren(CL);
            system("pause");
        }
        break;
        case 7:{
            cout<<"-- Hapus Mata Kuliah yang Telah Diambil --"<<endl;
            showChildren(CL);
            cout<<"Masukan nama mata kuliah yang ingin dihapus : ";
            cin>>namaMaKul;
            CP = findChildren(CL, namaMaKul);
            if (CP == NULL){
                cout<<"- Mata kuliah tidak ditemukan"<<endl;
                system("pause");
                goto start;
            }
            deleteChildren(CL, CP);
        }
        break;
        case 8:{
            cout<<"-- Ambil Mata Kuliah --"<<endl;
            showParent(PL);
            cout<<"Masukan NIM dari mahasiswa yang ingin mengambil mata kuliah: ";
            cin>>nim;
            if (findParent(PL,nim)==NULL){
                cout<<"- NIM tidak ditemukan"<<endl;
                system("pause");
                goto start;
            }
            showChildren(CL);
            cout<<"Masukan nama mata kuliah yang akan diambil: ";
            cin>>namaMaKul;
            if (findChildren(CL,namaMaKul)==NULL){
                cout<<"- Mata kuliah tidak ditemukan"<<endl;
                system("pause");
                goto start;
            }
            createRelation(PL, CL, nim, namaMaKul);
        }
        break;
        case 9:{
            cout<<"-- Tampilkan Mata Kuliah sedang Diambil --"<<endl;
            showParent(PL);
            cout<<"Masukan NIM mahasiswa yang ingin dicek mata kuliahnya: ";
            cin>>nim;
            if (findParent(PL,nim)==NULL){
                cout<<"- NIM tidak ditemukan"<<endl;
                system("pause");
                goto start;
            }
            showChildrenFrom(PL, nim);
            system("pause");
        }
        break;
        case 00:{
            cout << "(Nama_Judul) DIHENTIKAN, PROGRAM/SISTEM BERHENTI..."<<endl;
            return 0;                        //bagusan apa? program/sistem? atau apa?
        }
        break;
        default:
            cout<<"PILIHAN TIDAK TERSEDIA, HARAP ULANGI!"<<endl<<endl;
            system("pause");
    }
    goto start;
}
