// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        std::vector<Node*> vctr;
        char val;
    };
    Node* root;

 public:
    int per_size;
    std::vector<char> tmp_inf;
    std::vector<char> inf;
    std::vector<char> v;
    int n_fact;


    Node* addChilds(Node* root, std::vector<char> ch) {
        if (!root) {
            throw std::string("Error!");
        } else {
            if (!ch.empty()) {
                for (int i = 0; i < ch.size(); i++) {
                    root->vctr.push_back(new Node);
                    root->vctr[i]->val = ch[i];
                }
                for (int i = 0; i < ch.size(); i++) {
                    std::vector<char> in_i;
                    for (int k = 0; k < ch.size(); k++) {
                        if (k != i) {
                            in_i.push_back(ch[k]);
                        } else {
                            inf.push_back(ch[i]);
                        }
                    }
                    if (!in_i.empty()) {
                        root->vctr[i] = addChilds(root->vctr[i], in_i);
                    }
                }
            }
        }
        return root;
    }
    explicit Tree(std::vector<char> in) : root(nullptr), \
     n_fact(0), per_size(0) {
        if (root) {
            throw std::string("Error!");
        } else {
            if (!in.empty()) {
                v = in;
                per_size = in.size();
                n_fact = fact(per_size);
                root = new Node;
                root->val = '*';
                for (int i = 0; i < in.size(); i++) {
                    root->vctr.push_back(new Node);
                    root->vctr[i]->val = in[i];
                }
                for (int i = 0; i < in.size(); i++) {
                    std::vector<char> in_i;
                    for (int j = 0; j < in.size(); j++) {
                        if (j != i) {
                            in_i.push_back(in[j]);
                        } else {
                            inf.push_back(in[i]);
                        }
                    }
                    if (!in_i.empty()) {
                        root->vctr[i] = addChilds(root->vctr[i], in_i);
                    }
                    for (int k = 0; k < in.size() - 1; k++) {
                        tmp_inf.push_back(inf[inf.size() - 1]);
                        inf.pop_back();
                    }
                    inf.push_back(in[i]);
                    for (int q = 0; q < in.size() - 1; q++) {
                        inf.push_back(tmp_inf[tmp_inf.size() - 1]);
                        tmp_inf.pop_back();
                    }
                    tmp_inf.clear();
                }
            }
        }
    }

    int fact(int n) {
        int k = 1;
        for (int i = 1; i <= n; i++) {
            k *= i;
        }
        return k;
    }
};

std::vector<char> getPerm(const Tree& tree, int n);
#endif  // INCLUDE_TREE_H_
