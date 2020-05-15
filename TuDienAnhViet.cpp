#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "GiaoDienChinh.h"
#include "GiaoDienTraTu.h"
#include "GiaoDienLichSu.h"
#include "GiaoDienXoa.h"
#include "GiaoDienCapNhat.h"
#include "GiaoDienThem.h"
#include "HamChucNang.h"


#define LH -1
#define EH 0
#define RH 1

struct NODEDS
{
	char data[1000];
	NODEDS *link;
};

typedef struct NODEDS NodeDS;


struct LIST
{
	NodeDS *pHead;
	NodeDS *pTail;
};

typedef struct LIST List;


struct Word
{
	char TuVung[100];
	char LoaiTu[20];
	List Nghia;
	List ViDu;
};

struct Node
{
	Word data;
	char balF;
	Node *left;
	Node *right;
	Node *link;
};

typedef Node *Tree;

struct LichSu
{
	Node *top;
};

// danh sach lien ket
void Init(List &l);
NodeDS* GetNode(char *value);
void AddTail(List &l, char *value);
void XoaMotNode(List &l, NodeDS *nodecanxoa);

//cay
Node *CreateNode(Word x);
void RotateLL(Tree &T);
void RotateRR(Tree &T);
void RotateLR(Tree &T);
void RotateRL(Tree &T);
int BalanceL(Tree &T);
int BalanceR(Tree &T);
int InsertNode(Tree &T, Word x);

void DiTimNodeTheMang(Tree &X, Tree &Y);
void XoaNodeTrenCay(Tree &T, char *key);

// Stack lich su
void InitStack(LichSu &s);
int Empty(LichSu s);
void Push(LichSu &s, Word x);
void XuatLichSu(LichSu s);

// doc ghi file
void DocFileVaoCay(Tree &T, FILE *file);
void DocCayVaoFile(Tree T, FILE *file);

// case 1: Tra Tu Dien
char TraTu(Tree T, LichSu &lichSu);

//case 2: Chuc nang Them
void Them(Tree &T);
int GetWord(Tree T,Word &word);

//case 3: Chuc nang Cap Nhat
void CapNhat(Tree &T);
void CapNhatDSLKTheoSo(List &l, int sothutu, char *key);

//case 4: Chuc nang Xoa
void Xoa(Tree &T);
void XoaDSLKDTheoSo(List &l, int sothutu);



int main ()
{
	Tree T = NULL;
	LichSu LichSu;
	InitStack(LichSu);
	
	// doc file ra cay
    FILE *fileRead = fopen("data.txt", "r");
    DocFileVaoCay(T, fileRead);
    fclose(fileRead);
    
	system("color 96");
	resizeConsole(900, 450);
	
	int choice;
	do{
		
		system("cls");
		resizeConsole(850, 450);
		GiaoDienChinh();
		gotoxy(64, 25);
		scanf("%d", &choice);
		
		
		switch(choice)
		{
			case 1:
			{
			   char key;
			   do{
				   system("cls");
				   GiaoDienTraTu();
				   key = TraTu(T, LichSu);
				}while(key== 9);
				break;
			}
			
			
			case 2:				
			{
			    system("cls");
				GiaoDienLichSu();
				XuatLichSu(LichSu);
				getch();
				break;	
			}
			
			case 3:
			{
				system("cls");
				Them(T);				
			    break;
			   
			}
				
			case 4:
			{
				system("cls");
				CapNhat(T);
				break;
			}
			
			case 5:
			{
				system("cls");
				Xoa(T);
				break;
			}
			
			default: break;
				  
		}
	}
	while(choice !=6);
   
   
   // doc cay vao file
   FILE *fileWrite = fopen("data.txt", "w");
   DocCayVaoFile(T,fileWrite);
   fclose(fileWrite);
}


void DocFileVaoCay(Tree &T, FILE *file)
{	
    // bien de ghi tung dong trong file vao
	char tempt[1000];
	// bien de them vao cay
	Word word;
	Init(word.Nghia);
	Init(word.ViDu);

	if (file == NULL)
	{
		printf("File khong mo dc\n");
		exit(1);
	}
	
	// doc vao cay
	while(fgets(tempt, 1000, file))// tempt se chua tung dong trong file
	{	
	    // kiem tra co phai la Tu vung
		if(strstr(tempt, "@"))// kiem tra  '@' co chua trong tempt khong 
		{
			if(strlen(word.TuVung)>0)
			   InsertNode(T, word);
			
			Init(word.Nghia);
			Init(word.ViDu);
			strcpy(word.TuVung, tempt);
		}
		else  if(strstr(tempt, "*"))// kiem tra co phai la Loai tu
		      {
		      	  strcpy(word.LoaiTu, tempt);
		      }
		      else if(strstr(tempt, "#"))// kiem tra co phai la vi du
			      {
			  	      AddTail(word.ViDu, tempt);
			      }
			      else 
			      {
			      	AddTail(word.Nghia, tempt);
				  }
	}
	InsertNode(T,word);

}

void DocCayVaoFile(Tree T, FILE *file)
{	
	if(T==NULL)
	  return;
	
	fprintf(file, T->data.TuVung);
	fprintf(file, T->data.LoaiTu);
	
	// doc danh sach NGHIA vao file
	NodeDS *nghia = T->data.Nghia.pHead;
	while(nghia!=NULL)
	{
		fprintf(file, nghia->data);
		nghia = nghia->link;
	}
	
	// doc danh sach VI DU vao file
	NodeDS *vidu = T->data.ViDu.pHead;
	while(vidu!=NULL)
	{
		fprintf(file, vidu->data);
		vidu = vidu->link;
	}
	
	DocCayVaoFile(T->left, file);
	DocCayVaoFile(T->right, file);
	
}


Node* TimKiemCay(Tree T, char *key)
{
	if(T==NULL)
	   return NULL;
	
	// T->data.TuVung co dang "@abc\n"
	// can bien s de xu li chuoi thanh "abc" de so sanh voi key
	char s[100];
	strcpy(s,T->data.TuVung);
	XoaKiTu(s,'@');
	XoaKiTu(s, '\n');
	
    if(stricmp(s,key)==0)
       return T;
            
    if(stricmp(s,key)>0)
       return TimKiemCay(T->left,key);
            
     return TimKiemCay(T->right,key);
}


void GoiYTu(Tree T, char *word, int &soTu)
{
	if(T!=NULL)
	{
		// chi cho phep goi y ra 20 tu
		if(soTu<=20)
		{
			// bien de xu li chuoi
			char tempt[100];
			strcpy(tempt,T->data.TuVung);
			XoaKiTu(tempt, '@');
			XoaKiTu(tempt, '\n');
			
			char *s;
			s=strstr(tempt,word);
			
			if(s!=NULL && stricmp(tempt,s)==0)
			{
				soTu++;
				gotoxy(4, 13+soTu);
				
				printf("%s\n", tempt);
			}
		}
		else
			return;
		GoiYTu(T->left, word, soTu);
		GoiYTu(T->right, word, soTu);
	}
}


// Tra tu dien
char TraTu(Tree T, LichSu &LichSu)
{
	// canh toa do
	int x= 10, y= 12;
    int m = x-6, n = y; 

	// tu vung de tim kiem
	char word[1000];
	// so luong tu trong word
	int dem=0;
	// bat su kien nhap vao
	int key;
	
	
	do{
		
		gotoxy(m, n);
		key = getch();
		
		if(key == 13) //Khi nhan nut Enter
		{
			// neu so tu == 0
			if(dem==0)
			{
			  	gotoxy(53,19);
			    printf("===> BAN CHUA NHAP TU NAO <===");
			    
			    gotoxy(53,20);
			    printf(".... VUI LONG NHAP TU VAO ....");
			    
			
			}
			else 
			{
				// tim kiem tu vung
				Node *p = TimKiemCay(T, word);
				
				if(p==NULL)
				{
					gotoxy(53,19);
			        printf("===> KHONG TIM THAY TU BAN CAN TIM <===");
			    
			        gotoxy(53,20);
			        printf(".... VUI LONG KIEM TRA LAI ....");
				}
				else // da tim duoc
				{
					// luu vao Stack LichSu
					Push(LichSu, p->data);
					
					// xuat loai tu
					gotoxy(53,12);
					char TemptLoaiTu[100];
					strcpy(TemptLoaiTu, p->data.LoaiTu);
					XoaKiTu(TemptLoaiTu, '*'); 	
   	                printf("%s",TemptLoaiTu);
   	                
   	                // xuat danh sach nghia
   	                int y=15,count=0;
   	                NodeDS *nghia = p->data.Nghia.pHead;
  	                while(nghia!=NULL)
   	                {  	               
					    gotoxy(51,y+count);  	
   	  	                printf("%s", nghia->data);
   	  	                nghia = nghia->link;
   	  	                count++;
	                }
	                 
	                // xuat danh sach vi du
	                gotoxy(44, y+count+3); 
	                printf("Vi du: ");
	                NodeDS *vidu = p->data.ViDu.pHead;
   	                while(vidu!=NULL)
   	                {
   	                	gotoxy(51, y+count+4);
   	                	char TemptViDu[100];
					    strcpy(TemptViDu, vidu->data);
					    XoaKiTu(TemptViDu, '#'); 	
   	  	                printf("%s", TemptViDu);
   	  	                vidu = vidu->link;
   	  	                count++;
	                }
				}
			}
		}	
			
        
		if( (key >= 97 && key <=122) || (key >=65 && key <= 90) || (key == 32) || (key == 39) || (key == 45) )
		{
				word[dem] = char(key);
				dem++;
				word[dem] = '\0';
				printf("%c", key);
				gotoxy(m++, n);
				XoaGoiY();
				XoaKetQuaTimKiem();
				int soTu=0;
				GoiYTu(T,word, soTu);
				
		}
		
		
		if(key == 8) //Khi nhan nut xoa, BackSpace
		{
				if(dem>0)
				{
					dem--;
					word[dem] = '\0';			
					gotoxy(--m, n);
					printf(" ");
					gotoxy(m, n);
					XoaGoiY();
					XoaKetQuaTimKiem();
					int soTu = 0;
					GoiYTu(T, word, soTu);
				}
				
					
				if(dem == 0)
				{	
						gotoxy(x-6, y+2);
						XoaGoiY();	
						XoaKetQuaTimKiem();
				}		
		}
				
   }while(key != 27 && key != 9); // 27: ESC, 9: Tab
   
	return key;

}


// THEM
void Them(Tree &T)
{
	int choice;
	do{
		system("cls");
		GiaoDienLuaChonThem();
		gotoxy(44,21);
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			{
				system("cls");
				resizeConsole(1100,700);
				GiaoDienThemTu();
				
				Word word;
				int kt = GetWord(T,word);
				if(kt == -1)
				{
				   gotoxy(13,20);
				   printf("===> TU DA TON TAI");
				   getch();
				}
				else InsertNode(T,word);
				
				break;
			}
			
			case 2:
			{		
			    
			    system("cls");
			    GiaoDienThemNghia();
			    char key[100];
	            Node *p;
	            
	            // Kiem tra tu nhap vao phai dung
	            do{
		             gotoxy(29,15);
		             printf("               ");
		             gotoxy(29,15);
	                 fflush(stdin);
	                 gets(key);
	                 if(stricmp(key, "0")==0)return;
	
	                 p = TimKiemCay(T, key);
	                 gotoxy(90,15);
	                 if(p==NULL)printf("TU KHONG TON TAI");
	                 else
	                 {
						gotoxy(90,15);
	    	            printf("TU TON TAI      ");
		             }
	    
	           }while(p==NULL);
				
				
				char NghiaThem[100], flag2;
			    int dem=0;
			    do{
			    	TextNhapTu(25,20+dem);
	
			    	gotoxy(38, 20+dem+1);
				    fflush(stdin);
				    gets(NghiaThem);
				    ThemKiTu(NghiaThem, '-', '\n');
				    AddTail(p->data.Nghia, NghiaThem);
				    
				    
				    gotoxy(35, 20+dem+4);
				    printf("===> NHAP TIEP NHAN PHIM 1: ");
				    scanf("%d", &flag2);
				    dem = dem+4;
				}while(flag2==1);
				break;		  			  
			}
			
			case 3:
			{
				system("cls");
			    GiaoDienThemViDu();
				char key[100];
	            Node *p;
	            
	            // Kiem tra tu nhap vao phai dung
	            do{
		             gotoxy(29,15);
		             printf("               ");
		             gotoxy(29,15);
	                 fflush(stdin);
	                 gets(key);
	                 if(stricmp(key, "0")==0)return;
	
	                 p = TimKiemCay(T, key);
	                 gotoxy(90,15);
	                 if(p==NULL)printf("TU KHONG TON TAI");
	                 else
	                {
						gotoxy(90,15);
	    	            printf("TU TON TAI      ");
		            }
	    
	            }while(p==NULL);
				
				
				char ViDuThem[100], flag3;
			    int dem=0;
			    do{
			    	TextNhapViDu(25,20+dem);
	
			    	gotoxy(38, 20+dem+1);
				    fflush(stdin);
				    gets(ViDuThem);
				    ThemKiTu(ViDuThem, '#', '\n');
				    AddTail(p->data.ViDu, ViDuThem);
				    
				    
				    gotoxy(35, 20+dem+4);
				    printf("===> NHAP TIEP NHAN PHIM 1: ");
				    scanf("%d", &flag3);
				    dem = dem+4;
				}while(flag3==1);
				break;		  	
			}
			
			default: break;	
		}
		
	}while(choice!=4);
}


int GetWord(Tree T,Word &word)
{
	Init(word.Nghia);
	Init(word.ViDu);
	
	gotoxy(12,18);
	fflush(stdin);
	gets(word.TuVung);
	
	
	Node *p = TimKiemCay(T,word.TuVung);
	// da tim thay nen bi trung, khong duoc them vao nua
	if(p != NULL)return -1;
	
	// nhap tu vung
	ThemKiTu(word.TuVung, '@', '\n');
	
	// nhap loai tu
	gotoxy(37,18);
	fflush(stdin);
	gets(word.LoaiTu);
	ThemKiTu(word.LoaiTu, '*', '\n');
	
	// nhap nghia
	int flag;
	char Nghia[100];
	int x=18, i=0;
	gotoxy(62,18);

	do{
		gotoxy(52, x+i);
		
		fflush(stdin);
		gets(Nghia);
		ThemKiTu(Nghia, '-', '\n');
		AddTail(word.Nghia, Nghia);
		
		i++;
		gotoxy(62,x+i);
		printf("Nhap nua nhan PHIM 1: ");
		scanf("%d",&flag);
		i++;
	}while(flag==1); 
	
	// nhap vi du
	char ViDu[100];
	i=0;
	gotoxy(86, 18);
	do{
		gotoxy(96, x+i);
		fflush(stdin);
		gets(ViDu);
		ThemKiTu(ViDu, '#', '\n');
		AddTail(word.ViDu, ViDu);
		
		i++;
		gotoxy(106, x+i);
		printf("Nhap nua nhan PHIM 1: ");
		scanf("%d",&flag);
		i++;
	}while(flag==1); 
	
	return 1;
	
}

// CAP NHAT
void CapNhat(Tree &T)
{
	char TuCanTim[100];
	Node *p;
	
	GiaoDienCapNhat();
	// Kiem tra tu nhap vao phai dung 
	do{
		gotoxy(29,15);
		printf("               ");
		gotoxy(29,15);
		
		
	    fflush(stdin);
	    gets(TuCanTim);
	
	    if(stricmp(TuCanTim, "0")==0)return;
	    
	    p = TimKiemCay(T, TuCanTim);
	    gotoxy(90,15);
	    if(p==NULL)printf("TU KHONG TON TAI");
	    else
	    {
	    	gotoxy(90,15);
	    	printf("TU TON TAI      ");
		}
	    
	}while(p==NULL);
	
	
	int choice;
	do{
		
		system("cls");
		BangChonCapNhat();
		scanf("%d",&choice);
		
		switch(choice)
		{
			
			case 1:
			{
				printf("\n                                    =====> NHAP TU VU THAY DOI: ");
				char KeyTuVung[100];
				fflush(stdin);
				gets(KeyTuVung);
				ThemKiTu(KeyTuVung, '@', '\n');
				strcpy(p->data.TuVung, KeyTuVung);
				break;
			}
			
			case 2:
			{
				printf("\n                                    =====> NHAP LOAI TU THAY DOI: ");
				char KeyLoaiTu[100];
				fflush(stdin);
				gets(KeyLoaiTu);
				ThemKiTu(KeyLoaiTu, '*', '\n');
				strcpy(p->data.LoaiTu, KeyLoaiTu);
				break;
			}
			
			case 3:
			{
				int choice3;
				do{
				    system("cls");
				    int dem=0;
				    int y=0;
				    KhungTextDanhSachNghia(30,3);
				    
				    NodeDS *nghia = p->data.Nghia.pHead;
				    
				    if(nghia == NULL)
				    {
				    	gotoxy(30, 6);
				    	printf("===> KHONG CO NGHIA NAO");
				    	getch();
				    	break;
					}
				    // xuat danh sach nghia
				    while(nghia!=NULL)
				    {
				    	dem++;
				    	
				    	char tempt[100];
				    	strcpy(tempt, nghia->data);
				    	XoaKiTu(tempt, '-');
				    	
				    	y=y+2;
						KhungTextInTu(30, 3+y);
				    	gotoxy(32,3+y+1);
				    	
				    	
				    	printf("%d) %s",dem,tempt);
					    nghia = nghia->link;
				    }
				    
				    
				    int SoCanSua;
				    do{
				    	gotoxy(30,3+y+3);
				    	printf("                                 ");
				    	gotoxy(30,3+y+3);
				    	
				    	
				    	printf("===> MOI NHAP LUA CHON CAN SUA: ");
				
				        scanf("%d",&SoCanSua);
					}while(SoCanSua < 1 || SoCanSua>dem);
				  
				    gotoxy(30,3+y+4);
				    printf("===> NHAP NGHIA MOI: ");
				    
				    char KeyNghia[100];
				    fflush(stdin); 
				    gets(KeyNghia);
				    ThemKiTu(KeyNghia,'-','\n');
				    
				    CapNhatDSLKTheoSo(p->data.Nghia, SoCanSua, KeyNghia);
				    
				    gotoxy(30,3+y+5);
				    printf("BAN CO MUON CAP NHAP TIEP HAY KHONG: 1) CO: ");
				    scanf("%d",&choice3);
				}while(choice3==1);
				
				break;
			}
			
			case 4:
			{
				int choice4;
				do{
					system("cls");
				    int dem=0;
				    int y=0;
				    KhungTextDanhSachViDu(30,3);
				    NodeDS *vidu = p->data.ViDu.pHead;
				    
				    if(vidu == NULL)
				    {
				    	gotoxy(30,6);
				    	printf("===> KHONG CO VI DU NAO");
				    	getch();
				    	break;
					}
				    
				    // xuat danh sach nghia
				    while(vidu!=NULL)
				    {
				    	dem++;
				    	char tempt[100];
				    	strcpy(tempt, vidu->data);
				    	XoaKiTu(tempt, '#');
				    	y=y+2;
						KhungTextInTu(30, 3+y);
				    	gotoxy(32,3+y+1);
				    	printf("%d) %s",dem,tempt);
					    vidu = vidu->link;
				    }
				    
				    
				    int SoCanSua;
				    do{
				    	gotoxy(30,3+y+3);
				    	printf("                                 ");
				    	gotoxy(30,3+y+3);
				    	printf("===> MOI NHAP LUA CHON CAN XOA: ");
				
				        scanf("%d",&SoCanSua);
					}while(SoCanSua < 1|| SoCanSua>dem);
				  
				    gotoxy(30,3+y+4);
				    printf("===> NHAP VI DU MOI: ");
				    char KeyViDu[100];
				    fflush(stdin);
				    gets(KeyViDu);
				    ThemKiTu(KeyViDu,'#','\n');
				    
				    CapNhatDSLKTheoSo(p->data.ViDu, SoCanSua, KeyViDu);
				    
				    gotoxy(30,3+y+5);
				    printf("BAN CO MUON CAP NHAT TIEP HAY KHONG: 1) CO: ");
				    scanf("%d",&choice4);
				}while(choice4==1);
				
				
				break;
			}
			
			default: break;
		}
	}while(choice!=5);
}

void CapNhatDSLKTheoSo(List &l, int sothutu, char *key)
{
	NodeDS *p = l.pHead;
	int dem=1;
	
	while(dem!=sothutu)
	{
		dem++;
		p = p->link;
	}
	strcpy(p->data, key);
}
// XOA
void Xoa(Tree &T)
{
	char key[100];
	Node *p;
	
	GiaoDienXoa();
	// Kiem tra tu nhap vao phai dung
	do{
		gotoxy(29,15);
		printf("               ");
		gotoxy(29,15);
	    fflush(stdin);
	    gets(key);
	    
	    if(stricmp(key, "0")==0)return;
	    
	    p = TimKiemCay(T, key);
	    gotoxy(90,15);
	    if(p==NULL)printf("TU KHONG TON TAI");
	    else
	    {
	    	gotoxy(90,15);
	    	printf("TU TON TAI      ");
		}
	    
	}while(p==NULL);
	
	int choice;
	do{
		system("cls");
		BangChonXoa();
		scanf("%d",&choice);
		switch(choice)
		{
					
			case 1:
			{
				XoaNodeTrenCay(T, p->data.TuVung);
				choice = 5;
				break;
			}
			case 2:
			{
				char loaitu[20] = "";
				ThemKiTu(loaitu, '*', '\n');
				strcpy(p->data.LoaiTu, loaitu);
				break;
			}
			
			case 3:
			{
				int choice3;
				do{
					system("cls");
				    int dem=0;
				    int y=0;
				    KhungTextDanhSachNghia(30,3);
				    NodeDS *nghia = p->data.Nghia.pHead;
				    
				    if(nghia == NULL)
				    {
				    	gotoxy(30,6);
				    	printf("===> KHONG CO NGHIA NAO");
				    	getch();
				    	break;
					}
				    // xuat danh sach nghia
				    while(nghia!=NULL)
				    {
				    	dem++;
				    	char tempt[100];
				    	strcpy(tempt, nghia->data);
				    	XoaKiTu(tempt, '-');
				    	y=y+2;
						KhungTextInTu(30, 3+y);
				    	gotoxy(32,3+y+1);
				    	printf("%d) %s",dem,tempt);
					    nghia = nghia->link;
				    }
				    
				    
				    int SoCanXoa;
				    do{
				    	gotoxy(30,3+y+3);
				    	printf("                                 ");
				    	gotoxy(30,3+y+3);
				    	printf("===> MOI NHAP LUA CHON CAN XOA: ");
				
				        scanf("%d",&SoCanXoa);
					}while(SoCanXoa < 1|| SoCanXoa>dem);
				  
				    XoaDSLKDTheoSo(p->data.Nghia, SoCanXoa);
				    
				    gotoxy(30,3+y+4);
				    printf("BAN CO MUON XOA TIEP HAY KHONG: 1) CO: ");
				    scanf("%d",&choice3);
				}while(choice3==1);
				
				break;
			}
			
			case 4:
			{
				int choice4;
				do{
					system("cls");
				    int dem=1;
				    int y=0;
				    KhungTextDanhSachViDu(30,3);
				    NodeDS *vidu = p->data.ViDu.pHead;
				    
				    if(vidu == NULL)
				    {
				    	gotoxy(30,6);
				    	printf("===> KHONG CO VI DU NAO");
				    	getch();
				    	break;
					}
				    
				    // xuat danh sach nghia
				    while(vidu!=NULL)
				    {
				    	char tempt[100];
				    	strcpy(tempt, vidu->data);
				    	XoaKiTu(tempt, '#');
				    	y=y+2;
						KhungTextInTu(30, 3+y);
				    	gotoxy(32,3+y+1);
				    	printf("%d) %s",dem,tempt);
				    	dem++;
					    vidu = vidu->link;
				    }
				    
				    
				    int SoCanXoa;
				    do{
				    	gotoxy(30,3+y+3);
				    	printf("                                 ");
				    	gotoxy(30,3+y+3);
				    	printf("===> MOI NHAP LUA CHON CAN XOA: ");
				
				        scanf("%d",&SoCanXoa);
					}while(SoCanXoa < 1|| SoCanXoa>dem);
				  
				    XoaDSLKDTheoSo(p->data.ViDu, SoCanXoa);
				    
				    gotoxy(30,3+y+4);
				    printf("BAN CO MUON XOA TIEP HAY KHONG: 1) CO: ");
				    scanf("%d",&choice4);
				}while(choice4==1);
				
				break;
			}
			
			default: break;
		}
	}while(choice!=5);
}


void XoaDSLKDTheoSo(List &l, int sothutu)
{
	NodeDS *p = l.pHead;
	int dem=1;
	
	while(dem!=sothutu)
	{
		dem++;
		p = p->link;
	}
	XoaMotNode(l, p);
	
}



// DANH SACH LIEN KET
void Init(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NodeDS* GetNode(char *data)
{
	NodeDS *p = new NodeDS;
	if(p==NULL)return NULL;
	strcpy(p->data, data);
	p->link = NULL;
	return p;
}

void AddTail(List &l, char *data)
{
	NodeDS *p = GetNode(data);
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		
	}
	else 
	{
		l.pTail->link = p;
		l.pTail = p;
	}
}

void XoaMotNode(List &l, NodeDS *nodecanxoa)
{
	if(l.pHead == nodecanxoa)
	{
		NodeDS *p = l.pHead;
	    l.pHead = l.pHead->link;
	    delete p;
	    return;
	}
	
	if(l.pTail == nodecanxoa)
	{
		NodeDS *p;
	    for(NodeDS *k = l.pHead; k!=NULL;k = k->link)
	    {
		   if(k == l.pTail)
          {
 	        l.pTail = p;
 	        l.pTail->link =NULL;
 	        delete k;
 	        return;
		   }
		   p = k;
	    }
	    return;
	}
	
	NodeDS *tam;
	for(NodeDS *p=l.pHead;p!=NULL;p=p->link)
	{
		if(p == nodecanxoa)
		{
			tam->link = p->link;
			delete p;
			return;
		}
		
		tam = p;
	}
}


// CAY NHI PHAN
Node *CreateNode(Word x)
{
	Node *p = new Node;
	if(p==NULL)
		return NULL;
	p->data = x;
	p->balF = EH;
	p->left = NULL;
	p->right = NULL;	
	return p;
}
//Quay don L-L
void RotateLL(Tree &T)
{
	Node *T1 = T->left;
 	T->left = T1->right;
 	T1->right = T;
 	switch(T1->balF)
 	{
 		case LH:
 			T->balF = EH;
 			T1->balF = EH; 
 			break;
 		case EH:
 			T->balF = LH;
 			T1->balF = RH;
 			break;
 	}
	T = T1;
}
//Quay don R-R
void RotateRR(Tree &T)
{
 	Node *T1=T->right;
 	T->right = T1->left;
 	T1->left = T;
 	switch(T1->balF)
 	{
 		case RH:
 			T->balF = EH;
 			T1->balF = EH;
 			break;
 		case EH:
 			T->balF = RH;
 			T1->balF = LH;
 			break;
 	}
 	T = T1;
}
//Quay kep L-R
void RotateLR(Tree &T)
{
 	Node *T1 = T->left;
 	Node *T2 = T1->right;
 	T->left = T2->right;
 	T2->right = T;
 	T1->right = T2->left;
 	T2->left = T1;
 	switch(T2->balF)
 	{
 		case LH:
 			T->balF = RH;
 			T1->balF = EH;
 			break;
 		case EH:
 			T->balF = EH;
 			T1->balF = EH;
 			break;
 		case RH:
 			T->balF = EH;
 			T1->balF = LH;
 			break;
 	}
 	T2->balF = EH;
 	T = T2;
}
//Quay kep R-L
void RotateRL(Tree &T)
{
 	Node *T1 = T->right;
 	Node *T2 = T1->left;
 	T->right = T2->left;
 	T2->left = T;
 	T1->left = T2->right;
 	T2->right = T1;
 	switch(T2->balF)
 	{
 		case RH:
 			T->balF = LH;
 			T1->balF = EH;
 			break;
 		case EH:
 			T->balF = EH;
 			T1->balF = EH;
 			break;
 		case LH:
 			T->balF = EH;
 			T1->balF = RH;
 			break;
 	}
 	T2->balF = EH;
 	T = T2;
}
//Can bang cay khi bi lech TRAI
int BalanceL(Tree &T)
{
 	Node *T1=T->left;
 	switch(T1->balF)
 	{
 		case LH:
 			RotateLL(T);
 			return 2;
 		case  EH:
 			RotateLL(T);
 			return 1;
 		case RH:
 			RotateLR(T);
 			return 2;
 	}
 	return 0;
}
//Can bang cay khi bi lech PHAI
int BalanceR(Tree &T)
{
 	Node *T1=T->right;
 	switch(T1->balF)
 	{
 		case LH:
 			RotateRL(T);
 			return 2;
 		case EH:
 			RotateRR(T);
 			return 1;
 		case RH:
 			RotateRR(T);
 			return 2;
 	}
 	return 0;
}

int InsertNode(Tree &T, Word x)
{
	int res;
	if(T==NULL)
	{ 
		T = CreateNode(x);
		if(T==NULL)
			return -1;
		return 2;
	}
	else 
	{
		if(stricmp(T->data.TuVung, x.TuVung) == 0)
			return 0; 
		else if(stricmp(T->data.TuVung, x.TuVung) > 0)
		{
			res = InsertNode(T->left,x);
			if(res < 2) 
				return res;
			switch(T->balF)
			{ 

				case RH:
 					T->balF = EH;
 					return 1;
 				case EH:
 					T->balF = LH;
 					return 2;
 				case LH:
 					BalanceL(T);
 					return 1;
			}
		}
		else if(stricmp(T->data.TuVung, x.TuVung)<0)
		{
			res = InsertNode(T->right,x);
			if(res<2)
				return res;
			switch(T->balF)
			{
				case LH:
 					T->balF = EH;
 					return 1;
 				case EH:
 					T->balF = RH;
 					return 2;
 				case RH:
 					BalanceR(T);
 					return 1;
			}
		}
	}
}

// xoa node tren cay
void DiTimNodeTheMang(Tree &X, Tree &Y) 
{
	if (Y->left != NULL)
	{
		DiTimNodeTheMang(X, Y->left);
	}
	else 
	{
		X->data = Y->data; 
		X = Y; 
		Y = Y->right;
	}
}

void XoaNodeTrenCay(Tree &T, char *key)
{
	if (T == NULL)
	{
		return; 
	}
	else
	{
		if (stricmp(T->data.TuVung, key)>0)
		{
			XoaNodeTrenCay(T->left, key); 
		}
		else if(stricmp(T->data.TuVung, key)<0)
		{
			XoaNodeTrenCay(T->right, key); 
		}
		else 
		{
			Node *X = T;
		
			if (T->left == NULL)
			{
				 T = T->right; 
			}
			else if (T->right == NULL)
			{
				
				T = T->left;
			}
			else 
			{	
				DiTimNodeTheMang(X, T->right);
			}
			delete X;
		}
	}
}

// LICH SU
void InitStack(LichSu &s)
{
	s.top=NULL;
}

int Empty(LichSu s)
{
	return s.top==NULL ? 1:0;
}

void Push(LichSu &s, Word x)
{
	Node *p= new Node;
	if(p!=NULL)
	{
		p->data=x;
		p->link=s.top;
		s.top=p;
	}
}

void XuatLichSu(LichSu s)
{
	int i=0;
	Node *t = s.top;
	
	for(Node* p=t; p!=NULL; p=p->link)
	{
		XoaKiTu(p->data.TuVung,'@');
		if(i<18)
		{
			gotoxy(7, 7+i);
			printf("%d: %s", i+1, p->data.TuVung);
		}
		i++;
	}
}
