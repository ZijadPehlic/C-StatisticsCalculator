/* Program is a statistical tool that randomly "throws n balls in m bins". It records data from this process: 
1.Number of empty bins
2.Number of bins that had more than n/m balls in them
3.Number of bins that had more than 2n/m balls in them
4.Fullest bin

It runs this test for 50 times and then it calculates following:
1.Average empty bins
2.Max empty bins
3.Min empty bins
4.Average of bins that had more than n/m balls
5.Average of bins that had more than 2n/m balls
6.Number of balls in fullest bin
7.Percentage of bins that had more than n/m balls
8.Percentage of bins that had more than 2n/m balls
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
	srand(time(0));
	int n,m; //n=number of bins; m=number of balls
	int maxEmpty=0;
	int minEmpty=INT_MAX;
	double averageEmpty=0;
	double sumEmpty=0; 
	double mThannm,mThan2nm; // mThannm more than n/m; mThan2nm=more than 2n/m
	double mThannmAvg,mThan2nmAvg;
	int fullestBin=0;
	cout<<"Enter number of bins"<<endl;  //Specific input
	cin>>m;
	cout<<"Enter number of balls"<<endl;
	cin>>n;
	for(int i=0;i<50;i++){ //Start of test
	
	int random,emptyBins;
	int binsC[m];//BinsC - counter for each bin 
	random=1+(rand()%n);
	for (int i=0;i<m;i++)//Assigning each binC to value 0
	{
		binsC[i]=0;
	}
	cout<<".............................."<<endl;
	for(int i=0;i<n;i++) //Actual process of "throwing balls in bins 
	{
		random=1+(rand()%m);
		binsC[random-1]=binsC[random-1]+1;
		cout<<random<<endl;
	};
	cout<<".............................."<<endl;
	for (int i=0;i<m;i++) // Displaying amount of balls fallen in each bin
	{
		cout<<"Bin"<<i+1<<":  "<<binsC[i]<<endl;
	}
	emptyBins=0;
	for (int i=0;i<m;i++) //Amount of empty bins in 1 test
	{
		if  (binsC[i]==0) emptyBins++; 
	}
	sumEmpty=sumEmpty+emptyBins;// sum of all empty bins in 50 tests
	cout<<"Number of empty Bins:"<<emptyBins<<endl;
	
	if (emptyBins>maxEmpty) maxEmpty=emptyBins;
	if (emptyBins<minEmpty) minEmpty=emptyBins;
	
	averageEmpty=sumEmpty/50.0;
	for (int i=0;i<m;i++) // counting bins that had more than n/m and 2n/m balls 
	{
		if (binsC[i]>n/m) mThannm++;
		if (binsC[i]>2*n/m) mThan2nm++;
	}
	cout<<"More than n/m bins:"<<mThannm<<endl;
	cout<<"More than 2n/m bins:"<<mThan2nm<<endl;
	for (int i=0;i<m;i++)
	{
		if (binsC[i]>fullestBin) fullestBin=binsC[i];
	}
	cout<<"Fullest bin: "<<fullestBin<<endl;
	cout<<"----------------------End of test ---------------------------------------"<<endl;
	}
	//End of Test

	mThannmAvg=mThannm/50;
	mThan2nmAvg=mThan2nm/50;
	averageEmpty=sumEmpty/50;
	cout<<"Average empty bins:  "<<averageEmpty<<endl;
	cout<<"Max empty bins:  "<<maxEmpty<<endl;
	cout<<"Min empty bins:  "<<minEmpty<<endl;
	cout<<"Average of bins that had more than n/m balls: "<<mThannmAvg<<" out of "<<m<<endl;
	cout<<"Average of bins that had more than 2n/m balls: "<<mThan2nmAvg<<" out of "<<m<<endl;
	cout<<"Number of balls in fullest bin: "<<fullestBin<<endl;
	cout<<"Percentage of bins that had more than n/m balls: "<<mThannmAvg/m<<endl;
	cout<<"Percentage of bins that had more than 2n/m balls: "<<mThan2nmAvg/m<<endl;

	return 0; 
}
