 
void history();
void khungTextCacTuDaTra();
void textLichSu();


//Text lich su
void history()
{
     textColor(148);
     gotoxy(56, 8);
	 printf("\t       __    __   __       _______ \n");
     gotoxy(56, 9);
     printf("\t      |  |  |  | |  |     /       |\n");
     gotoxy(56, 10);
     printf("\t      |  |__|  | |  |    |   (----'\n");
     gotoxy(56, 11);
     printf("\t      |   __   | |  |     %c   %c    \n", 92, 92);
     gotoxy(56, 12);
     printf("\t      |  |  |  | |  | .----)   |   \n");
     gotoxy(56, 13);
     printf("\t      |__|  |__| |__| |_______/    \n");
     gotoxy(53, 14);
     printf(" ___________   ______    ______     ____    ____\n");
     gotoxy(53, 15);
     printf("|           | /  __  %c  |   _  %c    %c   %c  /   /\n", 92, 92, 92, 92);
     gotoxy(53, 16);
     printf("`---|  |----'|  |  |  | |  |_)  |    %c   %c/   / \n", 92, 92);
     gotoxy(53, 17);
     printf("    |  |     |  |  |  | |      /      %c_    _/  \n", 92);
     gotoxy(53, 18);
     printf("    |  |     |  `--'  | |  |%c  %c----.   |  |    \n", 92, 92);
     gotoxy(53, 19);
     printf("    |__|      %c______/  | _| `._____|   |__|    \n", 92);

}

//khung text
void khungTextCacTuDaTra()
{
     //tren
     gotoxy(5, 4);
     for(int i=0; i< 45; i++)
          printf("%c", 254);
     //duoi
     gotoxy(5, 25);
     for(int i=0; i< 45; i++)
          printf("%c", 254);
     //trai
     gotoxy(5, 5);
     for(int i=0; i<21; i++)
     {
          printf("%c", 219);
          gotoxy(5, 5+i);
     }
     //phai
     gotoxy(49, 5);
     for(int i=0; i<21; i++)
     {
          printf("%c", 219);
          gotoxy(49, 5+i);
     }
     //Giua
     gotoxy(7, 6);
     for(int i=0; i< 41; i++)
          printf("%c", 254);
}

//Text
void textLichSu()
{
     gotoxy(16, 5);
     printf("DANH SACH CAC TU VUA TRA\n");

     gotoxy(40, 26);
     printf("ESC - Exit");
     //getch();
}

void GiaoDienLichSu()
{
	resizeConsole(850, 450);
	hiencontro();
	history();
	khungTextCacTuDaTra();
	textLichSu();
}

