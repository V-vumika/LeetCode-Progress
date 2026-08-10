class Solution {
public:
    vector<int> t; //T.C : O(n * sqrt(n))
    //S.C : O(n)

    bool solve(int n) {

        if(n == 0) {
            return false;
        }

        if(t[n] != -1) {
            return t[n] == 1 ? true : false;
        }

        for(int k = 1; k*k <= n; k++) { //O(sqrt(n))
            
            if(solve(n - (k*k)) == false) {//Call for Bob //False - Bob lost it
                //Alice won the game
                return t[n] = true;
            }

        }

        return t[n] = false; //Alice could never win. Lost it.

    }

    bool winnerSquareGame(int n) {
        t.assign(n+1, -1);
        return solve(n); //Alice k lie call hai ye. If it's true, Alice wins, else Alice looses
    }
};