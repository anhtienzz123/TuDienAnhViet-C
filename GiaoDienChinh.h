void ancontro()
{
	 CONSOLE_CURSOR_INFO Info;
	 Info.bVisible = FALSE;
	 Info.dwSize = 20;
	 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

//Hien thi con tro tren console
void hiencontro()
{
	 CONSOLE_CURSOR_INFO Info;
	 Info.bVisible = TRUE;
	 Info.dwSize = 20;
	 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//Ham thay doi kich thuoc cua khung cmd/console
void resizeConsole (int width, int height)
{
     HWND console = GetConsoleWindow();
     RECT r;
     GetWindowRect(console, &r);
     MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//Ham to mau chu trong console
void textColor(int x)
{
     HANDLE color;
     color = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(color, x);
}

//Ham dich chuyen con tro den tai vi tri toa do (x, y)
void gotoxy(int x, int y)
{
     HANDLE hConsoleOutput;
     COORD Cursor_an_Pos = {x-1, y-1};
     hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//Ham xoa man hinh Console
void xoaManHinh()
{
     HANDLE hout;
     COORD Position;
     hout = GetStdHandle(STD_OUTPUT_HANDLE);
     Position.X = 0;
     Position.Y = 0;
     SetConsoleCursorPosition(hout, Position);
}

void textT()
{
	textColor(148);
	gotoxy(34,1);
	printf("  ______");
	gotoxy(34,2);
	printf(" |_    _|");
	gotoxy(34,3);
	printf("   |  |");
	gotoxy(34,4);
	printf("   |  |");
	gotoxy(34,5);
	printf("   |  |");
	gotoxy(34,6);
	printf("   |__|");
}

void textU()
{
	textColor(148);
	gotoxy(43,1);
    printf(" _   _");
    gotoxy(43,2);
    printf("| | | |");
    gotoxy(43,3);
    printf("| | | |");
    gotoxy(43,4);
    printf("| | | |");
    gotoxy(43,5);
    printf("| |_| |");
    gotoxy(44,6);
    printf("%c___/ ",92);
   
}
void textD()
{
	textColor(148);
	 gotoxy(54,1);
	printf(" _____");
	 gotoxy(54,2);
	printf("|  __ %c",92);
	 gotoxy(54,3);
	printf("| |  %c |",92);
	gotoxy(54,4);
	printf("| |  | |",92);
	 gotoxy(54,5);
	printf("| |__/ |");
	 gotoxy(54,6);
	printf("|_____/");
}
void textI()
{
	textColor(148);
	gotoxy(62,1);
	printf(" __");
	gotoxy(62,2);
	printf("|  |");
	gotoxy(62,3);
	printf("|  |");
	gotoxy(62,4);
	printf("|  |");
	gotoxy(62,5);
	printf("|  |");
	gotoxy(62,6);
	printf("|__|");
}
void textE()
{
	textColor(148);
	gotoxy(66,1);
	printf(" ____");
	gotoxy(66,2);
	printf("| ___|");
	gotoxy(66,3);
	printf("| |__");
	gotoxy(66,4);
	printf("| |__|");
	gotoxy(66,5);
	printf("| |__");
	gotoxy(66,6);
	printf("|____|");
	
	
}
void textN()
{
	textColor(148);
	gotoxy(72,1);
	printf(" _   _");
	gotoxy(72,2);
	printf("| %c | |",92);
	gotoxy(72,3);
	printf("|  %c| |",92);
	gotoxy(72,4);
	printf("| |%c  |",92);
	gotoxy(72,5);
	printf("| | %c |",92);
	gotoxy(72,6);
	printf("|_| |_|",92);
}

void TextTuDien()
{
	textT();
	textU();
	textD();
	textI();
	textE();
	textN();
}

//Khung text
void khungText()
{
	textColor(158);
	//TREN TRAI
	//Canh tren
	gotoxy(12, 7);
	for(int i=0; i<40; i++)
		printf("%c", 205);	
	//Canh duoi
	gotoxy(12, 15);
	for(int i=0; i<32; i++)
		printf("%c", 205);	
	//Canh trai
	gotoxy(14, 8);
	for(int i=0; i< 8; i++)
	{
		printf("%c", 206);
		gotoxy(14, 8+i);
	}
	//Canh phai
	gotoxy(49, 8);
	for(int i=0; i< 7; i++)
	{
		printf("%c", 206);
		gotoxy(49, 8+i);
	}	
	
	//TREN PHAI
	//Canh tren
	gotoxy(54, 7);
	for(int i=0; i<40; i++)
		printf("%c", 205);	
	//Canh duoi
	gotoxy(63, 15);
	for(int i=0; i<31; i++)
		printf("%c", 205);	
	//Canh trai
	gotoxy(56, 8);
	for(int i=0; i< 7; i++)
	{
		printf("%c", 206);
		gotoxy(56, 8+i);
	}
	//Canh phai
	gotoxy(91, 8);
	for(int i=0; i< 8; i++)
	{
		printf("%c", 206);
		gotoxy(91, 8+i);
	}
	
	//DUOI TRAI
	//Canh tren
	gotoxy(12, 16);
	for(int i=0; i<32; i++)
		printf("%c", 205);	
	//Canh duoi
	gotoxy(12, 24);
	for(int i=0; i<40; i++)
		printf("%c", 205);	
	//Canh trai
	gotoxy(14, 17);
	for(int i=0; i< 8; i++)
	{
		printf("%c", 206);
		gotoxy(14, 17+i);
	}
	//Canh phai
	gotoxy(49, 18);
	for(int i=0; i< 7; i++)
	{
		printf("%c", 206);
		gotoxy(49, 18+i);
	}		
	
	//DUOI PHAI
	//Canh tren
	gotoxy(63, 16);
	for(int i=0; i<31; i++)
		printf("%c", 205);	
	//Canh duoi
	gotoxy(54, 24);
	for(int i=0; i<40; i++)
		printf("%c", 205);	
	//Canh trai
	gotoxy(56, 18);
	for(int i=0; i< 7; i++)
	{
		printf("%c", 206);
		gotoxy(56, 18+i);
	}
	//Canh phai
	gotoxy(91, 17);
	for(int i=0; i< 8; i++)
	{
		printf("%c", 206);
		gotoxy(91, 17+i);
	}		
	
	//GIUA
	//Canh tren
	gotoxy(44, 13);
	for(int i=0; i<18; i++)
		printf("%c", 205);
	//Canh duoi
	gotoxy(44, 18);
	for(int i=0; i<18; i++)
		printf("%c", 205);
	
	//Canh trai
	gotoxy(43, 14);
	for(int i=0; i<=4; i++)
	{
		printf("%c", 186);
		gotoxy(43, 14+i);
	}
	//Canh phai
	gotoxy(62, 14);
	for(int i=0; i<=4; i++)
	{
		printf("%c", 186);
		gotoxy(62, 14+i);
	}
	
	gotoxy(43, 13);
	printf("%c", 201);
	
	gotoxy(43, 18);
	printf("%c", 200);
	
	gotoxy(62, 13);
	printf("%c", 187);
	
	gotoxy(62, 18);
	printf("%c", 188);
	

}

void InsertText()
{
	textColor(148);
	gotoxy(47, 15);
	printf("XOA TU");
	
	
	gotoxy(26, 11);
	printf("TRA TU DIEN");
	
	gotoxy(68, 11);
	printf("LICH SU TRA TU");
	
	gotoxy(28, 19);
	printf("THEM TU");
	
	gotoxy(66, 19);
	printf("CAP NHAT TU");
}
void KEY()
{
	textColor(158);	
	gotoxy(26, 12);
	printf("==>PHIM 1<==");
	
	gotoxy(68, 12);
	printf("==>PHIM 2<==");
	
	gotoxy(26, 20);
	printf("==>PHIM 3<==");
	
	gotoxy(68, 20);
	printf("==>PHIM 4<==");
	
	gotoxy(47, 16);
	printf("==>PHIM 5<==");
}

//mainGiaoDien2
void GiaoDienChinh()
{
	hiencontro();
	TextTuDien();
	khungText();
	InsertText();
	KEY();
	gotoxy(33, 25);
	printf("LUA CHON YEU CAU(6: KET THUC): ");
}
