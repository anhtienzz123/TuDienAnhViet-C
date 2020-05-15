
void OSua()
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
void TextSua()
{
	textColor(148);
	gotoxy(48,3);
	printf("   ___   _    _    ___ ");
	gotoxy(48,4);
	printf("  /___%c | |  | |  /   %c",92,92);
	gotoxy(48,5);
	printf(" |___ %c|| |  | | /     %c",92,92);
	gotoxy(48,6);
	printf("    %c_%c | |  | || ____  |",92,92);
	gotoxy(48,7);	
	printf(" |%c__| || |__| || |   | |",92);
	gotoxy(48,8);
	printf("  %c___/  %c __ / |_|   |_|",92,92);
	
}

void NTCapNhat()
{
	textColor(148);
	gotoxy(20,14);
	printf("============================");
	gotoxy(20,15);
	printf("|NHAP TU:                   |");
	gotoxy(20,16);
	printf("|                           |");
	gotoxy(20,17);
	printf("============================");
	
}
void TBCapNhat()
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
void BangChonCapNhat()
{
	textColor(148);
	printf("\n                                    ________________________________________");
	printf("\n                                    |           ==> 1. TU VUNG <==         |");
	printf("\n                                    |______________________________________|");
	printf("\n                                    |           ==> 2. TU LOAI <==         |");
	printf("\n                                    |______________________________________|");
	printf("\n                                    |           ==> 3. NGHIA <==           |");
	printf("\n                                    |______________________________________|");
	printf("\n                                    |           ==> 4. VI DU <==           |");
	printf("\n                                    |______________________________________|");
	printf("\n                                    |           ==> 5. KET THUC <==        |");
	printf("\n                                    |______________________________________|");
	printf("\n                                     ======> MOI BAN NHAP LUA CHON: ");

						
}
void LCvaThoatCapNhat()
{
	textColor(148);
	for(int i = 0 ; i < 23 ; i++)
	{
		gotoxy(50+i,15);
		printf("%c",205);
	}
	gotoxy(50,16);
	printf("%c    THOAT: PHIM 0    %c",206,206,206);
		for(int i = 0 ; i < 23 ; i++)
	{
		gotoxy(50+i,17);
		printf("%c",205);
	}
}

void GiaoDienCapNhat()
{
	LCvaThoatCapNhat();
	NTCapNhat();
	TBCapNhat();
	OSua();
	TextSua();
}

