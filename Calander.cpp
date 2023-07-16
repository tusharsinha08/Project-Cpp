#include<iostream>
using namespace std;

int firstDayOfYear(int y)
{
    int day = 0;

    day = (y*365+((y-1)/4)-((y-1)/100)+((y-1)/400)) % 7;

    return day;
}

void calender(int year)
{
    //initialize months name as string----------
    string month[] = {" January ","February","  March ","  April ",
                      "    May  ","  June  ","  July  "," August ",
                      "September"," October","November","December"};

    //Checking the year leap-year or not----------
    int week = 0, day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4 == 0 && year%100 != 0) || year%400 == 0 )
        day[1] = 29;

    system("cls");
    cout<<endl;
    cout<<"\t\t\t   Calender of "<<year<<endl;

    //Finding the first day of the year----------
    week = firstDayOfYear(year);

    for(int i=0; i<12; i++)
    {
        cout<<endl;
        cout<<endl;
        cout<<"\t--------------------- "<< month[i] <<" --------------------"<<endl;
        cout<<endl;
        cout<<"\tSun\tMon\tTue\tWed\tThu\tFri\tSat"<<endl;
        cout<<endl;

        //print tab
        for(int space=1; space<=week; space++)
        {
            cout<<"\t";
        }

        for(int j=1; j<=day[i]; j++)
        {

            cout<<"\t"<< j;
            week++;

            if(week > 6)
            {
                cout<<endl;
                cout<<endl;
                week = 0;
            }
        }
        cout<<endl;

    }
}

int main()
{
    int year;

    cout<<"# Which year's calender you want to see : ";
    cin>>year;
    calender(year);

    return 0;
}
