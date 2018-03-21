#ifndef LIBRARYCONTROLLER_H
#define LIBRARYCONTROLLER_H

#include <vector>
#include "Context.hpp"
#include "ItemRepository.hpp"
#include "Item.hpp"
#include "User.hpp"

#include <boost/asio.hpp>


#include <iostream>
#include "TermColor.hpp"

#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using boost::asio::ip::tcp;

class LibraryController {
public:
	LibraryController() = delete;
	LibraryController(Context& context);
	void start();
private:
	ItemRepository itemRepository;
	Context &context;
	void listen();
	void handleClient(tcp::socket& socket);
};
#endif