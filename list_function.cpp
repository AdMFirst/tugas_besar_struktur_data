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









//---------------------------Function untuk children list---------------------------------------
