#include<windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm")
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>                   
#define WIDTH 320 //���
#define HIGHT 103 //�߶�
#define PAGE_LIMIT 1694         //֡��
#define N HIGHT*WIDTH           //�ַ���
//������
char name[]="ASCII-1 0001.txt";
char str[N];
int main()
{
      system("pause");//�ȴ��û��źţ�
      int i,j,n=1,p,q;
      char a[4]="000";
      //֡����
	  PlaySound(TEXT("165214.WAV"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);
      for(i=1;i<=PAGE_LIMIT;i++)
      {
            //ʱ���ᶨλ
            for(p=10,q=0;q<4;q++)
            {
                  if(i<10&&q==1)break;
                  else if(i<100&&q==2)break;
                  else if(i<1000&&q==3)break;
                  else
                  {
                       a[q]=i%p/(p/10)+48;
                       p*=10; 
                  }
            }
            //������
            for(p=0;p<q;p++)
                  name[11-p]=a[p];
            FILE *fp;
            //���ı�
            if((fp=fopen(name,"r"))==NULL)  
            {
                  printf("%d",i);
                  system("pause");
                  continue;
            }
            //��ȡ�ı�
            while(fgets(str,N ,fp)!=NULL)
                  printf("%s",str);
            //�ر��ı�
            fclose(fp);
            system("cls");//����
      }
      system("pause");//�ȴ��û��ź�
      return 0;
}