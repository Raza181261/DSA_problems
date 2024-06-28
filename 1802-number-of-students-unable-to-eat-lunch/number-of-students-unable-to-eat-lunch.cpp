class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue;
        stack<int> sandwichStack;

        for(int student : students){
            studentQueue.push(student);
        }

        for(int i = sandwiches.size()-1; i>=0; i--){
            sandwichStack.push(sandwiches[i]);
        }

        int count=0;

        while(!studentQueue.empty() && count<studentQueue.size()){
            if(studentQueue.front() == sandwichStack.top()){
                studentQueue.pop();
                sandwichStack.pop();
                count=0;
            } else{
                int student = studentQueue.front();
                studentQueue.pop();
                studentQueue.push(student);
                count++;
            }
        }
        return studentQueue.size();
    }
};