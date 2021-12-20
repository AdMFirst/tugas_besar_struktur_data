#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;

/*
    penggunaan struktur data yang kita pakai untuk tubes ini ialah
    NkeN tipe 2;

    sedangkan untuk listnya,
    kami menggunakan single linked list dengan pointer last untuk list mahasiswa dan list mata kuliah
    namun untuk list mata kuliah yang diambil, kami tidak menggunakan pointer last

    tl:
    the type of the data structure that we use for these program is
    N to N type 2;

    meanwhile for the list,
    we use single linked list with last pointer for student list and course list
    but for the list of courses taken, we do not use the last pointer

*/

typedef struct Mahasiswa infotypeParent;
typedef struct MataKuliah infotypeChildren;
typedef struct node_parent *adrP;
typedef struct node_children *adrC;
typedef struct node_relation *adrR;

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


struct listParent {
    //tipe data bentukan untuk linked list parrent
    adrP First = NULL;
    adrP Last = NULL;
};

struct listChildren {
    //tipe data bentukan untuk linked list children
    adrC First = NULL;
    adrC Last = NULL;
};

struct listRelation {
    //tipe data bentukan untuk daftar mata kuliah
    adrR First = NULL;
};

struct node_relation{
    //tipe data bentukan untuk list relasi
    adrR next;
    adrC next_course;
};

struct node_parent {
    //tipe data bentukan untuk node parrent
    infotypeParent info;
    listRelation course;
    adrP next;
};

struct node_children {
    //tipe data bentukan untuk node children
    infotypeChildren info;
    adrC next;
};


//masukan fungsi-fungsi yang dipakai ke bawah tulisan ini
//insert functions used below this text

#endif // HEADER_H_INCLUDED
