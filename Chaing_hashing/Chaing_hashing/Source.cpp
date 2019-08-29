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
void deleteNode(Node** hashTable, int hashTableSize, int hashTableIndex, int data) {
	Node* p0, * p;
	p0 = 0;
	hashTableIndex = myhash(data, hashTableSize);
	p = hashTable[hashTableIndex];
	while (p && !(p->data == data)) {
		p0 = p;
		p = p->next;
	}
	if (!p) return;
	if (p0)
		p0->next = p->next;
	else
		hashTable[hashTableIndex] = p->next;
	free(p);
}
Node* insertNode(Node** hashTable, int hashTableSize, int hashTableIndex, int data) {
	Node* p, * p0;
	hashTableIndex = myhash(data, hashTableSize);
	if ((p = new Node) == 0) {
		cout << "Нехватка памяти (insertNode)\n";
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
	int i, * a2, * a, maxnum, * a1, maxnum1, hashTableSize = 0, hashTableSize1 = 0, hashTableIndex = 0, hashTableIndex1 = 0;
	cout << "Input of quantity element lots 1 : ";
	cin >> maxnum;
	cout << "input size of hash tables 1 : ";
	cin >> hashTableSize;
	cout << "Input of quantity element lots 2 : ";
	cin >> maxnum1;
	cout << "input size of hash tables 2 : ";
	cin >> hashTableSize1;
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
	cout << "Input element of 1 lot" << endl;
	for (i = 0; i < maxnum; i++) {
		int tempt = 0;
		cin >> tempt;
		a[i] = tempt;
		insertNode(hashTable, hashTableSize, i, a[i]);
	}
	cout << "Input element of 2 lot" << endl;
	for (i = 0; i < maxnum1; i++) {
		int tempt = 0;
		cin >> tempt;
		a1[i] = tempt;
		insertNode(hashTable1, hashTableSize1, i, a1[i]);
	}
	cout << "first" << endl;
	for (i = 0; i < maxnum; i++) {
		cout << a[i];
		if (i < maxnum - 1) cout << "\t";
	}
	cout << endl;
	cout << "Second" << endl;
	for (i = 0; i < maxnum1; i++) {
		cout << a1[i];
		if (i < maxnum1 - 1) cout << "\t";
	}
	cout << endl;
	cout << "first" << endl;
	for (i = 0; i < hashTableSize; i++) {
		cout << i + 1 << "  :  ";
		Node* Temp = hashTable[i];
		while (Temp) {
			cout << Temp->data << " -> ";
			Temp = Temp->next;
		}
		cout << endl;
	}
	cout << "Second";
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
	cout << "Input element for search" << endl;
	int it = 0, k = 0;
	cin >> it;
	for (i = 0; i < hashTableSize; i++) {
		int k1 = 0;
		Node* Temp = hashTable[i];
		while (Temp) {
			k1++;
			if (Temp->data == it) {
				cout << i + 1 << "  :  ";
				cout << k1;
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
					cout << k1;
				}
				Temp = Temp->next;
			}

		}
		cout << endl;
	}

	cout << "Input element for delete" << endl;
	int it1 = 0, k2 = 0, k3 = 0;
	cin >> it1;
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
	cout << "first" << endl;
	for (i = 0; i < hashTableSize; i++) {
		cout << i + 1 << "  :  ";
		Node* Temp = hashTable[i];
		while (Temp) {
			cout << Temp->data << " -> ";
			Temp = Temp->next;
		}
		cout << endl;
	}
	cout << "Second";
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
	for (i = 0; i < hashTableSize1 + hashTableSize; i++)
		hashTable2[i] = NULL;
	cout << "Union" << endl;
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
	for (i = 0; i < hashTableSize1 + hashTableSize; i++)
		hashTable3[i] = NULL;
	cout << "Intersection" << endl;
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
	for (i = maxnum - 1; i >= 0; i--) {
		deleteNode(hashTable, hashTableSize, i, a[i]);
	}
	for (i = maxnum1 - 1; i >= 0; i--) {
		deleteNode(hashTable1, hashTableSize1, i, a1[i]);
	}
	for (i = maxnum1 + maxnum - 1; i >= maxnum; i--) {
		deleteNode(hashTable2, hashTableSize1 + hashTableSize, i, a1[i - maxnum1]);
	}
	for (i = maxnum - 1; i >= 0; i--) {
		deleteNode(hashTable2, hashTableSize + hashTableSize1, i, a[i]);
	}
	tr = 0;
	for (i = 0; i < maxnum; i++) {
		for (int j = maxnum; j < maxnum + maxnum1; j++) {
			if (a[i] == a1[j - maxnum]) {
				deleteNode(hashTable3, hashTableSize1 + hashTableSize, tr, a[i]);
				tr++;
			}
		}
	}
}
