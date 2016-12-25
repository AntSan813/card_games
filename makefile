test: main.o Card.o Deck.o Tool.o Rock.o Paper.o Scissor.o Monte.o Marble.o DiscardPile.o PlayingHand.o 
	c++ -o test main.o Card.o Deck.o Tool.o Rock.o Paper.o Scissor.o DiscardPile.o PlayingHand.o
main.o: Card.h main.cpp
	c++ -c main.cpp
Card.o: Card.h Card.cpp
	c++ -c Card.cpp
Deck.o: Deck.h Node.h Stack.h Deck.cpp
	c++ -c Deck.cpp 
Tool.o: Tool.h Tool.cpp
	c++ -c Tool.cpp
Rock.o: Rock.h Rock.cpp
	c++ -c Rock.cpp
Paper.o: Paper.h Paper.cpp
	c++ -c Paper.cpp
Scissor.o: Scissor.h Scissor.cpp
	c++ -c Scissor.cpp
Monte.o: Monte.h Monte.cpp
	c++ -c Monte.cpp
Marble.o: Marble.h Marble.cpp
	c++ -c Marble.cpp
DiscardPile.o: DiscardPile.h DiscardPile.cpp
	c++ -c DiscardPile.cpp
PlayingHand.o: LinkedList.h PlayingHand.h PlayingHand.cpp
	c++ -c PlayingHand.cpp
clean:
	rm Card.o Deck.o main.o Tool.o Rock.o Paper.o Scissor.o Monte.o Marble.o DiscardPile.o PlayingHand.o
