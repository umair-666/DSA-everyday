
class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Your Code here
        if (!r1 && r2)
            return 0;
        if (r1 && !r2)
            return 0;
        if (!r1 && !r2)
            return 1;

        bool goLeft = isIdentical(r1->left, r2->left);
        bool goRight = isIdentical(r1->right, r2->right);

        if (goLeft && goRight && r1->data == r2->data)
            return 1;
        else
            return 0;
    }