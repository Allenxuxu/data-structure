#ifndef ITERARTOR
#define ITERARTOR

#include <stddef.h>

namespace XXLib
{
    template <class Tp>
    struct constTraits
    {
        typedef Tp                    value_type;
        typedef const Tp&             reference;
        typedef const Tp*             pointer;
    };

    template <class Tp>
    struct nonConstTraits
    {
        typedef Tp                    value_type;
        typedef Tp&                   reference;
        typedef Tp*                   pointer;
    };

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template <class T>
    struct iterator_traits<const T*>
    {
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef const T*                   pointer;
        typedef const T&                   reference;
    };

    template <class Iterator>
    inline typename iterator_traits<Iterator>::iterator_category
    iterator_category(const Iterator&)
    {
        typedef typename iterator_traits<Iterator>::iterator_category category;
        return category();
    }

    template <class Iterator>
    inline typename iterator_traits<Iterator>::difference_type*
    distance_type(const Iterator&)
    {
        return static_cast<typename iterator_traits<Iterator>::difference_type*>(0);
    }

    template <class Iterator>
    inline typename iterator_traits<Iterator>::value_type*
    value_type(const Iterator&)
    {
        return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
    }

//        /*
//         * bidirectional iterator
//         */
//        template<class T, class Traits, typename Node>
//        struct lbidirectionalIterator
//        {
//            typedef lbidirectionalIterator<T,constTraits<T>,Node >       iterator;
//            typedef lbidirectionalIterator<T,nonConstTraits<T>,Node >    const_iterator;
//            typedef lbidirectionalIterator<T,Traits,Node>                self;

//            typedef T                               value_type;
//            typedef typename Traits::pointer        pointer;
//            typedef typename Traits::reference      reference;

//            typedef  Node* link_type;

//            link_type m_node;

//            lbidirectionalIterator(link_type x) : m_node(x) {}
//            lbidirectionalIterator() {}
//            lbidirectionalIterator(const iterator& x) : m_node(x.m_node) {}
//            lbidirectionalIterator(const const_iterator& x) : m_node(x.m_node) {}

//            bool operator==(const self& x) const
//            { return m_node == x.m_node; }

//            bool operator!=(const self& x) const
//            { return m_node != x.m_node; }

//            reference operator*() const
//            { return (*m_node).value; }

//            pointer operator->() const
//            { return &(operator*()); }

//            self& operator++()
//            {
//                m_node = static_cast<link_type>((*m_node).next);
//                return *this;
//            }
//            self operator++(int)
//            {
//                self tmp = *this;
//                ++*this;
//                return tmp;
//            }
//            self& operator--()
//            {
//                m_node = static_cast<link_type>((*m_node).prev);
//                return *this;
//            }
//            self operator--(int)
//            {
//                self tmp = *this;
//                --*this;
//                return tmp;
//            }
//        };

    /*
     * forward iterator
     */
    template<class T, class Traits, typename Node>
    struct forwardIterator
    {
        typedef forwardIterator<T,constTraits<T>,Node >       iterator;
        typedef forwardIterator<T,nonConstTraits<T>,Node >    const_iterator;
        typedef forwardIterator<T,Traits,Node>                self;

        typedef T                               value_type;
        typedef typename Traits::pointer        pointer;
        typedef typename Traits::reference      reference;

        typedef  Node* link_type;

        link_type m_node;

        forwardIterator(link_type x) : m_node(x) {}
        forwardIterator() {}
        forwardIterator(const iterator& x) : m_node(x.m_node) {}
        forwardIterator(const const_iterator& x) : m_node(x.m_node) {}

        bool operator==(const self& x) const
        { return m_node == x.m_node; }

        bool operator!=(const self& x) const
        { return m_node != x.m_node; }

        reference operator*() const
        { return (*m_node).value; }

        pointer operator->() const
        { return &(operator*()); }

        self& operator++()
        {
            m_node = static_cast<link_type>((*m_node).next);
            return *this;
        }
        self operator++(int)
        {
            self tmp = *this;
            ++*this;
            return tmp;
        }

    };

    /*
     * bidirectional iterator
     */
    template<class T, class Traits, typename Node>
    struct lbidirectionalIterator : public forwardIterator<T,Traits,Node>
    {
        typedef lbidirectionalIterator<T,constTraits<T>,Node >       iterator;
        typedef lbidirectionalIterator<T,nonConstTraits<T>,Node >    const_iterator;
        typedef lbidirectionalIterator<T,Traits,Node>                self;

        typedef T                               value_type;
        typedef typename Traits::pointer        pointer;
        typedef typename Traits::reference      reference;

        typedef  Node* link_type;

        lbidirectionalIterator(link_type x) : forwardIterator<T,Traits,Node>(x) {}
        lbidirectionalIterator() {}
        lbidirectionalIterator(const iterator& x) : forwardIterator<T,Traits,Node>(x) {}
        lbidirectionalIterator(const const_iterator& x) : forwardIterator<T,Traits,Node>(x) {}

        self& operator--()
        {
            this->m_node = static_cast<link_type>((*this->m_node).prev);
            return *this;
        }
        self operator--(int)
        {
            self tmp = *this;
            --*this;
            return tmp;
        }
    };

}

#endif // ITERARTOR

