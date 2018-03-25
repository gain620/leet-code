class Solution {
private:
	enum class Parentheses {
		LEFT, RIGHT // LEFT = '(' , RIGHT = ')' ((())) 000111
	};
public:
	string getParenthesis(string szParam) {
		string resString;

		for(char word : szParam) {
			if(word=='1') {
				resString.push_back(')');
			}
			else
			{
				resString.push_back('(');
			}
		}

		return resString;
	}


    vector<string> generateParenthesis(int n) {
        int myNum = pow(2, n) - 1;
        string myStr;
        myStr.reserve(2*n);

        for(int i=0; i<myNum + 1; i++)
        {
        	int tempNum = myNum;
        	tempNum % 2



        	myNum--;
        }



        vector<string> vRes;
        vRes.add();

        return vRes;
    }
};