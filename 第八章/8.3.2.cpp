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
									//��ʵ��ô����һ�㲻��ʵ��
									//�������ǰ����еĵ绰�������һ��string����
									//��ʵ��Ӧ����һ���绰����Ϊһ��string��
									
//		while(oss>>s){
//			tmp.phoneNums.push_back(s);
//		}							//�������Ļ�����һ������һ��string 
		
	//	tmp.phoneNums[0]=ossNum.str();��ϸ�������Ǵ���ģ�
									//��Ϊ����phoneNums������һ��Ԫ��Ҳû�У�
									//���Բ���������[0]�� 
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
