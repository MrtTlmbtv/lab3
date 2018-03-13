#include <iostream>
#include <string>
using namespace std;
typedef struct car{
string number;
int chislo;
car *next;
};
void addcar(car **head,string numberv){
	car *temp=new car;
	temp->number=numberv;
	temp->chislo=0;
    temp->next=(*head);
    (*head)=temp;
}
void output(car *head){
	cout<<"\n(�����/�����) ";
    while(head!=NULL){
        cout  << " <- "<< head->number;
        head=head->next;
    }
	cout << "\n";
}
void popcar(car **head,string s){
    car *prev=*head;
	car *current;
	while(head!=NULL){
		if((*head)->number==s){
			cout << "\n���������� � ���� ������� ��������: "<< (*head)->chislo << " ���\n";
			prev=*head;
			*head=(*head)->next;
			free(prev);
			return;
		}
		prev->chislo++;
		if(prev->next->number==s){
			cout << "\n���������� � ���� ������� ��������: "<< prev->next->chislo << " ���\n";
			current=prev->next;
			prev->next=prev->next->next;
			free(current);
			return;
		}
		else{
			prev=prev->next;
		}
	}
}
int main(){
	setlocale(LC_ALL,"Russian");
	car *head=NULL;
	string number;
	int choice;
label1:
	//system("cls");
	cout << "1. �������� ����������\n2. ������ ���������� \n3. ����� ����������� �� ������� \n4. �����\n";
	cin >> choice;
	switch (choice){
	case 1: //��������
		cout << "\n�������� ���������� � �������: \n";
		cin >> number;
		addcar(&head,number);
		cout << "\n�������:";
		output(head);
		goto label1;
	break;
	case 2: //�������
		cout << "\n�������:";
		output(head);
		cout << "\n������ ���������� � �������: \n";
		cin >> number;
		popcar(&head,number);
		goto label1;
	break;
	case 3: //�������
		cout << "\n�������:";
		output(head);
		goto label1;
	break;
	case 4: //�����
		break;
	default:
		goto label1;
	}
    system("pause");
	return 0;
}
