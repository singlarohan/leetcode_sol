class Solution {
public:
    int createMask(string& str){
        int mask = 0;
        for(int i = 0; i < str.length(); i++){
            int x = str[i] - 'a';
            mask = (mask | (1 << x));
        }
        return mask;
    }

    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles){
        unordered_map<char, vector<int>> wordMap;
        // in this map .. a -> is vector which contains all words which 'a' char
        // b -> is vector which contains all words which have 'b' char in them..
        // actually we'll store masks

        // for every puzzle[i], thats a string str, so str[0] is the 1st letter
        // we go to map[1st letter] ..  it'll give all words which
        //   have this 1st letter at any place
        // so.. we dont have to iterate over all words array

        // if a word is : "dcfb" ... first of all create mask
        // then add this word in map[d], map[c], map[f], map[b]
        for(auto& word: words){
            int mask = createMask(word);

            unordered_set<char> sett;  // to avoid repetition
            for(int i = 0; i < word.length(); i++){
                if(sett.find(word[i]) == sett.end()){
                    sett.insert(word[i]);
                    wordMap[word[i]].push_back(mask);
                }
            }
        }

        vector<int> ans;
        for(auto& puzzle: puzzles){
            int puzzMask = createMask(puzzle);
            
            // 1st condition .... puzzle ka 1st letter word mein hona chahiye 
            char first = puzzle[0];
            vector<int> temp = wordMap[first];
            // now we've all eligible words i which this 1st char is present

            // iterate on this vector ... find those words where every letter in
            //   word must be present in puzzle and we've masks of both 
            int cnt = 0;
            for(int wordMask : temp){
                if((wordMask & puzzMask) == wordMask)
                    cnt++;
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};