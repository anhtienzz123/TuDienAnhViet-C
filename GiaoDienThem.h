
void Them()
{
	textColor(148);
	gotoxy(44,3);
	printf("  ______  _   _  ____   _    _");
	gotoxy(44,4);
	printf(" |_    _|| | | || ___| | %c  / |",92);
	gotoxy(44,5);
	printf("   |  |  | |_| || |__  |  %c/  |",92);
	gotoxy(44,6);
	printf("   |  |  |  _  || |__| |      |");
	gotoxy(44,7);
	printf("   |  |  | | | || |__  | |%c/| |",92);
	gotoxy(45,8);
	printf ("  |__|  |_| |_||____| |_|  |_|");
}
void Othem()
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
void Ochucnang()
{
	textColor(148);
	gotoxy(10,14);
	printf("==================================================================================================================================");//12
	for(int i = 0 ; i < 30 ; i ++)
	{
		gotoxy(10,15+i);
		printf("|                        |              |                                            |                                           |");
		if(i == 2)
		{
			gotoxy(10,15+i);
			printf("=================================================================================================================================");
		}
		if(i == 29)
		{
			gotoxy(10,15+i);
			printf("==============================================================================================================================");
		}
	}
	
	
	
}
void PhimESC()
{
	textColor(148);
	gotoxy(41,12);
	printf(" ==================");
	printf("|THOAT : Phim 0   |");
	printf(" ==================");
}
void Phimtat()
{
	textColor(148);
	gotoxy(16,15);
	printf("TU MUON THEM");
	gotoxy(38,15);
	printf("TU LOAI");
	gotoxy(70,15);
	printf("NGHIA");
	gotoxy(95,15);
	printf("VI DU");
}


void GiaoDienThemTu()
{
	system("color 96");
	Them();
	Othem();
	Ochucnang();
	Phimtat();	
}



//
void CapNhat()
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

void Ochucnang1()
{
	textColor(148);
	gotoxy(28,14);
	printf("----------------------------------------------------------------");
	gotoxy(28,15);
	printf("|                    |                    |                    |");
	gotoxy(28,16);
	printf("|                    |                    |                    |");
	gotoxy(28,17);
	printf("|                    |                    |                    |");
	gotoxy(28,18);
	printf("----------------------------------------------------------------");
	
	
}

void PhimTat1()
{
	textColor(148);
	gotoxy(30,16);
	printf("1. THEM TU MOI");
	gotoxy(51,16);
	printf("2. THEM NGHIA");
	gotoxy(73,16);
	printf("3. THEM VI DU");
	gotoxy(34,21);
	printf("LUA CHON: ");
	gotoxy(74,21);
	printf("THOAT: 4");
	
}


void Othuoat()
{
	textColor(148);
	gotoxy(33,20);
	printf("==============");
	gotoxy(33,21);
	printf("|            |");
	gotoxy(33,22);
	printf("==============");
}
void Onhap()
{
	textColor(148);
	gotoxy(73,20);
	printf("==============");
	gotoxy(73,21);
	printf("|            |");
	gotoxy(73,22);
	printf("==============");
}
void GiaoDienLuaChonThem()
{
	resizeConsole(850, 470);
	CapNhat();
	Ochucnang1();
	Othuoat();
	Onhap();
	Them();
	PhimTat1();
}


//
void NTThem()
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
void TBThem()
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

void TextNhapTu(int x, int y)
{
	gotoxy(x,y);
	printf("========================================\n");
	gotoxy(x,y+1);
	printf("|NHAP NGHIA:                            |\n");
	gotoxy(x,y+2);
	printf("|                                       |\n");
	gotoxy(x,y+3);
	printf("========================================\n");
}

void TextNhapViDu(int x, int y)
{
	gotoxy(x,y);
	printf("========================================\n");
	gotoxy(x,y+1);
	printf("|NHAP VI DU:                            |\n");
	gotoxy(x,y+2);
	printf("|                                       |\n");
	gotoxy(x,y+3);
	printf("========================================\n");
}

void GiaoDienThemNghia()
{
	NTThem();
	PhimESC();
	TBThem();
}

void GiaoDienThemViDu()
{
	NTThem();
	PhimESC();
	TBThem();
}



