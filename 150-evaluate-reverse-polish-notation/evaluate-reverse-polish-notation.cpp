class Solution {
public:
    int Operator(int a,int b,string token ) {
        if (token == "+")
            return a + b;

        if (token == "-")
            return a - b;

        if (token == "*")
            return long(a) * long(b);

        if (token == "/")
            return a / b;

            return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = Operator(a, b, token);
                st.push(result);
            } else {
                // confirm its will be a operand

                st.push(stoi(token));
            }
        }
        return st.top();
    }
};