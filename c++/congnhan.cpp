#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct sv
{
    /* data */
    char ten[30],id[3];
    float diem;
};

 void nhap(int &n, sv a[])
 {
    
     for(int i=0;i<n;i++)
     {
         cout<<"nhap thong tin:"<<endl;
         cout<<"nhap id: ";cin>>a[i].id;
         fflush(stdin);
         cout<<"\n nhap ten: ";cin.getline(a[i].ten,30);
         cout<<"\n nhap diem: ";cin>>a[i].diem;
        


 }
 }
 
 void in(int n,sv a[]){
     
    for(int i=0;i<n;i++)
     {
         /* code */
         cout<<"\n id: "<<a[i].id;
         cout<<"\ten: "<<a[i].ten;
         cout<<"\n luong: "<<a[i].ten;
     }
     
 }
 void tim(int n,sv a[]){
     float diem;
     cout<<"nhap diem càn tim: ";cin>>diem;
     for (int i = 0; i < n; i++){
     if(diem==a[i].diem)
     in(n,a);
     else
     {
         cout<<"khong co du lieu:"; break;
     }
     
     }
     
 }
 void sapxep(int n, sv a[]){
     for (int i = 0; i < n; i++){
         for(int j = i+1;j<n;j++)
         if(a[i]<a[j])
         swap(a[i],a[j]);
     }
     in(n,a);
 }
 void xoaTheoID(sv a[],  int n) {
    int found = 0;
    char id;
    cout<<"nhap id can xoa: ";cin>>id;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa SV co ID = " << id;
            break;
        }
    
    }
    in(n,a);
    if (found == 0) {
       cout<<"khong ton tai "<<id;
    

 }
 }

 int main(){
    int n;
    cout<<"nhap so luong sv: ";cin>>n;
    sv a[50];
    nhap(n,a);
    in(n,a);
    tim(n,a);
    sapxep(n,a);
    xoaTheoID(n,a);
 }
