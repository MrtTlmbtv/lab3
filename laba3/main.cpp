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
	cout<<"\n(Въезд/Выезд) ";
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
			cout << "\nАвтомобиль с этим номером удалялся: "<< (*head)->chislo << " раз\n";
			prev=*head;
			*head=(*head)->next;
			free(prev);
			return;
		}
		prev->chislo++;
		if(prev->next->number==s){
			cout << "\nАвтомобиль с этим номером удалялся: "<< prev->next->chislo << " раз\n";
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
	cout << "1. Прибытие автомобиля\n2. Отъезд автомобиля \n3. Вывод автомобилей на стоянке \n4. Выход\n";
	cin >> choice;
	switch (choice){
	case 1: //добавить
		cout << "\nПрибытие автомобиля с номером: \n";
		cin >> number;
		addcar(&head,number);
		cout << "\nСтоянка:";
		output(head);
		goto label1;
	break;
	case 2: //удалить
		cout << "\nСтоянка:";
		output(head);
		cout << "\nОтъезд автомобиля с номером: \n";
		cin >> number;
		popcar(&head,number);
		goto label1;
	break;
	case 3: //вывести
		cout << "\nСтоянка:";
		output(head);
		goto label1;
	break;
	case 4: //выход
		break;
	default:
		goto label1;
	}
    system("pause");
	return 0;
}
