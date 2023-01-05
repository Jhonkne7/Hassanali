#include "TUBESKEREN.h"
#include "CHILD.h"

int main(){
    //INSIALISASI LIST1
    list1 L;
    infotype1 x;
    int a;

    //INISIALISASI LIST2
    List_child LC;
    infotypechild xc ;
    adr_child ac ;



    //Disediakan 4 lomba yang berbeda
    createListchild(LC);
    //Lomba 1
    xc.nama = "IPA";
    xc.kuota = 2;
    xc.angkatan = 22;
    xc.level = "EASY";
    ac = alokasichild(xc) ;
    insertLastChild(LC,ac) ;

    //Lomba 2
    xc.nama = "BIOLOGI";
    xc.kuota = 2;
    xc.angkatan = 22;
    xc.level = "EASY";
    ac = alokasichild(xc) ;
    insertLastChild(LC,ac) ;

    //Lomba 3
    xc.nama = "FISIKA";
    xc.kuota = 2;
    xc.angkatan = 21;
    xc.level = "MEDIUM";
    ac = alokasichild(xc) ;
    insertLastChild(LC,ac) ;

    //Lomba 4
    xc.nama = "KIMIA";
    xc.kuota = 2;
    xc.angkatan = 20;
    xc.level = "HARD";
    ac = alokasichild(xc) ;
    insertLastChild(LC,ac) ;
    //PENAMBAHAN PESERTA
    createListPeserta(L);

    int pilihan = selectMenu();
    char o;
    while(pilihan != 0){
        switch(pilihan){
            case 1:{
                cout<<"Jumlah Peserta yang akan ditambahkan : ";cin>>  a;
                int i = 0;
                while(i <  a){
                    string NAMALOMBA;
                    cout<<"Nama Peserta : ";cin>>x.nama;
                    cout<<"Asal Universitar Peserta : ";cin>>x.asalUniv;
                    cout<<"NIM Peserta : ";cin>>x.nim;
                    cout<<"Angkatan Peserta : ";cin>>x.angkatan;
                    cout<<"Skor Lomba Peserta : ";cin>>x.scoreLomba;
                    cout<<"Peringkat Peserta : ";cin>>x.peringkat;
                    adr1 p = newElementPeserta(x);
                    insertFirstPeserta(L, p);
                    cout<<"Lomba yang Ingin Diikuti : ";cin>>NAMALOMBA;cout<<endl;
                    addChild(L, LC,p, NAMALOMBA);
                    i++;
                }
            }break;
            case 2:{
                string t1, nama;
                adr1 p;
                cout<<"--Masukkan Nama Peserta dan Lomba Yang Ingin Dipindahkan Dengan Benar!--"<<endl;
                cout<<"Nama Peserta : ";cin>> nama;
                cout<<"Nama Lomba : ";cin>> t1;cout<<endl;
                gantilomba(L, p, LC, t1, nama);
            }break;
            case 3:{
                string SL;
                cout<<"Masukkan Lomba yang Ingin DIhapus :" ;
                cin >> SL ;
                deleteChild(LC, L, SL);
            }break;
            case 4:{
                string BP;
                adr1 pes;
                cout<<"Masukkan Nama Peserta yang Ingin Dihapus :" ;
                cin >> BP;
                deletePeserta(L,pes, BP);
            }break;
            case 5:{
                printchild(LC);
            }break;
            case 6:{
                showAllPeserta(L);
            }break;
            case 7:{
                showAllPesertaNLomba(L);
            }break;
            case 8:{
                string nama;
                adr1 P;
                cout<<"--Harap Masukkan Data Diri Peserta yang Ingin Dicari Dengan Benar!--"<<endl;
                cout<<"Nama Peserta : ";cin>>nama;cout<<endl;
                showLombaPesertanya(L, nama);
            }break;
            case 9:{
                string NAMALOMBA;
                cout<<"--Harap Masukkan Lomba yang Ingin Dicari Dengan Benar!--"<<endl;
                cout<<"Nama Lomba : ";cin>>NAMALOMBA;cout<<endl;
                showPesertaLombanya(L, NAMALOMBA);
            }break;
            case 10:{
                showJumlahPeserta(L);
            }
        }
        cout<<"Kembali ke Menu Utama? (Y/N):";
        cin >>  o;
        if(o == 'Y' || o =='y'){
            pilihan =selectMenu();
        }else{
            pilihan = 0;
        }
    }
    cout<<endl;
    cout <<"ANDA TELAH KELUAR DARI MENU"<<endl;
}
//ADA MASALAH DI CASE 8,9 saat adanya PESERTA YANG TERDAFTAR DI LIST TAPI TIDAK MENDAPATKAN CHIL(LOMBA)
//PINDAHLOMBA DAN DELETE LOMBA(tambahin kuota) + MAIN.CPP


