#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;

/*
penggunaan struktur data yang kita pakai untuk tubes ini ialah
    1keN tipe 1; dan
    NkeN tipe 2;

    sedangkan untung listnya, kami menggunakan single linked list dengan pointer last
*/

typedef struct Mahasiswa infotypeParrent;
typedef struct MataKuliah infotypeChildren;
typedef struct node_parrent *adrP;
typedef struct node_children *adrC;

struct Mahasiswa {
    //tipe bentukan mahasiswa
    //isidatanya ada nama dan nim
    string nama, nim;
};

struct MataKuliah {
    //tipe bentukan mata kuliah
    //isi datanya ada nama mata kuliah, nama dosen, info ruangan, dan waktu masuk kelas
    string nama, dosen, ruangan, waktu_mulai;
};

struct node_parrent {
    //tipe data bentukan untuk node parrent
    infotypeParrent info;
    adrC nextAnak;
    adrP next;
};

struct node_children {
    //tipe data bentukan untuk node children
    infotypeChildren info;
    adrC next;
};

struct listParrent {
    //tipe data bentukan untuk linked list parrent
    adrP First;
    adrP Last;
};

struct listChildren {
    //tipe data bentukan untuk linked list children
    adrC First;
    adrC Last;
};

//masukan fungsi-fungsi yang dipakai ke bawah tulisan ini
//optional: tambahkan juga komentarnya

#endif // HEADER_H_INCLUDED
