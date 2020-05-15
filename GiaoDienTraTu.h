
void TieuDeTraTu();	
void KhungTraTu();
void Cuoi();





void TextT()
{

    gotoxy(30, 1);
	printf(" _____ \n");
	gotoxy(30, 2);
	printf("|_   _|\n");
	gotoxy(30, 3);
	printf("  | |\n");
	gotoxy(30, 4);
	printf("  | |\n");
	gotoxy(30, 5);
	printf("  |_|\n");
}

void TextR()
{

    gotoxy(37, 1);
	printf(" ____ \n");
	gotoxy(37, 2);
	printf("|  _  \\  \n");
	gotoxy(37, 3);
	printf("| |_) / \n");
	gotoxy(37, 4);
	printf("|  _ <\n");
	gotoxy(37, 5);
	printf("|_| \\|\n");
}

void TextA()
{

    gotoxy(44, 1);
	printf("    _\n",92);
	gotoxy(44, 2);
	printf("   / %c\n",92);
	gotoxy(44, 3);
	printf("  / _ %c\n",92);
	gotoxy(44, 4);
	printf(" / _ _ %c\n",92);
	gotoxy(44, 5);
	printf("/_/   %c_%c\n",92,92);
}

void TextT1()
{

    gotoxy(55, 1);
	printf(" _____ \n");
	gotoxy(55, 2);
	printf("|_   _|\n");
	gotoxy(55, 3);
	printf("  | |\n");
	gotoxy(55, 4);
	printf("  | |\n");
	gotoxy(55, 5);
	printf("  |_|\n");
}

void TextU()
{
	gotoxy(62, 1);
	printf(" _   _\n");
	gotoxy(62, 2);
	printf("| | | |\n");
	gotoxy(62, 3);
	printf("| | | |\n");
	gotoxy(62, 4);
	printf("| |_| |\n");
	gotoxy(62, 5);
	printf("|_____|\n");
}


void TieuDeTraTu()
{
   textColor(145);
   TextT();
   TextR();
   TextA();
   TextT1();
   TextU();
}


void KhungTraTu()
{
	textColor(145);
	//Tren
	gotoxy(3, 8);
	for(int i=0; i<98; i++)
		printf("%c", 205);
	//Duoi	
	gotoxy(3, 35);
	for(int i=0; i<98; i++)
		printf("%c", 205);
	//Trai
	gotoxy(2, 9);
	for(int i=0; i<27; i++){
		printf("%c", 186);
		gotoxy(2, 9+i);
	}
	//Phai
	gotoxy(101, 9);
	for(int i=0; i<27; i++)
	{
		printf("%c", 186);
		gotoxy(101, 9+i);
	}
	//Ngang giua
	gotoxy(3, 11);
	for(int i=0; i<98; i++)
		printf("%c", 205);
	//Doc giua
	gotoxy(42, 9);
	for(int i=0; i<27; i++)
	{
		printf("%c", 186);
		gotoxy(42, 9+i);
	}
	//Ngang duoi giua 
	gotoxy(3, 13);
	for(int i=0; i<98; i++)
		printf("%c", 205);
	gotoxy(42, 13);
	printf("%c", 206);
	gotoxy(101, 13);
	printf("%c", 185);
	gotoxy(2, 13);
	printf("%c", 204);
	//Goc duoi
	gotoxy(2, 35);
	printf("%c", 200);
	gotoxy(42, 35);
	printf("%c", 202);
	gotoxy(101, 35);
	printf("%c", 188);
	//Goc giua
	gotoxy(2, 11);
	printf("%c", 204);
	gotoxy(42, 11);
	printf("%c", 206);
	gotoxy(101, 11);
	printf("%c", 185);
	//Goc tren
	gotoxy(2, 8);
	printf("%c", 201);
	gotoxy(42, 8);
	printf("%c", 203);
	gotoxy(101, 8);
	printf("%c", 187);	
}

//Text
void Cuoi()
{
	textColor(148);
	gotoxy(19, 9);
	printf("ANH NGU");
	gotoxy(13, 10);
	printf("======ENGLISH=====");
	
	gotoxy(68, 9);
	printf("VIET NGU");
	gotoxy(62, 10);
	printf("=====VIETNAMESE=====");
	
	gotoxy(44, 12);
	printf("Tu Loai:	");
	gotoxy(44, 14);
	printf("Nghia: ");
	
	textColor(144);
	gotoxy(3, 37);
	printf("Nhap tu tieng Anh ma ban muon dich nghia");
	gotoxy(51, 37);
	printf("Nhan phim TAB de tiep tuc tra tu");
	
	gotoxy(91, 37);
	printf("ESC - Exit");
}

void GiaoDienTraTu()
{
	resizeConsole(850, 650);
	hiencontro();
	TieuDeTraTu();
	KhungTraTu();
	Cuoi();
}




