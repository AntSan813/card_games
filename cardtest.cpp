#include <iostream>
#include "Card.h"
#include "Deck.h"

using namespace std;

int main(){
	Card testCard2 = Card(4,3);
	Card testCard1 = Card(2,2);
	if(testCard1 > testCard2)
		cout << "Test card 1 wins with greater than. this is not right." << endl;
	else if(testCard1 < testCard2)
		cout << "Test card 2 wins with test card 1 being less than. this is correct." << endl;
	if(testCard2 > testCard1)
		cout << "Test card 2 wins with test card 1 being greater than. this is correct." << endl;
	else if (testCard2 < testCard1)
                cout << "Test card 1 wins with less than. this is not right." << endl;
	










	Card testCard3 = Card(9,2);
	Card testCard4 = Card(8,3);
	if(testCard4 > testCard3)
                cout << "Test card 4 wins with greater than. this is not right." << endl;
        else if(testCard4 < testCard3)
                cout << "Test card 3 wins with test card 3 being less than. this is correct." << endl;

        if(testCard3 > testCard4)
                cout << "Test card 3 wins with test card 4 being greater than. this is correct." << endl;
        else if (testCard3 < testCard4)
                cout << "Test card 3 wins with less than. this is not right." << endl;







	cout << " Test card 2: " << testCard2.getRank() << endl;
	cout << " Test card 1: " <<  testCard1.getRank() << endl;
	cout << " Test card 3: " << testCard3.getRank() << endl;
	cout << " Test card 4: " << testCard4.getRank() << endl;
return 0;
}
