#include "CHILD.h"
#include "TUBESKEREN.h"

void createListchild (List_child &L){
    first(L)=NULL;
    last(L)=NULL;
}

adr_child alokasichild(infotypechild child){
 /*if(head != NULL) {
    if(head->next == NULL) {
      head = NULL;
    } else {
      Node* temp = head;
      while(temp->next->next != NULL)
        temp = temp->next;
      Node* lastNode = temp->next;
      temp->next = NULL;
      free(lastNode);
     }
  } */
    adr_child P=new elmlist_child;
    info(P).nama=child.nama;
 info(P).kuota=child.kuota;
 info(P).angkatan=child.angkatan;
 info(P).level=child.level;
    next(P)=nil;
 prev(P)=nil;
 return P ;
} ;

void dealokasichild(adr_child &P){
    delete P;
} ;

void insertFirst_1301213501(List_child &L, adr_child P){
    if (first(L) != NULL && last(L) != NULL){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}

void printchild(List_child L){
    if(first(L)!=nil){
            adr_child P=first(L);
            int J=1;
            while(P!=nil){
                cout<<"Lomba "<<J<<" = "<<endl;
                cout<<"Nama Lomba: "<<info(P).nama<<" "<<endl;
                cout<<"Kuota :"<<info(P).kuota<<" "<<endl;
                cout<<"Peruntukan Angkatan : "<<info(P).angkatan<<" "<<endl;
                cout<<"Level Lomba : "<<info(P).level<<" "<<endl;

                cout<<"=============================================="<<endl<<endl;
            P=next(P);
            J++;
        }
    }else{
        cout<<"Tidak ada data member yang dapat dilihat"<<endl;
    }
}

adr_child findchild(List_child L, string P){
    if(first(L) != nil ){
        adr_child q = first(L);
        while(q != nil) {
            if (info(q).nama == P){
              return q;
            }
            q = next(q);
        }
    }
    return NULL;
}

void insertLastChild(List_child &L, adr_child P) {
 if(first(L) != nil && last(L) != nil){
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P ;
    } else {
        first(L) = P;
        last(L) = P;
    }
}

/*
void insertMember(List_child &L, adr_child P){
    if(first(L)!=nil && last(L)!=nil){
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }else{
        insertChild(L,P);
    }
}
*/

void deleteFirstchild(List_child &L){
    if(first(L)!=nil && last(L)!=nil){
        adr_child P=first(L);
        first(L)=next(P);
        next(P)=nil;
    }else{
        cout<<"Tidak ada child"<<endl;
    }
}

void deleteLastChild(List_child &L){
    if(first(L)!=nil && last(L)!=nil){
        adr_child q=last(L);
        last(L)=prev(q);
        next(last(L))=nil;
        delete q;
    }else{
        cout<<"Tidak ada child"<<endl;
    }
}

void deleteAfterChild(List_child &L, adr_child Prec){
    if(first(L)!=nil && Prec!=nil){
        adr_child q=first(L);
        while(next(q)!=nil && info(q).nama != info(next(Prec)).nama){
            q=next(q);
        }
        if(info(q).nama== info(next(Prec)).nama){
            if (next(q)==nil){
                deleteLastChild(L);
            }else{
                next(Prec) = next(q);
                prev(q) = nil ;
                prev(next(q)) = nil ;
                next(q) = nil ;
            }
        }else{
            cout<<"Tidak ditemukan child"<<endl;
        }
    }else{
        cout<<"List Kosong"<<endl;
    }
}
/*
void insertLast(List &L, adr p){
 if (first(L) != NULL && last(L) != NULL){
        next(last(L)) = p ;
        prev(p) = last(L);
        last(L) = p ;
    }else{
        first(L) = P;
        last(L) = P;
    }
}*/

void deleteChild(List_child &L, list1 &LP, string R){
    if(first(L) != nil){
        adr_child P = findchild(L, R);
        if(P != nil){
            if(P == first(L)){
                deleteFirstchild(L);
            }else if(P == last(L)){
                deleteLastChild(L);
            }else{
                adr_child prec = prev(P);
                deleteAfterChild(L,prec);
            }
            //moveChild(LP,P,L);
        }else{
            cout << "Tidak dapat menghapus list,data tidak ada dalam List" << endl;
        }
    }else{
        cout << "LIST KOSONG" << endl;
        cout<<"=============================================="<<endl<<endl;
    }

}
void moveChild(list1 &L, adr_child q,List_child Lc){
    if(first(L)!=NULL){
        adr1 p;
        string lomba;
        while(p!=NULL){
            if(child(p)==q){
                //cout<<"Peserta dengan nama "<< info(p).nama<<" lombanya tidak ada.\nHarap ganti lombanya"
                cin>>lomba;
                gantilomba(L,p,Lc,lomba,info(p).nama);
            }
            p=next(p);
        }
    }
}
void gantilomba(list1 &Lp,adr1 &p, List_child L, string tl, string nama){
    p = findPeserta(Lp,nama);
    if(p!=NULL && child(p) != NULL){
        adr_child l = findchild(L,tl);
        if(l!=NULL){
            if(info(l).level==info(child(p)).level&&cekKuota(L,l)){
                info(child(p)).kuota++;
                child(p)=l;
                info(child(p)).kuota--;
                cout<<"-- TELAH DIPROSES--"<<endl;
                cout<<"=============================================="<<endl<<endl;
            }else{
                cout<<"--TIDAK DITEMUKAN KRITERIA LOMBA--"<<endl;
                cout<<"=============================================="<<endl<<endl;
            }
        }else{
            cout<<"--LOMBA TIDAK DITEMUKAN--"<<endl;
            cout<<"=============================================="<<endl<<endl;
        }
    }else{
        cout<<"--NAMA PESERTA TIDAK DIEMUKAN--"<<endl;
        cout<<"=============================================="<<endl<<endl;
    }
}
adr1 findPeserta(list1 L, string nama){
    adr1 p = first(L);
    adr1 pp = last(L);
    if(p){
        while(p!=last(L)){
            if(info(p).nama==nama){
                return p;
            }
            p=next(p);
        }
        if(pp == last(L)){
            if(info(pp).nama==nama){
                return pp;
            }
        }
    }else{
        return NULL;
    }
}

adr1 findPeserta2(list1 L, string nama){
    adr1 p = first(L);
    adr1 pp = last(L);
    if(p){
        while(p!=last(L)){
            if(info(p).nama==nama && child(p) != NULL){
                return p;
            }
            p=next(p);
        }
        if(pp == last(L)){
            if(info(pp).nama==nama && child(pp) != NULL){
                return pp;
            }
        }
    }else{
        return NULL;
    }
}

