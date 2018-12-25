#include"iostream"
#include"stdlib.h"
#include"string.h"
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

int main()
{
	string st;
	cout<<"nhap du lieu: ";
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
  cout<<"Nam nhuan";
  else 
  cout<<"Khong phai nam nhuan";
  
  cout<<"So thu tu trong nam:"<<TimSTT(x);
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
