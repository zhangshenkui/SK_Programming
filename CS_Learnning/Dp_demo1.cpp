/*********编译时 g++ *.cpp   -std=c++11*************/




#include<iostream>
#include<vector>

using namespace std;




class solution{

	public:


		/***
		 *参数1：硬币的币值种类
		 *参数2：需要凑的硬币总价值
		 * ***/
		int CoinChg(vector<int> &coins,int amount){     

		/**
		 * *动态数组初始化为Max
		 * **/

		int Max=amount + 100;           //相当于硬币数-设成了最大值,amount更代表总币值，相当于自定义了一个Max
		vector<int> dp(amount+1,Max); 	//动态数组初始化

		dp[0]=0;   //金额0，需要0个金币
		
		/**开始增大背包大小***/
		for(int i=0;i<=amount;i++){  

			/***coins.size,说明这个硬币有几种种类***/
			for(int j=0;j<coins.size();j++){
			

			/**i代表金额，i-coins[j]代表从总金额去除一枚已有种类的硬币**/
			if(i-coins[j]>=0){

			int index=i-coins[j];   //
			
			dp[i]=dp[index]+1 <dp[i] ?dp[index]+1:dp[i];	

			}
			
			}

		}

return dp[amount]>amount ? -1:dp[amount];

		}
};





int main(){

int amount =8;
vector<int> coins={1,2,3};

solution S;


int r=S.CoinChg(coins,amount);


cout<<"最小使用的硬币数量:  \n"<<r<<endl;



return 0;


}
