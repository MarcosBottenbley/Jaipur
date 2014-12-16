Intermediate Programming Final Project README
David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
dmill118@jhu.edu, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu

Overview:
	When the game is started it will prompt the user to create two players. Here the user has the option of
making human or AI players. From there the game begins and players start making moves. For the human players it
will come up with a menu that allows the user to choose which move they want to make or choose to see the board.
Choosing to see the board will show the player how many goods tokens are left in the bank and the amount of points
that the player has earned. After choosing a move there a several ways the program takes in the user's input to see
which cards the user wants to use. For take it will just prompt the user to choose one card. For sell it will allow
the player to toggle the cards he wants to choose from his hand. For trade the input is the same for sell except it
allows the player to toggle market cards and it allows them to add or subtract camel cards. After a move is chosen 
and completed the game will prompt the user to either continue the game, quit or show the updated board. Then if
the game is continued the next player will go. For the AI the game simply outputs what move the AI made and then
comes up with the same prompt that asks the user to continue quit or display the board. This prompt allows the game
to be quit at any moment during the play through. This is important especially because after a round is completed 
another round is automatically started.

Implementation Details:
	We divided the code into several classes. Game handles the main sequencing of moves, and interactions
between the other classes. There are Bank, Deck and Market classes to hold Cards and Tokens on the board. The
Player has two subclasses, AI and Human to implement the two types of players. Our use of separate classes
allows us to cut down on repeated code and keep files relatively small and indepedent. The getMove() method
in Player is called to receive a Move from any player, and Move's are standardized by making a Move class
with the subclasses Take, Trade and Sell. makeMove() is then able to execute the changes in the board state
after a move without having to be specific about which Move is taking place since each subclass implements
its own version of makeMove().

	The Type class provides an enumeration to the different types of goods in the game. The type class
was written to easily convert "types" in the game from strings to their resepctive values. This is used
primarily in bank and the move classes where "types" eg. Diamond, Leather, Spice need to be checked. In 
bank it is used to initialize the bank it allows the program to take in one object and with that object
it will be able to put the tokens in the correct array while also initializing the tokens with the proper
string. It simply is there to shroten a lot of the code.

Testing:
	Testing is implemented in the various test files, and they are all run from the TestClassMain file.
Testing covers all the classes except AI (this was tested by simply running the AIs against each other). We also
ran the program under valgrind and found no leaks in a full AI vs AI match.

	A Makefile is included to build the tests and the main game. Use "make" to build the main game as a
JaipurMain executable, and "make MainTest" to make the tests. 

Thanks!

