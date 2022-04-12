#include<iostream>
#include<fstream>
using namespace std;
ofstream write("file1.txt");
class wifi;
class gas;
class electricity;
class person
{
public:
    int p1;
    void p_input()
    {

        cout<<"Enter the number of Person in Hostel:";
        cin>>p1;
         write<<"\t\t\t\t\t\t\t"<<"Person in hostel :"<<p1<<"\n\t\t\t\t\t\t\t-------------------"<<endl;
    }
      friend float wi(person,wifi,gas,electricity);
};
class p_p_meal :public person
{
protected:
   char name[6][8]={"Salam","Arif ","Zim  ","Sorif","Niloy","Sayad"};
   float sum=0,sum1=0,name1[10];
public:
    void p1_input()
    {
        int l=0;
        for(int i=0,j=0;i<p1 && j<p1;i++,j++)
        {
            cout<<i+1<<" : "<<"Name :"<<name[i]<<" "<<"Meal : ";
            cin>>name1[j];
            cout<<endl;
            write<<"\t\t\t\t\t\t"<<"Name "<<j+1<<" : "<<name[i]<<"\t"<<"Meal :"<<name1[j]<<endl;
            if(name1[j]>55)
                {
                    sum1=sum1+name1[j];
                }
          else
          {
              sum1=sum1+55;
          }
        }
        write<<"\t\t\t\t\t\t\t"<<"Total Meal : "<<sum1<<endl;
        cout<<"Total Meal : "<<sum1<<endl;
    }
};
class bazar
{
protected:
  int n,baz[12];
  int sum2=0;
public:
  void b1_input()
  {
      cout<<"Bazar Cost : "<<endl;
      write<<"\t\t\t\t\t\t\t   "<<"Bazar Cost :\n"<<"\t\t\t\t\t\t\t   ---------------"<<endl;
      for(int a=0;a<10;a++)
      {
          cout<<a+1<<" : "<<"Bazar : ";
          cin>>baz[a];
          cout<<endl;
          write<<"\t\t\t\t\t\t\t  "<<"Bazar "<<a+1<<" : "<<baz[a]<<endl;
          sum2=sum2+baz[a];
      }
      write<<"\t\t\t\t\t\t\t"<<"Total Bazar Cost : "<<sum2<<endl;
      cout<<"Total Bazar Cost : "<<sum2<<endl;
  }
};
class pan_ext
{
protected:
    int p,ex;
public:
    void p_e_input(void)
    {
        cout<<"Enter the extra cost : ";
        cin>>ex;
        write<<"\t\t\t\t\t\t\t"<<"Total Extra cost : "<<ex<<endl;
        cout<<"Enter the panishment : ";
        cin>>p;
        write<<"\t\t\t\t\t\t\t"<<"Total Panishment : "<<p<<endl;
    }
};
class calculation : public bazar,public pan_ext,public p_p_meal
{
protected:
    int j,l1;
    float sum5,sum6,sum3,sum7,a1[10];
public:
    void c_input(void)
    {
        sum5=(sum2+ex)-p;
        sum6=sum5/sum1;
        cout<<"Meal Rate : "<<sum6<<endl;
        write<<"\t\t\t\t\t\t\t "<<"Meal Rate : "<<sum6<<endl;

    }
   void input_c(float x)
    {
        sum3=200+(sum6*55)+x;
        cout<<"Fixed Meal Cost Per Person : "<<sum3<<endl;
        write<<"\t\t\t\t\t\t"<<"Fixed Meal Cost Per Person : "<<sum3<<endl;
    }
    void input_c1(float x)
    {
       cout<<"Total amount per person:"<<endl;
       write<<"\t\t\t\t\t\t\t"<<"Total amount per person:\n"<<"\t\t\t\t\t\t\t------------------------"<<endl;
       for(j=0;j<p1;j++)
       {
           cout<<j+1<<":";
           write<<"\t\t\t\t\t\t\t"<<j+1<<":";
           for(l1=0;l1<8;l1++)
           {
               cout<<name[j][l1];
               write<<name[j][l1];
           }
           if(name1[j]>55)
           {
               sum7=200+(sum6*name1[j])+x;
               a1[j]=sum7;
               cout<<"= "<<a1[j]<<endl;
               write<<"= "<<a1[j]<<endl;
           }
           else
           {
               sum7=200+(sum6*55)+x;
               a1[j]=sum7;
               cout<<"= "<<a1[j]<<endl;
                write<<"= "<<a1[j]<<endl;
           }
       }
    }
};
class wifi
{
protected:
    int w;
public:
    void w_input()
    {
        cout<<"Enter the wifi bill : ";
        cin>>w;
        write<<"\t\t\t\t\t\t\t   "<<"Wifi Bill : "<<w<<endl;
    }
    friend float wi(person,wifi,gas,electricity);
};
class gas
{
protected:
    int v;
public:
    void v_input()
    {
        cout<<"Enter the Gas bill : ";
        cin>>v;
        write<<"\t\t\t\t\t\t\t"<<"Total Gas Cost : "<<v<<endl;
    }
    friend float wi(person,wifi,gas,electricity);
};
class electricity
{
protected:
    int e;
public:
    void e_input()
    {
        cout<<"Enter the Electricity Bill : ";
        cin>>e;
        write<<"\t\t\t\t\t\t\t"<<"Total Electricity Bill : "<<e<<endl;
    }
    friend float wi(person,wifi,gas,electricity);
};
float wi(person a,wifi b,gas c,electricity d)
{
    float sum4;
    sum4=(b.w+c.v+d.e)/a.p1;
    cout<<"Wifi,Vusi and Electricity Bill Per Person : "<<sum4<<endl;
    cout<<"Aunt's Bill (who is cooking) per person: 200"<<endl;
    write<<"\t\t\t\t\t   "<<"Aunt's Bill (who is cooking) Per Person : 200"<<endl;
    write<<"\t\t\t\t\t   "<<"Wifi,Vusi and Electricity Bill Per Person : "<<sum4<<endl;
    return sum4;
}
int main()
{
    calculation c,c1;
    c.p_input();
    c.p1_input();
    c.b1_input();
    c.p_e_input();
    wifi w;
    w.w_input();
    gas v;
    v.v_input();
    electricity e;
    e.e_input();
    float z=wi(c,w,v,e);
    c.c_input();
    c.input_c(z);
     c.input_c1(z);
}

