#include <iostream>
#include <stdexcept>

#ifndef __PIMPL_HPP__
#define __PIMPL_HPP__

namespace implementation
{
	class ChesireCat;
}

namespace facade
{
	class Handler
	{
		public:
			Handler();
			Handler(const Handler& iRight);
			Handler& operator=(const Handler& iRight);

			~Handler();

			void smile() const;

		private:
			implementation::ChesireCat* _pimpl;
			static int id;

		protected:
	};
}

namespace implementation
{
	class ChesireCat
	{
		friend class facade::Handler;
		public:
			~ChesireCat() {};
		private:
			ChesireCat(int iId) 
				: _id(iId) {};

			ChesireCat(const ChesireCat& iRight) 
				: _id(iRight._id) {};

			ChesireCat& operator=(const ChesireCat& iRight) 
			{
				_id = iRight._id;
				return *this;
			};
			void smile() const;

			int _id;

		protected:
	};
}


#endif
