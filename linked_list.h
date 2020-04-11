//
// Created by Sebastian Knell on 4/11/20.
//

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

namespace utec {
    struct node_t {
        int _value = 0;
        node_t* _next = nullptr;
    };

    inline namespace first {
        class linked_list_t {
            node_t* _head = nullptr;
            node_t* _tail = nullptr;
            size_t _size = 0;
        public:

        };
    }
}


#endif //LINKED_LIST_LINKED_LIST_H
