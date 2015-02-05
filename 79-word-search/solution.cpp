class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {

        if (word.size() == 0) return true;

        int m = board.size(); // cols
        int n = board[0].size(); // rows

        //printf("int m: %d, int n: %d \n", m, n);

        // map<char, vector<vector<int> > > m; // for each char store all the positions it occurs in the board

        bool found = false;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j <n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (word.length() == 1) return true;
                    else
                    {
                        vector<int> pos(2);
                        pos[0] = i; pos[1] = j;

                        //printf("Char [%c] found at pos: (%d, %d} \n", board[i][j], i, j);
                        found = dfs(board, pos, word);

                        if (found == true) return true;
                    }

                }
            }
        }

        return false;


    }


    bool dfs(vector<vector<char> > &board, vector<int> pos, string word)
    {
        deque<vector<int> > stack;
        stack.push_front(pos);

        set<vector<int> > visited;

        int idx = 0; // position of 2nd letter in the word

        //printf("Entering loop ... \n\n");
        while (!stack.empty())
        {
            pos = stack.front();
            stack.pop_front();
            if (visited.find(pos) == visited.end())
            {
                visited.insert(pos);

                //printVectors(visited, "visited");

                idx++;

                //cout << "idx: " << idx << endl;
                if (idx == word.length()) return true;

                char next_char = word[idx];
                vector<vector<int> > all_neighbors;
                getNeighbors( board, pos, all_neighbors);

                if (all_neighbors.size() == 0) return false;

                int n = all_neighbors.size();

                vector<vector<int> > valid_neighbors;
                for(int i=0; i<n; i++)
                {
                    vector<int> n_pos = all_neighbors[i];

                    if (board[n_pos[0]][n_pos[1]] == next_char)
                        valid_neighbors.push_back(n_pos);
                }

                if (valid_neighbors.size() == 0)
                    return false;

                //printVectors(valid_neighbors, "valid_neighbors");
                //cout << endl;

                n = valid_neighbors.size();
                set<vector<int> > visited_neighbors;
                for (int i=0; i < n; i++)
    //              visited_neighbors.insert(valid_neighbors[i]); // can't visit same letter twice
                    stack.push_front(valid_neighbors[i]);

    //            set<vector<int> >


           }

        }

        return false;
    }


    bool isValid(vector<vector<char> > board, vector<int> pt)
    {
        int i = pt[0]; // row
        int j = pt[1]; // col


        int m = board.size(); // rows
        int n = board[0].size(); // cols

        if ((i >= 0 && i < m) &&  (j >= 0 && j < n)) return true;
        else return false;

    }

    void getNeighbors(vector<vector<char> > board, vector<int> pt, vector<vector<int> >& neighbors)
    {
        int i = pt[0]; // row
        int j = pt[1]; // col

        int x[] = {i-1, i, i+1, i};
        int y[] = {j, j+1, j, j-1};

        for(int i=0; i<4; i++)
        {
            vector<int> neighbor(2);
            neighbor[0] = x[i];
            neighbor[1] = y[i];

            if (isValid(board, neighbor))
                neighbors.push_back(neighbor);
        }
    }
};