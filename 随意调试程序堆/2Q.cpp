#include <iostream>
using namespace std;

int main ()
{
	int r,y,g;
	int n;
	int k,t;
	int ans=0;//���е���ǰ��·�µ���ʱ��
	cin>>r>>y>>g;cin>>n;
	int loop=r+y+g;//���������ѭ��һ�ε�ʱ�� 
	while(n--){
		cin>>k>>t;
		if(ans==0){//����ʱ�� 
			if(k==1||k==0){
			ans+=t;
			}
			else if(k==2){
				ans+=t+r;
			}
		}
		else{
	//		int cur=(T+t)%loop;//��ʾ������ʾ�Ƶ�ʱ�䣨δ����Ϊ����ĳ�ƣ���ѭ��ʱ���ڵľ���ʱ�䣩 
							//���ڵ��ǵ���ָʾ����ɫ�µľ���ʱ�䣡
			int cur=ans%loop;
			if(k==0){//�޵ƣ�ֱ�Ӽ��Ϻ�ʱ 
				ans+=t;
			}
			else if(k==1){//��� 
				if(cur>=t){//�����˺������ʱ�� 
					if(cur-t>=g){//�������̵�����ʱ�� 
						if(cur-t-g>=y){//�����˻Ƶ�����ʱ��
							ans+=r-(cur-t-g-y);
						}
						else{//δ�����Ƶ�����ʱ�� 
							ans+=(y-(cur-t-g))+r;
						}
					}
					else{//�����̵��� 
					}
				}
				else{//���ں���� 
					ans+=t-cur;
				}
			}
			else if(k==2){//�Ƶ� 
				if(cur>=t){//�����˻Ƶ�����ʱ�� 
					if(cur-t-r<=0){//���ں���� 
						ans+=r-(cur-t);
					}
					else{//�̵��� 
					}
				}
				else{//���ڻƵ���
					ans+=t-cur+r;
				}
			}
			else{//�̵�ʱ 
				if(cur>=t){//�������̵�����ʱ��
					if(cur-t>=y){//�����˻Ƶ�����ʱ�� 
						 if(cur-t-y>=r){//�����˺������ʱ�䣬�Դ����̵� 
						 }
						 else{//����� 
						 	ans+=r-(cur-t-y);
						 }
					}
					else{//���ڻƵ���
						ans+=y-(cur-t);
					}
				}
				else{//�̵��� 
				}
			}
		}
//		cout<<"now "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
