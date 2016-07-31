#include<iostream>
#include<vector>
#include<string>
#include"solve.h"
using namespace std;

void hdoj1097(){
    int i = 0;
    vector< vector<int> > last(10);
    for ( i = 0; i < 10; i++ ){
        int r = i*i%10;
        last[i].push_back(i);
        while( i!=r ){
            last[i].push_back( r );
            r = r*i%10;
        }
    }
    int a,b;
    while( cin>>a>>b ){
        int j = a%10;
        int len = last[j].size();
        cout << last[j][(b-1)%len] << endl;
    }

}




void hdoj1070(){
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++){
		int nBrand;
		cin >> nBrand;
		string brand;
		double price=-1;//单价
		int volume;
		string inputBrand;
		int inputPrice;      
		int inputVolume;
		int drinkedVolume;
		for (int j = 0; j < nBrand; j++){
			cin >> inputBrand >> inputPrice >> inputVolume;
			if (inputVolume > 1000)
				drinkedVolume = 1000;
			else
				drinkedVolume = inputVolume - inputVolume % 200;
			if (price < 0){
				price = inputPrice*1.0 / drinkedVolume;
				brand = inputBrand;
				volume = inputVolume;
			}
			else{
				double newPrice = inputPrice*1.0 / drinkedVolume;
				if (price > newPrice){
					price = newPrice;
					brand = inputBrand;
					volume = inputVolume;
				}
				else if (price == newPrice){
					if (volume < inputVolume){
						price = newPrice;
						brand = inputBrand;
						volume = inputVolume;
					}
				}
			}
			

		}
		cout << brand << endl;
	}
}


void hdoj1087(){
	int N=1;
	while (cin>>N){
		if (N == 0)
			return;
		vector<int> chessman;
		int value;
		for (int i = 0; i < N; i++){
			cin >> value;
			chessman.push_back(value);
		}
		vector<int> dp(N);           //dp[i]表示第i个位置的最大分值
		dp[0] = chessman[0];
		int max = dp[0];        
		for (int i = 1; i < N; i++){
			dp[i] = chessman[i];
			for (int j = 0; j < i; j++){
				
				if (chessman[i] > chessman[j]&&dp[i]<chessman[i]+dp[j]){
					dp[i] = chessman[i] + dp[j];
				}
				
			}
			if (dp[i] > max){
				max = dp[i];
			}
		}
		cout << max << endl;
	}
}