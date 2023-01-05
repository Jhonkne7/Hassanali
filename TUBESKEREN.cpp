#include "TUBESKEREN.h"
#include  "CHILD.h"
//CDLL
void createListPeserta(list1 &L){
    L.first = NULL;
    L.last = NULL;
}

adr1 newElementPeserta(infotype1 x){
    adr1 p = new elemen1;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    child(p) = NULL;
    return p;
}

void deleteFirstPeserta(list1 &L, adr1 p){
    if(L.first == NULL){
        cout<<"List Sudah Kosong"<<endl;
    }else if(L.first == L.last){
        p = L.last;
        L.last = NULL;
        L.first = NULL;
    }else{
        p = L.first;
        L.first = next(p);
        prev(L.first) = NULL;
        next(p) = NULL;
    }
    info(child(p)).kuota = info(child(p)).kuota + 1;
    child(p) = NULL;
}

void deleteAfterPeserta(list1 &L, adr1 p, adr1 prec){
    if(next(L.first) == L.first){
        p = L.first;
        next(p) = NULL;
        L.first = NULL;
    }else if(L.first == NULL && L.last == NULL){
        cout<<"List Kosong"<<endl;
    }else{
        p = next(prec);
        next(prec) = next(p);
        prev(next(p)) = prec;
        next(p) = NULL;
        prev(p) = NULL;
    }
    info(child(p)).kuota = info(child(p)).kuota + 1;
    child(p) = NULL;
}

void deleteLastPeserta(list1 &L, adr1 p){
    if(L.first == NULL && L.last == NULL){
        cout << "List Kosong"<<endl;
        }else if(L.first == L.last){
        p = L.last;
        L.last = NULL;
        L.first = NULL;
    }else if(L.first == L.last){
        p = L.last;
        L.last = NULL;
        L.first = NULL;
    }else {
        p = L.last;
        L.last = prev(L.last);
        next(L.last) = next(p);
        prev(next(p)) = prev(p);
        prev(p) = NULL;
        next(p) = NULL;
    }
    info(child(p)).kuota = info(child(p)).kuota + 1;
    child(p) = NULL;
}

void insertFirstPeserta(list1 &L, adr1 p){
    if(cekPeserta(L, p) == true){
        if(L.first == NULL && L.last == NULL){
            L.first = p;
            L.last = p;
            next(L.first) = L.first;
            prev(L.first) = L.first;
        }else{
            next(p) = L.first;
            prev(L.first) = p;
            next(L.last) = p ;
            prev(p) = L.last;
            L.first = p;
        }
    }else{
        cout<<"Peserta Sudah Mengikuti Lomba Lain"<<endl;
    }

}

void showAllPeserta(list1 L){
    if(L.first == NULL && L.last == NULL){
        cout<<"LIST KOSONG"<<endl;
         cout<<"=============================================="<<endl<<endl;
    }else{
        adr1 p = L.first;
        cout<<"Berikut Data Peserta yang Sudah Terdaftar : "<<endl<<endl;
        while(p != L.last){
            cout<<"Nama Peserta : "<<info(p).nama<<endl;
            cout<<"Asal Universitar Peserta : "<<info(p).asalUniv<<endl;
            cout<<"NIM Peserta : "<<info(p).nim<<endl;
            cout<<"Angkatan Peserta : "<<info(p).angkatan<<endl;
            cout<<"Skor Lomba Peserta : "<<info(p).scoreLomba<<endl;
            cout<<"Peringkat Peserta : "<<info(p).peringkat<<endl;
            cout<<"=============================================="<<endl<<endl;
            p = next(p);
        }
        adr1 q = L.last;
        if(q == L.last){
            cout<<"Nama Peserta : "<<info(q).nama<<endl;
            cout<<"Asal Universitar Peserta : "<<info(q).asalUniv<<endl;
            cout<<"NIM Peserta : "<<info(q).nim<<endl;
            cout<<"Angkatan Peserta : "<<info(q).angkatan<<endl;
            cout<<"Skor Lomba Peserta : "<<info(q).scoreLomba<<endl;
            cout<<"Peringkat Peserta : "<<info(q).peringkat<<endl;
            cout<<"=============================================="<<endl<<endl;
        }
    }
}

bool cekPeserta(list1 L, adr1 p){
    if(child(p) == NULL){
        return true;
    }else{
        return false;
    }
}

bool cekAngkatan(adr1 p, adr_child q){
    if(info(p).angkatan == info(q).angkatan){
        return true;
    }else{
        return false;
    }
}
bool cekKuota(List_child L2, adr_child q){
    if(info(q).kuota <= 0){
        return false;
    }else{
        return true;
    }
}

adr_child findLomba(List_child L2, string NAMALOMBA){
    adr_child q = L2.first;
    while(q!=NULL){
        if(info(q).nama ==  NAMALOMBA){
            return q;
        }
        q = next(q);
    }
}

void addChild(list1 &L, List_child &L2, adr1 p, string NAMALOMBA){
    adr_child q = findLomba(L2, NAMALOMBA);
    if(q){
         if(cekKuota(L2,q) == true && cekAngkatan(p, q) == true){
            child(p) = q;
            info(q).kuota = info(q).kuota - 1;
            cout<<"--PESERTA DITAMBAHKAN KE DAFTAR LOMBA--"<<endl<<endl;
        }else{
            child(p) = NULL;
            cout<<"--LOMBA SUDAH PENUH ATAU ANDA TIDAK MEMENUHI SYARAT--"<<endl;
            cout<<"-Anda Bisa Melihat Daftar Lomba di Menu 5-"<<endl<<endl;
        }
    }else{
        cout<<"--TIDAK ADA CABANG LOMBA "<<NAMALOMBA<<"--"<<endl;
        cout<<"=============================================="<<endl<<endl;

    }

}

void showJumlahPeserta(list1 L){
    if(L.first == NULL && L.last == NULL){
        cout<<"LIST KOSONG"<<endl;
        cout<<"=============================================="<<endl<<endl;
    }else{
        adr1 p = L.first;
        adr1 pp = L.last;
        int i = 0;
        while(p != L.last){
            if(child(p) != NULL){
                i++;
            }
            p = next(p);
        }
        if(child(pp) != NULL){
                i++;

        }
        cout<<"Peserta yang Terdafter Berjumlah : "<< i<<endl;
        cout<<"=============================================="<<endl<<endl;
    }
}

void showAllPesertaNLomba(list1 L){
    if(L.first == NULL && L.last == NULL){
        cout<<"LIST KOSONG"<<endl;
         cout<<"=============================================="<<endl<<endl;
    }else{
        adr1 p = L.first;
        while(p != L.last){
            if(child(p) != NULL){
                cout<<"Nama Peserta : "<<info(p).nama<<endl;
                cout<<"Asal Universitar Peserta : "<<info(p).asalUniv<<endl;
                cout<<"NIM Peserta : "<<info(p).nim<<endl;
                cout<<"Angkatan Peserta : "<<info(p).angkatan<<endl;
                cout<<"Skor Lomba Peserta : "<<info(p).scoreLomba<<endl;
                cout<<"Peringkat Peserta : "<<info(p).peringkat<<endl<<endl;
                cout<<"Lomba Yang Diikuti oleh "<<info(p).nama<<" : "<<info(child(p)).nama<<endl;
                cout<<"Sisa Kuota Lomba Yang Diikuti oleh "<<info(p).nama<<" : "<<info(child(p)).kuota<<endl;
                cout<<"Angkatan Lomba Yang Diikuti oleh "<<info(p).nama<<" : "<<info(child(p)).angkatan<<endl;
                cout<<"Level Lomba Yang Diikuti oleh "<<info(p).nama<<" : "<<info(child(p)).level<<endl;
                cout<<"=============================================="<<endl<<endl;
            }
            p = next(p);
        }
        adr1 q = L.last;
        if(q == L.last && child(q) != NULL){
            cout<<"Nama Peserta : "<<info(q).nama<<endl;
            cout<<"Asal Universitar Peserta : "<<info(q).asalUniv<<endl;
            cout<<"NIM Peserta : "<<info(q).nim<<endl;
            cout<<"Angkatan Peserta : "<<info(q).angkatan<<endl;
            cout<<"Skor Lomba Peserta : "<<info(q).scoreLomba<<endl;
            cout<<"Peringkat Peserta : "<<info(q).peringkat<<endl<<endl;
            cout<<"Lomba Yang Diikuti oleh "<<info(q).nama<<" : "<<info(child(q)).nama<<endl;
            cout<<"Sisa Kuota Lomba Yang Diikuti oleh "<<info(q).nama<<" : "<<info(child(q)).kuota<<endl;
            cout<<"Angkatan Lomba Yang Diikuti oleh "<<info(q).nama<<" : "<<info(child(q)).angkatan<<endl;
            cout<<"Level Lomba Yang Diikuti oleh "<<info(q).nama<<" : "<<info(child(q)).level<<endl;
            cout<<"=============================================="<<endl<<endl;
        }
    }
}

//Program dapat menampilkan mahasiswa tertentu mengkuti cabang lomba apa
void showLombaPesertanya(list1 L, string nama){
    adr1 p = findPeserta2(L, nama);
    if(p){
        cout<<"Peserta "<<nama<<" mengikuti lomba : "<<info(child(p)).nama<<endl;
        cout<<"=============================================="<<endl<<endl;
    }else{
        cout<<" Tidak Ditemukan "<<endl;
        cout<<"=============================================="<<endl<<endl;
    }
}


//Program dapat menampilkan sebuah cabang lomba tertentu diikuti oleh mahasiswa siapa saja
void showPesertaLombanya(list1 L, string NAMALOMBA){
    if(L.last == NULL && L.first == NULL){
        cout<<"LIST KOSONG PESERTA MASIH KOSONG"<<endl;
        cout<<"=============================================="<<endl<<endl;
    }else{
        cout<<"Berikut Data Peserta yang Sedang Mengikuti Lomba "<<NAMALOMBA<<" : "<<endl<<endl;
        adr1 p = L.first;
        adr1 pp = L.last;
        while(p != L.last){
            if(info(child(p)).nama == NAMALOMBA && child(p) != NULL ){
                cout<<"Nama Peserta : "<<info(p).nama<<endl;
                cout<<"Asal Universitas Peserta : "<<info(p).asalUniv<<endl;
                cout<<"NIM Peserta : "<<info(p).nim<<endl;
                cout<<"Angkatan Peserta : "<<info(p).angkatan<<endl;
                cout<<"Skor Lomba Peserta : "<<info(p).scoreLomba<<endl;
                cout<<"Peringkat Peserta : "<<info(p).peringkat<<endl;
                cout<<"=============================================="<<endl<<endl;
                }
            p = next(p);
        }
        if(info(child(pp)).nama == NAMALOMBA && child(pp) != NULL){
            cout<<"Nama Peserta : "<<info(pp).nama<<endl;
            cout<<"Asal Universitas Peserta : "<<info(pp).asalUniv<<endl;
            cout<<"NIM Peserta : "<<info(pp).nim<<endl;
            cout<<"Angkatan Peserta : "<<info(pp).angkatan<<endl;
            cout<<"Skor Lomba Peserta : "<<info(pp).scoreLomba<<endl;
            cout<<"Peringkat Peserta : "<<info(pp).peringkat<<endl;
            cout<<"=============================================="<<endl<<endl;
        }else{
            cout<<"--Tidak Ditemukan Peserta di Lomba "<<NAMALOMBA<<"--"<<endl;
            cout<<"=============================================="<<endl<<endl;
        }
    }
}

int selectMenu(){
    cout<<"======= MENU ======="<<endl;
    cout<<"1.Masukkan Data Peserta Baru dan Lomba yang Ingin Diikuti"<<endl;//BENER
    cout<<"2.Ganti Lomba"<<endl;
    cout<<"3.Hapus Suatu Lomba"<<endl;
    cout<<"4.Hapus Peserta"<<endl;
    cout<<"5.Lihat List Lomba Yang Disediakan"<<endl;//BENER
    cout<<"6.Lihat List Peserta "<<endl;
    cout<<"7.Lihat Lomba dan Pesertanya"<<endl;
    cout<<"8.Cari Peserta"<<endl;
    cout<<"9.Cari Lomba dan Pesertanya"<<endl;
    cout<<"10.Lihat Jumlah Peserta yang Sudah Terdaftar"<<endl;
    cout<<"0.EXIT"<<endl;
    cout<<"- Pilih Menu : ";
    int input = 0;
    cin >> input;cout<<endl;
    return input;
}

void deletePeserta(list1 &L,adr1 &P, string PESER){
    if(first(L) != nil){
        P = findPeserta(L, PESER);
        if(P != nil){
            if(P == first(L)){
                deleteFirstPeserta(L,P);
                cout << "--PESERTA TELAH TERHAPUS--" << endl;
            cout<<"=============================================="<<endl<<endl;
            }else if(P == last(L)){
                deleteLastPeserta(L,P);
                cout << "--PESERTA TELAH TERHAPUS--" << endl;
            cout<<"=============================================="<<endl<<endl;
            }else{
                adr1 prec = prev(P);
                deleteAfterPeserta(L,P,prec);
                cout << "--PESERTA TELAH TERHAPUS--" << endl;
            cout<<"=============================================="<<endl<<endl;
            }
        }else{
            cout << "--PESERTA TELAH TERHAPUS--" << endl;
            cout<<"=============================================="<<endl<<endl;
        }
    }
}
