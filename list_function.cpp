#include "header.h"
/*
    terdapat sekitar 12 fungsi yang akan digunakan di program ini
    jika fungsi main dan header dihitung, maka ada sekitar 14 fungsi yang digunakan,
    oleh karena itu pembagian pengerjaan fingsi akan dibagi menjadi 7-7
    detail akan didiskusikan di kemudian hari

    Translate:
    There are about 12 functions that will be used in this program
    if the main and header functions are counted, then there are about 14 functions used,
    therefore the division of function work will be divided into 7-7
    details will be discussed at a later date
*/

//----------------------------Function untuk parrent list-------------------------------------
void insertNewParent(listParent &PL, infotypeParent newInfo){
    /*
    IS: terdefinisi sebual list parent PL (bisa kosong) dan sebuah infotype baru
        yang akan dimasukan ke dalam list
    FS: infotype baru akan dubah menjadi elment list parent dan ditambahkan ke
        dalam list sebagai element terakhir
    */
    adrP PP = new node_parent;
    PP->info = newInfo;
    (PP->course).First = NULL;
    PP->next = NULL;

    if(PL.First == NULL || PL.Last == NULL){
        //Jika list kosong
        PL.First = PP;
        PL.Last = PP;
    } else {
        PL.Last->next = PP;
        PL.Last = PP;
    }
}


void deleteParent(listParent &PL, adrP p){
    /*
    IS: terdefinisi sebuah linked list parent yang tidak kosong, dan
        sebuah pointer yang menunjukan node/element list parent yang
        ingin dihapus dari list
    FS: node/element list parent yang ingin dihapus dari list terhapus
    */
    if( p == PL.First){
        if(PL.First == PL.Last){
            //jika hanya ada 1 node/element
            PL.First = NULL;
            PL.Last = NULL;
        } else {
            //jika p berada di paling depan list
            PL.First = p->next;
            p->next = NULL;
        }
    } else if(p == PL.Last){
        //jika p berada di paling belakang list
        adrP q = PL.First;
        while(q->next != PL.Last){
            q = q->next;
        }
        PL.Last = q;
        q->next = NULL;
    } else if(PL.First!=NULL){
        //jika p tidak di paling depan atau belakang, dan list tidak kosong
        adrP q = PL.First;
        while(q->next != p){
            q = q->next;
        }
        q->next = p->next;
        p->next = NULL;
    }

}


void showParent(listParent PL){
    // IS. terdefinisi sebuah listParent (list mungkin kosong)
    // FS. menampilkan seluruh isi dari list parent
    adrP p = PL.First;
    if (p == NULL){
        cout << "List Kosong." << endl;
    }else{
        while (p != NULL){
        cout << "Nama\t: " << p->info.nama << endl;
        cout << "NIM\t: " << p->info.nim << endl << endl;
        p = p->next;
        }
    }
}



//---------------------------Function untuk children list---------------------------------------
