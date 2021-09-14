
#include<iostream>
using namespace std;

int main(){
	int size;
    int indexOne;
	int indexTwo;
	char edgeOne;
	char edgeTwo;

	cout << "How many vertices: ";
	cin >> size;

	char* vertices = new char[size];
	int** matrix = new int* [size];

	for (int i = 0; i < size; i++){
		matrix[i] = new int[size];
    }

	for (int i = 0; i < size; i++){
		cout << "What is the label for vertex " << i + 1 << "? ";
		cin >> vertices[i];
	}
	
    while(true){
        cout << "\nDefine an edge by listing a pair of vertices, i.e. 'A B', or -1 to stop: ";
        cin >> edgeOne >> edgeTwo;
        cin.ignore();

		for (int i = 0; i < size; i++)
			if (edgeOne == vertices[i])
				indexOne = i;

		for (int i = 0; i < size; i++)
			if (edgeTwo == vertices[i])
				indexTwo = i;

		matrix[indexOne][indexTwo] = 1;

        if(edgeOne == '-' && edgeTwo == '1'){
            break;
        }
        
        cout << "Added Edge " << edgeOne << "->" << edgeTwo << endl;
        
    }
	
	cout << "\nYour edges are: " << endl;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (matrix[i][j] == 1){
				cout << vertices[i] << vertices[j] << " " << endl;
            }
        }
    }

    delete vertices;
    delete matrix;
}

/*
    Output:
        How many vertices: 6
        What is the label for vertex 1? A
        What is the label for vertex 2? B
        What is the label for vertex 3? C
        What is the label for vertex 4? D
        What is the label for vertex 5? E
        What is the label for vertex 6? F

        Define an edge by listing a pair of vertices, i.e. 'A B', or -1 to stop: A B
        Added Edge A->B

        Define an edge by listing a pair of vertices, i.e. 'A B', or -1 to stop: B A
        Added Edge B->A

        Define an edge by listing a pair of vertices, i.e. 'A B', or -1 to stop: -1

        Your edges are:
        AB
        BA
*/