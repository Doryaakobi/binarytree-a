#include <iostream>
#include <typeinfo>

namespace ariel {    

    template<typename T>
    class BinaryTree {
        private:
            struct Node {
                T val;
                Node *l_child, *r_child, *parent;
                Node(T value):val(value), l_child(nullptr), r_child(nullptr), parent(nullptr){} 
                ~Node(){delete l_child; delete r_child;}
            };
            
            class iterator {
                private:
                    Node* curr_node_ptr;
                public:
                    iterator(Node* n = nullptr):curr_node_ptr(n) {}
                    
                    iterator& operator++ (){
                        return *this;
                    }
                    iterator operator++ (int a){
                        iterator t{curr_node_ptr};
                        return t;
                    }

                    bool operator!= (const iterator& other){return false;}
                    const T& operator* () const {return curr_node_ptr->val;}
                    const T* operator->() const { return &(curr_node_ptr->val); }
            };

            Node* root;

        public:
            BinaryTree():root(nullptr){}
            BinaryTree<T>& add_root(const T& v){
                return *this;
            }
            BinaryTree<T>& add_left(const T& v1, const T& v2){return *this;}
            BinaryTree<T>& add_right(const T& v1, const T& v2){return *this;}
            
            
            iterator begin_preorder(){return iterator{root};}
            iterator end_preorder(){return end();} 

            iterator begin_inorder(){return iterator{root};}
            iterator end_inorder(){return end();}

            iterator begin_postorder(){return iterator{root};}
            iterator end_postorder(){return end();}
            
            iterator begin() {return iterator{root};}
            iterator end() {return iterator{nullptr};}
            
            friend std::ostream& operator <<(std::ostream& os, const BinaryTree& tree) {
                return os << "tree" << std::endl;
            }

    };
};