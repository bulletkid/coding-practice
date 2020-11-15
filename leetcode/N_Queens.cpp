#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) { 

				if (n == 1) {
					string s = "Q";
					vector<string> sVec ;
					sVec.push_back(s);
					vector<vector<string> > boardVec;
					boardVec.push_back(sVec);
					return boardVec;
				}

        vector<vector<int> > board(n);
        for (int i = 0; i < n; i++) {
            board[i] = vector<int>(n);
            
            // initialize to zeroes
            for (int j = 0; j < n; j++) {
                board[i].push_back(0);
            }
        }
        
				/*
				std::cout << "Board Size: " << board.size() << "\n";
        // Print vector
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
				*/

        
        vector<vector<string> > boardVec;
        placeQueens(board, 0, &boardVec);

				/*
				std::cout << "End Result\n";
				for(int i = 0; i < boardVec.size(); i++) {
					vector<string> sVec = boardVec[i];
					for (int j = 0; j < sVec.size(); j++)
						std::cout << sVec[j] << " ";
					std::cout << "\n";
				}
				*/
        
        return boardVec;
    }
    
private:
    void placeQueens(vector<vector<int> >& board, int currentRow, vector<vector<string> >* boardVec);
    bool isSafe(const vector<vector<int> >& board, int currentRow, int currentCol) const;
};


void Solution::placeQueens(vector<vector<int> >& board, int current, vector<vector<string> >* boardVec)
{
  const int n = board.size();

	if (current == n) {
		
		// Found match
		vector<string> sVec;
		//std::cout << "Safe position\n";
		for(int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
						//std::cout << board[i][j] << " ";
						
						if (board[i][j] == 0) 
							sVec.push_back(".");
						else
							sVec.push_back("Q");
				}
				//std::cout << "\n";
				sVec.push_back(",");
		}

		sVec.pop_back();

		/*
		std::cout << "Pushing..\n";
		for(int i = 0; i < sVec.size(); i++) {
			std::cout << sVec[i] << " ";
		}
    */

		boardVec->push_back(sVec);
		//std::cout << "Size of boardvec is " << boardVec->size() << "\n";
		
		return;
	}


	for (int i = 0; i < board.size(); i++) {
	
		board[current][i] = 1;
		if (isSafe(board, current, i)) {
        placeQueens(board, current + 1, boardVec);
		}
		board[current][i] = 0;
	}

}
    
bool Solution::isSafe(const vector<vector<int> >& board, int currentRow, int currentCol) const
{
	// TODO: Complete this
	// Need to evaluate quuens in rows above this
	// Need to focus only on current position

	for (int i = 0; i < currentRow; i++) {
		for (int j = 0; j < board.size(); j++) {
			if ( board[i][j] == 1) {
				//std::cout << "Found queen at position " << i << "," << j << ". Checking for safety..\n";
				if (j == currentCol) {
					//std::cout << "Threat: Same column\n";
					return false;
				}

				// Diagonal threat
				if ( abs(j - currentCol) == (currentRow - i) ) {
					//std::cout << "Threat: Diagonal attack\n";
					return false;
				}
			}
		}
	}
	


	return true;
}

int main(int argc, char *argv[])
{
	Solution sol;

  for(int i = 1; i < 9; i++) {
		std::cout << "Solving for " << i << "*" << i << " board\n";
		sol.solveNQueens(i);
	}

	return 0;
}


/**
. Q . . , . . . Q , Q . . . , . . Q . Size of boardvec is 1
. . Q . , Q . . . , . . . Q , . Q . . Size of boardvec is 2

**/
