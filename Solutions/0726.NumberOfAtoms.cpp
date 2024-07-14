class Solution {
public:
    string countOfAtoms(string formula) {
        // Speed thingies.
		// ios_base::sync_with_stdio(false);
        // cin.tie(nullptr);
        // cout.tie(nullptr);
        
        // NOTE: Honestly, don't know the best approach here. So im just gonna write a language tokenizer + parser.
        
        // Token definition.
        enum class Token {
            None,
            Element,
            Number,
            OpenBracket,
            CloseBracket,
        };

        // Find tokens.
        vector<pair<Token, string>> tokens;
        string activeString = "";
        Token activeToken = Token::None;
        const int n = formula.size();
        for (int i = 0; i < n; i++) {
            const char activeChar = formula[i];
            Token newToken = Token::None;
            
            // Tokenize.
            if (('A' <= activeChar && activeChar <= 'Z') ||
                ('a' <= activeChar && activeChar <= 'z')) {
                newToken = Token::Element;
            } else if ('0' <= activeChar && activeChar <= '9') {
                newToken = Token::Number;
            } else if (activeChar == '(') {
                newToken = Token::OpenBracket;
            } else if (activeChar == ')') {
                newToken = Token::CloseBracket;
            }

            if (newToken != activeToken || 
                newToken == Token::OpenBracket || newToken == Token::CloseBracket ||
                (newToken == Token::Element && 'A' <= activeChar && activeChar <= 'Z')) {
                // Add token.
                tokens.emplace_back(activeToken, activeString);
                activeString.clear();
            } 

            // Update variables for next iteration.
            activeString += activeChar;
            activeToken = newToken;
        }
        tokens.emplace_back(activeToken, activeString);

        // Setup calculation variables.
        stack<int> depthMultiplier;
        depthMultiplier.push(1);

        // Find element counts.
        map<string, int> elementCount;
        const int m = tokens.size();
        for (int i = 0; i < m; i++) {
            auto& currentToken = tokens[i];

            switch (currentToken.first) {
                case Token::Element: {
                    // Check if number to the right, if there is use it as a multiplier.
                    const int multiplier = depthMultiplier.top() * ((i + 1 < m && tokens[i + 1].first == Token::Number) ? atoi(tokens[i + 1].second.c_str()) : 1);

                    auto it = elementCount.find(currentToken.second);
                    if (it == elementCount.end()) {
                        // Add new element to list.
                        elementCount.emplace(currentToken.second, multiplier);
                    } else {
                        // Add on element count to list.
                        it->second += multiplier;
                    }
                } break;
                case Token::OpenBracket: {
                    // Find associated close bracket.
                    int j = i + 1, depth = 1;
                    for (; j < m; j++) {
                        if (tokens[j].first == Token::OpenBracket) {
                            depth++;
                        } else if (tokens[j].first == Token::CloseBracket) {
                            depth--;
                            if (depth <= 0) break;
                        }
                    }

                    // Get number after close bracket.
                    const int pni = j + 1;
                    const int multiplier = (pni < m && tokens[pni].first == Token::Number) ? atoi(tokens[pni].second.c_str()) : 1;

                    // Increment depth multiplier.
                    depthMultiplier.push(depthMultiplier.top() * multiplier);
                } break;
                case Token::CloseBracket: {
                    depthMultiplier.pop();
                } break;
            }
        }

        // Convert element map to string.
        string elementString = "";
        for (auto element : elementCount) {
            elementString += element.first;
            if (element.second > 1)
                elementString += to_string(element.second);
        }

        return elementString;
    }
};