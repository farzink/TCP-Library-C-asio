#include "stdafx.h"
#include <boost\test\unit_test.hpp>
#include "Item.hpp"
#include "User.hpp"
#include "Context.hpp"
#include "Generator.hpp"
#include "ItemRepository.hpp"
#include "UserRepository.hpp"

using namespace std;


BOOST_AUTO_TEST_SUITE(user_entity_test)

BOOST_AUTO_TEST_CASE(user_constructor_id) {
	User user("1", "", "", "");
	BOOST_CHECK_EQUAL(user.getId(), "1");
}
BOOST_AUTO_TEST_CASE(user_constructor_values) {
	string id = "1";
	string name = "name";
	string age = "23";
	string email = "email";
	User user(id, name, age, email);
	BOOST_CHECK_EQUAL((user.getId() + user.getName() + user.getAge() + user.getEmail()), /*|*/(id + name + age + email));
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(item_entity_test)

BOOST_AUTO_TEST_CASE(item_constructor_id) {
	Item item(1, "", "", "", "");
	BOOST_CHECK_EQUAL(item.getId(), 1);
}
BOOST_AUTO_TEST_CASE(item_constructor_values) {
	int id = 1;
	string title = "title";
	string author = "author";
	string publisher = "publisher";
	string isbn = "isbn";
	Item item(id, title, author, publisher, isbn);
	BOOST_CHECK_EQUAL((to_string(item.getId()) + item.getTitle() + item.getAuthor() + item.getPublisher() + item.getISBN()), /*|*/(to_string(id) + title + author + publisher + isbn));
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(context_test)

BOOST_AUTO_TEST_CASE(context_instace_initiation) {
	Context& context = Context::getInstance();
	BOOST_CHECK(&context!=NULL);
}
BOOST_AUTO_TEST_CASE(context_next_id_generator) {
	int a = Context::getInstance().getNextId();
	int b = Context::getInstance().getNextId();
	BOOST_CHECK_EQUAL(a, (b+1));
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(data_generator_test)

BOOST_AUTO_TEST_CASE(items_generation_5) {
	Generator generator;
	vector<Item> items = generator.generateItems(5);
	BOOST_CHECK_EQUAL(items.size(), 5);
}
BOOST_AUTO_TEST_CASE(items_generation_10) {
	Generator generator;
	vector<Item> items = generator.generateItems(10);
	BOOST_CHECK_EQUAL(items.size(), 10);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(item_repository)

BOOST_AUTO_TEST_CASE(item_insert) {
	Context& context = Context::getInstance();
	ItemRepository itemRepository(context);
	Item item(1, "", "", "", "");
	BOOST_CHECK_EQUAL(itemRepository.insert(item), true);
}
BOOST_AUTO_TEST_CASE(get_by_id) {
	Context& context = Context::getInstance();
	ItemRepository itemRepository(context);
	Item item(1, "title", "", "", "");
	itemRepository.insert(item);
	BOOST_CHECK_EQUAL(itemRepository.getItemById(item.getId())->getTitle(), item.getTitle());
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(user_repository)

BOOST_AUTO_TEST_CASE(user_insert) {
	Context& context = Context::getInstance();
	UserRepository userRepository(context);
	User user("1", "", "", "");
	BOOST_CHECK_EQUAL(userRepository.insert(user), true);
}
BOOST_AUTO_TEST_CASE(get_by_id) {
	Context& context = Context::getInstance();
	UserRepository userRepository(context);
	User user("1", "", "", "");
	userRepository.insert(user);
	BOOST_CHECK_EQUAL(userRepository.userExist(user.getId()), true);
}

BOOST_AUTO_TEST_SUITE_END()