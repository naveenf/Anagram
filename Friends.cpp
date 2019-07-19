#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#define PHRASE_LENGTH 100



char g_str[PHRASE_LENGTH];

/* Function to remove space from the user input phrase */
char* remove_space(char *str) 
{ 
	int i = 0, j = 0; 
	while (str[i]) 
	{ 
		if (str[i] != ' ') 
			str[j++] = str[i]; 
		i++; 
	} 
	str[j] = '\0'; 
	return str; 
} 

/* Function to check whether the word is present in Dictionary File */
int check(string word)
{
	string line = "";

	ifstream file("file.txt",  ios::in); 

	if (!file.is_open())
	{
		cout << "\nUnable to open file \n";
		exit(1);
	}

	while(getline(file,line))
	{
		if (line == word)
		{
			/* Match found with word in file - Print it */
			cout << word<< endl;
			return 1;         
		}
	}

	if (line != word)
	{
		/* No Match Found */
		return 0;
	}     
}

/* Function to find out all the possible word permutations from the user input phrase */
void permute(char* a, int l, int r)
{
	if (l == r)
	{	/* Check to avoid printing of the user input string again */
		if(strcmp (g_str,a))
		{	/* Check whether this word is there in dictionary */
			check (a);
		}
	}
	else
	{
		for (int i = l; i <= r; i++)
		{

			/* Swapping */
			swap(a[l], a[i]);

			permute(a, l+1, r);

			/* Backtracking */
			swap(a[l], a[i]);
		}
	}
}

int main()
{
	char str[PHRASE_LENGTH];
	char *newstr = NULL;
	cout << "Enter a string: ";
	cin.get(str, PHRASE_LENGTH);

	memcpy(g_str, str, sizeof(str));
	/* Remove the spaces from the user entered phrase */
	newstr = remove_space(str);

	int n = strlen(newstr);
	/* Find all possible strings from the user entered string */
	permute(newstr, 0, n-1);
	return 0;
}
