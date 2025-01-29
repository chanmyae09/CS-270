// void addAllNOdes(Node* root, vector<int>& result){
//     if (root == NULL)
//         return;
//     addAllNOdes(root-> left, result);
//     result.append(root->val);
//     addAllNodes(root->right, result)
// }
// BinarySearchTree bst;
// vector<int> input, reuslt;
//     //Put some data in input
// for (auto item: input)
//     bst.add(item)  // First step: insert all items
// addAllNOdes(bst.root, result); // Second step: read out all nodes in order
#include <utility>
class BST{
    private:
        class Node{
            public:
                int val;
                Node* left, *right;
        };
        Node* root;
    public:
        bool verify(){return _verify_helper(root, 0, 8999999999);};
    private:
        bool _verify_helper(Node* root, int min, int max) {
            if(!root){
               return true;
            }
            bool left = _verify_helper(root->left, min,  root->val);
            bool right = _verify_helper(root-> right, root->val, max);
            if (!left || !right) {
                return false;  // If any subtree is invalid, return false immediately
                }

            if (min < root->val && root->val < max) {
                return true;  // If node's value is valid and both subtrees are valid, return true
                } else {
                return false;  // If node's value is not valid, return false
            }
        };
};


template<class E>
class TwoDArray {
    //Write a constructor that creates a TwoDArray object width enough
    // space for width*height elements in the field _array.
    public:
        TwoDArray(int width, int height): _width(width),_height(height){
            _array = new E [_width*height];
        }
        E* operator[](int i) {
            return & _array[i*_width];
        }
        ~TwoDArray(){
            delete _array[];
        }
        int width() const { return _width; }
        int height() const { return _height; }
    protected:
        int _width, _height;
        E *_array;
    private:
    TwoDArray(const TwoDArray& other);
    const TwoDArray& operator=(const TwoDArray& other);
};

void brighten( TwoDArray<int>& image) {
    for (int i = 0; i < image.height(); i++) {
        for (int j = 0; j < image.width(); j++) {
    //Read the original image entry at index (i, j)
        int orig = image[i][j];
        int result = std::min<int>(orig+10, 255);
    //Write the new image entry at index (i, j)
        image[i][j]=result;
        }
    }
}
