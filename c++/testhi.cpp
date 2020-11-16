#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

// Nguyen lieu
struct NL 
{
	char TenNL[30],NguonNL[20];
	int MaNL,SoLuongNL,GiaNL;
};

struct NodeNL
{
	NL infonl;
	NodeNL *nextnl;
};

struct StackNL
{
	NodeNL *TopNL;
};

//khoi tao stack nl
void InitNL(StackNL &SNL)
{
	SNL.TopNL = NULL;
}

//tao node nl
NodeNL *CreateNodeNL( NL x )
{
	NodeNL *pnl = new NodeNL;
	if( pnl == NULL)
		exit(1);
	pnl -> infonl = x;
	pnl -> nextnl = NULL;
	return pnl;
}

bool EmptyNL( StackNL SNL)
{
	if(SNL.TopNL == NULL)
		return true;
	else
		return false;	
}
//push vao stack nguyen lieu
void PushNL( StackNL &SNL, NL x )
{
	NodeNL *pnl = CreateNodeNL(x);
	if( EmptyNL(SNL) )
	{
		SNL.TopNL = pnl;
	}
	else
	{
		pnl -> nextnl = SNL.TopNL;
		SNL.TopNL = pnl;
	}
}

//pop ra khoi stack nguyen lieu
void PopNL( StackNL &SNL )
{
	NodeNL *pnl = SNL.TopNL;
	if( !EmptyNL(SNL) )
	{
		SNL.TopNL = pnl -> nextnl;
		delete pnl;
	}
	else
	{
		cout<<"\nDanh sach nguyen lieu rong";
	}
}

//Nhap nguyen lieu
void InPutNL( NL &x )
{
	cout<<"Nhap ma nguyen lieu: "; cin>>x.MaNL;
	cout<<"Nhap ten nguyen lieu: "; fflush(stdin) ; gets(x.TenNL);
	cout<<"Nhap gia nguyen lieu: "; cin>>x.GiaNL;
	cout<<"Nhap so luong nguyen lieu: "; cin>>x.SoLuongNL;
	cout<<"Nhap nguon nhap nguyen lieu: "; fflush(stdin) ; gets(x.NguonNL);
	cout<<"--------------------------------------"<<endl;
}

void NhapNL( StackNL &SNL)
{
	NL x;
	int n;
	cout<<"\nSo nguyen lieu can nhap la: ";cin>>n;
	for( int i = 1 ; i <= n ; i++ )
	{
		InPutNL(x);
		NodeNL *pnl = CreateNodeNL(x);
		PushNL(SNL,x);
	}
}

//In nguyen lieu
void OutPut( NL x)
{
	cout<<x.MaNL<<setw(20)<<x.TenNL<<setw(30)<<x.GiaNL<<setw(20)<<x.SoLuongNL<<setw(25)<<x.NguonNL;
	cout<<endl;
}

void XuatNL( StackNL SNL )
{
	cout<<"\nDanh sach nguyen lieu: "<<endl;
	cout<<"Ma"<<setw(20)<<"Ten "<<setw(30)<<"Gia"<<setw(20)<<"So luong"<<setw(25)<<"Nguon nhap"<<endl;
	NodeNL *pnl = SNL.TopNL;
	while( pnl != NULL)
	{
		OutPut( pnl -> infonl);
		pnl = pnl -> nextnl;
	}
}

//them mot nguyen lieu
void ThemNL( StackNL &SNL )
{
	NL x;
	cout<<"\nNhap thong tin nguyen lieu can them: "<<endl;
	InPutNL(x);
	NodeNL *pnl = CreateNodeNL(x);
	PushNL(SNL,x);
}

//tim nguyen lieu
void SearchNL( StackNL &SNL )
{
	int n;
	cout<<"\nNhap ma nguyen lieu can tim: "; cin>>n;
	NodeNL *qnl = SNL.TopNL;
	while( qnl != NULL )
	{
		if( qnl -> infonl.MaNL == n )
		{
			OutPut( qnl -> infonl);
		}
		else
		 qnl = qnl -> nextnl;
	}
	
}

//San pham
struct SP
{
	char TenSP[30];
	int MaSP,GiaSP;
};

struct NodeSP
{
	SP infosp;
	NodeSP *nextsp;
};

struct StackSP
{
	NodeSP *TopSP;
};

void InitSP( StackSP &SSP)
{
	SSP.TopSP = NULL;
}

//tao node san pham
NodeSP *CreateNodeSP( SP y )
{
	NodeSP *psp = new NodeSP;
	if( psp == NULL )
		exit(1);
	psp -> infosp = y;
	psp -> nextsp = NULL;
	return psp;
}

//kiem tra sp rong
bool EmptySP( StackSP SSP )
{
	if(SSP.TopSP == NULL)
		return true;
	else
		return false;	
}

//push sp
void PushSP( StackSP &SSP, SP y )
{
	NodeSP *psp = CreateNodeSP(y);
	if( EmptySP(SSP) )
	{
		SSP.TopSP = psp;
	}
	else
	{
		psp -> nextsp = SSP.TopSP;
		SSP.TopSP = psp;
	}
}

//pop san pham
void PopSP( StackSP &SSP )
{
	NodeSP *psp = SSP.TopSP;
	if( !EmptySP(SSP) )
	{
		SSP.TopSP = psp -> nextsp;
		delete psp;
	}
	else
	{
		cout<<"\nDanh sach san pham rong";
	}
}

void InPutSP( SP &y )
{
	cout<<"Nhap ma san pham: "; cin>>y.MaSP;
	cout<<"Nhap ten san pham: "; fflush(stdin) ; gets(y.TenSP) ;
	cout<<"Nhap gia san pham: "; cin>>y.GiaSP;
	cout<<"----------------------------------------------"<<endl;
}

void NhapSP( StackSP &SSP)
{
	SP y;
	int n;
	cout<<"\nNhap so san pham ban muon nhap: "; cin>>n;
	for( int i = 0 ; i <= n ; i++)
	{
		InPutSP(y);
		NodeSP *psp = CreateNodeSP(y);
		PushSP(SSP,y);
	}
}

void OutPutSP( SP y )
{
	cout<<y.MaSP<<setw(20)<<y.TenSP<<setw(30)<<y.GiaSP;
	cout<<endl;
}

void XuatSP( StackSP SSP )
{
	NodeSP *psp = SSP.TopSP;
	cout<<"\nDanh sach san pham: "<<endl;
	cout<<"Ma"<<setw(20)<<"Ten"<<setw(30)<<"Gia"<<endl;
	while( psp != NULL)
	{
		OutPutSP( psp -> infosp );
		psp = psp -> nextsp;
	}
}

//them mot sanpha,
void ThemSP( StackSP &SSP )
{
	SP y;
	cout<<"\nNhap thong tin san pham: "<<endl;
	InPutSP(y);
	NodeSP *psp = CreateNodeSP(y);
	PushSP(SSP,y);
}

//Hoadon
struct HD
{
	char TenSPB[30];
	int MaHD,GiaSPB,SoLuongSPB;
};

struct NodeHD
{
	HD infohd;
	NodeHD *nexthd;
};

struct StackHD
{
	NodeHD *TopHD;
};

void InitHD( StackHD &SHD )
{
	SHD.TopHD = NULL;
}

NodeHD *CreateNodeHD( HD z )
{
	NodeHD *phd = new NodeHD;
	if( phd == NULL )
		exit(1);
	phd -> infohd = z;
	phd -> nexthd = NULL;
	return phd;
}

//kiem tra hoa don rong
bool EmptyHD( StackHD SHD )
{
	if(SHD.TopHD == NULL)
		return true;
	else
		return false;	
}

//push hoa don
void PushHD( StackHD &SHD, HD z )
{
	NodeHD *phd = CreateNodeHD(z);
	if( EmptyHD(SHD) )
	{
		SHD.TopHD = phd;
	}
	else
	{
		phd -> nexthd = SHD.TopHD;
		SHD.TopHD = phd;
	}
}

//pop hoa don
void PopHD( StackHD &SHD )
{
	NodeHD *phd = SHD.TopHD;
	if( !EmptyHD(SHD) )
	{
		SHD.TopHD = phd -> nexthd;
		delete phd;
	}
	else
	{
		cout<<"\nDanh sach hoa don rong";
	}
}

void InPutHD( HD &z )
{
	cout<<"Nhap ma hoa don: "; cin>>z.MaHD;
	cout<<"Nhap ten san pham ban: "; fflush(stdin) ; gets(z.TenSPB) ;
	cout<<"Nhap so luong san pham: "; cin>>z.SoLuongSPB;
	cout<<"Nhap gia cua san pham: "; cin>>z.GiaSPB;
}

void NhapHD( StackHD &SHD)
{
	
}

void OutPutHD( HD z )
{
	
}

void XuatHD( StackHD SHD )
{
}

//menu
void menu()
{
	StackNL SNL;
	NodeNL *pnl;
	NL x;
	StackSP SSP;
	NodeSP *psp;
	SP y;
	int chon;
	do
	{
        system("cls");
		cout<<"\n----------------MENU----------------";
		cout<<"\n1. Nhap danh sach nguyen lieu";
		cout<<"\n2. Nhap danh sach san pham";
		cout<<"\n3. Them hoa don";
		cout<<"\n4. In danh sach nguyen lieu";
		cout<<"\n5. In danh sach san pham";
		cout<<"\n6. In danh sach hoa don";
		cout<<"\n7. Them mot nguyen lieu";
		cout<<"\n8. Them mot san pham";
		cout<<"\n9. Xoa mot nguyen lieu theo ma";
		cout<<"\n10. Xoa mot san pham theo ma";
		cout<<"\n11. Xoa mot hoa don theo ma";
		cout<<"\n12. Sap xep danh sach nguyen lieu theo thu tu bang chu cai";
		cout<<"\n13. Sap xep danh sach san pham theo thu tu bang chu cai";
		cout<<"\n14. Sap xep danh sach hoa don theo ma";
		cout<<"\n15. Tim nguyen lieu theo ma nguyen lieu";
		cout<<"\n16. Tim san phan theo ma san pham";
		cout<<"\n17. Tim hoa don theo ma hoa don";
		cout<<"\n18. Tinh tong tien cua hoa don";
		cout<<"\n19. Ghi file";
		cout<<"\n20. Doc file";
		cout<<"\nMoi ban chon: ";
        
		cin>>chon;
		switch( chon )
		{
			case 1:
				{
					system("cls");
					NhapNL(SNL);
					break;
				}	
			case 2:
				{
					system("cls");
					NhapSP(SSP);
					getch();
					break;
				}	
			case 3:
				{
					
					break;
				}	
			case 4:
				{
					system("cls");
					XuatNL(SNL);
					break;
				}	
			case 5:
				{
					system("cls");
					XuatSP(SSP);
					break;
				}	
			case 6:
				{
					
					break;
				}	
			case 7:
				{
					system("cls");
					ThemNL(SNL);
					break;
				}	
			case 8:
				{
					system("cls");
					ThemSP(SSP);
					break;
				}	
			case 9:
				{
					
					break;
				}	
			case 10:
				{
					
					break;
				}	
			case 11:
				{
					
					break;
				}	
			case 12:
				{
					
					break;
				}	
			case 13:
				{
					
					break;
				}	
			case 14:
				{
					
					break;
				}	
			case 15:
				{
					system("cls");
					SearchNL(SNL);
					break;
				}
			case 16:
				{
					
					break;
				}	
			case 17:
				{
					
					break;
				}	
			case 18:
				{
					
					break;
				}	
			case 19:
				{
					
					break;
				}	
			case 20:
				{
					
					break;
				}
			case 0: exit(1);
			default: cout<<"\nMoi ban nhap lai";	
		}
		
	}
	while ( chon != '0' );

}

int main()
{
	while(1)
	{
		menu();
		getch();
	}
}
