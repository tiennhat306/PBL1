#include<stdio.h>

#include<Windows.h>

int  m,n;
int k[20],c[20], a[20][20], x[20][20];

int g[20],h[20]; 

void nhap()
{
int i,j;
printf("\n  Nhap so diem phat: "); scanf("%d",&m);
printf("  Nhap so diem thu: "); scanf("%d",&n);
	
printf("\n  Nhap so luong hang hoa moi diem phat \n");
for(i=1;i<=m;i++)
{
printf("  Diem phat %d: ",i);
scanf("%d",&k[i]); 
}
printf("\n  Nhap so luong hang hoa moi diem thu can \n");
for(j=1;j<=n;j++)
{
	printf("  Diem thu %d: ",j);
	scanf("%d",&c[j]); 
} 
printf("\n  Nhap khoang cach tu moi diem phat den diem thu \n"); 
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
{
printf("  Diem phat %d den diem thu %d: ",i,j);
	    	scanf("%d",&a[i][j]); 
    	}
	printf("\n"); 
}
}

void kiemTraCanBang()
{
int i,j,phat,thu,chenhlech;
phat=0; thu=0; 
	
for(i=1;i<=m;i++) phat=phat+k[i];
for(j=1;j<=n;j++) thu=thu+c[j];
chenhlech=phat-thu; 

if(chenhlech==0) printf("\n  Day la bai toan can bang thu phat"); 
else if(chenhlech<0) 
{
	m=m+1; 
	printf("\n  Day la bai toan khong can bang thu phat");
	printf("\n  Them 1 diem phat gia co %d luong hang",-chenhlech); 
	k[m]=-chenhlech;
	for(j=1;j<=n;j++) a[m][j]=0;  
	printf("\n  Nen chon phuong phap Fogels de giai bai toan");
}
else if(chenhlech>0)
{
	n=n+1; 
	printf("\n  Day la bai toan khong can bang thu phat");
	printf("\n  Them 1 diem thu gia can %d luong hang",chenhlech); 
	c[n]=chenhlech;
	for(i=1;i<=n;i++) a[i][n]=0;  
	printf("\n  Nen chon phuong phap Fogels de giai bai toan");
} 
}
   
void tayBac()
{
int i,j,delta;
for(i=1;i<=m;i++) g[i]=k[i];
for(j=1;j<=n;j++) h[j]=c[j];
	 
for(i=1;i<=m;i++) 
	for(j=1;j<=n;j++)  x[i][j]=0; 
	
i=1; j=1;
while(i<=m && j<=n)
{
if(k[i]<c[j]) delta=k[i]; else delta=c[j]; 
	k[i]=k[i]-delta;
	c[j]=c[j]-delta;
	x[i][j]=delta;
	if(k[i]==0) i=i+1;
	if(c[j]==0) j=j+1; 
}
	
for(i=1;i<=m;i++) k[i]=g[i];
for(j=1;j<=n;j++) c[j]=h[j];  
} 

void nhoNhat()
{
int i,j,flag,cmin,p,q;	
for(i=1;i<=m;i++) g[i]=k[i];
for(j=1;j<=n;j++) h[j]=c[j]; 
	
for(i=1;i<=m;i++)
	for(j=1;j<=n;j++) x[i][j]=0; 
	
do
{
flag=0; cmin=32767; 
	p=0; q=0; 
for(i=1;i<=m;i++) if(k[i]>0)
	{
		for(j=1;j<=n;j++) if(c[j]>0)
		{
			flag=1;
			if(cmin>a[i][j])
			{
				cmin=a[i][j];
				p=i; q=j; 
			} 
		} 
	}
	
	if(flag==1)
	{
		int delta;
		if(k[p]<c[q]) delta=k[p]; else delta=c[q]; 
		k[p]=k[p]-delta;
		c[q]=c[q]-delta;
		x[p][q]=delta;
	} 
} while(flag==1);

for(i=1;i<=m;i++) k[i]=g[i];
for(j=1;j<=n;j++) c[j]=h[j]; 
}

void Fogels()
{
int i,j,dem,flag,delta1,delta2,di,dj,u,p,q;
int cmin1,cmin2; 
    
for(i=1;i<=m;i++) g[i]=k[i];
for(j=1;j<=n;j++) h[j]=c[j]; 
    
for(i=1;i<=m;i++)
for(j=1;j<=n;j++) x[i][j]=0;
   
do
{ 
for(dem=1;dem<=m+n;dem++)
{
            	flag=0; 
	 	di=0; dj=0; 
delta1=-32768;	
for(i=1;i<=m;i++) if(k[i]>0) 
		{
			flag= 1; 
			cmin1= 32767; cmin2= 32767; 
			u=0; 
			for(j=1;j<=n;j++) if(c[j]>0)
			{
				u++;
				if(cmin1>a[i][j])
				{
				 	cmin1=a[i][j]; 
					di=i; dj=j; 
				} 
			} 
		    
			if(u>1) 
			{
				for(j=1;j<=n;j++)
			    	if(c[j]>0) if((j!=dj) && (cmin2>a[i][j])) cmin2=a[i][j]; 
			    	delta2=cmin2-cmin1; 
			}
			else if(u==1) delta2=cmin1;
			if(delta1<delta2)
			{
		            	delta1=delta2; 
		           		p=di; q=dj; 
			}  
		}
		    
		for(j=1;j<=n;j++) if(c[j]>0)
		{
			flag=1; 
			cmin1=32767; cmin2=32767; 
			u=0;  
			for(i=1;i<=m;i++) if(k[i]>0)
			{
				u++;
				if(cmin1>a[i][j])
				{
					cmin1=a[i][j]; 
					di=i; dj=j; 
				} 
			} 
			
			 if(u>1) 
			{
				for(i=1;i<=m;i++)
		        		if(k[i]>0) if((i!=di) &&(cmin2>a[i][j])) cmin2=a[i][j]; 
				delta2=cmin2-cmin1; 
			}
			else if(u==1) delta2=cmin1;
			if(delta1<delta2)
			{
				delta1=delta2; 
				p=di; q=dj; 
			} 
		}
}
	if(flag==1)
	{
		int delta;
		if(k[p]<c[q]) delta=k[p]; else delta=c[q]; 
		k[p]=k[p]-delta;
		c[q]=c[q]-delta;
		x[p][q]=delta;	
	}
}  while(flag==1);
	
for(i=1;i<=m;i++) k[i]=g[i];
for(j=1;j<=n;j++) c[j]=h[j]; 
}

int kiemTraSuyBien()
{
int i,j,dem=0;
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
		if(x[i][j]!=0) dem++; 
if(dem==m+n-1) return 1;
else return 0; 
}

int theVi() 
{
int i,j,k,di,dj,max,min,delta,selU,selV,dem,u1,v1,lc,flag,cmin;
int index=1, row,col;
int u[20],v[20],loop[20][20];
char sign[20][20]; 
	
while(index<=10) 
{
	if(kiemTraSuyBien()==0) return -4;
		
	for(i=1;i<=m;i++) u[i]=-1000;
	for(j=1;j<=n;j++) v[j]=-1000;
		
	max=0;
	selU=-1; selV=-1;
		
	for(i=1;i<=m;i++)
	{
		dem=0;
		for(j=1;j<=n;j++)
			if(x[i][j]>0) dem=dem+1;
		if(dem>max)
		{
			max=dem;
			selU=i; 
		} 
}
		
	for(j=1;j<=n;j++)
	{
		dem=0;  
		for(i=1;i<=m;i++)
				if(x[i][j]>0) dem=dem+1;
		if(dem>max)
		{
			max=dem;
			selU=-1; selV=j; 
		} 
	}
		
	u1=0; v1=0;
	if(selU!=-1)
	{
		u[selU]=0;
		u1=u1+1; 
	}
	else
	{
		v[selV]=0;
		v1=v1+1; 
	}
		
	flag=1;
	while(flag==1)
	{
		for(i=1;i<=m;i++)  for(j=1;j<=n;j++) 
			if(x[i][j]>0)
			{
				if((u[i]!=-1000)&&(v[j]==-1000))
				{
					v[j]=a[i][j]-u[i];
					v1=v1+1; 
				}
				else if((u[i]==-1000)&&(v[j]!=-1000))
				{
					u[i]=a[i][j]-v[j];
					u1=u1+1; 
				} 
			} 
		if(u1==m && v1==n) flag=0; 
	}

min=0;  
	di=-1; dj=-1;  
	for(i=1;i<=m;i++) 
		for(j=1;j<=n;j++)
			if(x[i][j]==0)
			{
				delta=a[i][j]-u[i]-v[j];
				if(delta<min)
				{
					min=delta;
					di=i; 
					dj=j; 
				 } 
			}
	if(min>=0) 
	{
		return 1;
	}
		
	for(i=1;i<=m;i++) 
		for(j=1;j<=n;j++)
		{
			if(x[i][j]>0) loop[i][j]=1; else loop[i][j]=0;
			sign[i][j]=' ';  
		}
	loop[di][dj]=1; 
	sign[di][dj]='+';
			
for(k=1;k<=m;k++)
	{ 
lc=0; 
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++) if(loop[i][j]==1) lc++;
		    	if(lc==1) for(j=1;j<=n;j++) loop[i][j]=0;
			lc=0; 
		}
		    
		lc=0; 
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=m;i++) if(loop[i][j]==1) lc++;
			if(lc==1) for(i=1;i<=m;i++) loop[i][j]=0; 
		    	lc=0; 
		} 
	}
		
	for(i=1;i<=m;i++)
	{	
		for(j=1;j<=n;j++) if(loop[i][j]==1) lc++;
		if(lc>=3)
		{
			return -1;
		}
			lc=0;
	}    
	for(j=1;j<=n;j++)
	{
		for(i=1;i<=m;i++) if(loop[i][j]==1) lc++;
		if(lc>=3)
		{
		    	return -1;
		}
			lc=0; 
	}    	
   
	sign[di][dj]='+';
	row=0;col=0;
	for(j=1;j<=n;j++) if(j!=dj && loop[di][j]==1) { row=1; break;}
	for(i=1;i<=m;i++) if(i!=di && loop[i][dj]==1) { col=1; break;}
	if(row+col<2)
	{
		return -2;
	} 
	else
	{
		i=di;
		for(k=1;k<=m;k++)
		{
			for(j=1;j<=n;j++) 
			if(loop[i][j]==1 && sign[i][j]==' ')
			{
				sign[i][j]='-';
				break;
			} 
			if(j==dj) break;		  
			for(i=1;i<=m;i++)
			if(loop[i][j]==1 && sign[i][j]==' ')
			{
				sign[i][j]='+';
break; 
			} 
		}
		if(k==m+1)
		{
			return -2;
		}
	}

	cmin=32767; 
	for(i=1;i<=m;i++) 
		for(j=1;j<=n;j++)
			if(sign[i][j]=='-' && x[i][j]>0)
				if(cmin>x[i][j]) cmin=x[i][j]; 
    
	for(i=1;i<=m;i++) 
		for(j=1;j<=n;j++)
		{
			if(sign[i][j]=='+') x[i][j]=x[i][j]+cmin;
			else if(sign[i][j]=='-') x[i][j]=x[i][j]-cmin; 
		}

	if(index>=10)
	{
		return -3;
	}
	index++; 
}
}

int ketQua()
{
int i,j,tong=0;
for(i=1;i<=m;i++) 
	for(j=1;j<=n;j++)
	{
		if(x[i][j]==0) continue;
		tong=tong+(a[i][j]*x[i][j]); 
	} 
return tong; 
} 
  
int main()
{	
system("color F0");
	
int i,j,cv,d,chon1,chon2,tong=0;
int g[20], h[20]; 
printf("\n  ================================================="); 
printf("\n  ==========  DO AN LAP TRINH TINH TOAN  ==========");
printf("\n  ================================================="); 
printf("\n  =   De tai: BAI TOAN VAN TAI    Ma de: 502      =");
printf("\n  =                                               =");  
printf("\n  =   Giao vien huong dan: NGUYEN TAN KHOI        =");
printf("\n  =   Ho va ten sinh vien: LE XUAN TIEN NHAT      =");
printf("\n  =   Lop: 21T_DT2                                =");
printf("\n  =   MSSV: 102210119                             =");
printf("\n  =                                               =");  
printf("\n  ================================================="); 
printf("\n  ========  CHUONG TRINH BAI TOAN VAN TAI  ========");
printf("\n  ================================================="); 
printf("\n\n      Moi ban nhap cac du lieu cua bai toan");
printf("\n"); 
do
{
nhap(); 
	kiemTraCanBang(); 
	
	printf("\n"); 
	printf("\n  Cac du lieu ban vua nhap duoc thong ke o bang sau:\n  ");
		
	for(j=1;j<=n+1;j++) printf("_______________" ); 
		                      printf("\n |              "); 
	for(j=1;j<=n+1;j++) printf("|              ");
		                      printf("\n |              |");
	for(j=1;j<=n;j++)   printf("   C[%d]: %3d  |",j,c[j]);
		                    printf("\n ");
		                    printf("|"); 
	for(d=1;d<=n+1;d++) printf("______________|"); 
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			printf("\n |              |"); 
			for(j=1;j<=n;j++)   printf(" %3d          |",a[i][j]);
printf("\n |   K[%d]: %3d  | ",i,k[i]); 
			for(j=1;j<=n;j++)   printf("         x%d%d | ",i,j); 
printf("\n ");
			printf("|"); 
		        	for(j=1;j<=n+1;j++) printf("______________|"); 
	        	} 
	}
		
   do 
   {
                   printf("\n  ================================================="); 
       printf("\n  Moi ban chon cach giai phuong an co ban ban dau");
       printf("\n      1. Phuong phap goc Tay Bac");
       printf("\n      2. Phuong phap chi phi be nhat");
       printf("\n      3. Phuong phap xap xi Fogels");
                   printf("\n  =================================================");  
       printf("\n  Moi ban chon: "); fflush(stdin); scanf("%d",&cv); 
		      
       switch (cv)
      {
                      case 1:  {  tayBac();  printf("\n  Ket qua phuong phap goc Tay Bac la:"); break; }
          case 2:  {  nhoNhat(); printf("\n  Ket qua phuong phap chi phi be nhat la:"); break; }
          case 3:  {  Fogels();   printf("\n  Ket qua phuong phap xap xi Fogels la:");  break; }
       }
			
printf("\n  "); 
	for(j=1;j<=n+1;j++) printf("_______________" ); 
	printf("\n |              "); 
	for(j=1;j<=n+1;j++) printf("|              ");
	printf("\n |              |");
	for(j=1;j<=n;j++)   printf("   C[%d]: %3d  |",j,c[j]);
	printf("\n ");
	printf("|"); 
	for(d=1;d<=n+1;d++) printf("______________|"); 
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			printf("\n |              |"); 
			for(j=1;j<=n;j++)   printf(" %3d          |",a[i][j]); 
			printf("\n |   K[%d]: %3d  | ",i,k[i]); 
			for(j=1;j<=n;j++)   printf("         %3d | ",x[i][j]); 
			printf("\n ");
			printf("|"); 
			for(j=1;j<=n+1;j++) printf("______________|"); 
		  } 
	}
			    
	printf("\n\n  => Tong la: %d", ketQua()); 
	printf("\n");
	if(kiemTraSuyBien()==0) printf("\n  Phuong an ban dau suy bien.\n  Hay thu phuong phap khac.\n");
	else if(kiemTraSuyBien()==1)
	{ 
		int rep = theVi();
		if(rep==-1) printf("\n  Phuong an co ban ban dau co chua chu trinh\n  Khong the lap chu ky dieu chinh.\n");
		else if(rep==-2) printf("\nKhong the lap chu trinh\n");
		else if(rep==-3) printf("\nPhuong phap bi lap vo han lan\n");
		else if(rep==-4) printf("\nPhuong an bi suy bien sau nhieu lan tinh toan");
		else if(rep==1)
		{
			printf("\nKet qua Phuong an toi uu cua bai toan la:\n");
			printf("  "); 
			for(j=1;j<=n+1;j++) printf("_______________" ); 
				printf("\n |              "); 
				for(j=1;j<=n+1;j++) printf("|              ");
				                            printf("\n |              |");
			            for(j=1;j<=n;j++)   printf("   C[%d]: %3d  |",j,c[j]);
				                            printf("\n ");
				    	                printf("|"); 
			    	for(d=1;d<=n+1;d++) printf("______________|"); 
			    	for(i=1;i<=m;i++)
			    	{
				      for(j=1;j<=n+1;j++)
				     {
					printf("\n |              |"); 
					for(j=1;j<=n;j++)   printf(" %3d          |",a[i][j]); 
				            printf("\n |   K[%d]: %3d  | ",i,k[i]); 
				            for(j=1;j<=n;j++)   printf("         %3d | ",x[i][j]); 
				            printf("\n ");
					                                printf("|"); 
				      	for(j=1;j<=n+1;j++) printf("______________|");  
				     } 
				}
				    
			printf("\n\n  => Tong toi uu la: %d", ketQua());
			printf("\n"); 
		}
	}
		        
       printf("\n  =================================================");  
       printf("\n  Ban co muon tiep tuc voi phuong phap khac?");
	printf("\n             1. Co");
	printf("\n             2. Khong");
       printf("\n  =================================================");  
	printf("\n  Moi ban chon: "); scanf("%d",&chon1);
			 
	if(chon1==2) printf("\nKet thuc bai toan.\n"); 
   }
   while(chon1==1); 

       printf("\n  ================================================="); 
       printf("\n  Ban co muon nhap du lieu khac?");
	 printf("\n             1. Co");
	 printf("\n             2. Khong");
       printf("\n  ================================================="); 
	printf("\n  Moi ban chon: "); scanf("%d",&chon2);
		 
	if(chon2==2) printf("\n  ************  KET THUC CHUONG TRINH  ************"); 
}
while(chon2 == 1); 
}