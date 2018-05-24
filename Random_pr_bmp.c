#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef unsigned short int WORD;
typedef unsigned long int DWORD;
typedef long int LONG;
typedef char BYTE;
#pragma  pack(push,1)

typedef struct tagBITMAPFILEHEADER {
      WORD    bfType;
      DWORD   bfSize;
      WORD    bfReserved1;
      WORD    bfReserved2;
      DWORD   bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagRGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} RGBTRIPLE;
#pragma pack(pop)
void Take_size(char* name, int* h, int* w) {
  FILE * f1;
  BITMAPFILEHEADER BFH;
  BITMAPINFOHEADER BIH;

  f1 = fopen(name, "rb");
  fread(&BFH,sizeof(BFH),1,f1);
  fread(&BIH,sizeof(BIH),1,f1);
  *h = BIH.biHeight;
  *w = BIH.biWidth;
  fclose(f1);
}

int N;

int main()
{
    srand((unsigned int)clock());
    FILE *f1, *f2;
    scanf("%d",&N);

    BITMAPFILEHEADER BFH;
    BITMAPINFOHEADER BIH;
    RGBTRIPLE RGB;
    char name[] = "test.bmp";
    f1 = fopen(name, "rb");
    f2 = fopen("new.bmp", "wb");

    fread(&BFH,sizeof(BFH),1,f1);
    fwrite(&BFH, sizeof(BFH), 1, f2);

    fread(&BIH,sizeof(BIH),1,f1);
    fwrite(&BIH, sizeof(BIH), 1, f2);

    int heig, wid;
    Take_size(name, &heig, &wid);

    int a[N][5];
    for (int i=0;i<N;i++)
    {
        a[i][0] = rand() % (heig-200);
        a[i][1] = rand() % (wid-200);
        a[i][2] = (rand() %60) + 40; //h
        a[i][3] = (rand() %60) + 40; //w
       // printf("%d %d %d %d\n",a[i][0],a[i][1],a[i][2],a[i][3] );
    }

    size_t padding = 0;
    if (wid % 4)
    {
		padding = 4 - (wid * 3) % 4;
    }
    int k=0;
  //  int flag =0;
    for( int i=0; i < heig ;i++)
    {
        for (int j = 0; j < wid; j++)
        {
            fread(&RGB, sizeof(RGB),1, f1);
            for (k=0;k<N;k++)
                if ((i>=a[k][0]) && (i<= a[k][0]+a[k][2]) && (j>=a[k][1]) && (j<=a[k][3]+a[k][1]) )
                {
                    RGB.rgbtBlue=((k+30)*50) % 255;
                    RGB.rgbtGreen=((k+10)*10) % 255;
                    RGB.rgbtRed=((k+20)*40) % 255;
                }
            fwrite(&RGB, sizeof(RGB), 1, f2);

        }
        if(padding)
        {
            fread(&RGB, padding,1, f1);
            fwrite(&RGB, padding, 1, f2);
	    }
    }
    fclose(f1);
    fclose(f2);



    return 0;
}
