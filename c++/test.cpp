#include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct book
{
    int ID,ST,Maph;
    char TenKh[15],Nn[10],Nt[10];
};
struct Node
{
    book info;
    struct Node* next;
};
struct Stack
{
    Node*Top;
};
Stack S;
void khoitao(Stack &S)
{
    S.Top = NULL;
}


Node* getNode(book x)
{
    Node* p;
    p = new Node;
    if(p == NULL){
        cout<<"loi";
        return NULL;
    }
    p->info = x;
    p-> next = NULL;
    return p;
}
bool Isempty(Stack S)
{
if(S.Top==NULL)
{
return true;// danh sach rong

}
return false; // danh sach co phan tu;
}


bool them(Stack &S,Node *p)
{
if(p == NULL)
{
    
return false;
}
if(Isempty(S)==true)// danh sach rong
{
S.Top=p; // phan tu p chinh la phan tu dau

}
else
{
p->next=S.Top;
S.Top=p;
}
return true;
}
bool laysanpham(Stack &S, book x)
{
if(Isempty(S)==true)
{
return false;
}
else
{
Node *p=S.Top;// tao phan tu p the mang de chuan bi xoa
x = p->info; // lay du lieu
S.Top=S.Top->next;// cap nhap phan tu dau moi
delete p;
}
return true; // lay phan tu thanh cong
}
void nhap(Stack &S)
{
    FILE*f;
    int n;
    Node* p;
    book x;
    f=fopen("book.dat","w+b");
    cout<<"nhap so luong phong " ;cin>>n;
    for(int i = 0;i<n;i++){
        cout<<"nhap ma thue phong: ";cin>>x.ID;
        cout<<"nhap ma phong: ";cin>>x.Maph;
        fflush(stdin);
        cout<<"nhap ten khach hang: ";cin.getline(x.TenKh,15);
            fflush(stdin);
         cout<<"nhap ngay thue phong: ";cin.getline(x.Nn,10);
             fflush(stdin);;
        cout<<"nhap ngay tra phong: ";cin.getline(x.Nt,10);
        cout<<"gia tien: ";cin>>x.ST;
        fwrite(&x,sizeof(book),1,f);
        p=getNode(x);
        them(S,p);

    }
    if(!f)
        cout<<"khong the tao file!!!";
    else
        cout<<"ghi file thanh cong!!"<<endl;
    fclose(f);


}
void doc(book x)
{
cout<<x.ID<<"\t\t"<<x.Maph<<"\t\t"<<x.TenKh<<"\t\t"<<x.Nn<<"\t\t"<<x.Nt<<"\t\t"<<x.ST<<endl;
}
void docds(Stack S)
{
    Node*p;
   cout<<"ma thue \tma phong \tten khach hang\tngay nhan\tngay tra\tthanh tien"<<endl;
        for(p= S.Top;p!=NULL;p=p->next)
        {

            doc(p->info);
        }
}
void hien (Stack &S)
{
    khoitao(S);
    FILE* f ;

    Node* p;
    book x;
    fopen("book.dat","r b");
    if(f==NULL){
        cout<<"khong the mo file";
        exit(1);
    }
    while(true){
    fread(&x,sizeof(book),1,f);
    if(feof(f))break;
    p=getNode(x);
    them(S,p);

    }
    fclose(f);
    cout<<"doc danh sach";
    docds(S);





}
void sapxep(Stack S)
{
    book tg;
    Node*p;
    for(p=S.Top;p!=NULL;p=p->next)
    {
        for(Node*q=p->next;q!=NULL;q=q->next){


            if(p->info.Nn>q->info.Nn)
            {

            tg = p->info;
            p->info=q->info;
            q->info=tg;
            }
        }
    }
    docds(S);


}
Node* tim(Stack S)
{
    int ma;
    cout<<"nhap ma phong can tim: ";cin>>ma;
    Node*p;
     for(p=S.Top;p!=NULL;p=p->next)
        if(p->info.Maph==ma)
            break;
     return p;
}

int main(){
    book x;
    Node *p;
    Stack S;
    khoitao(S);

    int select;

    	 do
 {
  system("cls");
  cout << "1.nhap - luu file" << endl;
  cout << "2.doc file" << endl;
  cout << "3.sap xep" << endl;
  cout << "4. tim theo ma phong" << endl;
  cout << "5. xoa sv " << endl;

  cout << "6. them sv " << endl;
   cout << "7. ket thuc " << endl;
  cout<<"nhap lua chon;"<<endl;
  cin >> select;
  switch (select){
   case 1: {
    nhap(S);
    getch();
    break;
   }
   case 2:
    {
        hien(S);
        docds(S);

        getch();
        break;
    }
   case 3:
    {
        sapxep(S);
        getch();
        break;
    }
   case 4:
    p=tim(S);

    if(p==NULL){
        cout<<"khong tim thay";
    }
    else
    {
       cout<<"ma thue \tma phong \tten khach hang\tngay nhan\tngay tra\tthanh tien"<<endl;
                   cout<<p->info.ID<<"\t\t"<<p->info.Maph<<"\t\t"<<p->info.TenKh<<"\t\t"<<p->info.Nn<<"\t\t"<<p->info.Nt<<"\t\t"<<p->info.ST<<endl;

    }
    getch();
        break;

  }
  }while(select != 0);
}

