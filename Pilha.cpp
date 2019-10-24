#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Node {
    private:
        Node* next;
        int value;
    
    public:
        Node (int value) {
            this->value = value;
            this->next = NULL;
        }

        ~Node () {

        }

        int get_value () {
            return this->value;
        }

        Node* get_next () {
            return this->next;
        }

        void set_next (Node* next_node) {
            this->next = next_node;
        }
};

class Pilha {
    private:
        Node* top;
        int qtde;
        // seta o que foi passado em argumento para o topo;
        void set_top(Node* topo) {
            top = topo;
        }

    public:
        Pilha() {
            Node* top = NULL;
            qtde = 0;
        }

        ~Pilha () {
            Node * aux;
            while (this->top) {
                aux = this->top;
                set_top(aux->get_next());
                delete aux;
            }
        }

        void pilha_push(int value) {
            Node* novo = new Node(value);
            if(this->top == NULL) {
                set_top(novo);
            } else {
                novo->set_next(this->top);
                set_top(novo);
            }
            this->qtde++;
        }

        void pilha_pop() {
            if(this->top == NULL) {
                cout << "Pilha Vazia!" << endl;
            } else {
                Node* aux = this->top;
                printf("%d \n", aux->get_value());
                set_top(aux->get_next());
                delete aux;
                this->qtde--;
            }
        }

};

int main() {
    Pilha* p = new Pilha();
    
    p->pilha_push(10);
    p->pilha_push(20);
    p->pilha_push(30);

    p->pilha_pop();
    p->pilha_pop();
    p->pilha_pop();
}