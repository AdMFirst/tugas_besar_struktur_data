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
    int i = 1;
    if (p == NULL){
        cout << "List Kosong." << endl;
    }else{
        while (p != NULL){
            cout << "Mahasiswa ke-"<<i<<endl;
            cout << "Nama\t: " << p->info.nama << endl;
            cout << "NIM\t: " << p->info.nim << endl << endl;
            p = p->next;
            i++;
        }
    }
}


adrP findParent(listParent PL, string NIM){
    // IS. terdefinisi sebuah listParent dan sebuah string NIM
    // FS. mengembalikan address parent apabila string NIM ditemukan di dalam listParent dan Null jika tidak
    //PS : sori di ubah, bikin relasinya lebih gampang kalo return adrP
    adrP p = PL.First;
    while (p != NULL){
        if (p->info.nim == NIM){
            return p;
        }
        p = p->next;
    }
    return p;
}




//---------------------------Function untuk children list---------------------------------------

void insertNewChildren(listChildren &CL, infotypeChildren newInfo){
    /*
    IS: terdefinisi sebual list children CL (bisa kosong) dan sebuah infotype baru
        yang akan dimasukan ke dalam list
    FS: infotype baru akan dubah menjadi element list children dan ditambahkan ke
        dalam list sebagai element terakhir
    */

    //ket: CL=Children list, CP=Children pointer
    adrC CP = new node_children;
    CP->info = newInfo;
    CP->next = NULL;

    if(CL.First == NULL || CL.Last == NULL){
        //Jika list kosong
        CL.First = CP;
        CL.Last = CP;
    } else {
        CL.Last->next = CP;
        CL.Last = CP;
    }
}

void deleteChildren(listChildren &CL, adrC c){
    /*
    IS: terdefinisi sebuah linked list children yang tidak kosong, dan
        sebuah pointer yang menunjukan node/element list children yang
        ingin dihapus dari list
    FS: node/element list children yang ingin dihapus dari list terhapus
    */
    if( c == CL.First){
        if(CL.First == CL.Last){
            //jika hanya ada 1 node/element
            CL.First = NULL;
            CL.Last = NULL;
        } else {
            //jika c berada di paling depan list
            CL.First = c->next;
            c->next = NULL;
        }
    } else if(c == CL.Last){
        //jika c berada di paling belakang list
        adrC ptr = CL.First;
        while(ptr->next != CL.Last){
            ptr = ptr->next;
        }
        CL.Last = ptr;
        ptr->next = NULL;
    } else if(CL.First!=NULL){
        //jika c tidak berada di paling depan atau belakang
        adrC ptr = CL.First;
        while(ptr->next != c){
            ptr = ptr->next;
        }
        ptr->next = c->next;
        c->next = NULL;
    }
}

void showChildren(listChildren &CL){
    /*
    IS :Terdefinisi sebuah list children (list bisa kosong) yang
        akan di printkan ke layar
    FS :Seluruh isi list children di ouputkan ke layar
    */
    adrC C = CL.First;
    int i = 1;
    if (C == NULL){
        cout << "List Kosong." << endl;
    }else{
        while (C != NULL){
            cout << i << ". Mata kuliah :" << C->info.nama<<endl;
            cout << "\tdiajar oleh dosen "<<C->info.dosen<<endl;
            cout << "\tmulai pada jam " << C->info.waktu_mulai<<endl;
            cout << "\tdi ruangan "<<C->info.ruangan<<endl;
            C = C->next;
            i++;
        }
    }

}

adrC findChildren(listChildren CL, string namaMaKul){
    /*
    IS : Terdefinisi sebuah list children CL dan sebuah string nama mata kuliah namaMaKul
    FS : Jika terdapat infotype dengan nama mata kuliah yang sama dengan namaMaKul, maka
         akan direturnkan address dari node infotype tersebut. Jika tidak ditemukan maka
         akan mereturn NULL
    */
    adrC CP = CL.First;
    while( CP != NULL){
        if(CP->info.nama == namaMaKul){
            return CP;
        }
        CP = CP->next;
    }
    return CP;
}

//---------------------------------Fungsi untuk relasi-------------------------------

void createRelation(listParent PL, listChildren CL, string nim, string makul){
    /*
    IS :Terdapat list parent dan list children, serta nim parent dan nama makul chidlren
    FS :Pada list relation di node parent akan dimasukan element relation baru yang menunjuk ke node children
    */

    adrP PP = findParent(PL, nim);
    adrC CP = findChildren(CL, makul);
    //ket : CP = Children's pointer, PP = Parent's pointer, RP = Relation's pointer

    if(PP != NULL && CP != NULL){
        adrR RP = new node_relation;
        RP->next_course = CP;
        RP->next = NULL;

        if(PP->course.First == NULL){
            //Jika list kosong
            PP->course.First = RP;
        } else {
            adrR tempRP = PP->course.First;
            while(tempRP->next != NULL){
                tempRP = tempRP->next;
            }
            tempRP->next = RP;
        }
    } else {
        cout << "ERROR, Mahasiswa atau Mata Kuliah tidak ditemukan"<<endl;
    }

}

void deleteRelation(listParent PL, string nim, string makul){
    /*
    IS :masukan berupa list parent, nim milik node parent dan
        makul milik node children yang ditunjuk oleh RP
    FS :RP dihapus dari dalam list relation PP
    */
    adrP PP = findParent(PL, nim);
    adrR RP= PP->course.First;
    while(RP->next_course->info.nama != makul && RP != NULL){
        RP = RP->next;
    }


    if(RP == PP->course.First){
        //Jika RP element relation paling depan
        if(RP->next != NULL){
            //jika terdapat element setelah RP
            PP->course.First = PP->course.First->next;
        } else {
            //Jika tidak terdapat element setelah RP
            PP->course.First = NULL;
        }
    } else if (RP!=NULL){
        //Jika RP bukan element paling depan
        adrR RPiterator = PP->course.First;
        while(RPiterator->next != RP){
            RPiterator = RPiterator->next;
        }

        //RPiterator merupakan pointer iterasi yang menunjukan ke element sebelum RP
        if(RP->next == NULL){
            //Jika RP meruapakan element paling belakang
            RPiterator->next = NULL;
        } else {
            //Jika RP bukan merupakan element paling belakang atau paling depan
            RPiterator->next = RP->next;
        }
    }
}

/*
------------------
ini bagian bikin fungsi bebas

2 jenis pengolahan data yang melibatkan child dan parent (total 20 poin),
misal :
- Min/Max from all data parent and child,
- count something from all data parent and child,
- sum something from all data parent and child,
- find child from all data parent,
- update some data from all data parent and child,
- show some data from all data parent and child,
- Dll

bikin satu satu aja
-----------------
*/

void semesterBaru(listParent PL){
    /*
    Semester baru merupakan saat dimana mahasiswa menyelesaikan mata kuliah yang diambil
    di suatu semester dan mengambil mata kuliah baru untuk semester selanjutnya. Fungsi ini
    berguna untung mengahapus semua relasi yang ada di semua node parent
    IS : Terdapat parent list
    FS : Relation list yang ada di setiap node parent akan dikosongkan
    */

    adrP PP = PL.First;
    while(PP != NULL){
        PP->course.First = NULL;
        PP = PP->next;
    }

}

void showChildrenFrom(listParent PL,string NIM){
//    IS. Terdefinisi sebuah list parent PL dan sebuah string NIM
//    FS. menampilkan mata pelajaran yang diambil oleh mahasiswa dengan nim yang ingin dicari
    adrP p = findParent(PL, NIM);
    int i = 1;
    if (PL.First == NULL){
        cout << "- Tidak ada mahasiswa yang terdaftar"<<endl<<endl;
    }
    if (p == NULL){
        cout << "- NIM yang anda cari tidak terdaftar" << endl;
    }else{
        adrR r = p->course.First;
        cout <<"Mahasiswa dengan NIM " << NIM << " mengambil mata kuliah:" << endl;
        // Belum/ tidak membuat relasi
        if(r == NULL){
            cout<<"- Mahasiswa ini sedang tidak mengambil mata kuliah"<<endl<<endl;
        }
        while (r != NULL){
            cout << i<<". "<< r->next_course->info.nama << endl;
            cout << "   diajar oleh dosen " << r->next_course->info.dosen << endl;
            cout << "   mulai pada jam " << r->next_course->info.waktu_mulai << endl;
            cout << "   di ruangan " << r->next_course->info.ruangan << endl;
            r = r->next;
            i++;
        }
    }
}
