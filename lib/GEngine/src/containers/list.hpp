// TODO! NOT DONE

#pragma once

template <typename T>
class list
{
public:
    iterator begin()
    {
        return {&head};
    }

    iterator end()
    {
        return {&tail};
    }

    struct node;

    class iterator
    {
    public:
        iterator(const node *n)
            : node(n)
        {
        }

        T &operator*()
        {
            return data->data;
        }

        void operator++()
        {
            data = data->next;
        }

        void operator--()
        {
            data = data->prev;
        }

    private:
        node *data;
    };

private:
    struct node
    {
        node *prev;
        node *next;
        T data;
    };

    node *head = nullptr;
    node *tail = nullptr;
};