#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
 struct CB{
    	char maCB[8];
    	char HoTen[40];
    	int tuoi,pc,tt,hsl;
    	
    };
   struct Node{
    	CB info;
    	struct Node* next;
    };
    struct List{
        Node *Head;
    	Node *Tail;

    };

    void CreateList(List &l)
    {
    	l.Head = l.Tail = NULL;
    }
    Node *GetNode(CB a)
    {
    	Node *p = new Node;
    	if (p == NULL)
    	{
    		return NULL;
    	}
    	p->info = a;
    	p->next = NULL;
    	return p;
    }
    void AddHead(List &l, Node *p)
    {
    	if (l.Head == NULL)
    	{
    		l.Head = l.Tail = p;
    	}
    	else{
    		p->next = l.Head;
    		l.Head = p;
    	}
    }
    void AddTail(List &l, Node *p)
    {
    	if (l.Head == NULL)
    	{
    		l.Head = l.Tail = p;
    	}
    	else{
    		l.Tail->next = p;
    		l.Tail = p;
    	}
    }
void InPut(List &l, int n)
    {

    	CB a;

    	for (int i = 0; i < n; i++)
    		{

            fflush(stdin);
    		cout << "nhap ma cb: "; cin.getline(a.maCB,8);
    		fflush(stdin);
    		cout << "nhap ten can bobo: "; cin.getline(a.HoTen,40);
    		fflush(stdin);
             cout<<"nhap tuoi: ";cin>>a.tuoi;
    		cout << "he so luong: ";cin>>a.hsl;
    		cout << "nhap phu cap: "; cin >> a.pc;
            a.tt = a.hsl*1050000+a.pc;
    		Node *p = GetNode(a);
    		AddTail(l, p);
    	}
    }
    void OutPut(CB a)
    {


    		cout << "ma cb : " << a.maCB<<endl;
    		cout << "ten can bo : " << a.HoTen<<endl;
    		cout << "tuoi  : " << a.tuoi<<endl;
    		cout << " he so luong : " << a.hsl<<endl;
            cout<<"phu cap: "<<a.pc;
            cout<<"tong luong: "<<a.tt<endl;
            
    		cout<<endl;

    }
    void xuat (List l)
{
	Node *p;

	cout<<"thong tin can bo: "<<endl;

	for(p = l.Head;p!=NULL;p=p->next){
        OutPut(p->info);
	}
}
 int main()
    {
        CB a;
        Node *p;
    	List l;
    	CreateList(l);
    	int select;
        
    	 do
 {
  system("cls");
  cout << "1.nhap dscb" << endl;
  cout << "2.xuat dscb" << endl;
  cout << "3.tim kiem theo diem sv " << endl;
  cout << "4. sap xep diem sv  giam dan " << endl;
  cout << "5. xoa sv " << endl;

  cout << "6. them sv " << endl;
   cout << "7. ket thuc " << endl;
  cout<<"nhap lua chon;"<<endl;
  cin >> select;
  switch (select)
  {
  case 1: {
    int n;
        cout<<"nhap so luong can bo";cin>>n;
        InPut(l,n);
        getch();
        break;
  }
  case 2: {
     xuat(l);
     getch();
     break;
  }
  
	case 7 : {
		cout<<"ket thuc!!!!!";
		return 0;
	}
  }
 } while (select != 0);


    }

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;


struct book
{
    int ID,ST,Maph;
    char TenKh[50],Nn[10],Nt[10];
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

void getStack(Stack &S)
{
    S.Top = NULL;
}
Node *getNode(book x)
{
    Node *p = new Node;
    if (p != NULL) {
        p->info = x;
        p->next = NULL;
        return p;
    }
     return NULL;
}
bool Isempty(Stack S)
{
    if(S.Top==NULL)
{
    return true;
}
    return false;
}

void Push(Stack &S, book x)
{

    Node *p = getNode(x);

if(Isempty(S))
{
    S.Top = p;
}
else
{
    p->next = S.Top;
    S.Top =p;
}

}


void Create_Data(book &x)
{
      cout<<"nhap ma thue phong: ";cin>>x.ID;

        cout<<"nhap ma phong: ";cin>>x.Maph;

        fflush(stdin);
        cout<<"nhap ten khach hang: ";cin.getline(x.TenKh,15);

        fflush(stdin);

        cout<<"nhap ngay thue phong: ";cin.getline(x.Nn,10);

        fflush(stdin);;
        cout<<"nhap ngay tra phong: ";cin.getline(x.Nt,10);

        cout<<"gia tien: ";cin>>x.ST;
}
void Create_File(Stack &S)
{
    FILE*f;
    int n;
    Node* p;
    book x;
    f=fopen("D:\\bookPhong.dat","w+b");

    cout<<"nhap so luong phong " ;cin>>n;

    for(int i = 0;i<n;i++){
        Create_Data(x);

        fwrite(&x,sizeof(book),1,f);

        Push(S,x);

    }
    if(!f)
        cout<<"khong the tao file!!!";
    else
        cout<<"ghi file thanh cong!!"<<endl;
    fclose(f);


}
void Read_Data(book x)
{

    cout<<x.ID<<"\t\t"<<x.Maph<<"\t\t"<<x.TenKh<<"\t\t"<<x.Nn<<"\t\t"<<x.Nt<<"\t\t"<<x.ST<<endl;

}
void Read_List(Stack S)
{
    Node*p;
    cout<<"ma thue \tma phong \tten khach hang\t\t ngay nhan\tngay tra\tthanh tien"<<endl;
        for(p= S.Top;p!=NULL;p=p->next)
        {

            Read_Data(p->info);
        }
}
void Read_File(Stack &S)
{

   getStack(S);
    FILE* f;


    book x;
    f=fopen("D:\\bookphong.dat","r+b");

    if(f==NULL){
        cout<<"khong the mo file";
        exit(1);
    }
    while(true)
    {

    fread(&x,sizeof(book),1,f);
    if(feof(f))break;
    Push(S,x);

    }
fclose(f);
Read_List(S);

}
void Sort_by_date(Stack &S)
{
    book tg;
    Node*p;
    FILE *f;

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
}
void Sort_by_Id(Stack &S)
{
    book tg;
    Node*p;
    FILE *f;

    for(p=S.Top;p!=NULL;p=p->next)
    {
        for(Node*q=p->next;q!=NULL;q=q->next){


            if(p->info.ID>q->info.ID)
            {

            tg = p->info;
            p->info=q->info;
            q->info=tg;

            }

        }

    }
}
 void Sort_by_Id_room(Stack &S)
{
    book tg;
    Node*p;
    FILE *f;

    for(p=S.Top;p!=NULL;p=p->next)
    {
        for(Node*q=p->next;q!=NULL;q=q->next){


            if(p->info.Maph>q->info.Maph)
            {

            tg = p->info;
            p->info=q->info;
            q->info=tg;

            }

        }

    }
}
void SortDown_by_date(Stack &S)
{
    book tg;
    Node*p;
    FILE *f;

    for(p=S.Top;p!=NULL;p=p->next)
    {
        for(Node*q=p->next;q!=NULL;q=q->next){


            if(p->info.Nn<q->info.Nn)
            {

            tg = p->info;
            p->info=q->info;
            q->info=tg;

            }

        }

    }
}
void SortDown_by_IdRent(Stack &S)
{
    book tg;
    Node*p;
    FILE *f;

    for(p=S.Top;p!=NULL;p=p->next)
    {
        for(Node*q=p->next;q!=NULL;q=q->next){


            if(p->info.ID<q->info.ID)
            {

            tg = p->info;
            p->info=q->info;
            q->info=tg;

            }

        }

    }
}
void SortDown_by_IdRoom(Stack &S)
{
    book tg;
    Node*p;
    FILE *f;

    for(p=S.Top;p!=NULL;p=p->next)
    {
        for(Node*q=p->next;q!=NULL;q=q->next){


            if(p->info.Maph<q->info.Maph)
            {

            tg = p->info;
            p->info=q->info;
            q->info=tg;

            }

        }

    }
}
Node* Search_by_IDroom(Stack S)
{
    int ma;
    cout<<"nhap ma phong can tim: ";cin>>ma;
    Node*p;
     for(p=S.Top;p!=NULL;p=p->next)
        if(p->info.Maph==ma)
            break;
     return p;
}
Node* Search_by_ID_RENT(Stack S)
{
    int ma;
    cout<<"nhap ma thue can tim: ";cin>>ma;
    Node*p;
     for(p=S.Top;p!=NULL;p=p->next)
        if(p->info.ID==ma)
            break;
     return p;
}
Node* Search_by_NameCustomer(Stack S)
{
    char name[40];
    cout<<"nhap ten can tim: ";
    fflush(stdin);
    cin.getline(name,40);
    Node*p;
     for(p=S.Top;p!=NULL;p=p->next)
        if(strcmp(p->info.TenKh,name)==0)
            break;
     return p;
}

void Remove_first(Stack &S)
{

    book x;
    FILE *f;
    f=fopen("D:\\bookphong.dat","w+b");

    if(Isempty(S)){
        cout<<"khong co du lieu";
        exit(1);
    }
    Node *q=S.Top;
    S.Top = S.Top->next;
    delete q;



    for(Node*p=S.Top;p!=NULL;p=p->next){
    x = p->info;
    fwrite(&x,sizeof(book),1,f);
    }

    cout<<"xoa thanh cong!!";
    if(Isempty(S)){
        cout<<"khong con du lieu ";
        S.Top = NULL;
    }



    fclose(f);
}
void Remove_elm(Stack &S)
{
     book x;
    FILE *f;
    Node *d;
    f=fopen("D:\\bookphong.dat","w+b");
     int ma;
     int dem=0;
    cout<<"nhap ma phong can xoa: ";cin>>ma;
    Node*p;

     for(p=S.Top;p!=NULL;p=p->next){
        if(p->info.Maph == ma ){
            d=p;
            dem++;
            delete d;
           cout<<"xoa thanh cong!!";

        }
        else{

            x= p->info;
            fwrite(&x,sizeof(book),1,f);
     }
     }
     if(dem==0)
     {
         cout<<"khong co du lieu can xoa";
     }
      if(Isempty(S)){
        cout<<"khong con du lieu ";
        S.Top = NULL;
    }


    fclose(f);

}
void Max_RentMoney(Stack S)
{
    Node *p,*max;

      for(p=S.Top;p!=NULL;p=p->next)
{


            max=p;



        for(Node*q = p->next;q!=NULL;q=q->next)
        {


            if(max->info.ST < q->info.ST){
                max = q;
                p=max;

            }
        }
}



 cout<<"ma phong co so tien cao nhat la:"<<max->info.ID;
}
void Min_RentMoney(Stack S)
{
    Node *p,*min;

      for(p=S.Top;p!=NULL;p=p->next)
{


            min=p;



        for(Node*q = p->next;q!=NULL;q=q->next)
        {


            if(min->info.ST > q->info.ST){
                min = q;
                p=min;

            }
        }
}


 cout<<"ma phong co so tien thap nhat la:"<<min->info.ID;
}
void Count_Rent(Stack S)
{
    Node *p;
    int dem = 0;
     for(p=S.Top;p!=NULL;p=p->next)
     {
         if(p->info.ST > 200000)
            dem++;
     }
     cout<<"so thue phong >200000: "<<dem;
}
void them(Stack &S)
{
    FILE *f;
    book x;
  //  getStack(S);
     f=fopen("D:\\bookphong.dat","w+b");
     if(Isempty(S))
     {
         cout<<"khong co du lieu";
         S.Top=NULL;
     }
     Create_Data(x);

     fwrite(&x,sizeof(book),1,f);
     Push(S,x);
     fclose(f);
}
int main(){
    FILE *f;
    book x;
    Stack S;

    getStack(S);
    int select;

    	 do
 {
  system("cls");
  cout << "1.nhap - luu file" << endl;
  cout << "2.doc file" << endl;
  cout << "3.sap xep tang dan theo ngay thue phong" << endl;
  cout << "4. tim theo ma phong" << endl;
  cout << "5. xoa thue phong theo ma " << endl;
  cout << "6. xoa thue phong dau tien  " << endl;
  cout << "7. tim theo ma thue " << endl;
   cout << "8. tim theo ten khach hang " << endl;
   cout << "9.sap xep tang dan theo ma thue" << endl;
   cout << "10.sap xep tang dan theo ma phong" << endl;
   cout << "12.sap xep giam dan theo ma thue" << endl;
   cout << "13.sap xep giam dan theo ma phong "<< endl;
   cout << "14.thue phong co gia cao nhat" << endl;
    cout << "15.thue phong co gia thap nhat" << endl;
   cout<<" 16. dem so thue phong >200000"<<endl;

  cout<<"nhap lua chon;"<<endl;
  cin >> select;
  switch (select){
   case 1: {
    Create_File(S);
    getch();
    break;
   }
   case 2:
    {
        Read_File(S);

        getch();
        break;
    }
   case 3:
    {
        Sort_by_date(S);
        Read_List(S);
        getch();
        break;
    }
   case 4:
       {


    Node*p=Search_by_IDroom(S);

    if(p==NULL){
        cout<<"khong tim thay";
    }
    else
    {
       cout<<"ma thue \tma phong \tten khach hang\tngay nhan\tngay tra\tthanh tien"<<endl;
               Read_Data(p->info);

    }
    getch();
        break;
       }
   case 5:
    {
    Remove_elm(S);
    getch();
    break;

    }
   case 6:
    {

   Remove_first(S);
    getch();
    break;
    }
   case 7:
    {
          Node*p=Search_by_ID_RENT(S);

    if(p==NULL){
        cout<<"khong tim thay";
    }
    else
    {
       cout<<"ma thue \tma phong \tten khach hang\tngay nhan\tngay tra\tthanh tien"<<endl;
               Read_Data(p->info);

    }
    getch();
        break;
    }
   case 8:
    {
    Node*p=Search_by_NameCustomer(S);

    if(p==NULL){
        cout<<"khong tim thay";
    }
    else
    {
       cout<<"ma thue \tma phong \tten khach hang\tngay nhan\tngay tra\tthanh tien"<<endl;
               Read_Data(p->info);

    }
    getch();
        break;
    }
   case 9:
    {
        Sort_by_Id(S);
        Read_List(S);
        getch();
        break;
    }
   case 10:
    {
        Sort_by_Id_room(S);
        Read_List(S);
        getch();
        break;

    }
   case 11:
    {
      SortDown_by_date(S);
        Read_List(S);
        getch();
        break;
    }
   case 12:
    {
      SortDown_by_IdRent(S);
        Read_List(S);
        getch();
        break;
    }
   case 13:
    {
       SortDown_by_IdRoom(S);
        Read_List(S);
        getch();
        break;
    }
   case 14:
    {
        Max_RentMoney(S);

        getch();
        break;
    }
   case 15:
    {
        Min_RentMoney(S);
        getch();
        break;
    }
   case 16:
    {
        Count_Rent(S);
        getch();
        break;
    }
  }
  }while(select != 0);
}

