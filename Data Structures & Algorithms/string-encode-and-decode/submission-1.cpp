class Solution {
public:

    string encode(vector<string>& strs) {
        string encoding = to_string(strs.size());
        encoding += "#";
        for(const string& str: strs){
            encoding += to_string(str.size());
            encoding.push_back('#');
        }
        for(const string& str: strs){
            encoding += str;
        }
        cout<<encoding;
        return encoding;
    }

    vector<string> decode(string s) {
        int ptr = 0;
        string n_str;
        while(s[ptr] != '#'){
            n_str.push_back(s[ptr]);
            ++ptr;
        }
        ++ptr;
        int n = stoi(n_str);
        vector <int> lens (n,0);
        for(int i=0;i<n;i++){
            string n_word;
            while(s[ptr] != '#'){
                n_word.push_back(s[ptr]);
                ++ptr;
            }
            lens[i] = stoi(n_word);
            ++ptr;
            n_word = "";
        }
        vector<string> words (n, "");
        for(int i=0;i<n;i++){
            words[i] = s.substr(ptr, lens[i]);
            ptr+=lens[i];
        }
        return words;
    }
};
