#include <iostream>
#include <cmath>
using namespace std;

//Queen Checkboard Box Print
void queenBox(int k, char m, char g){
	if(k == 0 || k == 4){
		cout << m << m << m << m << m << m << m;
	}
	if(k == 1){
		cout << m << g << m << g << m << g << m;
	}
	if(k > 1 && k < 4){
		cout << m << g << g << g << g << g << m;
	}
}


//Queen Checkboard Box Check
bool boxCheck(int q[], int i, int j){
	if(q[j] == i){
		return true;
	}
	else{
		return false;
	}
}

//Main Print
void print(int q[], int &c, int &solution){
	//Array Print, Solution # and 1D Array
	cout << endl;
	solution++;
	cout << "Solution #" << solution << ": ";
	cout << "q[8]: ";
    cout << "| ";
    for(int i = 0; i < 8; i++){
    	cout << q[i] << " | ";
	}
	cout << endl << endl;
	
	//Checkboard Print
	int i, j, k, l;
	char m = ' ';
	char g = char(219);
	for(int i = 0; i < 7*8 + 1; i++)cout << char(196); //Starting Checkboard Border
	cout << endl;
	cout << char(179);
	for(i = 0; i < 8; i++){
		for(k = 0; k < 5; k++){
			for(j = 0; j < 8; j++){
				//Even Boxes are set White
				if((i + j) % 2 == 0){
					m = char(219); 
					g = ' ';
				}
				//Odd Boxes are set Black
				else{
					m = ' '; 
					g = char(219);
				}
				//Queen Box Print Call
				if(boxCheck(q,i,j)){
						queenBox(k,m,g);
				}
				//Regular Box Print Call
				else{
					for(l = 0; l < 7; l++){
						cout << m;
					}
				}
			}
			//Side Chalkboard Borders
			cout << char(179) << endl;
			cout << char(179);
		}
	}
	for(int i = 0; i < 7*8 + 1; i++) cout << char(196); //Ending Checkboard Border
	cout << endl << endl;
	for(int i = 0; i < 7*8 + 3; i++) cout << "~"; //Array Solution Border
	cout << endl;
	c--;
}

//Array Check
bool ok(int q[], int c){
	for(int i = 0; i < c; i++){
		if(q[i] == q[c] || (c - i) == abs(q[c] - q[i])) return false;
	}
	return true;
}

//Array Creation
void createQueen(int q[], int &c, int &solution){
	while(c >= 0 && c < 8){
		c++;
		if(c == 8){
			print(q, c, solution);	
		}
		else q[c] = -1;
		while(c >= 0 && c < 8){
			q[c]++;
			if(q[c] == 8) c--;
			else if(ok(q, c)) break;
		}
	}
}

int main(){
	int q[8] = {0}, c = 0, solution = 0;
	q[0] = 0;
	
	createQueen(q, c, solution);
	
}