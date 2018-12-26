#include"iostream"
#include"stdlib.h"
#include"string.h"
#include"conio.h"
using namespace std;
typedef struct{
	int ngay;
	int thang;
	int nam;
} Ngaythang;

int thang[13] ={ 0,31,28,31,30,31,30,31,31,30,31,30,31};

int Ktranamnhuan(int nam){
	   if ((nam%4==0 && nam%100!=0) || (nam%400==0))
	   return 1;
	   return 0;
	
}

int TimSTT(Ngaythang n){
	int STT=0;
	for(int i=0; i<n.thang; i++)
	STT+= thang[i];
	STT+= n.ngay;
	if(Ktranamnhuan(n.nam)==1 && n.thang >2) // neu thang can tinh lon hon 2 thi moi cong 1 ngay nhuan vao tong
	STT+1;
	return STT;
}

Ngaythang NgaytuSTT(int STT, int nam){ // STT=81; nam =2018
	Ngaythang ngaycantim;
	int a=1;
	
	for(int i=1; i<12; i++){
    	if( STT > thang[i]){ //81 >31// 50>28//
    		
		if(Ktranamnhuan(nam) == 1 && i ==2)  
		thang[i]==29;
		
		STT -= thang[i]; // 81-31=50 //50-28 =22
		
		a=i+1; // a= 2 //a=3
		
    	}
    	
    	
	}
	ngaycantim.ngay= STT;
	ngaycantim.thang=a;
	ngaycantim.nam=nam;
	
	return ngaycantim;
}

Ngaythang CongNgaythang(Ngaythang n, int x){
	//x<=356
	int nam=n.nam; //2018
	int kq= x + TimSTT(n); // x= 20 + 61 (02/03/2018) = kq = 81
	cout<<"kq sau khi cong STT: "<<kq<<" / nam: "<<nam<<endl; // 81
	
	if(kq<=365) //81<365
	 return NgaytuSTT(kq,nam);
	else
	 if( Ktranamnhuan(nam)==1 )
	   if(kq==366)
	     return NgaytuSTT(kq,nam);
	   else
	     return NgaytuSTT(kq-366,nam+1);
	  else
	    return NgaytuSTT(kq-365,nam+1);
}

Ngaythang TruNgaythang(Ngaythang n, int x){
	//x<=356
	
	int kq,nam;
	if (x < TimSTT(n)){
		 kq = TimSTT(n)-x; //61 - 20 = 41
		 cout<<"kq sau khi tru STT th1: "<<kq<<" / nam: "<<n.nam<<endl;
		 nam=n.nam; //2018
		 }
	else {
		nam = n.nam-1; 
		kq = TimSTT(n) + 365 - x;
		cout<<"kq sau khi tru STT th2: "<<kq<<" / nam: "<<n.nam<<endl;
		
		if (Ktranamnhuan(n.nam)==1 && (n.thang>2 || (n.thang==2 && n.ngay==29)))
			kq++;
		}
		
	return NgaytuSTT(kq,nam);
}
void Inngay(Ngaythang n){
	cout <<n.ngay << "/" << n.thang << "/" <<n.nam <<endl;
}
int main()
{
	int a,b;
	
	string st;
	cout<<"nhap du lieu: "; // 02/03/2018
	getline(cin,st);
	char t[4];
	Ngaythang x;
	t[0]=st[0];
	t[1]=st[1];
	x.ngay=atoi(t);
	t[0]=st[3];
	t[1]=st[4];
	x.thang=atoi(t);
	t[0]=st[6];
	t[1]=st[7];
	t[2]=st[8];
	t[3]=st[9];
	x.nam=atoi(t);
  cout<<"ngay: "<<x.ngay<<endl;
  cout<<"thang: "<<x.thang<<endl;
  cout<<"nam: "<<x.nam<<endl;
  
  if(Ktranamnhuan(x.nam)==1 )
  cout<<"\nNam nhuan";
  else 
  cout<<"\nKhong phai nam nhuan "; // khong nhuan
  
  cout<<"\nSo thu tu trong nam:"<<TimSTT(x); // 61
 	
 	cout<<"\nNhap so nguyen a:"; // a=20
 	cin>>a;
 	cout<<"\nCong ngay thang: \n";
 	Inngay(CongNgaythang(x,a)); // 22/3/2018
 	
 	cout<<"\nNhap so nguyen b:"; //b=20
 	cin>>b;
 	cout<<"\nTru ngay thang: \n";
 	Inngay(TruNgaythang(x,a)); //10/2/2018

 
  getch();
// Cach 2:
//int day, month, year;
//char c;
//
//cout << "Nhap ngay thang: ";
//cin >> day >> c >> month >> c >> year;
//cout << "Ngay " << day << " thang " << month << " nam " << year;
 
//int ngaymax;
// if (nam<0 || thang<0 || thang> 12 || ngay<0 || ngay> 31)
//    {
//        cout<<"Ngay khong hop le";
//    }
//    else
//    {
//        switch (thang)
//        {
//            case 1:
//            case 3:
//            case 5:
//            case 7:
//            case 8:
//            case 10:
//            case 12:
//              ngaymax=31;
//              break;
//            case 2:
//                if ((nam%4==0 && nam%100!=0) || (nam%400==0))
//                    ngaymax=29;
//                else 
//                    ngaymax=28;
//                break;
//            case 4:
//            case 6:
//            case 9:
//            case 11:
//                ngaymax=30;
//                break;
//        }
//        if (ngay<=ngaymax)
//        {
//            cout<<"Ngay hop le !"<<endl;
//        }
//        else
//        {
//            cout<<"Ngay khong hop le !"<<endl;
//        }
//    }
}
