//FURKAN KARA�ALI 02200201005 1.��RET�M
#include<stdio.h>

int opernok(char a){//gelen char operatorm� veya noktalamam� kontrol� yap�yor
	if(a=='+' || a=='-' || a=='*' || a=='/' || a=='<' || a=='>'|| a=='=' || a=='('
	|| a==')' || a=='[' || a==']' || a=='{' || a=='}' || a==';' || a==',' || a=='"' || a=='!' || a=='&' || a=='|' || a=='%' || a=='#'){
		return 1;
	}
	return 0;
}

int harfmi(char c){//gelen char harfmi
	if(c>='A' && c<='Z' || c>='a' && c<='z'){
		return 1;
	}
	return 0;
}




int main(){
	
	char veri[1000];
	
	char kelime;
	
	int i=0,j=0,s=0,a;//s dosyadan gelen verinin karakter boyutudur
	
	char d_yolu[100];
	DONGU:
	printf("Dosya yolu girin:");
	scanf("%s",&d_yolu);
	
	FILE *dosya;
	
	dosya=fopen(d_yolu,"r");
	
	if(dosya==NULL){
		printf("Dosya bulunamadi\n");
		printf("Tekrar giriniz\n");
		goto DONGU;	//burada dosya ismi yanl�� girildi�inde DONGU etiketine y�nlendirme sa�lad�m.	
	}
	do{
	
		kelime= fgetc(dosya);//bu d�ng�de dosyadan gelen her karakter kontrol ediliyor,bo�luk veya tab veya entersa diziye at�lm�yor
		if((int)kelime!=32 && (int)kelime!=9 && (int)kelime!=10){
			veri[i]=kelime;
			s++;
			i++;				
		}
		printf("%c",kelime);//dosyay� oldu�u gibi yaz�yor
	}while(kelime!=EOF);
	printf("\n");
	printf("*******************************************************************************************************************************");
	printf("\n");
	
	printf("{ ");
	for(j=0;j<s;j++){
		
		
		if(opernok(veri[j])==1){//bu �art gelen karakter operat�rm� veya noktalamam� kontrolu yap�yor.
			if(veri[j]=='+' && veri[j+1]=='+' || veri[j]=='-' && veri[j+1]=='-' || 
			veri[j]=='>' && veri[j+1]=='=' || veri[j]=='<' && veri[j+1]=='=' || veri[j]=='=' && veri[j+1]=='=' || veri[j]=='!' && veri[j+1]=='='
			|| veri[j]=='+' && veri[j+1]=='=' || veri[j]=='-' && veri[j+1]=='=' || veri[j]=='*' && veri[j+1]=='=' || veri[j]=='/' && veri[j+1]=='=' ||
			veri[j]=='&' && veri[j+1]=='&' || veri[j]=='|' && veri[j+1]=='|' || veri[j]=='%' && veri[j+1]=='='){
				printf("%c",veri[j]);//bu i� �artta ++,-- vs gibi ifadelerin kelimele�mesi sa�lan�yor.
				printf("%c,",veri[j+1]);
				j++;
					
			}
			
			
			else if(veri[j]=='"'){/*bu k�s�mda printf i�inde t�rnaklar aras� c�mleyi tek kelime yap�yoruz.Yani gelen karakter " ise bi sonraki
			t�rnak gelene kadar oldu�u gibi yazd�r�yoruz.*/
				printf("%c,",veri[j]);
				
				a=1;//while i�ine girmesi i�in bu �art.
				while(a==1){
					if(veri[j+1]!='"'){
						printf("%c",veri[j+1]);
						j++;
					}
					else{
						printf(",%c,",veri[j+1]);
						j++;
						a=0;//Sonsuz d�ng�ye sokmamak i�in t�rnakla kar��la�t���nda a=0 yapmal�y�z
					}
				}
			}
			
			
		
			else{
				printf("%c,",veri[j]);//Burada ++ -- vs gibi ifade olmayanlar� normal �ekilde ay�r�oruz a,+,2 gibi.
			}	
			
		}
	
		if(opernok(veri[j])!=1){/*Burada karakter operator veya noktalama de�ilse 
		i�eri giriyor ve bi sonraki karakter operator ise araya virg�l koyup ay�r�yor.�r:for,( gibi*/
			if(opernok(veri[j+1])==1){ 
				printf("%c,",veri[j]);
			}
			
			else{/*Bu else blo�unda temel tipleri token yapmak amac�m�zd�r,int float double char long gibi.
			Burada kullan�lan harfmi fonksiyonu baz� fonksiyonlarda ge�en de�i�ken ismiyle  kar��mamas� i�indir.�r printf.*/
				if(harfmi(veri[j-1])==0 && veri[j]=='i' && veri[j+1]=='n' && veri[j+2]=='t'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c,",veri[j+2]);
					j+=2;/*burada j. elemandan sonra 2 ad�m yazd�rd���m�zdan dolay� 2 ad�m atlad�k.
				A�a��daki i�lemlerde ayn� ama�la yap�lm��t�r.E�er b�yle yapmasayd�k eksik art�rsak baz� karakterler birden fazla yaz�labilirdi,
				fazla artt�rsak karakter atlama sorunuyla kar��la��rd�k*/	
				}
				
				else if(harfmi(veri[j-1])==0 && veri[j]=='f' && veri[j+1]=='l' && veri[j+2]=='o' && veri[j+3]=='a' && veri[j+4]=='t'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c",veri[j+3]);
					printf("%c,",veri[j+4]);
					j+=4;
							
				}
				else if(harfmi(veri[j-1])==0 && veri[j]=='d' && veri[j+1]=='o' && veri[j+2]=='u' && veri[j+3]=='b' && veri[j+4]=='l' && veri[j+5]=='e'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c",veri[j+3]);
					printf("%c",veri[j+4]);
					printf("%c,",veri[j+5]);
					j+=5;		
				}
				else if(harfmi(veri[j-1])==0 && veri[j]=='c' && veri[j+1]=='h' && veri[j+2]=='a' && veri[j+3]=='r'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c,",veri[j+3]);
					j+=3;
					
				}
				else if(harfmi(veri[j-1])==0 && veri[j]=='l'  && veri[j+1]=='o' && veri[j+2]=='n' && veri[j+3]=='g'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c,",veri[j+3]);
					j+=3;
					
				}
				else if(harfmi(veri[j-1])==0 && veri[j]=='r' && veri[j+1]=='e' && veri[j+2]=='t' && veri[j+3]=='u' && veri[j+4]=='r' && veri[j+5]=='n'){
					printf("%c",veri[j]);//returnu ay�rmak i�in.�r: return,0
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c",veri[j+3]);
					printf("%c",veri[j+4]);
					printf("%c,",veri[j+5]);
					j+=5;		
				}
				else{
					printf("%c",veri[j]);//e�er temel tip de�ilse normal yazd�rma i�lemi yap�yor.
				}
				
			}	
		}						
    }
    printf("}");
    
    fclose(dosya);
    return 0;
}






  

