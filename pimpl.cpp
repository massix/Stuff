#include <iostream>
#include <stdexcept>
#include "pimpl.hpp"

using implementation::ChesireCat;
using facade::Handler;
using namespace std;

int Handler::id = 0;

Handler::Handler()
	: _pimpl(new ChesireCat(++id))
{
}

Handler::Handler(const Handler& iRight)
	: _pimpl(new ChesireCat(*iRight._pimpl))
{
	++id;
	_pimpl->_id = id;
}

Handler& Handler::operator=(const Handler& iRight)
{
	_pimpl = new ChesireCat(*iRight._pimpl);
	++id;
	_pimpl->_id = id;
	return *this;
}

Handler::~Handler()
{
	delete _pimpl;
}

void Handler::smile() const
{
	return _pimpl->smile();
}

void ChesireCat::smile() const
{
	cout << "Hello world\n";
	cout << " from ChesireCat #" << _id << endl;
}

int main()
{
	Handler aHandler;
	aHandler.smile();

	Handler aCopyHandler(aHandler);
	aCopyHandler.smile();

	Handler aNewHandler;
	aNewHandler.smile();

	return 0;
}

