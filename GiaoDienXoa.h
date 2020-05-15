
void OXoa()
{
	textColor(148);
	//Canh tren
		gotoxy(37, 2);
	for(int i=0; i<50; i++)
		printf("%c", 205);	
	//Canh duoi
	gotoxy(37, 10);
	for(int i=0; i<50; i++)
		printf("%c", 205);	
	//Canh trai
	gotoxy(37, 3);
	for(int i=0; i< 8; i++)
	{
		printf("%c", 206);
		gotoxy(37, 3+i);
	}
	//Canh phai
	gotoxy(86, 3);
	for(int i=0; i< 8; i++)
	{
		printf("%c", 206);
		gotoxy(86, 3+i);
	}	
}
void NT()
{
	textColor(148);
	gotoxy(20,14);
	printf("=========================");
	gotoxy(20,15);
	printf("|NHAP TU:               |");
	gotoxy(20,16);
	printf("|                       |");
	gotoxy(20,17);
	printf("=========================");
	
}
void TB()
{
	textColor(148);
	gotoxy(78,14);
	printf("==============================");
	gotoxy(78,15);
	printf("|THONG BAO:                   |");
	gotoxy(78,16);
	printf("|                             |");
	gotoxy(78,17);
	printf("==============================");
	
}
void BangChonXoa()
{
	textColor(148);
	printf("\n                                    ________________________________________");
	printf("\n                                    |           ==> 1. TU VUNG <==         |");
	printf("\n                                    |______________________________________|");
	printf("\n                                    |           ==> 2. TU LOAI <==         |");
	printf("\n                                    |______________________________________|");
	printf("\n                                    |           ==> 3. NGHIA   <==         |");
	printf("\n                                    |______________________________________|");
	printf("\n                                    |           ==> 4. VI DU   <==         |");
	printf("\n                                    |______________________________________|");
	printf("\n                                    |           ==> 5. THOAT   <==         |");
	printf("\n                                    |______________________________________|");
	printf("\n                                     ======> MOI BAN NHAP LUA CHON: ");
						
}
void LCvaThoat()
{
	textColor(148);
	for(int i = 0 ; i < 23 ; i++)
	{
		gotoxy(50+i,15);
		printf("%c",205);
	}
	gotoxy(50,16);
	printf("%c lC :     %c THOAT:ESC%c",206,206,206);
		for(int i = 0 ; i < 23 ; i++)
	{
		gotoxy(50+i,17);
		printf("%c",205);
	}
}
void TextXoa()
{
	textColor(148);
	gotoxy(48,3);
	printf(" __  __   ____     ____ ");
	gotoxy(48,4);
	printf("|  %c/  | /    %c   /    %c  ",92,92,92);
	gotoxy(48,5);
	printf(" %c    / |  __  | /      %c ",92,92);
	gotoxy(48,6);
	printf("  %c  /  | |  | ||        | ",92);
	gotoxy(48,7);
	printf("  /  %c  | |__| ||   __   |",92);
	gotoxy(48,8);
	printf(" /    %c |      ||  /  %c  | ",92,92);
	gotoxy(48,9);
	printf("|__/%c__| %c____/ |_|    |_| ",92,92);
}

void GiaoDienXoa()
{
	LCvaThoat();
	NT();
	TB();
	OXoa();
	TextXoa();
}

void KhungTextDanhSachNghia(int x, int y)
{
	gotoxy(x,y);
	printf("-------------------------------------------------------");
	gotoxy(x,y+1);
	printf("|                    DANH SACH NGHIA                  |");
	gotoxy(x,y+2);
	printf("-------------------------------------------------------");
}

void KhungTextDanhSachViDu(int x, int y)
{
	gotoxy(x,y);
	printf("-------------------------------------------------------");
	gotoxy(x,y+1);
	printf("|                    DANH SACH VI DU                   |");
	gotoxy(x,y+2);
	printf("-------------------------------------------------------");
}

void KhungTextInTu(int x, int y)
{
   gotoxy(x,y);
   printf("=======================================================");
   gotoxy(x,y+1);
   printf("|                                                     |");
   gotoxy(x,y+2);
   printf("=======================================================");
}


