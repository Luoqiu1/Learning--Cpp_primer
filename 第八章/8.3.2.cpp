#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class PersonInfo{
	public:
		string name;
		vector<string> phoneNums;
};

void DealPhoneNum(ifstream &ifs,vector<PersonInfo> &people)
{
	string line;
	while(getline(ifs,line)){
		istringstream oss(line);
		ostringstream ossNum;
		PersonInfo tmp;
		oss>>tmp.name;
		string s;
		
		while(oss>>s){
			ossNum<<s<<' ';
		}
		tmp.phoneNums.push_back(ossNum.str());
									//其实这么做有一点不合实际
									//我这样是把所有的电话号码合在一个string中了
									//按实际应该是一个电话号码为一个string！
									
//		while(oss>>s){
//			tmp.phoneNums.push_back(s);
//		}							//这样做的话就是一个号码一个string 
		
	//	tmp.phoneNums[0]=ossNum.str();仔细！这样是错误的！
									//因为现在phoneNums容器中一个元素也没有！
									//所以不存在索引[0]！ 
		people.push_back(tmp);
	}
}

void print(const vector<PersonInfo> &people)
{
	for(const auto &i:people){
		cout<<i.name<<' ';
		for(const auto &j:i.phoneNums){
			cout<<j<<' ';
		}
		cout<<endl;
	}
}

int main ()
{
	vector<PersonInfo> people;
	ifstream ifs;
	string ifile="Record.txt";
	ifs.open(ifile,fstream::in);
	DealPhoneNum(ifs,people);
	print(people);
	return 0;
}
