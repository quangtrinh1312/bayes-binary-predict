#include<bits/stdc++.h>
using namespace std;
struct T{
	float x[100];
	bool nhan;
};
int n=10;
		T a[100];
		T b[100];
void nhap(){
		ifstream ip("bayes.txt");//dia chi file training dataset
		
		for(int i=1;i<=n;i++){
			ip>>a[i].x[1]>>a[i].x[2]>>a[i].x[3]>>a[i].nhan;
		}
		ip.close();
}
void xuat(){
	for(int i=1;i<=n;i++){
			cout<<a[i].x[1]<<" "<<a[i].x[2]<<" "<<a[i].x[3]<<" "<<a[i].nhan<<endl;
}
}
main(){
	int sample=3;
	    b[1].x[1]=0;	b[1].x[2]=1; b[1].x[3]=0;
	    
		nhap();
		
		float yes=1,no=1;
		int county=0,countn=0;
		int demYes[100],demNo[100];
		for(int i=1;i<=sample;i++){
			demYes[i]=demNo[i]=0;
		}
		for(int i=1;i<=n;i++)	//duyet data training
		{
			for(int j=1;j<=sample;j++)	//duyet x1 x2
			{
			if(a[i].x[j]==b[1].x[j] && a[i].nhan==1) demYes[j]++;	//dem yes
			if(a[i].x[j]==b[1].x[j] && a[i].nhan==0) demNo[j]++;	//dem no
			}
			
			if(a[i].nhan==1) county++;
			else countn++;
		}
		for(int i=1;i<=sample;i++)
		{
			cout<<demYes[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=sample;i++)
		{
			cout<<demNo[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=sample;i++)
		yes*=(float)demYes[i]/county;
		for(int i=1;i<=sample;i++)
		no*=(float)demNo[i]/countn;
		cout<<fixed<<setprecision(3)<<yes<<" "<<no<<endl;
		b[1].nhan=0;
		if(yes>no) b[1].nhan=1;
		cout<<"nhan cua dataset se la: "<<b[1].nhan<<endl;
		cout<<county<<"  "<<countn;
}
