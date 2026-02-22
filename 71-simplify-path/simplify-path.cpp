class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string current = "";

        for(int i = 0; i <= path.length(); i++) {

            if(i == path.length() || path[i] == '/') {

                if(current == "..") {
                    if(!stack.empty())
                        stack.pop_back();
                }
                else if(current != "" && current != ".") {
                    stack.push_back(current);
                }

                current = "";
            }
            else {
                current += path[i];
            }
        }

        // Build final path
        string result = "";

        for(string dir : stack) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};