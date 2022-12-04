/*Question:- Assume in the Regional Passport Office,
a multitude of applicants arrive each day for passport renewal.
A list is maintained in the database to store the renewed passports
arranged in the increased order of passport ID. The list already would 
contain three cords renewed till the previous day. Apply Insertion sort technique
to place the current day's records in the list.
Later the office personnel wish to
sort the records based on the date of renewal so as to know the count of renewals done each day.
Taking into consideration the fact that each record has several fields (around 25 fields),
follow Selection sort logic to implement the same.
	
	1. Implement any one of the sorting techniques
	2. Implement the problem for both the sorting techniques.
*/
//CODE:
#include<iostream>
using namespace std;
class passportOffice
{
public:
int id,date;
};
void ShowLists(passportOffice List1[],passportOffice List2[], int n)
{
    cout<<"Sorting on basis of id i.e. insertion sort"<<endl;
	int i;
	for(i=0;i<n;i++){
        cout<<"Id: ";
		cout<<List1[i].id<<endl;
		cout<<"Date: ";
        cout<<List1[i].date<<endl;
        }
    cout<<"Sorting on basis of date i.e. selection sort"<<endl;
    for (i=0;i<n;i++)
	{
	    cout<<"Id: ";
		cout<<List2[i].id<<endl;
	    cout<<"Date: ";
        cout<<List2[i].date<<endl;
	}
}
int main()
{
    int i,j,minimum,today,n,sizeOfToday;
    cout<<"Enter the size of today's List"<<endl;
    cin>>sizeOfToday;
     if(sizeOfToday>23){cout<<"You Should Enter Only 23 size list"<<endl;}
    n=sizeOfToday+3;
    passportOffice  List1[n],List2[n],tem;
    List1[0].id=203;
    List1[0].date=15;
    List1[1].id=201;
    List1[1].date=12;
    List1[2].id=202;
    List1[2].date=20;
    cout<<"Enter Id and Date for today"<<endl;
    for(int i=3;i<n;i++)
    {
        cout<<"Id: ";
        cin>>List1[i].id;
        cout<<"Date: ";
        cin>>List1[i].date;
    }
    for( i=0;i<n;i++)
    {
        List2[i]=List1[i];
    }
    //loop for insertion sort
     for ( i=1;i<n;i++)
	{
		tem=List1[i];
		j=i-1;
		while(List1[j].id > tem.id && j>=0)
		{
			List1[j+1]=List1[j];
			j--;
		}
		List1[j+1]=tem;
	}

	//loop for selection sort
	for (i=0;i<n;i++)
	{
		minimum=i;
		for(j=i+1;j<n;j++)
		{
			if(List2[j].date<List2[minimum].date)
			{
				minimum=j;
			}
		}
		tem=List2[i];
		List2[i]=List2[minimum];
		List2[minimum]=tem;
	}
	ShowLists(List1, List2, n);
    return 0;
}
