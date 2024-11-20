# Fish-Show
Overall Idea:
	We are holding a fish show/contest. Our program will accept entries (fish class) and sort into a binary search tree. After the initial entries, there will be an acceptance for late entries or for people to get disqualified. Afterward, we will find the min and max of the tree. The min being awarded Skinny Queen and the max being awarded Curvy Lady. They will then be printed out in order to show all contestants rankings. 

Driver:
Allows for contestants to be entered in and sent to BST 
Allows for late entries or disqualifications 
Allows for print of winners based on weight of fish
skinny queen(min of tree) and curvy lady(max of tree) wins 
Ends program by awarding the skinny queen ribbon and curvy lady ribbon and print out ranks 

Tree Class:
     Private Data:
	NumofNodes
	Tree root 
     Public Data:
	Constructor
	Destructor 
    Insert 
	Get data 
	Remove
	Friend Function Print Data
	Find min (recursive) 
	Find max (recursive)

Data Class:
	String owner Name
	String fish type 
	Float  weight
	Float finSize; 

Functions
	Getters 
	Setters
	Print Data 

