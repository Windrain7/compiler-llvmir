parser.cpp: parser.y
	bison -d -o parser.cpp parser.y  
tokens.cpp: tokens.l 
	flex -o tokens.cpp tokens.l
clean:
	rm parser.cpp parser.hpp tokens.cpp parser