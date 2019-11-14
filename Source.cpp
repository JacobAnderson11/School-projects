// HuffTrees.cpp : Defines the entry point for the console application.
//

#include "Huffman_Tree.h"
#include <iostream>
#include<string>



using namespace std;

int main()
{


	Huff_Data<string> The(8, "the");
	Huff_Data<string> Itsy_Bitsy(2, "Itsy_Bitsy");
	Huff_Data<string> Spider(3, "Spider");
	Huff_Data<string> Climbed(2,"climbed");
	Huff_Data<string> Up(3, "Up");
	Huff_Data<string> Water(1, "Water");
	Huff_Data<string> Spout(2, "Spout");	
	Huff_Data<string> Down(1, "Down");
	Huff_Data<string> Came(2, "Came");
	Huff_Data<string> Rain(2, "Rain");
	Huff_Data<string> And(3, "And");
	Huff_Data<string> Washed(1, "Washed");
	Huff_Data<string> Out(1, "Out");
	Huff_Data<string> Sun(1, "Sun");
	Huff_Data<string> Dried(1, "Dried");
	Huff_Data<string> All(1, "All");
	Huff_Data<string> Again(1, "Again");


	std::ostringstream code;
	std::vector<Huff_Data<string>> huff_Data{The,Itsy_Bitsy,Spider,Climbed,Up,Water,Spout,Down,Came,Rain,And,Washed,Out,Sun,Dried,All,Again};
	Huffman_Tree<string> huff_tree;
	huff_tree.build_tree(huff_Data);
	huff_tree.print_code(code);
	std::string result = code.str();
	std::cout << result;

	return 0;
}

