#include "tests.h"
using namespace std;

Test::Test()
{
	
}

void Test::test_domain() 
{
	Book b("carte1","autor1",2020);
	assert(b.get_title().compare("carte1") == 0);
	assert(b.get_autor().compare("autor1") == 0);
	assert(b.get_year() == 2020);

	Book b2(b);
	assert(b2.get_title().compare("carte1") == 0);
	assert(b2.get_autor().compare("autor1") == 0);
	assert(b2.get_year() == 2020);
	assert(b == b2);

	b.set_year(2015);
	b.set_autor("autor2");
	b.set_title("carte2");
	assert(b.get_title().compare("carte2") == 0);
	assert(b.get_autor().compare("autor2") == 0);
	assert(b.get_year() == 2015);

	b2 = b;
	assert(b2.get_title().compare("carte2") == 0);
	assert(b2.get_autor().compare("autor2") == 0);
	assert(b2.get_year() == 2015);
	
	b.set_year(2020);
	assert(b > b2);
	assert(b2 < b);
	//cout << b << endl;
	cout << "domain tested" << endl;
	
}
void  Test::test_repo()
{
	//		without files

	//CREATE BOOK;
	Repository repo;
	Book b("carte1", "autor1", 2020), b2;
	repo.create_book(b);
	b2 = repo.read_books().top();
	assert(b2 == b);

	//UPDATE BOOK
	b2.set_title("cartenoua");
	repo.update_book(b, b2);
	b = repo.read_books().top();
	assert(b == b2);
	

	//DELETE BOOK
	Book b3("carte2", "autor2", 2000);
	repo.create_book(b3);
	repo.delete_book(b);
	b = repo.read_books().top();
	assert(b == b3);

	//		with fliles

	//CREATE BOOK;
	Repository repof("bookTest.txt");
	Book bf("carte1", "autor1", 2020), b2f;
	repof.create_book(bf);
	b2f = repof.read_books().top();
	assert(b2f == bf);

	//UPDATE BOOK
	b2f.set_title("cartenoua");
	repof.update_book(bf, b2f);
	bf = repof.read_books().top();
	assert(bf == b2f);


	//DELETE BOOK
	Book b3f("carte2", "autor2", 2000);
	repof.create_book(b3f);
	repof.delete_book(bf);
	bf = repof.read_books().top();
	assert(bf == b3f);

	while (!repof.read_books().empty())
	{
		b3 = repof.read_books().top();
		repof.delete_book(b3);
	}


	cout << "repository tested" << endl;
}
void Test::test_service()
{
	Repository repo;
	Service serv(repo);
	
	//ADD BOOK
	serv.add_book("carte1", "autor1", 2000);
	Book b1(serv.get_all().top());
	assert(b1.get_title() == "carte1");
	assert(b1.get_autor() == "autor1");
	assert(b1.get_year() == 2000);

	//UPDATE BOOK
	serv.update_book("carte1","carte2", "autor2", 2000);
	Book b2(serv.get_all().top());
	assert(b2.get_title() == "carte2");
	assert(b2.get_autor() == "autor2");
	assert(b2.get_year() == 2000);

	//DELETE BOOK
	serv.add_book("carte3", "autor3", 2015);
	Book b3(serv.get_all().top());
	assert(b3.get_title() == "carte3");
	serv.delete_book("carte3");
	b3 = serv.get_all().top();
	assert(b3.get_title() == "carte2");
	assert(b3.get_autor() == "autor2");
	assert(b3.get_year() == 2000);

	cout << "service tested" << endl;

	
}
void Test::test_all()
{
	this->test_domain();
	this->test_repo();
	this->test_service();
	cout << endl << endl;
}
