
#include<bits/stdc++.h>
#include <conio.h>
using namespace std;

   struct SV{
    	char maSV[8];
    	char HoTen[40];
    	char Lop[10];
    	float diemTB;
    };
   struct Node{
    	SV info;
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
    Node *GetNode(SV a)
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

    	SV a;

    	for (int i = 0; i < n; i++)
    		{

            fflush(stdin);
    		cout << "nhap ma sv: "; cin.getline(a.maSV,8);
    		fflush(stdin);
    		cout << "nhap ten sinh vien : "; cin.getline(a.HoTen,40);
    		fflush(stdin);
    		cout << "lop : "; cin >> a.Lop;
    		cout << "diem trung binh: "; cin >> a.diemTB;
    		Node *p = GetNode(a);
    		AddTail(l, p);
    	}
    }

    void OutPut(SV a)
    {


    		cout << "ma sv : " << a.maSV<<endl;
    		cout << "ten sinh vien : " << a.HoTen<<endl;
    		cout << "lop  : " << a.Lop<<endl;
    		cout << "diem trung binh : " << a.diemTB<<endl;
    		cout<<endl;

    }
    void xuat (List l)
{
	Node *p;

	cout<<"thong tin sinh vien: "<<endl;

	for(p = l.Head;p!=NULL;p=p->next){
        OutPut(p->info);
	}
}
void tim(List l){

    Node *p;
	p = l.Head;
	float diem;
    int dem =0;

    cout<<"nhap diem can tim: ";cin>>diem;
	for(p = l.Head;p!= NULL;p=p->next){
         if(p->info.diemTB == diem){
            OutPut(p->info);
            dem++;

        }

        }
    if(dem== 0){
        cout<<"khong ton tai"<<endl;
    }
}
void sapxep(List &l)

{
	Node* p, * q,* max;
	SV temp;
	for(p = l.Head;p != NULL ; p= p->next)
    {
        max =p;
        for( q = p->next; q!= NULL; q= q->next)
        {
            if(max->info.diemTB < q->info.diemTB)
                max=q;
        }
        temp = p->info;
        p->info = max->info;
        max->info =temp;

    }
}
void themsau(List l, Node* p, Node* q)
    p = l.Head;
	float diem;
    int dem =0;

    cout<<"nhap diem can tim: ";cin>>diem;
	for(p = l.Head;p!= NULL;p=p->next){
         if(p->info.diemTB == diem){

}

void xoa (List &l)
{
    Node *p, *q;
    char a[8];
    int dem=0;
    p=l.Head;
    q=NULL;
    cout<<"\nNhap MSSV can xoa: ";
    fflush(stdin);
    cin.getline(a,8);


    while (p!=NULL)
    {
        if(strcmp(a,p->info.maSV)==0){ dem++;   break;}
        else{
        q=p;
        p=p->next;
        }
    }
    if(q!=NULL)
    {
        if(p!=NULL)
        {
            q->next=p->next;
            delete (p);
            if(p==l.Tail)  l.Tail=q;
            delete(p);
        }
    }
    else
    {
        l.Head=p->next;
        delete(p);
        if(l.Head==NULL)  l.Tail=NULL;
    }
    if(dem==0){
        cout<<"khong kho sv can xoa!!!";
    }
}
void them(List &l){
    SV a;

            fflush(stdin);
    		cout << "nhap ma sv: "; cin.getline(a.maSV,8);
    		fflush(stdin);
    		cout << "nhap ten sinh vien : "; cin.getline(a.HoTen,40);
    		fflush(stdin);
    		cout << "lop : "; cin >> a.Lop;
    		cout << "diem trung binh: "; cin >> a.diemTB;
    		Node *p = GetNode(a);
    		AddTail(l, p);
}
void add(List &l , Node* p, Node*q){
    for(Node* k = l.Head ; k!=NULL; k=k->next){
        if(k->info == q->info)
        {
            Node* g = k->next;
            k->next = p;
            p->next = g;
            return 0;
        }
    }
}

    int main()
    {
        SV a;
        Node *p;
    	List l;
    	CreateList(l);
    	int select;
        
    	 do
 {
  system("cls");
  cout << "1.nhap dssv" << endl;
  cout << "2.xuat dssv" << endl;
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
        cout<<"nhap so luong sinh vien";cin>>n;
        InPut(l,n);
        getch();
        break;
  }
  case 2: {
     xuat(l);
     getch();
     break;
  }
  case 3: {
    tim(l);
    getch();
     break;
  }
  case 4: {
     cout<<"danh sach sau khi sap xep: "<<endl;
    sapxep(l);
    xuat(l);
    getch();
     break;
  }
  case 5: {
    xoa(l);
     cout<<"danh sach sau khi xoa"<<endl;

     xuat(l);
     getch();
     break;
  }

  case 6: {
    them(l);
    xuat(l);
	getch();
	break;  }
	case 7 : {
		cout<<"ket thuc!!!!!";
		return 0;
	}
    case 8:{
        Node* Q = GetNode(q);
        
    }
  }
 } while (select != 0);


    }
