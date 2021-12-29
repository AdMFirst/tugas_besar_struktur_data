#include "header.h"
/*
    test 0001
*/


int main(){
    listParent PL;
    listChildren CL;
    adrC c = CL.First;

    infotypeParent ip;
    infotypeChildren ic;

    adrP p;

    ip.nama = "my name";
    ip.nim = "111";
    insertNewParent(PL,ip);



    ip.nama = "nama kamu ke 2";
    ip.nim = "123";
    insertNewParent(PL,ip);

    showParent(PL);

    cout << "----delete yang ke-2---"<<endl;
    p = PL.Last;
    deleteParent(PL,p);
    showParent(PL);

    //---------uncomment kode dibawah ini biar rr nya muncul ---------+++++++++++----------
    //p = PL.First;

    // child -------------------------o
    cout << "________Child__________"<<endl;
    ic.dosen = "nama dosen";
    ic.nama = "nama matkul";
    ic.ruangan = "ruangan";
    ic.waktu_mulai = "waktu";
    insertNewChildren(CL,ic);
     cout << "show child awal--------------------------\n";
    showChildren(CL);

    cout << "\n===============Buat relasi============" <<endl;
     createRelation(PL,CL,"111", "nama matkul");
    cout << "===============udah Buat relasi============\n\n" <<endl;


    ic.dosen = "nama dosen2";
    ic.nama = "nama matkul2";
    ic.ruangan = "ruangan2";
    ic.waktu_mulai = "waktu2";
    insertNewChildren(CL,ic);//////////////
    cout << "show child setelah ditambah lagi--------------------------\n";
    showChildren(CL);


    cout << "\n\n_______Children from parent____\n";

//    showChildrenFromParent(PL,"nim kamu", CL);
    adrR rr;
    rr = p->course.First;
    cout<<rr<<endl;
    cout<<rr->next_course<<endl;
    cout << rr->next_course->info.dosen;

    return 0;
    }
