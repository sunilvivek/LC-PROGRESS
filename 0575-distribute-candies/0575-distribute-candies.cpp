class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> types;

        for (int candy : candyType) {
            types.insert(candy);
        }

        return min((int)types.size(), (int)candyType.size() / 2);
    }
};

