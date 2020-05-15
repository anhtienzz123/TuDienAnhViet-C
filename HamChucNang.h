void ThemKiTu(char *chuoi, char dau, char cuoi)
{
	int n = strlen(chuoi);
	n++;
    for(int i=n;i>0;i--)
    {
        chuoi[i] = chuoi[i-1];
    }
    chuoi[0] = dau;
    chuoi[n] = cuoi;
    chuoi[n+1] = '\0'; 
}

void XoaKiTu(char *chuoi, char kiTu)
{
    int n = strlen(chuoi);
    for(int i=0;i<n;i++)
    {
        if(chuoi[i]==kiTu)
        {
            for(int j=i; j<n;j++)
                chuoi[j]=chuoi[j+1];
            break;
        }	
    }
}

void XoaGoiY()
{
	int k=0;
	int x= 10, y= 12;
	int a = x -6;
	int b = y +2;
	for(int i= 0; i< 21; i++)
	{
		gotoxy(a, b+k);
		for(int j = 0; j< 38; j++)
			printf(" ");
		k++;
	}
}


void XoaKetQuaTimKiem()
{
	int x= 10, y= 12;
	int a = x+34;
	int b = y+3;
	for(int i=0; i< 20; i++)
	{
		gotoxy(a, b+i);
		for(int j = 0; j < 57;j++)
			printf(" ");
	}
	for(int i=0; i< 49; i++)
	{
		gotoxy(52+ i, 12);
		printf(" ");
	}
	for(int i=0; i< 50; i++)
	{
		gotoxy(51+ i, 14);
		printf(" ");
	}
}
