//FURKAN KARAÇALI 02200201005 1.ÖÐRETÝM
#include<stdio.h>

int opernok(char a){//gelen char operatormü veya noktalamamý kontrolü yapýyor
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
		goto DONGU;	//burada dosya ismi yanlýþ girildiðinde DONGU etiketine yönlendirme saðladým.	
	}
	do{
	
		kelime= fgetc(dosya);//bu döngüde dosyadan gelen her karakter kontrol ediliyor,boþluk veya tab veya entersa diziye atýlmýyor
		if((int)kelime!=32 && (int)kelime!=9 && (int)kelime!=10){
			veri[i]=kelime;
			s++;
			i++;				
		}
		printf("%c",kelime);//dosyayý olduðu gibi yazýyor
	}while(kelime!=EOF);
	printf("\n");
	printf("*******************************************************************************************************************************");
	printf("\n");
	
	printf("{ ");
	for(j=0;j<s;j++){
		
		
		if(opernok(veri[j])==1){//bu þart gelen karakter operatörmü veya noktalamamý kontrolu yapýyor.
			if(veri[j]=='+' && veri[j+1]=='+' || veri[j]=='-' && veri[j+1]=='-' || 
			veri[j]=='>' && veri[j+1]=='=' || veri[j]=='<' && veri[j+1]=='=' || veri[j]=='=' && veri[j+1]=='=' || veri[j]=='!' && veri[j+1]=='='
			|| veri[j]=='+' && veri[j+1]=='=' || veri[j]=='-' && veri[j+1]=='=' || veri[j]=='*' && veri[j+1]=='=' || veri[j]=='/' && veri[j+1]=='=' ||
			veri[j]=='&' && veri[j+1]=='&' || veri[j]=='|' && veri[j+1]=='|' || veri[j]=='%' && veri[j+1]=='='){
				printf("%c",veri[j]);//bu iç þartta ++,-- vs gibi ifadelerin kelimeleþmesi saðlanýyor.
				printf("%c,",veri[j+1]);
				j++;
					
			}
			
			
			else if(veri[j]=='"'){/*bu kýsýmda printf içinde týrnaklar arasý cümleyi tek kelime yapýyoruz.Yani gelen karakter " ise bi sonraki
			týrnak gelene kadar olduðu gibi yazdýrýyoruz.*/
				printf("%c,",veri[j]);
				
				a=1;//while içine girmesi için bu þart.
				while(a==1){
					if(veri[j+1]!='"'){
						printf("%c",veri[j+1]);
						j++;
					}
					else{
						printf(",%c,",veri[j+1]);
						j++;
						a=0;//Sonsuz döngüye sokmamak için týrnakla karþýlaþtýðýnda a=0 yapmalýyýz
					}
				}
			}
			
			
		
			else{
				printf("%c,",veri[j]);//Burada ++ -- vs gibi ifade olmayanlarý normal þekilde ayýrýoruz a,+,2 gibi.
			}	
			
		}
	
		if(opernok(veri[j])!=1){/*Burada karakter operator veya noktalama deðilse 
		içeri giriyor ve bi sonraki karakter operator ise araya virgül koyup ayýrýyor.ör:for,( gibi*/
			if(opernok(veri[j+1])==1){ 
				printf("%c,",veri[j]);
			}
			
			else{/*Bu else bloðunda temel tipleri token yapmak amacýmýzdýr,int float double char long gibi.
			Burada kullanýlan harfmi fonksiyonu bazý fonksiyonlarda geçen deðiþken ismiyle  karýþmamasý içindir.ör printf.*/
				if(harfmi(veri[j-1])==0 && veri[j]=='i' && veri[j+1]=='n' && veri[j+2]=='t'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c,",veri[j+2]);
					j+=2;/*burada j. elemandan sonra 2 adým yazdýrdýðýmýzdan dolayý 2 adým atladýk.
				Aþaðýdaki iþlemlerde ayný amaçla yapýlmýþtýr.Eðer böyle yapmasaydýk eksik artýrsak bazý karakterler birden fazla yazýlabilirdi,
				fazla arttýrsak karakter atlama sorunuyla karþýlaþýrdýk*/	
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
					printf("%c",veri[j]);//returnu ayýrmak için.ör: return,0
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c",veri[j+3]);
					printf("%c",veri[j+4]);
					printf("%c,",veri[j+5]);
					j+=5;		
				}
				else{
					printf("%c",veri[j]);//eðer temel tip deðilse normal yazdýrma iþlemi yapýyor.
				}
				
			}	
		}						
    }
    printf("}");
    
    fclose(dosya);
    return 0;
}






  

