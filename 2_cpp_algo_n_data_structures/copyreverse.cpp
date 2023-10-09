#include <iostream>

list_element* copy_reverse(list_element* root)
{
    list_element* root_1 = NULL;
    while (root)
    {
        list_element* elem = create_list_element(root->value);
        root_1 = insert_into_list(root_1, elem);
        root = root->next;
    }
    return root_1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
