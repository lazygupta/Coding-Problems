
// Extracting words from both
// Comparing each word first from front
// Then from back
// Maintaion a index to do this
// If the index reaches the ned of the shorter sentence
// It means it is possible to make the secind sentence from it

class Solution {
public:

    void wordSplit(string sentence1, string sentence2,vector<string> &word1,vector<string> &word2){
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        string word;
        while(ss1 >> word){
            word1.push_back(word);
        }
        while(ss2 >> word){
            word2.push_back(word);
        }
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> word1,word2;
        wordSplit(sentence1,sentence2,word1,word2);
        int index = 0;
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1>n2){
            return areSentencesSimilar(sentence2,sentence1);
        }
        while(index<n1 && !(word1[index].compare(word2[index]))){
            index++;
        }
        while(index<n1 && !(word1[index].compare(word2[n2-n1+index]))) {
            index++;
        }
        return index == n1;
    }
};