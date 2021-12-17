#include "header.h"


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









//---------------------------Function untuk children list---------------------------------------
