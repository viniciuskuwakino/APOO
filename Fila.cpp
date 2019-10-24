#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

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

class Fila {
    private:
        int qtde;
        Node* first;
        Node* last;

        void set_last(Node* last) {
            this->last = last;
        }

        void set_first(Node* first) {
            this->first = first;
        }

    public:
        Fila() {
            qtde = 0;
            Node* first = NULL;
            Node* last = NULL;
        }

        ~Fila () {
            Node * aux;
            while (this->first) {
                aux = this->first;
                set_first(aux->get_next());
                delete aux;
            }
        }

        void fila_push(int value) {
            Node* novo = new Node(value);
            if(this->last == NULL) {
                set_first(novo);
                set_last(novo);
            } else {
                this->last->set_next(novo);
                set_last(novo);
            }
            this->qtde++;
        }

        void fila_pop() {
            if(this->last == NULL) {
                cout << "Fila vazia!" << endl;
            } else {
                Node* aux = this->first;
                set_first(aux->get_next());
                delete aux;
                this->qtde--;
            }
        }

        string to_string () {
            string response = "[";

            Node * aux = this->first;

            while (aux) {
                string val = aux->get_next() != NULL? ", ": "";

                response.append(std::to_string(aux->get_value()));
                response.append(val);

                aux = aux->get_next();
            }
            return response + "]";
        }

};

int main() {
    Fila* f = new Fila();

    f->fila_push(10);
    f->fila_push(20);
    f->fila_push(30);



    cout << f->to_string() << endl;
    f->fila_pop();
    cout << f->to_string() << endl;
}