#include <set>


namespace ft
{
	//set container in c++98 style

	template <class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key> >
	class set
	{
		public:
			typedef Key key_type;
			typedef Key value_type;
			typedef Compare key_compare;
			typedef Compare value_compare;
			typedef Alloc allocator_type;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
			typedef typename Alloc::difference_type difference_type;
			typedef typename Alloc::size_type size_type;

		private:
			typedef typename Alloc::template rebind<value_type>::other value_alloc;
			typedef typename Alloc::template rebind<value_type*>::other pointer_alloc;
			typedef typename Alloc::template rebind<value_type**>::other pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type***>::other pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type****>::other pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type*****>::other pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type******>::other pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type*******>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type********>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type*********>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type**********>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type***********>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type************>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type*************>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type**************>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type***************>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			typedef typename Alloc::template rebind<value_type****************>::other pointer_pointer_pointer_pointer_pointer_pointer_pointer pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_pointer_alloc;
			


}