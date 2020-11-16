#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct sv
{
    char ten[20];
    char MSSV[10];
    int dtb;
};
struct NODE
{
    sv info;
    struct NODE* next;
};
struct LIST
{
    NODE *head;
    NODE *tail;
};
NODE* CreateNode (sv x)
{
    NODE *p;
    p=new NODE;
    if(p==NULL)  exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}
void CreateList (LIST &L)
{
    L.head=L.tail=NULL;
}
void input (sv &x)
{
    printf("\nNhap MSSV: ");  fflush(stdin); gets(x.MSSV);
    printf("\nNhap ten: ");  fflush(stdin); gets(x.ten);   
    printf("\nNhap dtb: "); scanf("%d", &x.dtb);
}
void AddLast (LIST &L, NODE *p)
{
    if(L.head==NULL)  L.head=L.tail=p;
    else
    {
        L.tail->next=p;
        L.tail=p;
    }
}
void nhap (LIST &L)
{
    sv x;
    char kt;   
    printf("\nNhan phim bat ki de tiep tuc nhap.");
    printf("\nNhan 0 de dung nhap.");
    do
    {
        kt=getch();
        if(kt=='0')  break;
        input(x);
        NODE *p=CreateNode(x);
        AddLast(L,p);
    } while (1);
}
void output (sv x)
{
    printf("\n%s    %s      %d",x.MSSV,x.ten,x.dtb);
}
void xuat (LIST L)
{
    NODE *p;
    p=L.head;
    while(p!=NULL)
    {
        output(p->info);
        p=p->next;
    }
}
void maxdtb (LIST L)
{
    NODE *p,*max;
    int dem;
    p=L.head;
    max=p;
    while (p!=NULL)
    {
        if(p->info.dtb>max->info.dtb)  { max=p; dem=0; }
        if(p->info.dtb==max->info.dtb) { max=p; dem++; }
        p=p->next;
    }
    printf("\nSV co dtb cao nhat la: \n");
    if(dem==0)  output(max->info);
    else
    {
        NODE *q=L.head;
        while (q!=NULL)
        {
            if(q->info.dtb==max->info.dtb) output(q->info);
            q=q->next;
        }
    }
}
void thongkedtb (LIST L)
{
    NODE *p;
    int dem=0;
    p=L.head;
    while (p!=NULL)
    {       
        if(p->info.dtb>=5)  dem++;
        p=p->next;
    }
    if(dem==0)  printf("\nKo co sv co dtb>=5.");
    else printf("\nCo %d sv co dtb >=5.",dem);
}
void tim (LIST L)
{
    NODE *p;
    int dem=0;
    char k[20];
    printf("\nNhap ten sv can tim: ");
    fflush(stdin);
    gets(k);
    p=L.head;
    while (p!=NULL)
    {
        if(strcmp(k,p->info.ten)==0)      dem++;
        p=p->next;
    }
    if(dem!=0)
    {
            printf("\nTim thay sv: "); output(p->info);
    }
    else printf("\nKo tim thay.");
}
int main(){
     LIST L;
     NODE *p;
      sv x;
      CreateList(L);
      nhap(L);
      xuat(L);
      tim(L);
      thongkedtb(L);
}