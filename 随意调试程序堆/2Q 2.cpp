#include <iostream>
using namespace std;

int main ()
{
	int r,y,g;
	int n;
	int k,t;
	long long ans=0;//���е���ǰ��·�µ���ʱ��
	cin>>r>>y>>g;cin>>n;
	int loop=r+y+g;//���������ѭ��һ�ε�ʱ��
	while(n--){
		cin>>k>>t;
		if(k==0)ans+=t;
		else{
			if(ans-t<=0){//���ڸõƵ�ʱ���� 
				if(k==1) ans=t;//��Ƶȴ�ʱ�� 
				else if(k==3) ;//�̵�ͨ�� 
				else ans=t+r;//�Ƶ�+��Ƶȴ�ʱ�� 
			}
			else{
				int cur=(ans-t)%loop;//�ӸõƵ���һ���ƿ�ʼ
				if(k==1){//�� 
					if(cur<g);//������
					else ans+=r+(y-(cur-g)); 
				}
				else if(k==2){//��
					if(cur<r)ans+=r-cur;//���ں� 
					else if(cur>=r&&cur<r+g);//������
					else{//���ڻ� 
						ans+=loop-cur+r;
					}
				}
				else{//�� 
					if(cur<y)ans+=y-cur+r;
					else if(cur>=y&&cur<y+r)ans+=y+r-cur;
				}
			}
		}
	}
	cout<<ans;
	return 0;
 } 
