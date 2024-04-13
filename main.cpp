#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node *next;

    Node() {};
};

template <typename T>
class forward_list {
private:
    Node<T> *head;

public:
    forward_list(): head(NULL) {}

    // primer elemento
    T front() {
        if (empty()) {
            return 0;
        }
        return head->data;
    }

    // último elemento
    T back() {
        if (empty()) {
            return 0;
        }

        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->data;
    }

    // agregar un elemento al inicio
    void push_front(T data) {
        Node<T> *temp = new Node<T>;
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    // agregar un elemento al final
    void push_back(T data) {
        if (empty()) {
            push_front(data);
            return;
        }

        Node<T> *node = new Node<T>;
        node->data = data;
        Node<T> *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
        node->next = NULL;
    }

    // eliminar el primer elemento
    void pop_front() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    // eliminar el último elemento
    void pop_back() {
        if (head->next == NULL) {
            delete head;
            head = NULL;
        }

        Node<T> *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    T operator[](int index) {
        if (index < 0 || index >= size()) {
            return 0;
        }

        Node<T> *temp = head;
        for (int i = 0; i < index; ++i)
            temp = temp->next;
        return temp->data;
    }

    // comprobar si está vacío
    bool empty() {
        return head == NULL;
    }

    // calcular tamaño
    int size() {
        int count = 0;
        Node<T> *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // eliminar todos los elementoss
    void clear() {
        while (!empty())
            pop_front();
    }

    void sort() {
        Node<T> *temp = head;
        while (temp) {
            Node<T> *min = temp;
            Node<T> *r = temp->next;

            while (r) {
                if (min->data > r->data)
                    min = r;
                r = r->next;
            }

            T x = temp->data;
            temp->data = min->data;
            min->data = x;
            temp = temp->next;
        }
    }

    // Invierte el orden de los elementos
    void reverse() {
        Node<T> *current = head;
        Node<T> *prev = NULL;
        Node<T> *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // destructor
    ~forward_list() {
        while (head != NULL) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    return 0;
}