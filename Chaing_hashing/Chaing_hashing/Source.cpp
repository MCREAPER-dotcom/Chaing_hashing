#include<iostream>
using namespace std;
class Node {
private:
public:
	int data;
	Node* next;
};
int myhash(int data, int hashTableSize) {
	if (hashTableSize != 0)
		return (data % hashTableSize);
	else return 0;
}
int CHECK() {
	int lk;
	while (true)
	{
		cin >> lk;
		if (!cin)
		{
			cout << "INCORRECT" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	return lk;
}
void deleteNode(Node** hashTable,int hashTableSize) {
	for (int i = 0; i < hashTableSize; i++)
	{
		delete hashTable[i];
	}
}
Node* insertNode(Node** hashTable, int hashTableSize, int hashTableIndex, int data) {
	Node* p, * p0;
	hashTableIndex = myhash(data, hashTableSize);
	if ((p = new Node) == 0) {
		cout << "net pamity (insertNode)\n";
		return 0;
	}
	p0 = hashTable[hashTableIndex];
	hashTable[hashTableIndex] = p;
	p->next = p0;
	p->data = data;
	return p;
}
int main() {
	Node** hashTable;
	Node** hashTable1;
	Node** hashTable2;
	Node** hashTable3;
	int i, * a2, * a, maxnum=0, * a1, maxnum1=0, hashTableSize = 0, hashTableSize1 = 0, hashTableIndex = 0, hashTableIndex1 = 0;
	cout << "vvedite kolihestvo elementov 1 mnojestva: ";
	maxnum=CHECK();
	cout << "vvedine razmer hash-tablic 1: ";
	hashTableSize=CHECK();
	cout << "vvedite kolihestvo elementov 2 mnojestva: ";
	maxnum1=CHECK();
	cout << "vvedine razmer hash-tablic 2: ";
	hashTableSize1=CHECK();
	a = new int[maxnum];
	a1 = new int[maxnum1];
	hashTable = new Node * [hashTableSize];
	hashTable1 = new Node * [hashTableSize1];
	hashTable2 = new Node * [hashTableSize1 + hashTableSize];
	hashTable3 = new Node * [hashTableSize1 + hashTableSize];
	for (i = 0; i < hashTableSize; i++)
		hashTable[i] = NULL;
	for (i = 0; i < hashTableSize1; i++)
		hashTable1[i] = NULL;
	cout << "vvedite elementi 1 mnojestva:" << endl;
	for (i = 0; i < maxnum; i++) {
		int tempt = 0;
		tempt=CHECK();
		a[i] = tempt;
		insertNode(hashTable, hashTableSize, i, a[i]);
	}
	cout << "vvedite elementi 2 mnojestva:" << endl;
	for (i = 0; i < maxnum1; i++) {
		int tempt = 0;
		tempt=CHECK();
		a1[i] = tempt;
		insertNode(hashTable1, hashTableSize1, i, a1[i]);
	}
	cout << "1 mnojestvo :" << endl;
	for (i = 0; i < maxnum; i++) {
		cout << a[i];
		if (i < maxnum - 1) cout << "\t";
	}
	cout << endl;
	cout << "2 mnojestvo :" << endl;
	for (i = 0; i < maxnum1; i++) {
		cout << a1[i];
		if (i < maxnum1 - 1) cout << "\t";
	}
	cout << endl;
	cout << "1 mnojestvo :" << endl;
	for (i = 0; i < hashTableSize; i++) {
		cout << i + 1 << "  :  ";
		Node* Temp = hashTable[i];
		while (Temp) {
			cout << Temp->data << " -> ";
			Temp = Temp->next;
		}
		cout << endl;
	}
	cout << "2 mnojestvo :";
	cout << endl;
	for (i = 0; i < hashTableSize1; i++) {
		cout << i + 1 << "  :  ";
		Node* Temp1 = hashTable1[i];
		while (Temp1) {
			cout << Temp1->data << " -> ";
			Temp1 = Temp1->next;
		}
		cout << endl;
	}
	cout << endl;
	int MENU=0,MENU_CHECK=0;
	do {
		cout << "Vibrat variant: 1.Poisk, 2.Udalenie, 3.Obedinenie, 4.Peresechenie" << endl;
		MENU_CHECK = CHECK();
		if (MENU_CHECK == 1) {
			cout << "vvedite element dlya poiska" << endl;
			int it = 0, k = 0;
			it = CHECK();
			for (i = 0; i < hashTableSize; i++) {
				int k1 = 0;
				Node* Temp = hashTable[i];
				while (Temp) {
					k1++;
					if (Temp->data == it) {
						cout << i + 1 << "  :  ";
						cout << k1 << endl;
						k++;
					}
					Temp = Temp->next;
				}
			}
			cout << endl;
			if (k == 0) {
				for (i = 0; i < hashTableSize1; i++) {
					int k1 = 0;
					Node* Temp = hashTable1[i];
					while (Temp) {
						k1++;
						if (Temp->data == it) {
							cout << i + 1 << "  :  ";
							cout << k1 << endl;
						}
						Temp = Temp->next;
					}

				}
				cout << endl;
			}
		}
		else if (MENU_CHECK == 2) {
			cout << "vvedite element dlya udaleniya" << endl;
			int it1 = 0, k2 = 0, k3 = 0;
			it1 = CHECK();
			for (i = 0; i < maxnum - 1; i++) {
				if (it1 == a[i]) {
					for (int j = i; j < maxnum - 1; j++) {
						a[j] = a[j + 1];
					}
					k2++;

				}

			}
			if (k2 == 0) {
				for (i = 0; i < maxnum - 1; i++) {
					if (it1 == a1[i]) {
						for (int j = i; j < maxnum1 - 1; j++) {
							a1[j] = a1[j + 1];
						}
						k3++;
					}
				}
				if (k3 != 0) {
					for (i = 0; i < hashTableSize1; i++)
						hashTable1[i] = NULL;
					maxnum1 = maxnum1 - k3;
					for (i = 0; i < maxnum1; i++) {
						insertNode(hashTable1, hashTableSize1, i, a1[i]);
					}
				}
			}
			else {
				for (i = 0; i < hashTableSize; i++)
					hashTable[i] = NULL;
				maxnum = maxnum - k2;
				for (i = 0; i < maxnum; i++) {
					insertNode(hashTable, hashTableSize, i, a[i]);
				}
			}
			cout << "1 mnojestvo :" << endl;
			for (i = 0; i < hashTableSize; i++) {
				cout << i + 1 << "  :  ";
				Node* Temp = hashTable[i];
				while (Temp) {
					cout << Temp->data << " -> ";
					Temp = Temp->next;
				}
				cout << endl;
			}
			cout << "2 mnojestvo :";
			cout << endl;
			for (i = 0; i < hashTableSize1; i++) {
				cout << i + 1 << "  :  ";
				Node* Temp1 = hashTable1[i];
				while (Temp1) {
					cout << Temp1->data << " -> ";
					Temp1 = Temp1->next;
				}
				cout << endl;
			}
		}
		else if (MENU_CHECK == 3) {
			cout << endl;
			for (i = 0; i < hashTableSize1 + hashTableSize; i++)
				hashTable2[i] = NULL;
		
			cout << "Obedinenie" << endl;
			for (i = 0; i < maxnum; i++) {
				insertNode(hashTable2, hashTableSize + hashTableSize1, i, a[i]);
			}
			for (i = maxnum; i < maxnum + maxnum1; i++) {
				insertNode(hashTable2, hashTableSize1 + hashTableSize, i, a1[i - maxnum]);
			}
			for (i = 0; i < hashTableSize + hashTableSize1; i++) {
				cout << i + 1 << "  :  ";
				Node* Temp = hashTable2[i];
				while (Temp) {
					cout << Temp->data << " -> ";
					Temp = Temp->next;
				}
				cout << endl;
			}
			deleteNode(hashTable2, hashTableSize1 + hashTableSize);
				}
		else if (MENU_CHECK == 4) {
			for (i = 0; i < hashTableSize1 + hashTableSize; i++)
				hashTable3[i] = NULL;
	
			cout << "Peresechenie" << endl;
			int tr = 0;
			for (i = 0; i < maxnum; i++) {
				for (int j = maxnum; j < maxnum + maxnum1; j++) {
					if (a[i] == a1[j - maxnum]) {
						insertNode(hashTable3, hashTableSize1 + hashTableSize, tr, a[i]);
						tr++;
					}

				}
			}
			for (i = 0; i < hashTableSize + hashTableSize1; i++) {
				cout << i + 1 << "  :  ";
				Node* Temp = hashTable3[i];
				while (Temp) {
					cout << Temp->data << " -> ";
					Temp = Temp->next;
				}
				cout << endl;
			}
			deleteNode(hashTable3, hashTableSize1 + hashTableSize);
		}
		cout << "stop \"1\" , else \"0\"" << endl;
		MENU = CHECK();
	}while (MENU != 1);
	deleteNode(hashTable, hashTableSize);
	deleteNode(hashTable1, hashTableSize1);
}
