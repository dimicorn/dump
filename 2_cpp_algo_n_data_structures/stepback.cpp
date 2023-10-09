#include <iostream>

int find_prev_value(list_element* root, int value)
{
    int c = 0;
    while (root->next)
    {
        if (root->value == value && root->prev!=NULL)
        {
            return root->prev->value;
        }
        root = root->next;
    }
    return 0;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
