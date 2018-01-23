#include<iostream>

using namespace std;

template <typename t>
void insertion_sort(t* a, int num){
	t current;
	for (int i=1;i<num;i++){
		current = a[i];
		int j=i-1;
		while ((j>=0) && (a[j]>current)){
			a[j+1]=a[j];
			j--;
		}
	a[j+1] = current;
	}
}


int main(){

     while(1){
	char choice;
	int num;
	int* arr;
	cout << "Enter number of Elements :";
	cin >> num;
	arr = new int[num];
	cout << "Enter the array elements: \n";
	for (int i=0;i < num;i++){
		cin>>arr[i];
	}
	insertion_sort<int>(arr,num);
	cout<<"Array Contents: \n";
	for(int i=0;i<num;i++){
		cout<<arr[i]<<"\n";
	}
	cout << "Do you wish to continue (y/n) ? ";
	cin >> choice;
	if(choice == 'n'){
		delete[] arr;
		break;
	}
    }
    return 0;
}

