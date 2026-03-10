class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls = 0;
        int cows = 0;

        vector<int> count(10,0);

        for(int i=0;i<secret.size();i++){

            if(secret[i] == guess[i]){
                bulls++;
            }
            else{

                if(count[secret[i]-'0'] < 0)
                    cows++;

                if(count[guess[i]-'0'] > 0)
                    cows++;

                count[secret[i]-'0']++;
                count[guess[i]-'0']--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};